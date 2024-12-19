#include "get_next_line.h"

int	ft_strlen(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*a;
	size_t			i;

	a = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		a[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*str;

	str = malloc(nmemb * size);
	if (str)
		ft_bzero(str, nmemb * size);
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	int		i;
	int		j;

	i = 0;
	s = (char *)ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (!s)
		return (NULL);
	while (s1[i] != '\0')
	{
		s[i] = (char)s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		s[i + j] = (char)s2[j];
		j++;
	}
	s[i + j] = '\0';
	return (s);
}
