#ifndef TO_DO_H
#define TO_DO_H

#include <gtk/gtk.h>

typedef struct {
    GtkWidget *window;
    GtkWidget *entry;
    GtkWidget *add_button;
    GtkWidget *list_box;
} ToDoApp;

void add_task(GtkButton *button, gpointer user_data);
void remove_task(GtkButton *button, gpointer user_data);

#endif
