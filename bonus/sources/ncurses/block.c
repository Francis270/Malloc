/*
** EPITECH PROJECT, 2018
** block.c
** File description:
** Created by Thomas BLENEAU
*/

#include <stdlib.h>
#include <ncurses.h>
#include <curses.h>
#include "visual.h"
#include "malloc.h"

window_t *init_block(block_t *current)
{
	window_t *_block = create_window(LINES / 6 * 4, COLS / 4, LINES / 4,
			(COLS / 2) - ((COLS / 4) / 2));

	update_block_title(_block);
	update_block(_block, &current);
	return (_block);
}

void update_block_title(window_t *_block)
{
	wattron(_block, COLOR_PAIR(rand() % 6));
	create_box(_block, 0, 0);
	mvwprintw(_block, 1, 1, "  ___ _    ___   ___ _  __");
	mvwprintw(_block, 2, 1, " | _ | |  / _ \\ / __| |/ /");
	mvwprintw(_block, 3, 1, " | _ | |_| (_) | (__|   <");
	mvwprintw(_block, 4, 1, " |___|____\\___/ \\___|_|\\_\\");
	wattroff(_block, COLOR_PAIR(1));
	refresh();
	wrefresh(_block);
}

void update_block(window_t *_block, block_t **_actual)
{
	size_t max_x;
	size_t max_y;

	getmaxyx(_block, max_y, max_x);
	mvwprintw(_block, 9, 2, "Current BLOCK Size   :");
	mvwprintw(_block, 9, 34, "%zu bytes    ",
		(*_actual)->size - ALIGN_SIZE(sizeof(block_t)));
	mvwprintw(_block, 10, 2, "Current BLOCK Statut :");
	if ((*_actual)->used == true)
		mvwprintw(_block, 10, 34, "USED");
	else
		mvwprintw(_block, 10, 25, "UNUSED");
	mvwprintw(_block, 11, 2, "Current Start BLOCK Adress :");
	mvwprintw(_block, 11, 34, "%p  ", (uintptr_t) GET_EBLOCK(*_actual));
	mvwprintw(_block, 12, 2, "Current End BLOCK Adress   :");
	mvwprintw(_block, 12, 34, "%p  ", (uintptr_t) GET_EBLOCK(*_actual) +
		(*_actual)->size - ALIGN_SIZE(sizeof(block_t)));
	display_block(_block, max_y, max_x);
	refresh();
	wrefresh(_block);
}

void update_pointer_left(window_t *_block, window_t *prev,
			window_t *next, block_t **_current)
{
	block_t *tmp = *_current;

	if (tmp->prev != NULL) {
		(*_current) = (*_current)->prev;
		update_block_title(_block);
		update_block(_block, _current);
		update_arrow(prev, next, _current, 260);
	} else
		update_arrow_prev(prev, false);
}

void update_pointer_right(window_t *_block, window_t *prev,
			window_t *next, block_t **_current)
{
	block_t *tmp = *_current;

	if (tmp->next != NULL) {
		(*_current) = (*_current)->next;
		update_block_title(_block);
		update_block(_block, _current);
		update_arrow(prev, next, _current, 261);
	} else
		update_arrow_next(next, false);
}
