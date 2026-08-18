#include "../../inc/cub3d.h"

int is_pos(char c)
{
    return (c == 'N' || c == 'E' || c == 'S' || c == 'W');
}

void scan_pos(t_map *map, int y, int *count)
{
    int x;

    x = 0;
    while(map->raw_map[y][x])
    {
        if (is_pos(map->raw_map[y][x]))
        {
            map->start_pos.x = x;
            map->start_pos.y = y;
            map->start_view = map->raw_map[y][x];
            (*count)++;
        }
        x++;
    }
}

void find_player(t_map *map)
{
    int y;
    int count;

    y = 0;
    count = 0;
    while(map->raw_map[y] != NULL)
    {
        scan_pos(map, y, &count);
        y++;
    }
    if(count == 0)
        error_exit("Could not find player");
    if(count > 1)
        error_exit("There are too many start positions for the player");
}