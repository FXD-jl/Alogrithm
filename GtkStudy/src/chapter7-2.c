#include <gtk/gtk.h>

/* 整个流程：创建一个与open信号对应的 app_open响应函数
   * 创建win -> notebook
 * notebook -> append notebookpage(一定程度上认为nbp是src共用结构体),只是多了label
 * src -> textview -> textbuffer
 * */

static void app_activate() { g_printerr("you need a filename argument.\n"); }

static void app_open(GApplication *app, GFile **files, int n_files,
                     char *hint) {
  GtkWidget *win;
  // GtkNotebookPage,它可以容纳scrolled同时带有标签,此时它的
  GtkWidget *nb;
  // 单独单元称为GtkNotebookPage
  GtkNotebookPage *nbp;
  GtkWidget *lab;

  GtkWidget *scr;
  GtkWidget *tv;
  GtkTextBuffer *tb;

  GError *err = NULL;
  char *contents;
  gsize length;
  char *filename;
  // 最基本的窗体，只能有一个子类
  win = gtk_application_window_new(GTK_APPLICATION(app));
  gtk_window_set_default_size(GTK_WINDOW(win), 800, 600);
  gtk_window_set_title(GTK_WINDOW(win), "file viewer");
  nb = gtk_notebook_new();
  // nb作为子体，它的page包含scr，scr->text->buffer
  gtk_window_set_child(GTK_WINDOW(win), nb);

  for (int i = 0; i < n_files; i++) {
    if (g_file_load_contents(files[i], NULL, &contents, &length, NULL, &err)) {
      scr = gtk_scrolled_window_new();
      tv = gtk_text_view_new();
      tb = gtk_text_view_get_buffer(GTK_TEXT_VIEW(tv));
      gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(tv), GTK_WRAP_WORD_CHAR);
      gtk_text_view_set_editable(GTK_TEXT_VIEW(tv), false);
      gtk_scrolled_window_set_child(GTK_SCROLLED_WINDOW(scr), tv);

      gtk_text_buffer_set_text(tb, contents, length);
      g_free(contents);
      if ((filename = g_file_get_basename(files[i])) != NULL) {
        lab = gtk_label_new(filename);
        g_free(filename);
      } else {
        lab = gtk_label_new("");
      }
      //nbp是nb的单独单元,一定程度上可以认为nbp与scr共用了一个结构体？
      gtk_notebook_append_page(GTK_NOTEBOOK(nb), scr, lab);
      //获取单独单元
      nbp = gtk_notebook_get_page(GTK_NOTEBOOK(nb), scr);
      //设置属性，通过g_object_set设置
      g_object_set(nbp, "tab-expand", TRUE, NULL);
    } else {
      g_printerr("%s.\n", err->message);
      g_clear_error(&err);
    }
  }
  if (gtk_notebook_get_n_pages(GTK_NOTEBOOK(nb)) > 0)
    gtk_window_present(GTK_WINDOW(win));
  else
    gtk_window_destroy(GTK_WINDOW(win));
}

void chapter7_2(int argc, char **agv) {
  GtkApplication *app;
  int stat;
  // step1:先设置app,这个是一个在在g_application_run中被管理的对象
  app = gtk_application_new("com.FXD-JYB.chapter7", G_APPLICATION_HANDLES_OPEN);
  // step2:事件信号
  g_signal_connect(app, "activate", G_CALLBACK(app_activate), NULL);
  g_signal_connect(app, "open", G_CALLBACK(app_open), NULL);
  // 通过g_application_run中的环境进行管理
  stat = g_application_run(G_APPLICATION(app), argc, agv);
  g_object_unref(app);
}
