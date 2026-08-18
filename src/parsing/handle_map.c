#include "../../inc/cub3d.h"

int count_map_lines(t_map *map)
{
    int i;
    int offset;


    i = 0;
    offset = map->map_start_idx;
    while(map->raw_lines[i + offset] != NULL)
        i++;
    return (i);
}

void extract_map(t_map *map)
{
    int i;
    int len;
    int offset;

    i = 0;
    len = count_map_lines(map);
    offset = map->map_start_idx;
    map->raw_map = malloc(sizeof(char *) * (len + 1));
    if (!map->raw_map)
        error_exit("Could not allocate raw_map");
    while(i < len)
    {
        map->raw_map[i] = ft_strdup(map->raw_lines[i + offset]);
        if(map->raw_map[i] == NULL)
            error_exit("Could not copy raw_lines -> raw_map");
        i++;
    }
    map->raw_map[i] = NULL;
}

void find_max_length(t_map *map)
{
    int i;
    int len;

    i = 0;
    len = 0;
    while(map->raw_map[i] != NULL)
    {
        len = ft_strlen(map->raw_map[i]);
        if (len > 0 && map->raw_map[i][len - 1] == '\n')
            len--;
        if (len > map->max_length)
            map->max_length = len;
        i++;
    }
    map->max_height = i;
}

char *build_new_line(char *line, int len)
{
    int i;
    int old_len;
    char *new_line;

    i = -1;
    old_len = ft_strlen(line);
    if (old_len > 0 && (line[old_len - 1] == '\n'))
        old_len--;
    new_line = malloc(sizeof(char) * (len + 1));
    if (new_line == NULL)
        error_exit("Could not allocate padded-line");
    while(++i < old_len)
        new_line[i] = line[i];
    while(i < len)
    {
        new_line[i] = ' ';
        i++;
    }
    new_line[i] = '\0';
    return (new_line);
}

void pad_map(t_map *map)
{
    int i;
    char *new_line;

    i = 0;
    find_max_length(map);
    while(map->raw_map[i] != NULL)
    {
        new_line = build_new_line(map->raw_map[i], map->max_length);
        free(map->raw_map[i]);
        map->raw_map[i] = new_line;
        i++;
    }
}