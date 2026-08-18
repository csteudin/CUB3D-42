#include "../../inc/cub3d.h"

void check_flags(t_map *map)
{
    if (map->lines.count_NO != 1 || map->lines.count_SO != 1
        || map->lines.count_WE != 1 || map->lines.count_EA != 1
        || map->lines.count_F != 1 || map->lines.count_C != 1)
        error_exit("Config identifiers missing or duplicated");
    if (map->map_start_idx == -1)
        error_exit("No map found in file");
}

void increment_flag(t_map *map, t_line_type type)
{
    if (type == LINE_NO)
        map->lines.count_NO++;
    else if (type == LINE_EA)
        map->lines.count_EA++;
    else if (type == LINE_SO)
        map->lines.count_SO++;
    else if (type == LINE_WE)
        map->lines.count_WE++;
    else if (type == LINE_F)
        map->lines.count_F++;
    else if (type == LINE_C)
        map->lines.count_C++;
}

void update_flags(t_map *map, t_line_type type, int idx)
{
    if (type == LINE_INVALID)
        error_exit("Invalid line in file");
    if (type == LINE_EMPTY && map->map_start_idx != -1)
            error_exit("Empty line inside map");
    if (type == LINE_MAP)
    {
        if(map->map_start_idx == -1)
            map->map_start_idx = idx;
        return ;
    }
    if (map->map_start_idx != -1)
        error_exit("Config found after map start");
    increment_flag(map, type);
}

int parse_lines()
{
    t_map *map;
    int i;

    map = &getdata()->map;
    i = 0;

    while(map->raw_lines[i])
    {
        update_flags(map, get_line_type(map->raw_lines[i]), i);
        i++;
    }
    check_flags(map);
    extract_map(map);
    //validate values
    
    return (0);
}
