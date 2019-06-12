/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 15:29:27 by waddam            #+#    #+#             */
/*   Updated: 2019/01/28 06:27:23 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_gnllst	*ft_glstnew(void *content, size_t content_size, const int fd)
{
	t_gnllst	*temp;

	if (!(temp = (t_gnllst *)malloc(sizeof(t_gnllst))))
		return (NULL);
	if (!content)
	{
		temp->content = NULL;
		temp->content_size = 0;
		temp->fd = fd;
		temp->next = NULL;
	}
	else
	{
		if (!(temp->content = malloc(sizeof(*content) * content_size)))
		{
			free(temp);
			return (NULL);
		}
		ft_memcpy(temp->content, content, content_size);
		temp->content_size = content_size;
		temp->fd = fd;
		temp->next = NULL;
	}
	return (temp);
}

static void		ft_glstaddb(t_gnllst **begin, t_gnllst *new)
{
	t_gnllst	*temp;

	if (begin && new)
	{
		temp = *begin;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
}

static int		ft_gdellst(int ret, char **line,
							t_gnllst **begin, t_gnllst **lst)
{
	t_gnllst	*tmp_lst;

	tmp_lst = NULL;
	if ((*lst)->content)
	{
		if (ret == 0)
		{
			*line = ft_strnew((*lst)->content_size);
			ft_memcpy(*line, (*lst)->content, (*lst)->content_size);
		}
		DEL((*lst)->content, (*lst)->content_size);
		if ((*lst)->fd == (*begin)->fd)
			*begin = (*begin)->next;
		else
		{
			tmp_lst = *begin;
			while (tmp_lst->next->fd != (*lst)->fd)
				tmp_lst = tmp_lst->next;
			tmp_lst->next = (*lst)->next;
		}
		FREE(*lst);
		return (ret ? -1 : 1);
	}
	else
		return (ret);
}

static int		ft_gfind(char **line, t_gnllst **lst)
{
	void	*pos;
	void	*temp;

	pos = NULL;
	temp = NULL;
	if ((pos = ft_memchr((*lst)->content, DELIMITER, (*lst)->content_size)) > 0)
	{
		*line = ft_strnew(pos - (*lst)->content);
		ft_memcpy(*line, (*lst)->content, pos - (*lst)->content);
		(*lst)->content_size =
			(*lst)->content_size - (pos - (*lst)->content) - 1;
		temp = (*lst)->content;
		(*lst)->content = ft_memalloc((*lst)->content_size);
		ft_memcpy((*lst)->content, (pos + 1), (*lst)->content_size);
		ft_memdel(&temp);
		return (1);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static t_gnllst	*begin;
	char			buf[BUFF_SIZE];
	void			*temp;
	int				ret;
	t_gnllst		*lst;

	CHECK_VALIDATE;
	IF_BEGIN_EXIST;
	RET_IF_MALLOC_CRUSH;
	while (lst->fd != fd)
		!lst->next ? ft_glstaddb(&begin, lst = ft_glstnew(NULL, 0, fd))
			: (lst = lst->next);
	RET_IF_FIND(line, lst);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		temp = ft_memjoin(lst->content, buf, lst->content_size, ret);
		lst->content_size += ret;
		free(lst->content);
		lst->content = temp;
		RET_IF_FIND(line, lst);
	}
	RET_DEL_LIST;
}
