#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int		number;
	struct node	*next;
}			node;

int	main(int argc, char *argv[])
{
	int	i;
	int	number;
	node	*list;
	node	*ptr;
	node	*n;

	list = NULL;
	i = 1;
	//do the following for each command line arg
	while (i < argc)
	{
		// Convert string to int
		number = atoi(argv[i]);
		n = malloc(sizeof(node));
		if (!n)
		{
			//free memory used thus far?
			return (1);
		}
		n->number = number;
		n->next = NULL;
		ptr = list;
		// If list is empty
		if (list == NULL)
			// This node is the whole list
			list = n;
		// If # belongs at beginning of list
		else if (n->number < list->number)
		{
			n->next = list;
			list = n;
		}
		// If # belongs later in list
		else
		{
			while (ptr)
			{
				// If at end of list (bigger than other #s)
				if (ptr->next == NULL)
				{
					// Append node
					ptr->next = n;
					break;
				}
				// If in mid-list
				else if (n->number < ptr->next->number)
				{
					n->next = ptr->next;
					ptr->next = n;
					break;
				}
				ptr=ptr->next;
			}
		}
		i++;
	}
	ptr = list;
	while (ptr)
	{
		printf("%i\n", ptr->number);
		ptr = ptr->next;
	}
}
