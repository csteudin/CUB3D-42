#include "../../inc/cub3d.h"

int is_number(char *str)
{
    int i;

    i = 0;
    if (str[i] == '\0')
        return (0);
    while(str[i])
    {
        if (!ft_isdigit(str[i]))
            return (0);
        i++;
    }
    return (1);
}

int parse_rgb(char *str)
{
    int value;

    if (!is_number(str))
        error_exit("Invalid RGB value (not a number)");
    value = ft_atoi(str);
    if(value < 0 || value > 255)
        error_exit("Invalif RGB value (num is out of scope 0 - 255)");
    return (value);
}

void get_color(char *line, t_line type)
{
    t_map *map;
    char **numz;
    t_clr clr;

    map = &getdata()->map;
    numz = ft_split(line, ',');
    if (!numz)
        error_exit("Could not split color values");
    if (!numz[0] || !numz[1] || !numz[2] || numz[3])
        error_exit("Color must have exactly 3 values");
    clr.channel.R = parse_rgb(numz[0]);
    clr.channel.G = parse_rgb(numz[1]);
    clr.channel.B = parse_rgb(numz[2]);
    clr.channel.A = 255;
    if (type == LINE_F)
        map->floor_clr = clr;
    else
        map->ceiling_clr = clr;
    ft_free_2d(numz);
}
