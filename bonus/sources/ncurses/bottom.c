/*
** EPITECH PROJECT, 2018
** display.c
** File description:
** Created by Thomas BLENEAU
*/

#include <curses.h>
#include <ncurses.h>
#include <string.h>
#include "visual.h"

void display_bottom(window_t *_window, const char *const _str)
{
	size_t max_x;
	size_t max_y;

	getmaxyx(_window, max_y, max_x);
	mvwprintw(_window, (max_y / 2),
		(max_x / 2) - (strlen(_str) / 2), _str);
	refresh();
	wrefresh(_window);
}

void init_bottom(void)
{
	window_t *_dev = create_window(2, COLS / 2, LINES - 3, COLS / 4);
	window_t *_module = create_window(2, 24, LINES - 5,
				COLS / 2 - COLS / 8 - 26);
	window_t *_date = create_window(2, 21, LINES - 5,
			COLS / 2 + COLS / 8 + 2);

	display_bottom(_dev,
		"Developped by François Caïecedo, Thomas Bleneau");
	display_bottom(_module, "PROGRAMATION SYSTEM UNIX");
	display_bottom(_date, "EPITECH - 2017 / 2018");
}
