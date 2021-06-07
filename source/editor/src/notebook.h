#ifndef NOTEBOOK_H
#define NOTEBOOK_H
#include <stdio.h>
#include <stdbool.h>
#include <gtk/gtk.h>


GtkWidget *notebook_init(void);

void notebook_append(GtkWidget *child, const char *label);
void notebook_remove(GtkWidget *child);

#endif