/*************************************************************************
    > File Name: Test.cpp
    > Author: bjzhang03
    > Mail: bjzhang03@outlook.com
    > Created Time: Fri 28 Oct 2016 01:00:12 AM EDT
 ************************************************************************/

#include<iostream>
#include<gtk/gtk.h>
using namespace std;

int main(int argc,char *argv[])
{
	GtkWidget *window;
	GtkWidget *label;

	gtk_init(&argc,&argv);

	/*create the main,top level,window*/
	window=gtk_window_new(GTK_WINDOW_TOPLEVEL);

	/*give it the title*/
	gtk_window_set_title(GTK_WINDOW(window),"Test Window!");
	gtk_widget_set_size_request(window,500,400);

	/*
	 * connect the destroy signal of the window to gtk_main_quit
	 * when the window is about to be destroyed we get a notification and
	 * stop the main GTK+ loop
	 * */
	g_signal_connect(window,"destroy",G_CALLBACK(gtk_main_quit),NULL);

	/*create the "Test" label*/
	label=gtk_label_new("Test GTK Window");

	/*insert it into the main window*/
	gtk_container_add(GTK_CONTAINER(window),label);

	/*make sure that everything,window and label ,are visible*/
	gtk_widget_show_all(window);

	/*start the main loop,and let it rest until the application is closed*/
	gtk_main();

	return 0;
}

