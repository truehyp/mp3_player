#include <gtk/gtk.h>
#include <glib.h>
#include "interface.h"

void on_btVolume_clicked(GtkWidget *btVolume, InterFace *ui)
{
    if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(btVolume)))
        gtk_widget_show(ui->diaVolume);
    else
        gtk_widget_hide(ui->diaVolume);
}

void on_btPlaylist_clicked(GtkWidget *btPlaylist, InterFace *ui)
{
    gtk_widget_show(ui->diaPlaylist);
}

void on_btMedialib_clicked(GtkWidget *btMedialib, InterFace *ui)
{
    gtk_widget_show(ui->diaMedialib);
}

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
    
    GtkWidget *btPause;//暂停按钮
    btPause = gtk_button_new();
    gtk_widget_show(btPause);
    gtk_container_add(GTK_CONTAINER(hbCtrl), btPause);
    gtk_widget_set_size_request(btPause, 34, 34);
    GTK_WIDGET_SET_FLAGS(btPause, GTK_CAN_DEFAULT);
    GtkWidget *image3;
    image3 = gtk_image_new_from_stock("gtk-media-pause", GTK_ICON_SIZE_BUTTON);
    gtk_widget_show(image3);
    gtk_container_add(GTK_CONTAINER(btPause), image3);
    
    GtkWidget *btStop;//停止按钮
    btStop = gtk_button_new();
    gtk_widget_show(btStop);
    gtk_container_add(GTK_CONTAINER(hbCtrl), btStop);
    gtk_widget_set_size_request(btStop, 34, 34);
    GTK_WIDGET_SET_FLAGS(btStop, GTK_CAN_DEFAULT);
    GtkWidget *image4;
    image4 = gtk_image_new_from_stock("gtk-media-stop", GTK_ICON_SIZE_BUTTON);
    gtk_widget_show(image4);
    gtk_container_add(GTK_CONTAINER(btStop), image4);

    GtkWidget *btNext;//下一首按钮
    btNext = gtk_button_new();
    gtk_widget_show(btNext);
    gtk_container_add(GTK_CONTAINER(hbCtrl), btNext);
    gtk_widget_set_size_request(btNext, 34, 34);
    GTK_WIDGET_SET_FLAGS(btNext, GTK_CAN_DEFAULT);
    GtkWidget *image5;
    image5 = gtk_image_new_from_stock("gtk-media-next", GTK_ICON_SIZE_BUTTON);
    gtk_widget_show(image5);
    gtk_container_add(GTK_CONTAINER(btNext), image5);


    GtkWidget *hbOther;//创建横向组装盒
    hbOther = gtk_hbox_new(FALSE, 0);
    gtk_widget_show(hbOther);
    gtk_box_pack_start(GTK_BOX(vbMain),hbOther, TRUE, TRUE, 0);

    GtkWidget *cbbMode;//播放模式
    cbbMode = gtk_combo_box_new_text();
    gtk_widget_show(cbbMode);
    gtk_box_pack_start(GTK_BOX(hbOther), cbbMode, TRUE, TRUE, 0);
    gtk_widget_set_size_request(cbbMode, 46, 31);
    gtk_combo_box_append_text(GTK_COMBO_BOX(cbbMode), "顺序模式");
    gtk_combo_box_append_text(GTK_COMBO_BOX(cbbMode), "循环模式");
    gtk_combo_box_append_text(GTK_COMBO_BOX(cbbMode), "随机模式");
    gtk_combo_box_append_text(GTK_COMBO_BOX(cbbMode), 0);


    GtkWidget *btMedialib;//媒体库按钮
    btMedialib = gtk_button_new();
    gtk_widget_show(btMedialib);
    gtk_box_pack_start(GTK_BOX(hbOther), btMedialib, FALSE, FALSE, 0);
    gtk_widget_set_size_request(btMedialib, 92, 32);

    GtkWidget *alignment1;//对齐构件
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

    GtkWidget *btVolume;//创建音量调节按钮
    btVolume = gtk_toggle_button_new();
    gtk_widget_show(btVolume);
    gtk_box_pack_start(GTK_BOX(hbOther), btVolume, FALSE, FALSE, 0);
    gtk_widget_set_size_request(btVolume, 85, 34);

    GtkWidget *alignment2;//对齐构件
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

    GtkWidget *tbtMute;//静音开关
    tbtMute = gtk_toggle_button_new_with_mnemonic("静音");
    gtk_widget_show(tbtMute);
    gtk_box_pack_start(GTK_BOX(hbOther), tbtMute, FALSE, FALSE, 0);
    gtk_widget_set_size_request(tbtMute, 48, 29);


    g_signal_connect((gpointer)btVolume, "clicked",G_CALLBACK(on_btVolume_clicked), ui);
    g_signal_connect((gpointer)btPlaylist, "clicked", G_CALLBACK(on_btPlaylist_clicked), ui);
    g_signal_connect((gpointer)btMedialib, "clicked",G_CALLBACK(on_btMedialib_clicked), ui);
    return winMain;
    
}

