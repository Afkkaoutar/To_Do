// #include <gtk/gtk.h>
#include "to_do.h"

void remove_task(GtkButton *button, gpointer user_data)
{
    (void)button;
    GtkWidget *row = GTK_WIDGET(user_data);
    gtk_widget_unparent(row);
}

void add_task(GtkButton *button, gpointer user_data) {
    (void)button;
    ToDoApp *app = (ToDoApp *)user_data;

    const char *text = gtk_editable_get_text(GTK_EDITABLE(app->entry));
    if (g_strcmp0(text, "") == 0) return;

    GtkWidget *row = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
    GtkWidget *label = gtk_label_new(text);
    GtkWidget *remove_button = gtk_button_new_with_label("Supprimer");

    gtk_box_append(GTK_BOX(row), label);
    gtk_box_append(GTK_BOX(row), remove_button);

    g_signal_connect(remove_button, "clicked", G_CALLBACK(remove_task), row);

    gtk_list_box_append(GTK_LIST_BOX(app->list_box), row);

    gtk_editable_set_text(GTK_EDITABLE(app->entry), "");
}
