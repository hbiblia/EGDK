#include "canvas.h"

GtkWidget *canvas_init(void)
{
    GtkWidget *area = gtk_drawing_area_new();

    return area;
}