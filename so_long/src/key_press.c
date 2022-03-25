#include "../includes/so_long.h"

void	key_func(t_param *param, int changing_row, int changing_col)
{
	int	target_row;
	int	target_col;

	target_row = param->game->cur_row + changing_row;
	target_col = param->game->cur_col + changing_col;
	if (param->game->map[target_row][target_col] != '1')
	{
		if (param->game->map[target_row][target_col] == 'E')
			move_to_exit(param, target_row, target_col);
		else
		{
			move_player(param, target_row, target_col);
		}
		printf("movement : %d\n", ++(param->game->n_move));
	}
}

int	key_press(int keycode, t_param *param)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(param->mlx, param->win);
		exit(0);
	}
	else if (keycode == KEY_W)
		key_func(param, -1, 0);
	else if (keycode == KEY_S)
		key_func(param, 1, 0);
	else if (keycode == KEY_A)
		key_func(param, 0, -1);
	else if (keycode == KEY_D)
		key_func(param, 0, 1);
	return (0);
}
