#include "libft.h"

int	main(void)
{
	char	src[] = "this one out";
	char	dst[] = "Try";
	char	source[] = "this one out";
	char	dest[] = "Try";
	char	s[] = "this one out";
	char	d[] = "Try ";
	char	*join;
	char	**matrix;
	size_t	size;
	int	i;

	size = 12;
	i = 0;
	//printf("%lu\n", strlcpy(dst, src, size));
	printf("New dst: %s\n", dst);
	printf("%lu\n", ft_strlcpy(dest, source, size));
	printf("New dest: %s\n", dest);
	join = ft_strjoin(d, s);
	printf("%s\n", join);
	free(join);
	matrix = ft_split(s, ' ');
	while (matrix[i])
	{
		printf("%s\n", matrix[i]);
		free(matrix[i]);
		i++;
	}
	free(matrix);
	return (0);
}
