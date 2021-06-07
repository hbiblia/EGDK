#include "menubar.h"

GtkWidget *menubar_init(void)
{
    GtkWidget *file_item, *file_quit;
    GtkWidget *help_item;

    GtkWidget *menubar = gtk_menu_bar_new();

    // FILE
    file_item = gtk_menu_item_new_with_label("File");
    gtk_menu_shell_append(GTK_MENU_SHELL(menubar), file_item);
    {
        GtkWidget *file_submenu = gtk_menu_new();
        gtk_menu_item_set_submenu(GTK_MENU_ITEM(file_item), file_submenu);
        {
            file_quit = gtk_menu_item_new_with_label("Quit");
            gtk_menu_shell_append(GTK_MENU_SHELL(file_submenu), file_quit);
        }
    }

    // Edit

    // Windows

    // Tools

    // Build

    // Help
    help_item = gtk_menu_item_new_with_label("Help");
    gtk_menu_shell_append(GTK_MENU_SHELL(menubar), help_item);

    return menubar;
}