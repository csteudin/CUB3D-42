#include "../../inc/cub3d.h"

void error_exit(char *msg)
{
    write(2, "Error\n", 6);
    if(msg)
    {
        write(2, msg, ft_strlen(msg));
        write(2, "\n", 1);
    }
    free_data();
    exit(EXIT_FAILURE);  
}

t_data *getdata(void)
{
    static t_data    data;
    return (&data);
}