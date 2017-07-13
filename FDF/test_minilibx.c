
#include "./includes/fdf.h"

int   main()
{
  void *mlx;
  void *win;
  int x;
  int y;

  mlx = mlx_init();
  win = mlx_new_window(mlx, 1280, 960, "mlx 42");
  y = 100;
  while(y < 300)
  {
    x = 100;
    while(x < 300)
    {
      mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF);
      x++;
    }
    y++;
  }
  mlx_loop(mlx);
}
