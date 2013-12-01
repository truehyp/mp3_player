#include <gtk/gtk.h>
#include <glib.h>
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
    gtk_box_pack_start (GTK_BOX (vbMain), menubar, FALSE, FALSE, 0);//将菜单条入横向组装盒中

    GtkWidget *miFile;
    miFile = gtk_menu_item_new_with_mnemonic("文件(_F)"); //创建文件菜单项
    gtk_widget_show (miFile);
    gtk_container_add (GTK_CONTAINER(menubar), miFile);//将文件菜单装入菜单条

    GtkWidget *miFile_menu;
    miFile_menu = gtk_menu_new();
    gtk_menu_item_set_submenu (GTK_MENU_ITEM(miFile), miFile_menu); //将菜单构件设为菜单项的子菜单
    GtkWidget *menuOpen;
    menuOpen = gtk_image_menu_item_new_from_stock ("gtk-open", accel_group); //创建打开菜单项
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

    GtkWidget *miPlay;
    miPlay = gtk_menu_item_new_with_mnemonic("播放(_P)");
    gtk_widget_show(miPlay);
    gtk_container_add (GTK_CONTAINER(menubar), miPlay); //将播放菜单项装入菜单条

    GtkWidget *miPlay_menu;
    miPlay_menu = gtk_menu_new();
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(miPlay), miPlay_menu);//创建播放菜单构件
    GtkWidget *menuPre; //创建上一首菜单项
    menuPre = gtk_image_menu_item_new_from_stock("gtk-media-previous", accel_group);
    gtk_widget_show(menuPre);
    gtk_container_add(GTK_CONTAINER(miPlay_menu), menuPre);

    GtkWidget *menuPlay;//创建开始播放菜单项
    menuPlay = gtk_image_menu_item_new_from_stock("gtk-media-play",accel_group);
    gtk_widget_show(menuPlay);
    gtk_container_add(GTK_CONTAINER(miPlay_menu), menuPlay);

    GtkWidget *menuPause; //创建暂停播放菜单项
    menuPause = gtk_image_menu_item_new_from_stock("gtk-media-pause",accel_group);
    gtk_widget_show(menuPause);
    gtk_container_add(GTK_CONTAINER(miPlay_menu), menuPause);

    GtkWidget *menuStop;  //创建停止播放菜单项
    menuStop = gtk_image_menu_item_new_from_stock("gtk-media-stop",accel_group);
    gtk_widget_show(menuStop);
    gtk_container_add(GTK_CONTAINER (miPlay_menu), menuStop);

    GtkWidget *menuNext;  //创建下一首菜单项
    menuNext = gtk_image_menu_item_new_from_stock("gtk-media-next", accel_group);
    gtk_widget_show(menuNext);
    gtk_container_add(GTK_CONTAINER(miPlay_menu), menuNext);
    
    GtkWidget *miHelp; //创建帮助菜单项
    miHelp = gtk_menu_item_new_with_mnemonic("帮助(_H)");
    gtk_widget_show(miHelp);
    gtk_container_add(GTK_CONTAINER(menubar), miHelp);

    GtkWidget *miHelp_menu;  //创建帮助菜单构件
    miHelp_menu = gtk_menu_new();
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(miHelp), miHelp_menu);
    
    GtkWidget *menuHelp;  //创建帮助子菜单项
    menuHelp = gtk_image_menu_item_new_from_stock("gtk-help", accel_group);
    gtk_widget_show(menuHelp);
    gtk_container_add(GTK_CONTAINER(miHelp_menu), menuHelp);

    GtkWidget *menuAbout;  //创建关于菜单项
    menuAbout = gtk_image_menu_item_new_from_stock("gtk-about", accel_group);
    gtk_widget_show(menuAbout);
    gtk_container_add(GTK_CONTAINER(miHelp_menu), menuAbout);
    gtk_window_add_accel_group(GTK_WINDOW(winMain), accel_group);//为主窗体加入快捷方式集合


    GtkWidget *hbState; //创建一个横向组装盒
    hbState = gtk_hbox_new (FALSE, 0);
    gtk_widget_show(hbState);
    gtk_box_pack_start(GTK_BOX(vbMain), hbState, TRUE, TRUE, 0);//将横向组装盒装入上层纵向组装盒

    GtkWidget *hsSche; //创建横向比例构件，并新建调整对象
    hsSche = gtk_hscale_new (GTK_ADJUSTMENT(gtk_adjustment_new(0, 0, 0, 0, 0, 0)));
    gtk_widget_show(hsSche);
    gtk_box_pack_start(GTK_BOX(hbState), hsSche, TRUE, TRUE, 0);//将横躺比例构件装入横向组装盒
    
    gtk_widget_set_size_request(hsSche, 32, 20);//定义横向比例构件最小需求尺寸
    gtk_scale_set_draw_value(GTK_SCALE(hsSche), FALSE);//设置比例构件的数值为不显示
    gtk_scale_set_digits(GTK_SCALE(hsSche), 0);//设置比例构件小数点后长度为0

    GtkWidget *lbTime;//创建文本标签构件
    lbTime = gtk_label_new("00:00:00");
    gtk_widget_show(lbTime);
    gtk_box_pack_start(GTK_BOX(hbState), lbTime, FALSE, FALSE, 0);//将文本标签构件装入横躺组装盒
    gtk_widget_set_size_request(lbTime, 48, 14);//定义文本标签构件最小需求尺寸
    
    GtkWidget *hbCtrl;
    hbCtrl = gtk_hbutton_box_new();//创建横向组装盒构件
    gtk_widget_show(hbCtrl);
    gtk_box_pack_start(GTK_BOX(vbMain), hbCtrl, TRUE, TRUE, 0);//将横向组装盒装入上层容器

    GtkWidget *btPre;
    btPre = gtk_button_new();//创建上一首按钮
    gtk_widget_show(btPre);
    gtk_container_add(GTK_CONTAINER(hbCtrl), btPre);//将上一首按钮装入横向组装盒

    gtk_widget_set_size_request(btPre, 34, 34);//定义上一首按钮最小需求尺寸
    GTK_WIDGET_SET_FLAGS(btPre, GTK_CAN_DEFAULT);//设置按钮可以为默认
    
    GtkWidget *image1;
    image1 = gtk_image_new_from_stock("gtk-media-previous", GTK_ICON_SIZE_BUTTON);
    gtk_widget_show(image1);
    gtk_container_add(GTK_CONTAINER(btPre), image1);//将上一首图标装入到按钮中
    
    GtkWidget *btPlay;
    btPlay = gtk_button_new();//创建播放按钮
    gtk_widget_show(btPlay);
    gtk_container_add(GTK_CONTAINER(hbCtrl),btPlay);
    gtk_widget_set_size_request(btPlay, 34, 34);
    GTK_WIDGET_SET_FLAGS(btPlay, GTK_CAN_DEFAULT);
    GtkWidget *image2;
    image2 = gtk_image_new_from_stock("gtk-media-play", GTK_ICON_SIZE_BUTTON);
    gtk_widget_show(image2);
    gtk_container_add(GTK_CONTAINER(btPlay), image2);
    
    GtkWidget *btPause;
    btPause = gtk_button_new();
    gtk_widget_show(btPause);
    gtk_container_add(GTK_CONTAINER(hbCtrl), btPause);
    gtk_widget_set_size_request(btPause, 34, 34);
    GTK_WIDGET_SET_FLAGS(btPause, GTK_CAN_DEFAULT);
    GtkWidget *image3;
    image3 = gtk_image_new_from_stock("gtk-media-pause", GTK_ICON_SIZE_BUTTON);
    gtk_widget_show(image3);
    gtk_container_add(GTK_CONTAINER(btPause), image3);
    
    GtkWidget *btStop;
    btStop = gtk_button_new();
    gtk_widget_show(btStop);
    gtk_container_add(GTK_CONTAINER(hbCtrl), btStop);
    gtk_widget_set_size_request(btStop, 34, 34);
    GTK_WIDGET_SET_FLAGS(btStop, GTK_CAN_DEFAULT);
    GtkWidget *image4;
    image4 = gtk_image_new_from_stock("gtk-media-stop", GTK_ICON_SIZE_BUTTON);
    gtk_widget_show(image4);
    gtk_container_add(GTK_CONTAINER(btStop), image4);

    GtkWidget *btNext;
    btNext = gtk_button_new();
    gtk_widget_show(btNext);
    gtk_container_add(GTK_CONTAINER(hbCtrl), btNext);
    gtk_widget_set_size_request(btNext, 34, 34);
    GTK_WIDGET_SET_FLAGS(btNext, GTK_CAN_DEFAULT);
    GtkWidget *image5;
    image5 = gtk_image_new_from_stock("gtk-media-next", GTK_ICON_SIZE_BUTTON);
    gtk_widget_show(image5);
    gtk_container_add(GTK_CONTAINER(btNext), image5);


    GtkWidget *hbOther;
    hbOther = gtk_hbox_new(FALSE, 0);
    gtk_widget_show(hbOther);
    gtk_box_pack_start(GTK_BOX(vbMain),hbOther, TRUE, TRUE, 0);

    GtkWidget *cbbMode;
    cbbMode = gtk_combo_box_new_text();
    gtk_widget_show(cbbMode);
    gtk_box_pack_start(GTK_BOX(hbOther), cbbMode, TRUE, TRUE, 0);
    gtk_widget_set_size_request(cbbMode, 46, 31);
    gtk_combo_box_append_text(GTK_COMBO_BOX(cbbMode), "顺序模式");
    gtk_combo_box_append_text(GTK_COMBO_BOX(cbbMode), "循环模式");
    gtk_combo_box_append_text(GTK_COMBO_BOX(cbbMode), "循环模式");
    gtk_combo_box_append_text(GTK_COMBO_BOX(cbbMode), 0);


    GtkWidget *btMedialib;
    btMedialib = gtk_button_new();
    gtk_widget_show(btMedialib);
    gtk_box_pack_start(GTK_BOX(hbOther), btMedialib, FALSE, FALSE, 0);
    gtk_widget_set_size_request(btMedialib, 92, 32);

    GtkWidget *alignment1;
    alignment1 = gtk_alignment_new(0.5, 0.5, 0, 0);
    gtk_widget_show(alignment1);
    gtk_container_add(GTK_CONTAINER(btMedialib), alignment1);

    GtkWidget *hbox2;
    hbox2 = gtk_hbox_new(FALSE, 2);
    gtk_widget_show(hbox2);
    gtk_container_add(GTK_CONTAINER(alignment1), hbox2);
    GtkWidget *image6;
    image6 = gtk_image_new_from_stock("gtk-index", GTK_ICON_SIZE_BUTTON);
    gtk_widget_show(image6);
    gtk_box_pack_start(GTK_BOX(hbox2), image6, FALSE, FALSE, 0);

    GtkWidget *label1;
    label1 = gtk_label_new_with_mnemonic("媒体库");
    gtk_widget_show(label1);
    gtk_box_pack_start(GTK_BOX(hbox2), label1, FALSE, FALSE, 0);

    GtkWidget *btPlaylist;
    btPlaylist = gtk_button_new_with_mnemonic("播放列表");
    gtk_widget_show(btPlaylist);
    gtk_box_pack_start(GTK_BOX(hbOther), btPlaylist, FALSE, FALSE, 0);
    gtk_widget_set_size_request(btPlaylist, 60, 29);

    GtkWidget *btVolume;
    btVolume = gtk_toggle_button_new();
    gtk_widget_show(btVolume);
    gtk_box_pack_start(GTK_BOX(hbOther), btVolume, FALSE, FALSE, 0);
    gtk_widget_set_size_request(btVolume, 85, 34);

    GtkWidget *alignment2;
    alignment2 = gtk_alignment_new(0.5, 0.5, 0, 0);
    gtk_widget_show(alignment2);
    gtk_container_add(GTK_CONTAINER(btVolume), alignment2);

    GtkWidget *hbox3;
    hbox3 = gtk_hbox_new(FALSE, 2);
    gtk_widget_show(hbox3);
    gtk_container_add(GTK_CONTAINER(alignment2), hbox3);
    GtkWidget *image7;
    image7 = gtk_image_new_from_stock("gtk-preferences", GTK_ICON_SIZE_BUTTON);

    gtk_widget_show(image7);
    gtk_box_pack_start(GTK_BOX(hbox3), image7, FALSE, FALSE, 0);

    GtkWidget *label2;
    label2 = gtk_label_new_with_mnemonic("调节音量");
    gtk_widget_show(label2);
    gtk_box_pack_start(GTK_BOX(hbox3), label2, FALSE, FALSE, 0);

    GtkWidget *tbtMute;
    tbtMute = gtk_toggle_button_new_with_mnemonic("静音");
    gtk_widget_show(tbtMute);
    gtk_box_pack_start(GTK_BOX(hbOther), tbtMute, FALSE, FALSE, 0);
    gtk_widget_set_size_request(tbtMute, 48, 29);

    return winMain;
    
}
int main(int argc, char *argv[])
{
    gtk_init(&argc, &argv);
    InterFace ui;
    ui.winMain = create_winMain(&ui);
    gtk_widget_show(ui.winMain);
    g_signal_connect(G_OBJECT(ui.winMain), "delete-event", G_CALLBACK(gtk_main_quit), NULL);
    gtk_main();
    return 0;
}


