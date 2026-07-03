#include <stdio.h>
#include <unistd.h>

void	ft_swap(char *s1, char *s2)
{
	char	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

void	sort_str(char *str)
{
	int	i = 0;
	while (str[i])
	{
		int	j = i + 1;
		while (str[j])
		{
			if (str[i] > str[j])
				ft_swap(&str[i], &str[j]);
			j++;
		}
		i++;
	}
}

void	perm(char *str, int start, int end)
{
	if (start == end)
	{
		puts(str);
		return ;
	}
	int	i = start;
	while (i < end)
	{
		sort_str(str + start);
		ft_swap(&str[start], &str[i]);
		sort_str(str + start + 1);
		perm(str, start + 1, end);
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (0);
	int	len = 0;
	while (av[1][len])
		len++;
	sort_str(av[1]);
	perm(av[1], 0, len);
	return (0);
}