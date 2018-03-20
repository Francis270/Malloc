/*
** EPITECH PROJECT, 2018
** init.c
** File description:
** Created by Thomas BLENEAU
*/

#include <ncurses.h>
#include <curses.h>

void init_color_pair(void)
{
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_BLUE, COLOR_BLACK);
	init_pair(5, COLOR_CYAN, COLOR_BLACK);
	init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(7, COLOR_RED, COLOR_BLACK);
}

void init_term(void)
{
	initscr();
	cbreak();
	noecho();
	nodelay(stdscr, true);
	keypad(stdscr, true);
	curs_set(0);
	timeout(0);
	start_color();
	init_color_pair();
}
