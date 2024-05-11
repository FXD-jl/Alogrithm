#include <gtk/gtk.h>

static void app_activate() { g_printerr("you need a filename argument.\n"); }

static void app_open(GApplication *app, GFile **files, int n_files,
                     char *hint) {
  GtkWidget *win;
  GtkWidget *scr;
  GtkWidget *tv;
  GtkTextBuffer *tb;
  // 最基本的窗体，只能有一个子类
  win = gtk_application_window_new(GTK_APPLICATION(app));
  gtk_window_set_default_size(GTK_WINDOW(win), 800, 600);

  // text的父窗体，它可以拓展
  scr = gtk_scrolled_window_new();
  tv = gtk_text_view_new();
  // buffer是在tv中获取
  tb = gtk_text_view_get_buffer(GTK_TEXT_VIEW(tv));
  gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(tv), GTK_WRAP_WORD_CHAR);
  gtk_text_view_set_editable(GTK_TEXT_VIEW(tv), false);

  gtk_window_set_child(GTK_WINDOW(win), scr);
  gtk_scrolled_window_set_child(GTK_SCROLLED_WINDOW(scr), tv);

  // 设置buffer的值,files这些变量都是通过信号"open"自动填充的
  char *contents;
  gsize length;
  GError *err = NULL;
  char *filename;
  if (g_file_load_contents(files[0], NULL, &contents, &length, NULL, &err)) {
    gtk_text_buffer_set_text(tb, contents, length);
    g_free(contents);
    // 设置标题
    if ((filename = g_file_get_basename(files[0])) != NULL) {
      gtk_window_set_title(GTK_WINDOW(win), filename);
      g_free(filename);
    }
    gtk_window_present(GTK_WINDOW(win));
  } else {
    g_printerr("%s.\n", err->message);
    g_error_free(err);
    gtk_window_destroy(GTK_WINDOW(win));
  }
}

void chapter7(int argc, char **agv) {
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
