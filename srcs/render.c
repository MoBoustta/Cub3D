/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboustt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 14:54:16 by moboustt          #+#    #+#             */
/*   Updated: 2020/02/15 14:54:18 by moboustt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

void render_firt_time(t_struct *data)
{
	cast_rays(data);
	render_walls(data);
	move_player(data);
	help_text(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
}

int update(t_struct *data)
{
	cast_rays(data);
	render_walls(data);
	move_player(data);
	if (data->m)
		mini_map(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	if (data->h)
		help_text(data);
	return (FALSE);
}

int move_player(t_struct *data)
{
	data->rotation_angle += data->turn_direction * data->turn_speed;
	data->move_step = data->walk_direction * data->walk_speed;
	data->updated_player_x = data->x + cos(data->rotation_angle) * data->move_step;
	data->updated_player_y = data->y + sin(data->rotation_angle) * data->move_step;

	int x = calculate_index(data->updated_player_x);
	int y = calculate_index(data->updated_player_y);

	if (!valid_indeces(data, x, y))
		return FALSE;

	if (!if_wall(data->updated_player_x, data->updated_player_y, data) && !is_sprite(data->map[y][x]))
	{
		data->x = data->updated_player_x;
		data->y = data->updated_player_y;
	}
	return (TRUE);
}
