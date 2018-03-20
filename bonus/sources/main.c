/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main.c
*/

#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "visual.h"
#include "malloc.h"

int main(void)
{
	srand(time(NULL));
	mmalloc(134);
	mmalloc(365);
	mmalloc(54);
	mmalloc(10);
	init_term();
	show_alloc_mem();
	endwin();
	return (0);
}