GtkWidget *create_diaVolume(InterFace *ui)//音量调节对话框
{
    GtkWidget *diaVolume;
    diaVolume = gtk_dialog_new();
    GTK_WINDOW(diaVolume)->type = GTK_WINDOW_POPUP;//设置为弹出式窗口
    gtk_window_set_position(GTK_WINDOW(diaVolume), GTK_WIN_POS_MOUSE);//窗口显示位置为鼠标位置
    gtk_window_set_type_hint(GTK_WINDOW(diaVolume), GDK_WINDOW_TYPE_HINT_DIALOG);//使对话框获得焦点
    gtk_dialog_set_has_separator(GTK_DIALOG(diaVolume), FALSE);//不显示对话框的分隔符

    GtkWidget *dialog_vbox1;//横向组装盒
    dialog_vbox1 = GTK_DIALOG(diaVolume)->vbox;
    gtk_widget_show(dialog_vbox1);
    
    GtkWidget *vscale1;//创建垂直比例尺和调整对象
    vscale1 = gtk_vscale_new(GTK_ADJUSTMENT(gtk_adjustment_new(100, 0, 100, 0, 0, 0)));
    gtk_widget_show(vscale1);
    gtk_box_pack_start(GTK_BOX(dialog_vbox1), vscale1, TRUE, TRUE, 0);
    gtk_widget_set_size_request(vscale1, 40, 150);
    GTK_WIDGET_SET_FLAGS(vscale1, GTK_CAN_DEFAULT);
    gtk_scale_set_digits(GTK_SCALE(vscale1), 0);//设置垂直比例尺数值的小数位为0
    
    GtkWidget *dialog_action_area1;//用于保存活动区域容器
    dialog_action_area1 = GTK_DIALOG(diaVolume)->action_area;
    gtk_widget_set_sensitive(dialog_action_area1, FALSE);//设置活动区域为不显示
    gtk_button_box_set_layout(GTK_BUTTON_BOX(dialog_action_area1), GTK_BUTTONBOX_END);//结束活动区域设置
    gtk_widget_grab_default (vscale1);//使垂直比例尺获得焦点
    
    return diaVolume;
}

