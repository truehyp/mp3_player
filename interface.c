#include <gtk-2.0/gtk/gtk.h>
#include <glib-2.0/glib.h>
#include "interface.h"

GtkWidget *create_winMain (InterFace *ui)
{
    GtkWidget *winMain;                           //用于保存主窗体构件指针
    winMain = gtk_window_new(GTK_WINDOW_TOPLEVEL);    //创建主窗体
    gtk_window_set_title (GTK_WINDOW (winMain),"媒体播放器");  //设置主窗体标题
    GtkWidget *vbMain;                                      //用于保存横向组装构件指针
    vbMain = gtk_vbox_new (FALSE, 0);      //创建横向组装盒
    gtk_widget_show (vbMain);//显示横向组装盒
    gtk_container_add (GTK_CONTAINER (winMain), vbMain); //将横向组装盒装入窗体

    GtkAccelGroup *accel_group;//用于保存快捷方式集合指针
    accel_group = gtk_accel_group_new();
    GtkWidget *menubar; //用于保存菜单条构件指针
    menubar = gtk_menu_bar_new();
    gtk_widget_show (menubar);
    gtk_box_pack_start (GTK_BOX (vbmain), menubar, FALSE, FALSE, 0);//将菜单条入横向组装盒中

    GtkWidget *miFile;
    miFile = gtk_menu_item_new_with_mnemonic("文件(_F)"); //创建文件菜单项
    gtk_widget_show (miFile);
    gtk_container_add (GTK_CONTAINER(menubar), miFile);//将文件菜单装入菜单条

    GtkWidget *miFile_menu;
    miFile_menu = gtk_menu_new();
    gtk_menu_item_set_submenu (GTK_MENU_ITEM(miFile), miFile_menu); //将菜单构件设为菜单项的子菜单
    GtkWidget *menuOpen;
    menuOpen = gtk_image_menu_item_new_from_stock ("gtk_open", accel_group); //创建打开菜单项
    gtk_widget_show(menuOpen);
    gtk_container_add(GTK_CONTAINER (miFile_menu), menuOpen); //将打开菜单装入文件菜单

    GtkWidget *menuM3u;
    menuM3u = gtk_menu_item_new_with_mnemonic ("打开播放列表");//创建打开播放列表菜单项
    gtk_widget_show (menuM3u);
    gtk_container_add(GTK_CONTAINER(miFile_menu), menuM3u);//将打开播放列表菜单项装入文件菜单

    GtkWidget *menuSave;
    menuSave = gtk_image_menu_item_new_from_stock ("gtk-save", accel_group);
    gtk_container_add (GTK_CONTAINER (miFile_menu), menuSave); //将保存菜单装入文件菜单
    GtkWidget *separatormenuitem1;
    separatormenuitem1 = gtk_separator_menu_item_new(); //创建一个分隔条
    gtk_widget_show(separatormenuitem1);
    gtk_container_add(GTK_CONTAINER(miFile_menu), separatormenuitem1);//将分隔条装入文件菜单
    gtk_widget_set_sensitive(separatormenuitem1, FALSE); //设置分隔条为不活动状态

    GtkWidget *menuQuit;
    menuQuit = gtk_image_menu_item_new_from_stock("gtk-quit",accel_group);
    gtk_widget_show(menuQuit);
    gtk_container_add (GTK_CONTAINER(miFile_menu), menuQuit);//将显示菜单项装入文件菜单
    
}

