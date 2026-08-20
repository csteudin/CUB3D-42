#include "../../inc/cub3d.h"

int trimmed_len(char *str)
{
    int len;

    len = ft_strlen(str);
    while (len > 0 && (str[len - 1] == '\n' || str[len - 1] == ' ' || str[len - 1] == '\t'))
        len--;
    return (len);
}

char *cut_value(char *line, t_line type)
{
    char *value;
    
    int i;

    i = 0;
    while(line[i] == ' ' || line[i] == '\t')
        i++;
    if (type == LINE_NO || type == LINE_EA || type == LINE_SO || type == LINE_WE)
        i = i + 2;
    else
        i++; 
    while(line[i] == ' ' || line[i] == '\t')
        i++;
    value = ft_substr(line + i, 0, trimmed_len(line + i));
    if (!value)
        error_exit("Could not allocate value (path extraction)");
    return (value);
}

void get_path(char *line, t_line type)
{
    char *new_line;
    t_map *map;

    map = &getdata()->map;
    if (access(line, R_OK | F_OK ) == -1)
        error_exit("Could not access given Texture-path");
    new_line = ft_strdup(line);
    if (!new_line)
        error_exit("Could not allocate new_path");
    if (type == LINE_NO)
        map->texpath_NO = new_line;
    else if (type == LINE_EA)
        map->texpath_EA = new_line;
    else if (type == LINE_SO)
        map->texpath_SO = new_line;
    else if (type == LINE_WE)
        map->texpath_WE = new_line;
}

/*
    need to get paths and colors, thats all
*/
void parse_values(t_map *map)
{
    int i;
    t_line type;
    char *value;

    i = 0;
    while(i <= map->map_start_idx - 1)
    {
        type = get_line_type(map->raw_lines[i]);
        if (type == LINE_EMPTY)
        {
            i++;
            continue;
        }
        value = cut_value(map->raw_lines[i], type);
        if (type == LINE_NO || type == LINE_EA || type == LINE_SO || type == LINE_WE)
            get_path(value, type);
        else if (type == LINE_F || type == LINE_C)
            get_color(value, type);
        else
            error_exit("Could not parse Value");
        free (value);
        i++;
    }
}