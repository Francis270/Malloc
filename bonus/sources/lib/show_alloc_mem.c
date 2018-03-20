/*
** EPITECH PROJECT, 2018
** show_alloc_mem.c
** File description:
** show_alloc_mem.c
*/

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <ncurses.h>
#include <curses.h>
#include "malloc.h"
#include "visual.h"

ssize_t m_putchar(const int fd, const int c)
{
	return (write(fd, &c, 1));
}

ssize_t m_putstr(const int fd, const char *const str)
{
	return (write(fd, str, strlen(str)));
}

ssize_t m_putnbr_base(const int fd, const size_t n,
			const char *const b)
{
	if (n / strlen(b))
		m_putnbr_base(fd, n / strlen(b), b);
	return (m_putchar(1, b[n % strlen(b)]));
}

void show_alloc_mem(void)
{
	size_t _key = 0;
	block_t *tmp = g_malloc.first_block;
	window_t *title = init_title();
	window_t *block = init_block(tmp);
	window_t *next = init_arrow_next(tmp);
	window_t *prev = init_arrow_prev(tmp);

	init_bottom();
	while ((_key = getch()) != 113) {
		update_title(title);
		if (_key == 260)
			update_pointer_left(block, prev, next, &tmp);
		else if (_key == 261)
			update_pointer_right(block, prev, next, &tmp);
	}
}
