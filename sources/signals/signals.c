/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:43:30 by anvoets           #+#    #+#             */
/*   Updated: 2024/05/21 15:07:38 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_sigint(int sig)
{
	(void)sig;
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 1);
	rl_redisplay();
}

void	ft_signal(void *type)
{
	if (type != SIG_DFL)
		signal(SIGINT, ft_sigint);
	else
		signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, type);
}

void	ft_get_ctrl_d(t_data *data)
{
	if (data->input == NULL)
	{
		printf("\033[A\033[2K");
		printf("%s", PROMPT "exit\n");
		ft_free_data(data);
		exit(EXIT_SUCCESS);
	}
}

int	ft_init_signal(void)
{
	struct termios	term;

	ft_signal(SIG_IGN);
	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
	return (EXIT_SUCCESS);
}