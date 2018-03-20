/*
** EPITECH PROJECT, 2018
** visual.h
** File description:
** Created by Thomas BLENEAU
*/

#ifndef VISUAL_H_
	#define VISUAL_H_

	#include <stdbool.h>
	#include <ncurses.h>
	#include <curses.h>
	#include "malloc.h"

	typedef WINDOW window_t;

	window_t *create_window(size_t, size_t, size_t, size_t);
	void create_box(window_t *, size_t, size_t);
	void create_border(window_t *, size_t);
	void clear_window(window_t *);
	void display_bottom(window_t *, const char *const);
	void init_bottom(void);
	window_t *init_block(block_t *);
	void update_block(window_t *, block_t **);
	void update_block_title(window_t *);
	void update_pointer_left(window_t *, window_t *, window_t *,
		block_t **);
	void update_pointer_right(window_t *, window_t *, window_t *,
		block_t **);
	window_t *init_title(void);
	void display_title(window_t *);
	void update_title(window_t *);
	window_t *init_arrow_next(block_t *);
	window_t *init_arrow_prev(block_t *);
	void update_arrow_next(window_t *, const bool);
	void update_arrow_prev(window_t *, const bool);
	void update_arrow(window_t *, window_t *, block_t **, size_t);
	void init_term(void);
	void display_key_next(window_t *, size_t, size_t);
	void display_next(window_t *, size_t);
	void display_key_prev(window_t *, size_t, size_t);
	void display_prev(window_t *, size_t);
	void display_block(window_t *, size_t, size_t);

#endif /* !VISUAL_H_ */
