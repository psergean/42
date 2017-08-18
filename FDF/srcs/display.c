#include "./../includes/fdf.h"

void    display(t_env *env)
{
  mlx_string_put(env->mlx, env->win, 10, 0, 0x00FFFFFF, "Quit : Esc");
  mlx_string_put(env->mlx, env->win, 450, 300, 0x00FFFF00, "Je string des put ta mere au mileu de /ff df..");
  mlx_string_put(env->mlx, env->win, 300, 150, 0x000000FF, "Sa C 2 l'Art grafitike Ma GUEULE !!!");
  mlx_string_put(env->mlx, env->win, 10, 500, 0x00FF0000, "#jetelametenlongenlargeentraversurlemarchepied!");

}
