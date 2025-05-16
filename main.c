#include <gtk/gtk.h>
#include "to_do.h"

static void activate(GtkApplication *app, gpointer user_data)
{
    (void)user_data;

    ToDoApp *todo_app = g_new0(ToDoApp, 1);

    todo_app->window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(todo_app->window), "Liste de Tâches");
    gtk_window_set_default_size(GTK_WINDOW(todo_app->window), 400, 300);

    // Chargement du CSS
    GtkCssProvider *provider = gtk_css_provider_new();
    gtk_css_provider_load_from_path(provider, "style.css");
    gtk_style_context_add_provider_for_display(
        gdk_display_get_default(),
        GTK_STYLE_PROVIDER(provider),
        GTK_STYLE_PROVIDER_PRIORITY_USER
    );

    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_window_set_child(GTK_WINDOW(todo_app->window), vbox);

    todo_app->entry = gtk_entry_new();
    gtk_box_append(GTK_BOX(vbox), todo_app->entry);

    todo_app->add_button = gtk_button_new_with_label("Ajouter");
    gtk_box_append(GTK_BOX(vbox), todo_app->add_button);

    todo_app->list_box = gtk_list_box_new();
    gtk_box_append(GTK_BOX(vbox), todo_app->list_box);

    g_signal_connect(todo_app->add_button, "clicked", G_CALLBACK(add_task), todo_app);

    gtk_window_present(GTK_WINDOW(todo_app->window));
}

int main(int argc, char **argv) {
    GtkApplication *app = gtk_application_new("com.example.ToDoList", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    int status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);
    return status;
}
