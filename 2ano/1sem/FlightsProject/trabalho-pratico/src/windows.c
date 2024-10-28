#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <locale.h>

#include "../include/windows.h"

#define MAX_LINES_PER_WINDOW 50
#define MAX_LINE_LENGTH 200

int once = 0;

typedef struct WindowNode {
    WINDOW *win;
    char **content;
    int num_lines;
    struct WindowNode *next;
} WindowNode;

// Cria nova window, quando limite máximo de linhas foi atingido
static WindowNode *createWindow(WindowNode *current) {
    WindowNode *new_win = (WindowNode *)malloc(sizeof(WindowNode));
    new_win->next = NULL;
    new_win->num_lines = 0;
    new_win->win = newwin(MAX_LINES_PER_WINDOW, MAX_LINE_LENGTH, 0, 0);
    new_win->content = (char **)malloc(MAX_LINES_PER_WINDOW * sizeof(char *));
    for (int i = 0; i < MAX_LINES_PER_WINDOW; i++) {
        new_win->content[i] = (char *)malloc(MAX_LINE_LENGTH * sizeof(char));
    }

    if (current != NULL) {
        current->next = new_win;
    }

    return new_win;
}


// Escreve na window correspondente
static void addContent(WindowNode *window, char *line) {
    if (window->num_lines < MAX_LINES_PER_WINDOW) {
        strncpy(window->content[window->num_lines], line, MAX_LINE_LENGTH - 1);
        window->content[window->num_lines][MAX_LINE_LENGTH - 1] = '\0';
        window->num_lines++;
    }
}


static void displayWindow(WindowNode *window) {
    if (window->win != NULL) {
        wclear(window->win);

        int windowHeight, windowWidth;
        getmaxyx(window->win, windowHeight, windowWidth);
        int nada = windowHeight - windowHeight;

        for (int i = 0; i < window->num_lines; i++) {
            int startColumn = (windowWidth - strlen(window->content[i])) / 2;

            mvwprintw(window->win, i + nada, startColumn, "%s", window->content[i]);
        }
        wrefresh(window->win);
    }
}

void Windows() {

    initscr();
    cbreak();
    noecho();
    intrflush(stdscr, false);
    keypad(stdscr, TRUE);

    WindowNode *head = createWindow(NULL);
    WindowNode *current = head;

    char line[100];
    int ch;

    FILE *file = fopen("Resultados/outputINT.txt", "r");
    if (file == NULL) {
        endwin();
        return;
    }

    // Lê o ficheiro linha a linha e mete o conteúdo nas windows
    while (fgets(line, sizeof(line), file)) {
        if (current->num_lines >= MAX_LINES_PER_WINDOW) {
            current = createWindow(current);
        }
        addContent(current, line);
    }
    fclose(file);
    displayWindow(current);

    if(once == 0) ch = wgetch(current->win), once = 1;

    // Navegação entre as windows
    while ((ch = getch()) != 'q') {
        if (ch == KEY_DOWN && current->next != NULL) {
            current = current->next;
            displayWindow(current);
        } else if (ch == KEY_UP && current != head) {
            WindowNode *temp = head;
            while (temp->next != current) {
                temp = temp->next;
            }
            current = temp;
            displayWindow(current);
        }
    }

    endwin();
}