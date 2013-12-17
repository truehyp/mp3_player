#include <stdlib.h>
#ifndef INTERFACE_H_
#define INTERFACE_H_
typedef struct _interface InterFace;       //定义一个新的类型

struct _interface{
    GtkWidget *winMain;     //主窗体
    GtkWidget *diaPlaylist;    //播放列表对话框
    GtkWidget *diaMedialib;    //媒体库对话框
    GtkWidget *diaVolume;     //音量调节对话框
    GtkWidget *diaFile;       //文件选择对话框
    GtkWidget *diaDir;        //目录选择对话框
    GtkWidget *treeClass;    //分类树视图的指针
};

GtkWidget *create_winMain (InterFace *ui);  //创建主窗体函数原型
GtkWidget *create_diaPlaylist (InterFace *ui);  //创建播放列表对话框函数原型
GtkWidget *create_diaMedialib (InterFace *ui);   //创建媒体库对话框函数原型
GtkWidget *create_diaVolume (InterFace *ui);     //创建音量调节对话框函数原型
#endif
