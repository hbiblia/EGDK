
#include <stdio.h>
#include <stdbool.h>
#include <gtk/gtk.h>

#include "menubar.h"
#include "notebook.h"
#include "canvas.h"


int main(int argc, char *argv[])
{
    gtk_init(&argc, &argv);

    GtkWidget *win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(win), 1280, 768);
    gtk_window_set_title(GTK_WINDOW(win),"Example - window");
    g_signal_connect(win, "destroy", gtk_main_quit, NULL);

    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_container_add(win, box);

    GtkWidget *menubar = menubar_init();
    gtk_box_pack_start(GTK_BOX(box), menubar, false, false, 0);

    GtkWidget *notebook = notebook_init();
    gtk_box_pack_end(GTK_BOX(box), notebook, true, true, 0);

    // Default UI
    notebook_append(canvas_init(), "Viewport");

    gtk_widget_show_all(win);
    gtk_main();

    return 0;
}