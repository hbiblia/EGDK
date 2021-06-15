#include "notebook.h"

static GtkWidget *notebook[10];

GtkWidget *notebook_init(int id)
{
    notebook[id] = gtk_notebook_new();
    return notebook[id];
}

void notebook_append(int id, GtkWidget *child, const char *label)
{
    gtk_notebook_append_page(GTK_NOTEBOOK(notebook[id]), child, gtk_label_new(label));
}

void notebook_remove(int id, GtkWidget *child)
{
    gtk_notebook_remove_page(GTK_NOTEBOOK(notebook[id]), gtk_notebook_page_num(notebook[id], child));
}