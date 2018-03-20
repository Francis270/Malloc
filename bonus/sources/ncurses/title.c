/*
** EPITECH PROJECT, 2018
** title.c
** File description:
** Created by Thomas BLENEAU
*/

#include <ncurses.h>
#include <curses.h>
#include <unistd.h>
#include <stdlib.h>
#include "visual.h"

void display_memory(window_t *title)
{
	mvwprintw(title, 0, 58, "___  ___   _____       ___  ");
	mvwprintw(title, 0, 86, "___   _____   __");
	mvwprintw(title, 0, 101, "____   __    __");
	mvwprintw(title, 1, 57, "/   |/   | | ____|     /   |/");
	mvwprintw(title, 1, 86, "   | /  _  \\ |");
	mvwprintw(title, 1, 101, " _  \\  \\ \\  / / ");
	mvwprintw(title, 2, 56, "/ /|   /| | | |__      / /|");
	mvwprintw(title, 2, 83, "   /| | | | | | |");
	mvwprintw(title, 2, 100, " |_| |   \\ \\/ /");
	mvwprintw(title, 3, 55, "/ / |__/ | | |  __|    / / |__/ | | | | | |");
	mvwprintw(title, 3, 98, " |  _  /    \\  /");
	mvwprintw(title, 4, 45, "_        / /       | | | |___   / /       |");
	mvwprintw(title, 4, 88, " | | |_| | | | \\ \\    / /");
	mvwprintw(title, 5, 44, "__|      /_/        |_| |_____| /_/        ");
	mvwprintw(title, 5, 87, "|_| \\_____/ |_|  \\_\\  /_/");
}

void display_title(window_t *title)
{
	mvwprintw(title, 0, 0, " _     _   _   _____   _   _       ___   _  ");
	mvwprintw(title, 1, 0, "| |   / / | | /  ___/ | | | |     /   | | | ");
	mvwprintw(title, 2, 0, "| |  / /  | | | |___  | | | |    / /| | | | ");
	mvwprintw(title, 3, 0, "| | / /   | | \\___  \\ | | | |   / / | | |");
	mvwprintw(title, 3, 42, "|");
	mvwprintw(title, 4, 0, "| |/ /    | |  ___| | | |_| |  / /  | | |");
	mvwprintw(title, 4, 41, " |__");
	mvwprintw(title, 5, 0, "|___/     |_| /_____/ \\_____/ /_/   |_| ");
	mvwprintw(title, 5, 40, "|___");
	display_memory(title);
}

window_t *init_title(void)
{
	window_t *_title = create_window(7, COLS, 2, (COLS / 4) - 4);

	display_title(_title);
	refresh();
	wrefresh(_title);
	return (_title);
}

void update_title(window_t *_title)
{
	wbkgd(_title, COLOR_PAIR(rand() % 7));
	wrefresh(_title);
	refresh();
	usleep(450000);
}
