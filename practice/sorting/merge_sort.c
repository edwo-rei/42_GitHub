#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//combine 2 strings together w/ chars in ascending order
char	*merge(char *s1, char *s2)
{
	int	i;
	char	*combo;

	i = 0;
	combo = malloc(strlen(s1) + strlen(s2) +  1);
	if (!combo)
		return (0);
	while (*s1  || *s2)
	{
		//first 2 if no chars remain in one of the strings
		if (!*s1)
		{
			combo[i] = *s2;
			s2++;
		}
		else if (!*s2)
		{
			combo[i] = *s1;
			s1++;
		}
		else if (*s1 < *s2)
		{
			combo[i] = *s1;
			s1++;
		}
		else
		{
			combo[i] = *s2;
			s2++;
		}
		i++;
	}
	combo[i] = 0;
	return (combo);
}

//divide string into halves, then recursively call merge_sort until divided
//into single chars
char	*merge_sort(char *str)
{
	int	i;
	int	j;
	int	half;
	char	*left;
	char	*right;
	char	*tmp_l;
	char	*tmp_r;
	
	if (strlen(str) < 2)
		//necessary to duplicate b/c otherwise I will try to free
		//this below before using it to merge. Instead of returning
		//something something in newly allocated mem per usual, it 
		//returns a ptr to mem that was previously allocated
		return (strdup(str));
	i = 0;
	j = 0;
	half = (strlen(str) / 2);
	left = malloc(half + 1);
	right = malloc(strlen(str) - half + 1);
	if (!left || !right)
		return (0);
	while (i < half)
	{
		left[i] = str[i];
		i++;
	}
	left[i] = 0;
	while (str[i])
	{
		right[j] = str[i];
		i++;
		j++;
	}
	right[j] = 0;
	//to be able to free mem originally allocated to left & right
	tmp_l = merge_sort(left);
	tmp_r = merge_sort(right);
	free(left);
	free(right);
	str = merge(tmp_l, tmp_r);
	free(tmp_l);
	free(tmp_r);
	return (str);
}

int	main(int argc, char **argv)
{
	int	i;
	char	*array;
	char	*sorted;

	i = 1;
	if (argc < 3)
		return (0);
	array = malloc(argc);
	if (!array)
		return (0);
	//loop through args assigning each to corresponding index in array
	while (i < argc)
	{
		array[i - 1] = *argv[i];
		i++;
	}
	//append null char
	array[i - 1] = 0;
	//to be able to free mem originally allocated to array
	sorted = merge_sort(array);
	printf("%s", sorted);
	free(array);
	free(sorted);
}
