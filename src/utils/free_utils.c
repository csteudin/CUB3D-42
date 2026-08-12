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
	if (map->texpath_N)
		free(map->texpath_N);
	if (map->texpath_S)
		free(map->texpath_S);
	if (map->texpath_E)
		free(map->texpath_E);
	if (map->texpath_W)
		free(map->texpath_W);
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
