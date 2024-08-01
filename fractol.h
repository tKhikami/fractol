/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrandri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 13:50:48 by nyrandri          #+#    #+#             */
/*   Updated: 2024/08/01 08:05:29 by nyrandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H

# ifndef WIN_LENGTH
#  define WIN_LENGTH 500
# endif
# ifndef WIN_WIDTH
#  define WIN_WIDTH 500
# endif
# ifndef ACCURACY
#  define ACCURACY 500
# endif
# ifndef RATIO
#  define RATIO 1.4
# endif

# include <math.h>
# include <stdlib.h>
# include "printf/ft_printf.h"

/*
 * define origine of the affine coordonate
 * here we have an orthogonal system
 * i & j representes in pixel, the size of the unit vector director
*/

typedef struct s_sys
{
	long long int		origine_x;
	long long int		origine_y;
	unsigned long long	i;
	unsigned long long	j;
}	t_sys;

typedef struct s_image
{
	void	*img;
	char	*addr;
	t_sys	system;
	int		bpp;
	int		line_len;
	int		endian;
}	t_image;

typedef struct s_coordonne
{
	double	x;
	double	y;
}	t_coordonne;

typedef struct s_data
{
	void		*ptr;
	void		*win;
	char		index;
	char		button1;
	char		button3;
	double		ratio;
	t_coordonne	c;
	t_coordonne	c_move;
	int			color;
	t_coordonne	hook_position;
	t_image		image_front;
	t_image		image_back;
}	t_data;

/*
 * pixel managing
*/

void		my_mlx_pixel_put(t_image *image, int x, int y, int color);
void		prototype(t_data *data, void (*f)());
int			get_color_pixel(t_image *image, int x, int y);
int			check(int color, t_data *data, t_coordonne temp);

/*
   maping
*/

void		affine_to_pixel(int *i, int *j, t_coordonne pos, t_sys system);
t_coordonne	pixel_to_affine(double a, double b, t_sys system);
void		default_system(t_sys *system);
void		system_zoom(t_data *data);
void		pixel_translation(t_data *data, t_coordonne vector, void (*f)());

/*
 * basic math
 * */

int			min(int a, int b);
t_coordonne	homothety(t_coordonne point, t_coordonne center, double ratio);

/*
 * event function
 */

int			comportement_key(int key, t_data *data);
int			button_is_press(int button, int x, int y, t_data *data);
int			button_is_release(int button, int x, int y, t_data *data);
void		render(t_data *data);
int			init_all(t_data *data, char *str);
void		all_event(t_data *data);
void		optim_zoom(int *tab, t_data *data);

/*
   back managing
   */

void		update_system_back(t_data *data);
void		update_back(t_data *data);

/*
   color
*/

double		blue_shade(t_coordonne next, double i);

/*
   arg manager
*/

void		error_message(void);
char		**ft_split(char const *s, char c);
double		ft_double_atoi(char *str);
int			ft_strcmp(const char *s1, const char *s2);
int			arg_valide(int n, char **vector, t_data *data);

/*
   fractal
   */

void		mandelbrot(int *tab, t_data *data);
void		julia(int *tab, t_data *data);
void		zoom(int button, t_data *data);
int			translation(int x, int y, t_data *data);
int			key_translation(int key, t_data *data);
int			c_move_julia(int x, int y, t_data *data);

#endif
