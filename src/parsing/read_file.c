#include "../../inc/cub3d.h"

void get_lines(char **av, t_map *map)
{
    int count;
    int fd;
    char *ptr;

    count = 0;
    fd = open(av[1], O_RDONLY);
    if (fd == -1)
        error_exit("Could not open file");
    ptr = get_next_line(fd);
    while(ptr != NULL)
    {
        map->raw_lines[count] = ptr;
        ptr = get_next_line(fd);
        count ++;
    }
    map->raw_lines[count] = NULL;
    close(fd);
}

void read_lines(char **av, t_map *map)
{
    int count;
    int fd;
    char *ptr;

    count = 0;
    fd = open(av[1], O_RDONLY);
    if (fd == -1)
        error_exit("Could not open file");
    ptr = get_next_line(fd);
    while(ptr != NULL)
    {
        free(ptr);
        ptr = get_next_line(fd);
        count ++;
    }
   
    map->raw_lines = malloc(sizeof(char *) * (count + 1));
    if (map->raw_lines == NULL)
    error_exit("Could not allocate raw_lines");
    close(fd);
}

void read_file(char **av)
{
    t_data *data;
    char *ptr;

    data = getdata();
    ptr = ft_strrchr(av[1], '.');
    if (!ptr || ft_strncmp(".cub\0", ptr, 5) != 0)
        error_exit("File doesnt match specified ending < .cub >");
    if (access(av[1], F_OK | R_OK) == -1)
        error_exit("File is not accesable, please check file permissions");
    read_lines(av, &data->map);
    get_lines(av, &data->map);
}