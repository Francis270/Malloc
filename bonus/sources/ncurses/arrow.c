/*
** EPITECH PROJECT, 2018
** arrow.c
** File description:
** Created by Thomas BLENEAU
*/

#include <stdbool.h>
#include <ncurses.h>
#include <curses.h>
#include "visual.h"

window_t *init_arrow_next(block_t *block)
{
	window_t *_next = create_window(LINES / 6 * 4, COLS / 4,
		LINES / 4, COLS - (COLS / 4) - 4);

	if (block != NULL) {
		if (block->next == NULL)
			update_arrow_next(_next, false);
		else
			update_arrow_next(_next, true);
	}
	return (_next);
}

window_t *init_arrow_prev(block_t *block)
{
	window_t *_prev = create_window(LINES / 6 * 4, COLS / 4,
		LINES / 4, 4);

	if (block != NULL) {
		if (block->prev == NULL)
			update_arrow_prev(_prev, false);
		else
			update_arrow_prev(_prev, true);
	}
	return (_prev);
}

void update_arrow_next(window_t *_next, const bool next)
{
	size_t x = 0;
	size_t y = 0;

	getmaxyx(_next, y, x);
	clear_window(_next);
	if (next == true) {
		mvwprintw(_next, y / 2 - 5, 0, " ___ _    ___   ___ _  __");
		mvwprintw(_next, y / 2 - 4, 0, "| _ | |  / _ \\ / __| |/ /");
		mvwprintw(_next, y / 2 - 3, 0, "| _ | |_| (_) | (__|   <");
		mvwprintw(_next, y / 2 - 2,
			0, "|___|____\\___/ \\___|_|\\_\\");
		display_next(_next, y);
		display_key_next(_next, y, x);
	}
	refresh();
	wrefresh(_next);
}

void update_arrow_prev(window_t *_prev, const bool prev)
{
	size_t x = 0;
	size_t y = 0;

	getmaxyx(_prev, y, x);
	clear_window(_prev);
	if (prev == true) {
		mvwprintw(_prev, y / 2 - 5, 1, "  ___ _    ___   ___ _  __");
		mvwprintw(_prev, y / 2 - 4, 1, " | _ | |  / _ \\ / __| |/ /");
		mvwprintw(_prev, y / 2 - 3, 1, " | _ | |_| (_) | (__|   <");
		mvwprintw(_prev, y / 2 - 2,
			1, " |___|____\\___/ \\___|_|\\_\\");
		display_prev(_prev, y);
		display_key_prev(_prev, y, x);
	}
	refresh();
	wrefresh(_prev);
}

void update_arrow(window_t *prev, window_t *next, block_t **block, size_t _key)
{
	block_t *tmp = *block;

	if (_key == 261) {
		if (tmp->prev != NULL)
			update_arrow_prev(prev, true);
		else
			update_arrow_prev(prev, false);
		if (tmp->next == NULL)
			update_arrow_next(next, false);
	} else if (_key == 260) {
		if (tmp->next != NULL)
			update_arrow_next(next, true);
		else
			update_arrow_next(next, false);
		if (tmp->prev == NULL)
			update_arrow_prev(prev, false);
	}
}
