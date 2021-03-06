/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 22:26:17 by user42            #+#    #+#             */
/*   Updated: 2021/09/05 23:47:38 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MLX_H
# define FT_MLX_H

# define TITLE "fdf"
# define WIDTH 1900 
# define HEIGHT 1200 

/*
** This structure contains all informations needed by the MLX. Even if a screen-
** shot is called (hence the mlx is not initialized) the *data pointer contains
** the array of pixels of the resulting image.
*/

typedef struct s_mlx
{
	int		win_width;
	int		win_height;
	int		screen_width;
	int		screen_height;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int		*data;
	int		size_line;
	int		bits_per_pixel;
	int		endian;
}	t_mlx;

typedef struct s_color
{
	float	r;
	float	g;
	float	b;
}	t_color;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_bresenham
{
	int	diff_x;
	int	diff_y;
	int	err;
	int	err_times_two;
	int slope_x;
	int slope_y;
}	t_bresenham;

/*
** mlx_utils.c
*/

t_mlx	*get_mlx(void);
int	run_window(t_mlx *mlx);
t_color	get_color(float r, float g, float b);
t_error	init_mlx(void);
int		close_mlx(void);
void	put_pixel(t_mlx *mlx, int x, int y, t_color color);

/*
** mlx_hooks.c
*/

void	set_mlx_hooks(t_mlx *mlx);

#endif
