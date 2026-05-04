#include <gtk/gtk.h>
#include <stdio.h>
#include "analyzer.h"

GtkTextBuffer *buffer;

void on_button_clicked(GtkWidget *widget, gpointer data) {
    FILE *fp = fopen("data/sample.log", "r");
    if (!fp) return;

    analyze_logs(fp); // currently prints to stdout

    gtk_text_buffer_set_text(buffer, "Analysis Complete\n(Check terminal for now)", -1);

    fclose(fp);
}

void start_gui(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Log Analyzer");

    GtkWidget *button = gtk_button_new_with_label("Analyze Logs");
    GtkWidget *text = gtk_text_view_new();

    buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text));

    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_box_pack_start(GTK_BOX(box), button, FALSE, FALSE, 5);
    gtk_box_pack_start(GTK_BOX(box), text, TRUE, TRUE, 5);

    g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), NULL);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_container_add(GTK_CONTAINER(window), box);
    gtk_widget_show_all(window);

    gtk_main();
}