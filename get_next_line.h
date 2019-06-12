/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 13:53:33 by waddam            #+#    #+#             */
/*   Updated: 2019/01/28 06:22:30 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft/libft.h"

# define BUFF_SIZE	555
# define DELIMITER	'\n'
# define DEL(content, content_size) ft_memdel(&(content)); content_size = 0
# define FREE(lst) free(lst); lst = NULL
# define GNL_INVALID (fd < 0 || BUFF_SIZE <= 0 || read(fd, buf, 0) == -1)
# define CHECK_VALIDATE if GNL_INVALID return (-1)
# define RET_IF_MALLOC_CRUSH if (!(lst = begin)) return (-1)
# define IF_BEGIN_EXIST if (!begin) begin = ft_glstnew(NULL, 0, fd)
# define RET_IF_FIND(line, lst) if (ft_gfind(line, &(lst))) return (1)
# define RET_DEL_LIST return (ft_gdellst(ret, line, &begin, &lst))

typedef struct		s_gnllst
{
	void			*content;
	size_t			content_size;
	int				fd;
	struct s_gnllst	*next;
}					t_gnllst;

int					get_next_line(const int fd, char **line);

#endif
