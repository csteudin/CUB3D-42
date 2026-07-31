#ifndef CUB3D_H
#define CUB3D_H

//_INCLUDES_
#include "../libs/MLX42/include/MLX42/MLX42.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdint.h>

//_DEFINES_
# define WIDTH 1920
# define HEIGHT 1080

# define TILE_SIZE 16;

//_STRUCTURES_
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

    char **raw_map;
    int     max_length;
    int     max_height;

    t_vec2  start_pos;
    char    start_view;
}   t_map;

typedef struct s_data //WIP
{
    t_map map;

}   t_data;

//_FUNCTIONS_
//-MAIN

//-PARSING

//-RENDER

//-UTILS


#endif