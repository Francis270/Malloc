/*
** EPITECH PROJECT, 2018
** display.c
** File description:
** Created by Thomas BLENEAU
*/

#include <stdlib.h>
#include <ncurses.h>
#include <curses.h>
#include "visual.h"

void display_key_next(window_t *_next, size_t y, size_t x)
{
	mvwprintw(_next, y / 2 + 8, x / 2 - 2, "_____");
	mvwprintw(_next, y / 2 + 9, x / 2 - 3, "|     |");
	mvwprintw(_next, y / 2 + 10, x / 2 - 3, "|  >  |");
	mvwprintw(_next, y / 2 + 11, x / 2 - 3, "|_____|");
	mvwprintw(_next, y / 2 + 13, x / 2 - 8, "Press arrow right");
	mvwprintw(_next, y / 2 + 14, x / 2 - 10, "to display next BLOCK");
}

void display_key_prev(window_t *_prev, size_t y, size_t x)
{
	mvwprintw(_prev, y / 2 + 8, x / 2 - 1, "_____");
	mvwprintw(_prev, y / 2 + 9, x / 2 - 2, "|     |");
	mvwprintw(_prev, y / 2 + 10, x / 2 - 2, "|  <  |");
	mvwprintw(_prev, y / 2 + 11, x / 2 - 2, "|_____|");
	mvwprintw(_prev, y / 2 + 13, x / 2 - 7, "Press arrow left");
	mvwprintw(_prev, y / 2 + 14, x / 2 - 12, "to display previous BLOCK");
}

void display_prev(window_t *_prev, size_t y)
{
	mvwprintw(_prev, y / 2,
			13, "  ___ ___ _____   _____ ___  _   _ ___ ");
	mvwprintw(_prev, y / 2 + 1,
			13, " | _ | _ | __  \\ / |_ _/ _ \\| | | / __|");
	mvwprintw(_prev, y / 2 + 2,
			13, " |  _|   | _| \\ V / | | (_) | |_| \\__ \\");
	mvwprintw(_prev, y / 2 + 3,
			13, " |_| |_|_|___| \\_/ |___\\___/ \\___/|___/");
}

void display_next(window_t *_next, size_t y)
{
	mvwprintw(_next, y / 2, 13, " _  _ _____  _______");
	mvwprintw(_next, y / 2 + 1, 13, "| \\| | __\\ \\/ |_   _|");
	mvwprintw(_next, y / 2 + 2, 13, "| .` | _| >  <  | |");
	mvwprintw(_next, y / 2 + 3, 13, "|_|\\_|___/_/\\_\\ |_|");
}

void display_block(window_t *_block, size_t max_y, size_t max_x)
{
	size_t inc_y = 2;
	size_t inc_x = 0;
	size_t inc = 0;

	while (inc_y < 23) {
		inc = 0;
		inc_x = rand() % max_x;
		wattron(_block, COLOR_PAIR(2));
		while (++inc < inc_x)
			mvwprintw(_block, max_y - inc_y, inc, "#");
		wattroff(_block, COLOR_PAIR(1));
		wattron(_block, COLOR_PAIR(7));
		while (inc < max_x - 1)
			mvwprintw(_block, max_y - inc_y, inc++, "#");
		wattroff(_block, COLOR_PAIR(1));
		inc_y++;
	}
	wattroff(_block, COLOR_PAIR(1));
}
