
#include "level_editor.h"
#include "notebook.h"
#include "canvas.h"
#include "ui_browser.h"

GtkWidget *level_editor(void)
{
    // BOX PARENT
    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);

    // Toolbar
    GtkWidget *toolbar = gtk_toolbar_new();
    gtk_box_pack_start(GTK_BOX(box), toolbar, FALSE, TRUE, 0);
    {
        GtkWidget *undo = gtk_tool_button_new_from_stock(GTK_STOCK_UNDO);
        gtk_widget_set_name(GTK_WIDGET(undo), "undo");
        gtk_toolbar_insert(GTK_TOOLBAR(toolbar), undo, -1);
    }

    // Notebook
    GtkWidget *panel_1 = notebook_init(NOTEBOOK_EDITOR_PANEL_A);
    GtkWidget *panel_2 = notebook_init(NOTEBOOK_EDITOR_PANEL_B);
    GtkWidget *panel_3 = notebook_init(NOTEBOOK_EDITOR_PANEL_C);

    GtkWidget *module_browser = module_ui_browser();
    gtk_widget_set_size_request(module_browser, 200, -1);
    notebook_append(NOTEBOOK_EDITOR_PANEL_A, module_browser, "Browser");

    GtkWidget *module_canvas = canvas_init();
    notebook_append(NOTEBOOK_EDITOR_PANEL_B, module_canvas, "Viewport");

    GtkWidget *module_props = gtk_label_new("Property");
    gtk_widget_set_size_request(module_props, 200, -1);
    notebook_append(NOTEBOOK_EDITOR_PANEL_C, module_props, "Property");


    // Paned parent - El principal de los paned
    GtkWidget *paned_parent = gtk_paned_new(GTK_ORIENTATION_HORIZONTAL);
    gtk_paned_pack1(GTK_PANED(paned_parent), panel_1, FALSE, TRUE);
    gtk_box_pack_end(GTK_BOX(box), paned_parent, TRUE, TRUE, 5);
    {
        // Paned second -
        GtkWidget *paned_second = gtk_paned_new(GTK_ORIENTATION_HORIZONTAL);
        gtk_paned_add2(GTK_PANED(paned_parent), paned_second);
        {
            gtk_paned_pack1(GTK_PANED(paned_second), panel_2, TRUE, FALSE);
            gtk_paned_pack2(GTK_PANED(paned_second), panel_3, FALSE, TRUE);
        }
    }

    return box;
}
