#include "../../inc/cub3d.h"

int	calc_tile_size(t_map *map)
{
	int	tile_w;
	int	tile_h;

	tile_w = WIDTH / map->max_length;
	tile_h = HEIGHT / map->max_height;
	if (tile_w < tile_h)
		return (tile_w);
	return (tile_h);
}

void put_tile(int x_pos, int y_pos, t_render rnd, t_clr clr)
{
    int x = 0;
    int y = 0;


    while(y != rnd.tile_size)
    {
        while(x != rnd.tile_size)
        {
            mlx_put_pixel(rnd.img, (x_pos * rnd.tile_size) + x, (y_pos * rnd.tile_size) + y , clr.rgba);
            x++;
        }
        y++;
        x = 0;
    }
}

int rendering()
{
    t_data *data;
    t_map * map;

    data = getdata();
    map = &data->map;
    int x = 0;
    int y = 0;


    t_clr clr_A;
    clr_A.channel.A = 255;
    clr_A.channel.R = 199;
    clr_A.channel.B = 199;
    clr_A.channel.G = 199;
    t_clr clr_B;
    clr_B.channel.A = 255;
    clr_B.channel.R = 11;
    clr_B.channel.B = 11;
    clr_B.channel.G = 11;

    while(y < map->max_height)
    {
        while(x < map->max_length)
        {
            if (map->raw_map[y][x] == '1')
                put_tile(x, y, data->render, clr_A);
            else
                put_tile(x, y, data->render, clr_B);
            x++;
        }
        y++;
        x = 0;
    }
    mlx_image_to_window(data->render.mlx, data->render.img, 0, 0);
    mlx_loop(data->render.mlx);
    
    return (0);
}