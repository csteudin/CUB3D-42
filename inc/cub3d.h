#ifndef CUB3D_H
#define CUB3D_H

//-__INCLUDES__-
#include "../libs/MLX42/include/MLX42/MLX42.h"
#include "../libs/libft/libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdint.h>

//-__DEFINES__-
# define WIDTH 1920
# define HEIGHT 1080

# define TILE_SIZE 16;

//-__STRUCTURES__-
typedef struct s_vec2
{
    int x;
    int y;
}   t_vec2;

typedef union u_clr
{
    uint32_t rgba;

    struct
    {
        uint8_t  A;
        uint8_t  B;
        uint8_t  G;
        uint8_t  R;
    }   channel;
}   t_clr;

typedef struct s_map
{
    char *file_path;
    char *texpath_N;
    char *texpath_E;
    char *texpath_S;
    char *texpath_W;

    t_clr floor_clr;
    t_clr ceiling_clr;

    char    **raw_lines;
    char    **raw_map;
    int     max_length;
    int     max_height;

    t_vec2  start_pos;
    char    start_view;
}   t_map;

typedef struct s_data //WIP
{
    t_map map;

    // t_mlx *mlx_image
    // other mlx stuff . . .
    // other game stuff . . .
}   t_data;

//-___FUNCTIONS___-

//_--MAIN--_------>
int main(int ac, char **av);

//_--PARSING--_--->
//-parse_file
int     parse_file(char **av);

//-parse_lines
int     parse_lines();

//-read_file
void    get_lines(char **av, t_map *map);
void    read_lines(char **av, t_map *map);
void    read_file(char **av);

//_--RENDER--_---->


//_--UTILS--_----->
//-free_utils
void    free_map(t_data *data);
void    free_data(void);

//-init_utils
void    init_map(t_data *data);
void    init_data(void);

//-program_utils
void    error_exit(char *msg);
t_data  *getdata(void);


#endif