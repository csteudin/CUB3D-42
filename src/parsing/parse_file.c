#include "../../inc/cub3d.h"

// PARSING_MAIN
int parse_file(char **av)
{
    t_map *map;

    map = &getdata()->map;
    read_file(av);
    parse_lines();
    extract_map(map);
    pad_map(map);
    validate_map(map);
    return (0);
}