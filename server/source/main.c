#include <gtk/gtk.h>
#include "server.h"

static void print_listen(GtkWidget* widget, gpointer data);
static void activate(GtkApplication* app, gpointer user_data);

int main(int argc, char** argv)
{
    GtkApplication* app;
    int status;

    app = gtk_application_new("org.gtk.example", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app); // cleanup
    return status;
}

static void print_listen(GtkWidget* widget, gpointer data) // data is NULL
{
    run_server();
}

static void activate(GtkApplication* app, gpointer user_data)
{
    GtkWidget* window;
    GtkWidget* button;

    window = gtk_application_window_new(app); // assigning are window to the GtkApplication struct in main.
    gtk_window_set_title(GTK_WINDOW(window), "Botnet"); // window title;
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 800); // dimensions of window

    button = gtk_button_new_with_label("Start Listener"); // button label
    g_signal_connect(button, "clicked", G_CALLBACK(print_listen), NULL); // what happens when button is clicked

    gtk_window_set_child(GTK_WINDOW(window), button); // set box to the child window, of our main applicationy
    gtk_window_present(GTK_WINDOW(window)); // display GtkApplication, with our child window(button)
}
