/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_ft.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 19:18:19 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/04/06 17:52:44 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_ultimate_ft(int *********nbr)
{
	*********nbr = 42;//changes the value in the last address pointed to to 42
}

int	main(void)
{
	int	i;
	i = 17;
	printf("%i\n", i);

	int* j = &i;
	printf("%i\n", *j);
	printf("%p\n", &i);
	printf("%p\n", j);

	int** k = &j;
        printf("%i\n", **k);
	printf("%p\n", *k);
	printf("%p\n", k);

	int*** l = &k;
        printf("%i\n", ***l);
	printf("%p\n", **l);
	printf("%p\n", *l);
	printf("%p\n", l);

	int**** m = &l;
        printf("%i\n", ****m);

	int***** n = &m;
        printf("%i\n", *****n);

	int****** o = &n;
        printf("%i\n", ******o);

	int******* p = &o;
        printf("%i\n", *******p);

	int******** q = &p;
        printf("%i\n", ********q);

	int********* r = &q;
        printf("%i\n", *********r);

	ft_ultimate_ft(r);
	printf("%i\n", *********r);
	printf("%i\n", i);
}
