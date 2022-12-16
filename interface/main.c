#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415926
#include <gtk/gtk.h>

void start_button_clicked(GtkWidget *widget, gpointer data);
void exit_button_clicked(GtkWidget *widget, gpointer data);
void execute_program();



int main(int argc, char *argv[])
{
  GtkWidget *window;
  GtkWidget *button_start;
  GtkWidget *button_exit;
  GtkWidget *screen;

  gtk_init(&argc, &argv);

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), "Program Interface");
  gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);

  button_start = gtk_button_new_with_label("Пуск");
  button_exit = gtk_button_new_with_label("Выйти");
  screen = gtk_label_new("Нажмите кнопку Пуск, чтобы начать.");

  g_signal_connect(button_start, "clicked", G_CALLBACK(start_button_clicked), screen);
  g_signal_connect(button_exit, "clicked", G_CALLBACK(exit_button_clicked), NULL);

  GtkWidget *grid = gtk_grid_new();
  gtk_grid_set_row_homogeneous(GTK_GRID(grid), TRUE);
  gtk_grid_set_column_homogeneous(GTK_GRID(grid), TRUE);
  gtk_grid_attach(GTK_GRID(grid), button_start, 0, 0, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), button_exit, 1, 0, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), screen, 0, 1, 2, 1);

  gtk_container_add(GTK_CONTAINER(window), grid);

  gtk_widget_show_all(window);

  gtk_main();

  return 0;
}

void start_button_clicked(GtkWidget *widget, gpointer data)
{
  GtkWidget *screen = GTK_WIDGET(data);
  gtk_label_set_text(GTK_LABEL(screen), "Программа работает...");


  execute_program();
}

void exit_button_clicked(GtkWidget *widget, gpointer data)
{
  gtk_main_quit();
}

void execute_program()
{
  printf("%*s", 22, "LISSAJOUS");
    printf("\n%*s", 18, "CREATIVE COMPUTING");
    printf("\n%*s", 16, "MORRISTOWN NEW JERSEY");
    printf("\n\n\n");
    double f1, f2, p2;
    int x1, y1, y2;

    printf("Relative freq. for x: ");
    scanf("%lf", &f1);
    if (f1 < 1 || f1 != (int)f1)
    {
        printf("Invalid input.\n");
        return 1;
    }

    printf("Relative freq. for y: ");
    scanf("%lf", &f2);
    if (f2 < 1 || f2 != (int)f2)
    {
        printf("Invalid input.\n");
        return 1;
    }

    printf("Y phase, multiple of pi: ");
    scanf("%lf", &p2);
    f1 = 2 * PI * f1;
    f2 = 2 * PI * f2;
    p2 = PI * p2;

    for (x1 = -18; x1 <= 18; x1++)
    {
        double x = x1 / 18.0;
        double t1 = x, t2 = PI - x;

        for (int i = 0; i < f1; i++)
        {
            double t3 = (t1 + 2 * i * PI) / f1;
            double t4 = (t2 + 2 * i * PI) / f1;
            y1 = 30 * sin(f2 * t3 + p2);
            y2 = 30 * sin(f2 * t4 + p2);
            y1 = (y1 > 0) ? (int)(y1 + 0.5) : (int)(y1 - 0.5);
            y2 = (y2 > 0) ? (int)(y2 + 0.5) : (int)(y2 - 0.5);


            if (y1 < y2)
            {
                printf("%*s*\n", 36 + y1, "");
                printf("%*s*\n", 36 + y2, "");
            }
            else
            {
                printf("%*s*\n", 36 + y2, "");
                printf("%*s*\n", 36 + y1, "");
            }
        }
    }

    return 0;
}
