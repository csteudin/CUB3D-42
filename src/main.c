#include "../inc/cub3d.h"

int main(int ac, char **av)
{
    if (ac != 2)
        error_exit("Wrong number of arguments");

    init_data();
    parse_file(av);
    // PSEUDO
    //  INIT_MLX -> onto data struct
    //  RENDER_LOOP(STRUCT)
    //      infinite -> calls clear funciton inside render loop-setup
    //  FREE-FUNCTIONS

    return (0);
}