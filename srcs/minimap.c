#include "../include/cub3d.h"

void draw_line(t_struct *data)
{
    float j;
    float i;
    float radius;

    i = data->x;
    j = data->y;
    radius = 40;
    while (radius > 0)
    {
        j = data->y;
        while (j++ < data->y + 1)
            ft_draw(data, (i + cos(data->rotation_angle) * radius) * MINI,
                    (j + sin(data->rotation_angle) * radius) * MINI, 0x4287f5);
        radius -= 1;
    }
}

void circle(t_struct *data)
{
    float two_pi;
    float i;
    float get_radius;

    two_pi = 2 * PI;
    i = 0;
    get_radius = 10;
    while (get_radius > 0)
    {
        i = 0;
        while (i <= two_pi)
        {
            ft_draw(data, MINI * ((cosf(i) * get_radius) + data->x),
                    MINI * ((sinf(i) * get_radius) + data->y), 0xfcba03);
            i += 0.1F;
        }
        get_radius -= 0.1F;
    }
}

void fill_square(int square_x, int square_y,
                 int tile_size, int tile_color, t_struct *data)
{
    int i;
    int j;

    i = square_x;
    while (i++ < tile_size + square_x && i < data->w_height)
    {
        j = square_y;
        while (j++ < tile_size + square_y) {
            //printf("j === %d\n", j);
            ft_draw(data, i * MINI, j * MINI, tile_color);
        }
    }
    printf("i === %d\n", i);
}

int render_map(t_struct *data, int m)
{
    int i;
    int j;
    int square_x;
    int square_y;
    int square_color;

    i = 0;
    while (i <= data->n_lines)
    {
        j = 0;
        while (j < g_lines_length[i])
        {
            m = data->map[i][j];
            square_x = j * SQUARE_SIZE;
            square_y = i * SQUARE_SIZE;
            square_color = m == '0' ? YELLOW : GREEN;
            if (m == 'N' || m == 'W' || m == 'E' || m == 'S')
                square_color = PLAYER_COLOR;
            if (m == '2')
                square_color = SPRITE_COLOR;
            fill_square(square_x - 1, square_y - 1, SQUARE_SIZE, square_color, data);
            j++;
        }
        i++;
    }
    return (TRUE);
}

void mini_map(t_struct *data)
{
    int m = 0;
    render_map(data, m);
    circle(data);
    draw_line(data);
}