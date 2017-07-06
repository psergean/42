
#include "./includes/fdf.h"

int   main()
{
  void *mlx;
  void *win;
  int x;
  int y;
  int e;
  int w;

  mlx = mlx_init();
  win = mlx_new_window(mlx, 400, 400, "mlx 42");
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
  w = 50;
  while(w < 150)
  {
    e = 50;
    while(e < 150)
    {
      mlx_pixel_put(mlx, win, e, w, 0x09F9F99F);
      e++;
    }
    w++;
  }  
  mlx_loop(mlx);
}
