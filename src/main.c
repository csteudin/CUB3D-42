#include "../inc/cub3d.h"

int main(int ac, char **av)
{
    (void)ac;
    (void)av;

    printf("cub3d execution started . . .\n");
    parse_file(ac, av);
    // PSEUDO
    //  INIT(ac, av)
    // - creates STRUCT
    //      return(error)
    //  RENDER_LOOP(STRUCT)
    //      infinite -> calls clear funciton inside render loop-setup
    //  FREE-FUNCTIONS

    return (0);
}