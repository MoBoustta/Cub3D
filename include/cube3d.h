/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboustt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 01:10:12 by moboustt          #+#    #+#             */
/*   Updated: 2020/02/02 18:43:11 by moboustt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
#define CUBE3D_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "../libs/OpenGL/mlx.h"
#include <fcntl.h>

#define BLACK 0x000000
#define GREEN 0x2ecc71
#define WHITE 0xecf0f1
#define PLAYER 0xecf0f1
#define SPRITE 0XFF00FF

#define PI 3.14159265359
#define TWO_PI 2 * PI
#define DEG(x) x * 180 / M_PI
#define RAD(x) x *M_PI / 180

#define TRUE 1
#define FALSE 0
#define MINI 0.2

#define SQUARE_SIZE 512
#define TEX_WIDTH SQUARE_SIZE
#define TEX_HEIGHT SQUARE_SIZE
#define SPRITE_SIZE 128

#define FOV_ANGLE 60 * (PI / 180)

#define MAX_INT 2147483647
#define BUFFER_SIZE 90
#define MAP_ERR "error : Map error\n"

typedef struct s_sprite
{
	int *buff;
	float x;
	float y;
	float x_off;
	float y_off;
	float size;
	float dis;
} t_sprite;

typedef struct s_ray
{
	float ray_angle;
	float wall_h_x;
	float wall_h_y;
	float distance;
	int wall_h_vert;
	int is_ray_facing_up;
	int is_ray_facing_down;
	int is_ray_facing_right;
	int is_ray_facing_left;
	int was_hit_vertical;
} t_ray;

t_ray *g_rays;
t_sprite *g_sprite;
uint32_t g_buff[TEX_WIDTH * TEX_HEIGHT + 1];

typedef struct s_struct
{
	int m;
	int h;
	int t;
	int orientation;
	int *buff;
	int bpp;
	int size_line;
	int endian;
	int bpp_text;
	int size_line_text;
	int endian_text;
	int *img_data_texture1;
	int *img_data_texture2;
	int *img_data_texture3;
	int *img_data_texture4;
	void *xpm_ptr1;
	void *xpm_ptr2;
	void *xpm_ptr3;
	void *xpm_ptr4;
	void *mlx_ptr;
	void *img_ptr;
	void *win_ptr;
	char *img_data;
	float move_step;
	float updated_player_x;
	float updated_player_y;
	float x;
	float y;
	float radius;
	float width;
	float height;
	int turn_direction;
	int walk_direction;
	float rotation_angle;
	float walk_speed;
	float turn_speed;

	float dx;
	float dy;
	float ray_angle;
	float x_intercept;
	float y_intercept;
	float save_horiz_wall_hit_x;
	float save_horiz_wall_hit_y;
	float save_vert_wall_hit_x;
	float save_vert_wall_hit_y;
	int found_horiz_wall_hit;
	int found_vert_wall_hit;
	int vert_wall_hit_content;
	float horz_hit_distance;
	float vert_hit_distance;
	int is_ray_facing_down;
	int is_ray_facing_up;
	int is_ray_facing_right;
	int is_ray_facing_left;

	float corrected_dsitance;
	float top_pixel;
	float bottom_pixel;
	float distance_to_projection_plane;
	float wall_height;
	int i_wall_index;
	int txt_offset_x;
	int txt_offset_y;

	float vert_touch_x;
	float vert_touch_y;
	float horiz_touch_x;
	float horiz_touch_y;

	int m_height;

	float x_horz_to_check;
	float y_horz_to_check;
	float x_vert_to_check;
	float y_vert_to_check;
	int steps;
	float x_inc;
	float y_inc;

	void *sprite_xpm;
	int *img_data_texture_sprite;

	int was_horz_touching_sprite;
	int was_vert_touching_sprite;
	int which_radius;

	int n_lines;
	int l_length;
	int pos;
	int get_to_map;
	signed int w_width;
	signed int w_height;
	signed int f_red;
	signed int f_green;
	signed int f_blue;
	signed int c_red;
	signed int c_green;
	signed int c_blue;
	char no[25];
	char so[25];
	char we[25];
	char ea[25];
	char sp[25];
	char **map;
	int locate_player_x;
	int locate_player_y;

	t_sprite *sprite;
	int count_spt;

	int i;
	int j;
} t_struct;

int *g_lines_length;

int get_next_line(int fd, char **line);
void free_d_shit(char **to_free);
char *ft_strjoin(char *s1, char *s2);
char *ft_strdup(const char *s1);
char *ft_substr(char *s, unsigned int start, size_t len);
size_t ft_strlen(const char *s);
int gnl_get_index(char *stack);
void gnl_verify_line(char **line, char **stack, char **heap);
int gnl_read_line(char **line, char **stack,
				  char **heap, int byte, int fd);
int ft_atoi(const char *s);
char **ft_split(const char *ss, char c);
void render_player(t_struct *data);
void initialize_1(t_struct *data);
void initialize_2(t_struct *data);
int render_map(t_struct *data, int m);
void fill_square(int square_x, int square_y, int tile_size,
				 int square_color, t_struct *data);
int key_hook(int keycode, void *param);
int initialize_window(t_struct *data);
int move_player(t_struct *data);
void circle(t_struct *data);
void draw_line(t_struct *data);
void ft_draw(t_struct *data, int x, int y, int color);
int if_wall(float x, float y, t_struct *data);
void line(t_struct *data, int x0, int y0, int x1, int y1);
void ft_draw_texture(t_struct *data, int x, int y, int color);
float limit_angle(float angle);
float distance_between_points(float x1, float y1,
							  float x2, float y2);
void horizontal_ray_intersection(float ray_angle, t_struct *data,
								 int *found_horiz_wall_hit);
void vertical_ray_intersection(float ray_angle, t_struct *data,
							   int *found_vert_wall_hit);
void get_smalest_distance(t_struct *data,
						  int found_horiz_wall_hit, int found_vert_wall_hit);
void cast_single_ray(int ray_id, float ray_angle,
					 t_struct *data);
void fill_out_ray(int ray_id, t_struct *data);
void render_all_rays(t_struct *data);
void cast_rays(t_struct *data);
void render_firt_time(t_struct *data);
void mini_map(t_struct *data);
int update(t_struct *data);
int ft_close(void *param);
int key_pressed(int keycode, t_struct *data);
int key_released(int keycode, t_struct *data);
void texture_from_file(t_struct *data);
void texture(t_struct *data);
void render_walls(t_struct *data);
void calculate_vert_ray_intercept(t_struct *data,
								  float ray_angle);
void calculate_horz_ray_intercept(t_struct *data,
								  float ray_angle);
int parse(t_struct *data, char **av);
void initialize_file_struct(t_struct *data);
int read_map(t_struct *data, char *buff);
int fill_out_map(t_struct *data, char *buff);
int check_boudded_map(t_struct *data);
int line_length(char *line);
int count_lines(char *buff);
void *ft_memset(void *b, int c, size_t len);
uint32_t creatergb(int r, int g, int b);
char *ft_strchr(const char *s, int c);
void render_sprite(t_struct *data);
void get_western_texture_path(t_struct *data, char *buff);
void get_easter_texture_path(t_struct *data, char *buff);
void get_resolution_values(t_struct *data, char *buff);
void get_floor_values(t_struct *data, char *buff);
void get_ceilling_values(t_struct *data, char *buff);
void get_north_texture_path(t_struct *data, char *buff);
void get_south_texture_path(t_struct *data, char *buff);
int skip_number(const char *str);
int check_textures_f_c_s_availibility(char *buff);
void get_sprite_path(t_struct *data, char *buff);
int screw_this_norminette(t_struct *data, char *buff);
char *ft_strnstr(const char *haystack,
				 const char *needle, size_t len);
void initialize_sprite(t_struct *data);
void set_up_sprite(t_struct *data);
void draw_sprites(t_struct *data, float x_off, float y_off, int index);
void help_text(t_struct *data);
void init_player(t_struct *data);
void set_up_player(t_struct *data, int e);
int is_sprite(char c);
int is_player(t_struct *data, char *buff);
int calculate_index(float value);
int is_not_valid_element(t_struct *data, char *buff);
int valid_indeces(t_struct *data, int x, int y);

#endif
