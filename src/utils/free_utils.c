#include "../../inc/cub3d.h"

// SUB FUNCTION
void free_map(t_data *data)
{
	t_map	*map;

	map = &data->map;
	if (map->file_path)
		free(map->file_path);
	if (map->texpath_NO)
		free(map->texpath_NO);
	if (map->texpath_SO)
		free(map->texpath_SO);
	if (map->texpath_EA)
		free(map->texpath_EA);
	if (map->texpath_WE)
		free(map->texpath_WE);
    ft_free_2d(map->raw_lines);
    //ft_free_2d(map->raw_map);
    if (map->raw_map)
        free(map->raw_map);
}

// FREE_DATA
// Calls free_map
// deletes MLX and own DATA
void free_data(void)
{
	t_data *data;

	data = getdata();
	free_map(data);

}
