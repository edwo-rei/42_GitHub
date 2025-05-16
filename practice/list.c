#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node//structure name; typedef allows use of "node" instead of "struct node"
{
	int number;//this is a structure member & holds content
	struct node *next;//this is a pointer to next node
} node;//this is the type alias, with typedef allows use of just "node"

int main(int argc, char *argv[])
{
	node *list = NULL;//ptr to head of linked list
	int	i;

	i = 1;//start at 1 so as not to print program position
	while (i < argc)
	{
		int	number;

		number = atoi(argv[i]);
		node *n = malloc(sizeof(node));//allocates mem to hold int each iteration of loop, doen't need to be contiguous as w/ an array
		if (n == NULL)
		{
			free(n);
			return (1);
		}
		n->number = number;//"n->number" = "(*n).number
		n->next = list;//(*n).next = ptr variable "list"
		list = n;//moves list ptr to location of most recent node (n), aka "head"
		i++;
	}
	//print whole list
	node *ptr = list;
	while (ptr != NULL)
	{
		printf("%i\n", ptr->number);
		ptr = ptr -> next;
	}
}
