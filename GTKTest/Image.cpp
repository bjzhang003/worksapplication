/*************************************************************************
    > File Name: Image.cpp
    > Author: bjzhang03
    > Mail: bjzhang03@outlook.com
    > Created Time: Fri 28 Oct 2016 09:15:38 PM EDT
 ************************************************************************/

#include<iostream>
#include<gtk/gtk.h>
using namespace std;

int main(int argc,char * argv[])
{
	gtk_init(&argc,&argv);

	GtkWidget *label;
	label=gtk_label_new("image");
	

	GtkWidget *window=gtk_window_new(GTK_WINDOW_TOPLEVEL);

	GtkWidget *hbox=gtk_hbox_new(TRUE,10);
	gtk_container_add(GTK_CONTAINER(window),hbox);


	gtk_container_add(GTK_CONTAINER(hbox),label);


	GtkWidget *image_one=gtk_image_new_from_file("./Image.jpg");
	gtk_container_add(GTK_CONTAINER(hbox),image_one);

	GdkPixbuf *src=gdk_pixbuf_new_from_file("./Image.jpg",NULL);
	GdkPixbuf *dst=gdk_pixbuf_scale_simple(src,100,100,GDK_INTERP_BILINEAR);

	GtkWidget *image_two=gtk_image_new_from_pixbuf(dst);
	g_object_unref(src);
	g_object_unref(dst);
	gtk_container_add(GTK_CONTAINER(hbox),image_two);

	GdkPixbuf *tmp=gtk_image_get_pixbuf(GTK_IMAGE(image_two));
	GtkWidget *image_three=gtk_image_new_from_pixbuf(tmp);
	gtk_container_add(GTK_CONTAINER(hbox),image_three);

	GtkWidget *image_four=gtk_image_new_from_file("./Image.jpg");
	src=gdk_pixbuf_new_from_file("./Image.jpg",NULL);
	dst=gdk_pixbuf_scale_simple(src,200,200,GDK_INTERP_BILINEAR);
	gtk_image_set_from_pixbuf(GTK_IMAGE(image_four),dst);
	g_object_unref(src);
	g_object_unref(dst);
	gtk_container_add(GTK_CONTAINER(hbox),image_four);

	gtk_widget_show_all(window);

	gtk_main();

	return 0;
}
