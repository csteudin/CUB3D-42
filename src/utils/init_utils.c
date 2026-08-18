#include "../../inc/cub3d.h"

//SUB FUNCTION
void	init_map(t_data *data)
{
	t_map	*map;

	map = &data->map;
	map->file_path = NULL;
	map->texpath_NO = NULL;
	map->texpath_SO = NULL;
	map->texpath_EA = NULL;
	map->texpath_WE = NULL;
	map->raw_map = NULL;
    map->map_start_idx = -1;
	map->max_length = 0;
	map->max_height = 0;
	map->start_pos.x = -1;
	map->start_pos.y = -1;
	map->start_view = 0;
	map->floor_clr.rgba = 0;
	map->ceiling_clr.rgba = 0;
}

void init_data(void)
{
	t_data	*data;

	data = getdata();
	init_map(data);
	
}
