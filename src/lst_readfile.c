#include <fcntl.h>
#include <unistd.h>

#include "libft.h"
#include "get_next_line.h"

/* SEE lst_extra.h */
t_list	*ft_lst_readfile(const char* path)
{
	t_list	*first;
	t_list	*next;
	t_list	*new;
	char	*line;
	int		fd;

	fd = open(path, O_RDONLY);
	first = ft_lstnew((void*)0);
	next = first;
	line = get_next_line(fd);
	while (line)
	{
		next->next = ft_lstnew(line);
		next = next->next;	
		*(first->content)++;
		line = get_next_line(fd);
	}
	close (fd);
	next->next = ft_lstnew(NULL);
	return (first);
}
