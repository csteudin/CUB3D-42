#include "../../inc/cub3d.h"

// PARSING_MAIN
int parse_file(int ac, char **av)
{
    if (ac != 2)
        error_exit("Wrong number of arguments");
    read_file(av);
    parse_lines();
    return (0);
}