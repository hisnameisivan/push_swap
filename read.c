#include "get_next_line.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
//	int		fd;
//	int		gnl;
	char	*line;
	int		x;
	int		y;

	get_next_line(0, &line);
	x = ft_strcmp(line, "OK");
	y = ft_strcmp(line, "KO");
	while (x != 0 && y != 0)
	{
		get_next_line(0, &line);
		x = ft_strcmp(line, "OK");
		y = ft_strcmp(line, "KO");
		//printf("%s\nx = %d\ny = %d\n", line, x, y);
		free(line);
	}
	//printf("%s\nx = %d\ny = %d\n", line, x, y);
	//gnl = get_next_line(1, &line);
	//printf("%d %s\n", gnl, line);
	return (0);
}
