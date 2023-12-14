#include "get_next_line.h"

char	*ft_strdup(char const *s, int i_nl)
{
	char	*str;
	int		i;

	i = 0;
	if (i_nl >= 0)
		i = i_nl + 1;
	else
		i = ft_strlen(s);
	str = (char *)malloc((size_t)(1 + i) * sizeof(char));
	if (!str)
		return (NULL);
	i = -1;
	if (i_nl >= 0)
		while (++i <= i_nl)
			str[i] = s[i];
	else
		while (s[++i] != '\0')
			str[i] = s[i];
	str[i] = '\0';
	return (str);
}

int	finder(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\n' && s[i] != '\0')
		++i;
	if (s[i] == '\0')
		return (-1);
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2, int i_nl)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = -1;
	j = 0;
    if (!s1 || !s2)
        return (NULL);
	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (s1[++i] != '\0')
		str[i] = s1[i];
	while (s2[j] != '\0' && s2[j] != '\n')
	{
		str[i + j] = s2[j];
		++j;
	}
	if (s2[i] == '\n')
		str[i + j] = '\n';
	++j;
	str[i + j] = '\0';
	return (str);
}
