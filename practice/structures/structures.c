#include <stdio.h>

struct	exercise
{
	const char	*description;
	float		duration;
};

struct	meal
{
	const char	*ingredients;
	float		weight;
};

//This struct's members are the types of structs listed above
struct	preferences
{
	struct meal	food;
	struct exercise	exercise;
};

typedef union
{
	int	cm;
	float	ft;
}		size;

//declare a structure called fish w/ variables of the following types & use
//typedef to give it an alias (at the end of the structure). If you give it
//an alias, it's not necessary to name it after "struct"
typedef struct
{
	//const char because these will hold string literals (won't change)
	const char		*name;
	const char		*species;
	int			teeth;
	int			age;
	struct preferences	care;
	size			length;
}				phish;

//functions take a fish structure as parameter & prints a string w/ its
//characteristics
void	catalog(phish f)
{
	printf("%s is a %s with %i teeth. He is %i.\n", f.name, f.species, 
			f.teeth, f.age);
}

void	label(phish f)
{
	printf("Name: %s\nSpecies: %s\n%i years old, %i teeth, %2.2f ft\n", 
			f.name, f.species, f.age, f.teeth, f.length.ft);
	printf("Feed with %2.2f lbs of %s and allow to %s for %2.2f hours\n",
		       	f.care.food.weight, 
			f.care.food.ingredients, 
			f.care.exercise.description, 
			f.care.exercise.duration);
}

//increase fish's age by 1
void	birthday(phish *f)
{
	f->age++;
	printf("Happy birthday %s, you are now %i years old!\n", 
			(*f).name, f->age);
	//f->age = (*f).age
}

//define the fish structure snappy and initialize its diff variables, then
//pass snappy to the catalog function
int	main(void)
{
	phish snappy = {"Snappy", "piranha", 69, 4, {{"meat", 0.2}, 
		{"swim in the jacuzzi", 7.5}}, .length.ft=3.5};
	catalog(snappy);
	//birthday function takes a ptr as its parameter
	birthday(&snappy);
	label(snappy);
}
