#include <stdio.h>
#include <stdlib.h>

//function returns 1 until array is sorted
int	is_sorted(char *array)
{
	int	i;
	
	i = 0;
	while (array[i + 1])
	{
		if (array[i] > array[i + 1])
			return (1);
		i++;
	}
	return (0);
}

void	bubblesort(char *array)
{
	char	tmp;
	int	i;

	while (is_sorted(array))
	{
		//must reset inside this loop each time
		i = 0;
		//loop until penultimate char
		while (array[i + 1])
		{
			//if char is greater than char that follows it,
			//switch them
			if (array[i] > array[i + 1])
			{
				tmp = array[i + 1];
				array[i + 1] = array[i];
				array[i] = tmp;
			}
			i++;
		}
	}
}

int	main(int argc, char **argv)
{
	int	i;
	char	*array;

	i = 1;
	if (argc < 3)
		return (0);
	//loop through args assigning each to corresponding index in array
	while (i < argc)
	{
		array[i - 1] = *argv[i];
		i++;
	}
	//append null char
	array[i - 1] = 0;
	bubblesort(array);
	printf("%s", array);
}