GtkWidget *create_diaPlaylist (InterFace *ui)
{
    GtkWidget *diaPlaylist;//对话框
    diaPlaylist = gtk_dialog_new();
    gtk_window_set_title(GTK_WINDOW(diaPlaylist), "播放列表");
    gtk_window_set_type_hint(GTK_WINDOW(diaPlaylist), GDK_WINDOW_TYPE_HINT_DIALOG);
    gtk_widget_set_size_request(diaPlaylist, 550, 200);
    GtkWidget *dialog_vbox2;//用于保存纵向组装盒
    dialog_vbox2 = GTK_DIALOG(diaPlaylist)->vbox;
    gtk_widget_show(dialog_vbox2);
    GtkWidget *vbPlaylist;//用于保存新建纵向组装盒地址
    vbPlaylist = gtk_vbox_new(FALSE, 0);
    gtk_widget_show(vbPlaylist);
    gtk_box_pack_start(GTK_BOX(dialog_vbox2), vbPlaylist, TRUE, TRUE, 0);

    GtkWidget *toolbar;//工具条构件
    toolbar = gtk_toolbar_new();
    gtk_widget_show(toolbar);
    gtk_box_pack_start(GTK_BOX(vbPlaylist), toolbar, FALSE, FALSE, 0);
    gtk_toolbar_set_style(GTK_TOOLBAR(toolbar), GTK_TOOLBAR_BOTH);
    
    GtkIconSize tmp_toolbar_icon_size;//工具条图标当前默认尺寸
    tmp_toolbar_icon_size = gtk_toolbar_get_icon_size(GTK_TOOLBAR(toolbar));
    
    GtkWidget *tbtAdd;//添加按钮
    tbtAdd = (GtkWidget*)gtk_tool_button_new_from_stock("gtk-add");
    gtk_widget_show(tbtAdd);
    gtk_container_add(GTK_CONTAINER(toolbar), tbtAdd);

    GtkWidget *tmp_image;//图像构件
    tmp_image = gtk_image_new_from_stock("gtk-directory", tmp_toolbar_icon_size);
    gtk_widget_show(tmp_image);
    
    GtkWidget *tbtAddir;//保存添加目录按钮
    tbtAddir = (GtkWidget*)gtk_tool_button_new(tmp_image, "添加目录");
    gtk_widget_show(tbtAddir);
    gtk_container_add(GTK_CONTAINER(toolbar), tbtAddir);

    GtkWidget *tbtOpen;//打开按钮
    tbtOpen = (GtkWidget *)gtk_tool_button_new_from_stock("gtk-open");
    gtk_widget_show(tbtOpen);
    gtk_container_add(GTK_CONTAINER(toolbar), tbtOpen);

    GtkWidget *tbtSave;//保存按钮
    tbtSave = (GtkWidget *)gtk_tool_button_new_from_stock("gtk-save");
    gtk_widget_show(tbtSave);
    gtk_container_add(GTK_CONTAINER(toolbar), tbtSave);
    
    GtkWidget *tbtDel;//删除按钮
    tbtDel = (GtkWidget *)gtk_tool_button_new_from_stock("gtk-remove");
    gtk_widget_show(tbtDel);
    gtk_container_add(GTK_CONTAINER(toolbar), tbtDel);

    GtkWidget *tbtDelall;//删除全部按钮
    tmp_image = gtk_image_new_from_stock("gtk-clear", tmp_toolbar_icon_size);
    gtk_widget_show(tmp_image);
    tbtDelall = (GtkWidget *)gtk_tool_button_new(tmp_image, "删除全部");
    gtk_widget_show(tbtDelall);
    gtk_container_add(GTK_CONTAINER(toolbar), tbtDelall);

    GtkWidget *separatormenuitem3;//工具条分隔符
    separatormenuitem3 = (GtkWidget *)gtk_separator_tool_item_new();
    gtk_widget_show(separatormenuitem3);
    gtk_container_add(GTK_CONTAINER(toolbar), separatormenuitem3);

    GtkWidget *tbtComp;//排序按钮
    tmp_image = gtk_image_new_from_stock("gtk-sort-ascending", tmp_toolbar_icon_size);
    gtk_widget_show(tmp_image);
    tbtComp = (GtkWidget *)gtk_tool_button_new(tmp_image, "排序");
    gtk_widget_show(tbtComp);
    gtk_container_add(GTK_CONTAINER(toolbar), tbtComp);


    GtkWidget *scrolledwindow1;//滚动条窗体容器
    scrolledwindow1 = gtk_scrolled_window_new(NULL, NULL);
    gtk_widget_show(scrolledwindow1);
    gtk_box_pack_start(GTK_BOX(vbPlaylist), scrolledwindow1, TRUE, TRUE, 0);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrolledwindow1), GTK_POLICY_NEVER, GTK_POLICY_AUTOMATIC);
    gtk_scrolled_window_set_shadow_type(GTK_SCROLLED_WINDOW(scrolledwindow1), GTK_SHADOW_IN);

    GtkWidget *treePlaylist;//树视图
    treePlaylist = gtk_tree_view_new();
    gtk_widget_show(treePlaylist);
    gtk_container_add (GTK_CONTAINER(scrolledwindow1), treePlaylist);

    GtkWidget *dialog_action_area2;//活动区域
    dialog_action_area2 = GTK_DIALOG(diaPlaylist)->action_area;
    gtk_widget_show(dialog_action_area2);
    gtk_button_box_set_layout(GTK_BUTTON_BOX(dialog_action_area2), GTK_BUTTONBOX_END);//结束活动区域

    GtkWidget *closebutton1;//显示关闭按钮
    closebutton1 = gtk_button_new_from_stock("gtk-close");
    gtk_widget_show(closebutton1);
    gtk_dialog_add_action_widget(GTK_DIALOG(diaPlaylist), closebutton1, GTK_RESPONSE_CLOSE);
    GTK_WIDGET_SET_FLAGS(closebutton1, GTK_CAN_DEFAULT);
    
    return diaPlaylist;
    
}

