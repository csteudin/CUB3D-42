#include "../../inc/cub3d.h"

int **init_vision(t_map *map)
{
    int **vision;
    int y;

    y = 0;
    vision = malloc(sizeof(int *) * map->max_height);
    if (!vision)
        error_exit("Could not allocate vision-grid");
    while(y < map->max_height)
    {
        vision[y] = malloc(sizeof(int) * map->max_length);
        if (!vision[y])
            error_exit("Could not allocate vision-grid");
        ft_bzero((void *)vision[y], sizeof(int) * map->max_length);
        y++;
    }
    return (vision);
}

void free_vision(t_map *map, int **vision)
{
    int y;

    y = 0;
    while(y < map->max_height)
    {
        free(vision[y]);
        y++;
    }
    free(vision);
}

void flood_fill(t_map *map, int **vision, int y, int x)
{
    if (y < 0 || y >= map->max_height)
        error_exit("Map is not closed (out of bound)");
    if (x < 0 || x >= ft_strlen(map->raw_map[y]))
        error_exit("Map is not closed (out of bound)");
    if (map->raw_map[y][x] == ' ')
        error_exit("Map is not closed (leak)");
    if (map->raw_map[y][x] == '1' || vision[y][x])
        return ;
    vision[y][x] = 1;
    flood_fill(map, vision, y - 1, x);
    flood_fill(map, vision, y + 1, x);
    flood_fill(map, vision, y, x - 1);
    flood_fill(map, vision, y, x + 1);
}

void validate_map(t_map *map)
{
    int **vision;

    find_player(map);
    vision = init_vision(map);
    flood_fill(map, vision, map->start_pos.y, map->start_pos.x);
    free_vision(map, vision);
}