#ifndef NOTEBOOK_H
#define NOTEBOOK_H
#include <stdio.h>
#include <stdbool.h>
#include <gtk/gtk.h>


typedef enum NOTEBOOKS{
    PARENT_NOTEBOOK,
    NOTEBOOK_EDITOR_PANEL_A,
    NOTEBOOK_EDITOR_PANEL_B,
    NOTEBOOK_EDITOR_PANEL_C,
};

GtkWidget *notebook_init(int id);
void notebook_append(int id, GtkWidget *child, const char *label);
void notebook_remove(int id, GtkWidget *child);

#endif