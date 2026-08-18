#include "../../inc/cub3d.h"

// SUB FUNCTION
void free_map(t_data *data)
{
	t_map	*map;
	int 	i;

	i = 0;
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
	if (map->raw_lines)
	{
		i = 0;
		while (map->raw_lines[i])
		{
			free(map->raw_lines[i]);
			i++;
		}
		free(map->raw_lines);
	}
    if (map->raw_map)
	{
		i = 0;
		while (map->raw_map[i])
		{
			free(map->raw_map[i]);
			i++;
		}
		free(map->raw_map);
	}
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
