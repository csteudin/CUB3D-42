#include "../../inc/cub3d.h"

int starts_with(char *line, char *key)
{
    int len;

    len = ft_strlen(key);
    if (ft_strncmp(line, key, len) != 0)
        return (0);
    if (line[len] != ' ' && line[len] != '\t')
        return (0);
    return (1);
}

int is_map_line(char *line)
{
    int i;

    i = 0;
    if (line[0] == '\0')
        return (0);
    while(line[i])
    {
        if (!ft_strchr("01NESW \n", line[i]))
            return (0);
        i++;
    }
    return (i);
}

t_line_type get_line_type(char *line)
{
    t_identifier    idents[6];
    int i;

    i = 0;
    idents[0] = (t_identifier){"NO", LINE_NO};
    idents[1] = (t_identifier){"EA", LINE_EA};
    idents[2] = (t_identifier){"SO", LINE_SO};
    idents[3] = (t_identifier){"WE", LINE_WE};
    idents[4] = (t_identifier){"F", LINE_F};
    idents[5] = (t_identifier){"C", LINE_C};
    while(*line == ' ' || *line == '\t')
        line++;
    if (*line == '\0' || *line == '\n')
        return (LINE_EMPTY);
    while(i <= 5)
    {
        if (starts_with(line, idents[i].key))
            return (idents[i].type);
        i++;
    }
    if (is_map_line(line))
        return (LINE_MAP);
    return (LINE_INVALID);
}
