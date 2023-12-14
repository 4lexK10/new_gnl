#include "get_next_line.h"

static char	*get_read(int fd)
{
	char	*str;
	char	*buf;
	int		cnt;

	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	cnt = read(fd, buf, BUFFER_SIZE);
	if (cnt > 0)
		buf[cnt] == '\0';
	if (cnt < 0)
		return (free(buf), NULL);
	str = ft_strdup(buf, finder(buf));
	free(buf);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*nl;
	int			check;

	if (fd < 1 || BUFFER_SIZE < 1 || BUFFER_SIZE >= INT_MAX)
		return(NULL);
	if (!str)
		str = get_next_line(fd);
	if (!str)
		return (NULL);
	check = finder(str);
	nl = str + check;
	while (check != -1)
	{
		str = ft_strjoin(str, get_read(fd), -1);
		check = finder(str);
		nl += check;
	}
}