GtkWidget *create_diaMedialib (InterFace *ui)
{
    GtkWidget *diaMedialib;//媒体库对话框
   diaMedialib = gtk_dialog_new ();
   gtk_widget_set_size_request (diaMedialib, 740, 400);
   gtk_window_set_title (GTK_WINDOW (diaMedialib), "媒体库");
   gtk_window_set_type_hint (GTK_WINDOW (diaMedialib), GDK_WINDOW_TYPE_HINT_DIALOG);
   GtkWidget *dialog_vbox4;
   dialog_vbox4 = GTK_DIALOG (diaMedialib)->vbox;
   gtk_widget_show (dialog_vbox4);
   GtkWidget *vbMedialib;
   vbMedialib = gtk_vbox_new (FALSE, 0);
   gtk_widget_show (vbMedialib);
   gtk_box_pack_start (GTK_BOX (dialog_vbox4), vbMedialib, TRUE, TRUE, 0);

   GtkWidget *toolbar;//工具条容器
   toolbar = gtk_toolbar_new ();
   gtk_widget_show (toolbar);
   gtk_box_pack_start (GTK_BOX (vbMedialib), toolbar, FALSE, FALSE, 0);
   gtk_toolbar_set_style (GTK_TOOLBAR (toolbar), GTK_TOOLBAR_BOTH);
   GtkIconSize tmp_toolbar_icon_size;
   tmp_toolbar_icon_size = gtk_toolbar_get_icon_size (GTK_TOOLBAR (toolbar));
   GtkWidget *tlbAdd;
   tlbAdd = (GtkWidget*) gtk_tool_button_new_from_stock ("gtk-add");
   gtk_widget_show (tlbAdd);
   gtk_container_add (GTK_CONTAINER (toolbar), tlbAdd);
   GtkWidget *tmp_image;
   tmp_image = gtk_image_new_from_stock ("gtk-directory", tmp_toolbar_icon_size);
   gtk_widget_show (tmp_image);
   GtkWidget *tlbAdddir;
   tlbAdddir = (GtkWidget*) gtk_tool_button_new (tmp_image, "添加目录");
   gtk_widget_show (tlbAdddir);
   gtk_container_add (GTK_CONTAINER (toolbar), tlbAdddir);
   GtkWidget *tlbDel;
   tlbDel = (GtkWidget*) gtk_tool_button_new_from_stock ("gtk-remove");
   gtk_widget_show (tlbDel);
   gtk_container_add (GTK_CONTAINER (toolbar), tlbDel);
   tmp_image = gtk_image_new_from_stock ("gtk-clear", tmp_toolbar_icon_size);
   gtk_widget_show (tmp_image);
   GtkWidget *tlbDelall;
   tlbDelall = (GtkWidget*) gtk_tool_button_new (tmp_image, "删除全部");
   gtk_widget_show (tlbDelall);
   gtk_container_add (GTK_CONTAINER (toolbar), tlbDelall);
   GtkWidget *separatortoolitem1;
   separatortoolitem1 = (GtkWidget*) gtk_separator_tool_item_new ();
   gtk_widget_show (separatortoolitem1);
   gtk_container_add (GTK_CONTAINER (toolbar), separatortoolitem1);
   tmp_image = gtk_image_new_from_stock ("gtk-refresh", tmp_toolbar_icon_size);
   gtk_widget_show (tmp_image);
   GtkWidget *tlbSearch;
   tlbSearch = (GtkWidget*) gtk_tool_button_new (tmp_image, "搜索本地媒体文件");
   gtk_widget_show (tlbSearch);
   gtk_container_add (GTK_CONTAINER (toolbar), tlbSearch);
   GtkWidget *separatortoolitem2;
   separatortoolitem2 = (GtkWidget*) gtk_separator_tool_item_new ();
   gtk_widget_show (separatortoolitem2);
   gtk_container_add (GTK_CONTAINER (toolbar), separatortoolitem2);
   tmp_image = gtk_image_new_from_stock ("gtk-media-play", tmp_toolbar_icon_size);
   gtk_widget_show (tmp_image);
   GtkWidget *tlbSendto;//传递按钮
   tlbSendto = (GtkWidget*) gtk_tool_button_new (tmp_image, "传递到播放列表");
   gtk_widget_show (tlbSendto);
   gtk_container_add (GTK_CONTAINER (toolbar), tlbSendto);

   GtkWidget *hpaned;//水平窗格
   hpaned = gtk_hpaned_new ();
   gtk_widget_show (hpaned);
   gtk_box_pack_start (GTK_BOX (vbMedialib), hpaned, TRUE, TRUE, 0);

   GtkWidget *scrolledwindow2;//
   scrolledwindow2 = gtk_scrolled_window_new (NULL, NULL);
   gtk_widget_show (scrolledwindow2);
   gtk_paned_pack1 (GTK_PANED (hpaned), scrolledwindow2, FALSE, TRUE);
   gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (scrolledwindow2), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
   gtk_scrolled_window_set_shadow_type (GTK_SCROLLED_WINDOW (scrolledwindow2), GTK_SHADOW_IN);
   GtkWidget *treeClass;//分类树视图
   treeClass = gtk_tree_view_new ();
   gtk_widget_set_size_request (treeClass, 300, 227);
   gtk_widget_show (treeClass);
   gtk_container_add (GTK_CONTAINER (scrolledwindow2), treeClass);
   ui->treeClass = treeClass;
   GtkWidget *scrolledwindow3;
   scrolledwindow3 = gtk_scrolled_window_new (NULL, NULL);
   gtk_widget_show (scrolledwindow3);
   gtk_paned_pack2 (GTK_PANED (hpaned), scrolledwindow3, TRUE, TRUE);
   gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (scrolledwindow3), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
   gtk_scrolled_window_set_shadow_type (GTK_SCROLLED_WINDOW (scrolledwindow3), GTK_SHADOW_IN);
   GtkWidget *treeMedialib;//媒体库树视图
   treeMedialib = gtk_tree_view_new ();
   gtk_widget_show (treeMedialib);
   gtk_container_add (GTK_CONTAINER (scrolledwindow3), treeMedialib);
   //ui->treeMedialib = treeMedialib;

   GtkWidget *hbFind;//横向组装盒
   hbFind = gtk_hbox_new (FALSE, 0);
   gtk_widget_show (hbFind);
   gtk_box_pack_start (GTK_BOX (vbMedialib), hbFind, TRUE, TRUE, 0);
   GtkWidget *etFind;//文本输入框地址
   etFind = gtk_entry_new ();
   gtk_widget_show (etFind);
   gtk_box_pack_start (GTK_BOX (hbFind), etFind, TRUE, TRUE, 0);
   gtk_widget_set_size_request (etFind, 160, 24);
   gtk_entry_set_invisible_char (GTK_ENTRY (etFind), 8226);
   //ui->etFind = etFind;
   GtkWidget *cbbFind;//组合框
   cbbFind = gtk_combo_box_new_text ();
   gtk_combo_box_append_text (GTK_COMBO_BOX (cbbFind), "标题");
   gtk_combo_box_append_text (GTK_COMBO_BOX (cbbFind), "艺术家");
   gtk_combo_box_append_text (GTK_COMBO_BOX (cbbFind), "专辑");
   gtk_combo_box_append_text (GTK_COMBO_BOX (cbbFind), "流派");
   gtk_combo_box_append_text (GTK_COMBO_BOX (cbbFind), "文件名");
   gtk_combo_box_set_active (GTK_COMBO_BOX (cbbFind), 0);
   gtk_widget_show (cbbFind);
   gtk_box_pack_start (GTK_BOX (hbFind), cbbFind, TRUE, TRUE, 0);
   gtk_widget_set_size_request (cbbFind, 30, 28);
   //ui->cbbFind = cbbFind;
   GtkWidget *btFind;//查找按钮
   btFind = gtk_button_new_from_stock ("gtk-find");
   gtk_widget_show (btFind);
   gtk_box_pack_start (GTK_BOX (hbFind), btFind, FALSE, FALSE, 0);
   gtk_widget_set_size_request (btFind, 82, 34);
   
   GtkWidget *dialog_action_area4;
   dialog_action_area4 = GTK_DIALOG (diaMedialib)->action_area;
   gtk_widget_show (dialog_action_area4);
   gtk_button_box_set_layout (GTK_BUTTON_BOX (dialog_action_area4), GTK_BUTTONBOX_END);
   GtkWidget *closebutton2;
   closebutton2 = gtk_button_new_from_stock ("gtk-close");
   gtk_widget_show (closebutton2);
   gtk_dialog_add_action_widget (GTK_DIALOG (diaMedialib), closebutton2, GTK_RESPONSE_CLOSE);
   GTK_WIDGET_SET_FLAGS (closebutton2, GTK_CAN_DEFAULT);

   
   return diaMedialib;
    
}

