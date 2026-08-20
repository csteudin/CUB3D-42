#include "../inc/cub3d.h"

int main(int ac, char **av)
{
    if (ac != 2)
        error_exit("Wrong number of arguments");

    init_data();
    parse_file(av);
    
    
    //TESTING - - - - - - - - - -
    init_render();
    rendering();

    // - - - - - - - - - - - - -


    // PSEUDO
    //init signals
    //  INIT_MLX -> onto data struct
    //  RENDER_LOOP(STRUCT)
    //      infinite -> calls clear funciton inside render loop-setup

    free_data();

    return (0);
}