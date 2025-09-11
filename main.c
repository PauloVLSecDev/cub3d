
#include </workspaces/ft_template_repo-main/minilibx-linux/mlx.h>
#include <stdlib.h>
#include <stdio.h>

#define WIN_WIDTH 600
#define WIN_HEIGHT 600
#define PIXEL_COLOR 0x00FF0000
#define MOVE_SPEED 5

#define KEY_W 119
#define KEY_A 97
#define KEY_S 115
#define KEY_D 100
#define KEY_ESC 65307

typedef struct s_game
{
	void	*mlx;
	void	*win;
	int		pixel_x;
	int		pixel_y;
}	t_game;

int	exit_program(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

int	key_press_handler(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		game->pixel_y -= MOVE_SPEED;
	else if (keycode == KEY_S)
		game->pixel_y += MOVE_SPEED;
	else if (keycode == KEY_A)
		game->pixel_x -= MOVE_SPEED;
	else if (keycode == KEY_D)
		game->pixel_x += MOVE_SPEED;
	else if (keycode == KEY_ESC)
		exit_program(game);
	return (0);
}

int	render_loop(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);

	mlx_pixel_put(game->mlx, game->win, game->pixel_x, game->pixel_y, PIXEL_COLOR);

	return (0);
}

int	main(void)
{
	t_game	game;

	game.mlx = mlx_init();

	game.win = mlx_new_window(game.mlx, WIN_WIDTH, WIN_HEIGHT, "Pixel em Movimento");

	game.pixel_x = WIN_WIDTH / 2;
	game.pixel_y = WIN_HEIGHT / 2;
	mlx_key_hook(game.win, key_press_handler, &game);
	mlx_hook(game.win, 17, 0, exit_program, &game);
	mlx_loop_hook(game.mlx, render_loop, &game);
	mlx_loop(game.mlx);
}
