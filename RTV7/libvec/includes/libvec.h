/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libvec.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapperce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 11:50:36 by tapperce          #+#    #+#             */
/*   Updated: 2018/03/05 17:41:51 by tapperce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBVEC_H
# define LIBVEC_H

# include <math.h>
# include "../../libft/libft.h"



# include <stdio.h>

typedef struct	s_vec2
{
	double		x;
	double		y;
}				t_vec2;

typedef struct	s_vec3
{
	double		x;
	double		y;
	double		z;
}				t_vec3;

void			vec_normalise3(t_vec3 *vec);
t_vec3			vec_add3(t_vec3 v1, t_vec3 v2);
t_vec3			vec_sub3(t_vec3 v1, t_vec3 v2);
t_vec3			vec_mult3(t_vec3 vec, double k);
t_vec3			vec_cross3(t_vec3 v1, t_vec3 v2);
double			vec_dot3(t_vec3 v1, t_vec3 v2);
double			vec_length3(t_vec3 vec);

void			vec_normalise2(t_vec2 *vec);
t_vec2			vec_add2(t_vec2 v1, t_vec2 v2);
t_vec2			vec_sub2(t_vec2 v1, t_vec2 v2);
t_vec2			vec_mult2(t_vec2 vec, double k);
double			vec_dot2(t_vec2 v1, t_vec2 v2);
double			vec_length2(t_vec2 vec);

double			**mat_create44(void);
double			**mat_product44(double **m1, double **m2);
double			**mat_transpose44(double **m);
double			**mat_inverse4x4(double **mat);
double			**mat_translate(t_vec3 abc);
double			**mat_rotate(t_vec3 abc);
int				mat_free44(double **mat);

t_vec3			mat_multpmat44(t_vec3 p, double **m);
t_vec3			mat_multvmat44(t_vec3 vec, double **m);

#endif
