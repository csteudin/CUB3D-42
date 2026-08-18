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


typedef enum e_line_type
{
	LINE_NO,
	LINE_EA,
	LINE_SO,
	LINE_WE,
	LINE_F,
	LINE_C,
	LINE_MAP,
    
	LINE_EMPTY,
	LINE_INVALID
}	t_line_type;

typedef struct s_identifier
{
    char *key;
    t_line_type type;
}   t_identifier;

typedef struct s_lines
{
    int count_NO;
    int count_EA;
    int count_SO;
    int count_WE;
    int count_F;
    int count_C;
}   t_lines;

typedef struct s_map
{
    char *file_path;
    char *texpath_NO;
    char *texpath_EA;
    char *texpath_SO;
    char *texpath_WE;

    t_clr floor_clr;
    t_clr ceiling_clr;

    t_lines lines;

    char    **raw_lines;
    char    **raw_map;
    int     map_start_idx;
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
//-extract_map

void extract_map(t_map *map);

//-get_line_type
int     starts_with(char *line, char *key);
int     is_map_line(char *line);
t_line_type get_line_type(char *line);

//-parse_file
void    increment_flag(t_map *map, t_line_type type);
void    update_flags(t_map *map, t_line_type type, int idx);
void    check_flags(t_map *map);
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