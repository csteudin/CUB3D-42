#include "../../inc/cub3d.h"

//SUB FUNCTION
void	init_map(t_data *data)
{
	t_map	*map;

	map = &data->map;
	map->texpath_NO = NULL;
	map->texpath_SO = NULL;
	map->texpath_EA = NULL;
	map->texpath_WE = NULL;
	map->raw_lines = NULL;
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
//SEPERAT AUFRUFEN
void	init_render()
{
    t_render *render;
	
    render = &getdata()->render;
    render->mlx = mlx_init(WIDTH, HEIGHT, "_-cub3D-_", true);
	if (!render->mlx)
		error_exit("Could not initialize MLX42");
	render->img = mlx_new_image(render->mlx, WIDTH, HEIGHT);
	if (!render->img)
		error_exit("Could not create MLX42 image");
	if (mlx_image_to_window(render->mlx, render->img, 0, 0) < 0)
		error_exit("Could not attach image to window");
    render->tile_size = calc_tile_size(&getdata()->map);
}

void init_data(void)
{
	t_data	*data;

	data = getdata();
	init_map(data);
}
