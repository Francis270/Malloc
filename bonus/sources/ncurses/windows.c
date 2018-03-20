/*
** EPITECH PROJECT, 2018
** windows.c
** File description:
** Created by Thomas BLENEAU
*/

#include <string.h>
#include <curses.h>
#include <ncurses.h>
#include "visual.h"

void create_box(window_t *_window, size_t form_x, size_t form_y)
{
	box(_window, form_y, form_x);
	refresh();
	wrefresh(_window);
}

window_t *create_window(size_t max_y, size_t max_x,
			size_t pos_y, size_t pos_x)
{
	return (newwin(max_y, max_x, pos_y, pos_x));
}

void create_border(window_t *_window, size_t format)
{
	wborder(_window, format, format, format, format,
		format, format, format, format);
	refresh();
	wrefresh(_window);
}

void clear_window(window_t *_clear)
{
	size_t max_x = 0;
	size_t max_y = 0;
	size_t inc_i = 0;
	size_t inc_j = 0;

	getmaxyx(_clear, max_y, max_x);
	for (inc_i = 0; inc_i < max_y; inc_i++) {
		for (inc_j = 0; inc_j < max_x; inc_j++) {
			mvwprintw(_clear, inc_i, inc_j, " ");
		}
	}
}
