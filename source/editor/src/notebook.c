#include "notebook.h"

static GtkWidget *notebook;

GtkWidget *notebook_init(void)
{
    notebook = gtk_notebook_new();
    return notebook;
}

void notebook_append(GtkWidget *child, const char *label)
{
    gtk_notebook_append_page(GTK_NOTEBOOK(notebook), child, gtk_label_new(label));
}

void notebook_remove(GtkWidget *child)
{
    gtk_notebook_remove_page(GTK_NOTEBOOK(notebook), gtk_notebook_page_num(notebook, child));
}