int set_treeClass(InterFace *ui)
{
	GtkTreeStore *treestore;
	treestore = gtk_tree_store_new(1, G_TYPE_STRING);
	GtkTreeIter iter;
	GtkTreeIter child;
	gtk_tree_store_append(treestore, &iter, NULL);
	gtk_tree_store_set(treestore, &iter, 0, "全部", -1);
	gtk_tree_store_append(treestore, &child, &iter);
	gtk_tree_store_set(treestore, &child, 0, "艺术家", -1);
	gtk_tree_store_append(treestore, &child, &iter);
	gtk_tree_store_set(treestore, &child, 0, "专辑", -1);
	gtk_tree_store_append(treestore, &child, &iter);
	gtk_tree_store_set(treestore, &child, 0, "流派", -1);

	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	gtk_tree_view_set_model(GTK_TREE_VIEW(ui->treeClass), GTK_TREE_MODEL(treestore));
	g_object_unref(G_OBJECT(treestore));
	renderer = gtk_cell_renderer_text_new();
	g_object_set(G_OBJECT(renderer), "foreground", "red", NULL);
	column = gtk_tree_view_column_new_with_attributes("分类", renderer, "text", 0, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(ui->treeClass), column);
	return 1;
}

int main(int argc, char *argv[])
{
    gtk_init(&argc, &argv);
    InterFace ui;
    ui.winMain = create_winMain(&ui);
    ui.diaVolume = create_diaVolume(&ui);
    ui.diaPlaylist = create_diaPlaylist(&ui);
    ui.diaMedialib = create_diaMedialib(&ui);
    set_treeClass(&ui);
    gtk_widget_show(ui.winMain);
    g_signal_connect(G_OBJECT(ui.winMain), "delete-event", G_CALLBACK(gtk_main_quit), NULL);
    gtk_main();
    return 0;
}


