#include "../includes/so_long.h"

void	init_and_check(t_param *param, char *file_name)
{
	param->game = (t_game *)malloc(sizeof(t_game));
	if (!(param->game))
		ft_exit("GAME MALLOC ERROR");
	init_param(param);
	check_file_name(param->game, file_name);
	read_map(param->game, file_name);
	check_map(param->game);
}

void	init_param(t_param *param)
{
	param->mlx = mlx_init();
	param->game->n_move = 0;
	param->game->n_row = 0;
	param->game->n_col = 0;
}

void	save_map(t_game *game, int fd)
{
	char	*line;
	char	*save;
	char	*temp;
	int		rows;

	save = ft_strdup("");
	rows = 0;
	line = get_next_line(fd);
	while (line)
	{
		++rows;
		temp = ft_strjoin(save, line);
		free(line);
		if (!temp)
			ft_exit("READING MAP ERROR");
		free(save);
		save = temp;
		line = get_next_line(fd);
	}
	game->n_row = rows;
	game->map = ft_split(save, '\n');
	free(save);
	if (!(game->map) || game->n_row == 0)
		ft_exit("READING MAP ERROR");
}

void	read_map(t_game *game, char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		ft_exit("FILE OPEN ERROR");
	save_map(game, fd);
}
