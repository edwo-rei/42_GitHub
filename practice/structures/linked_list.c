#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//declare a structure called island w/ the following variables
typedef struct	island
{
	char		*name;
	char		*open;
	char		*close;
	struct island	*next;
}			island;

//loop through all nodes printing their info
void	display(island *start)
{
	island	*i;

	i = start;
	while (i)
	{
		printf("Name: %s - open: %s-%s\n", i->name, i->open, i->close);
		i =  i->next;//same as (*i).next
	}
}

//create a new island given its name
island	*create(char *name)
{
	island	*i;

	i = malloc(sizeof(island));
	if (!i)
		return (NULL);
	i->name = strdup(name);
	i->open = "09:00";
	i->close = "17:00";
	i->next = NULL;
	return (i);
}

//initialize variable of each node of the island-type structure. Start w/ NULLs
//for ptr to next island, then initialize w/ adresses of islands created
int	main(void)
{
	island	amity = {"Amity", "09:00", "17:00", NULL};
	island	craggy = {"Craggy", "09:00", "17:00", NULL};
	island	isla_nublar = {"Isla Nublar", "09:00", "17:00", NULL};
	island	skull = {"Skull", "09:00", "17:00", NULL};
	island	shutter = {"Shutter", "09:00", "17:00", NULL};

	amity.next = &craggy;
	craggy.next = &isla_nublar;
	isla_nublar.next = &skull;
	skull.next = &shutter;
	display(&amity);

	//add a new island to the list
	island	*start = NULL;
	island	*i = NULL;
	island	*next = NULL;
	char	name[] = "Atlantis";

	next = create(name);
	if (start == NULL)
		start = next;
	if (i)
		i->next = next;
	display(start);
}
