/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 20:27:53 by jgasparo          #+#    #+#             */
/*   Updated: 2024/05/23 15:00:55 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
**	setup env var PWD OLDPWD
*/
static void	ft_setup_pwd_oldpwd(t_cd *cd)
{
	if (cd->pwd)
		cd->new_pwd = ft_pwdcat(cd->temp_pwd, cd);
	else
		cd->new_pwd = ft_strdup(cd->pwd);
	ft_seek_replace(cd->data, PWD, cd->new_pwd);
	ft_seek_replace(cd->data, OLDPWD, cd->pwd);
}

/*
**	searches for variable in env, if doesn't exist -> adds it
*/
void	ft_seek_replace(t_data *data, char *search, char *pwd)
{
	int			i;
	int			found;

	i = 0;
	found = 0;
	while (data->env[i])
	{
		if (!ft_strncmp(data->env[i], search, ft_strlen(search)))
		{
			free(data->env[i]);
			data->env[i] = ft_strjoin(search, pwd);
			found = 1;
		}
		i++;
	}
	if (!found)
	{
		if (!ft_strncmp(search, OLDPWD, ft_strlen(search)) && !pwd)
			pwd = ft_strdup("");
		data->env = ft_add_to_env(data->env, ft_strjoin(search, pwd));
	}
}

/*
**	cd without args/path -> change data for PWD / OLDPWD in env
*/
void	ft_cd_home(t_cd *cd)
{
	ft_seek_replace(cd->data, PWD, cd->home + 5);
	ft_seek_replace(cd->data, OLDPWD, cd->pwd);
}

/*
**	cd with absolute path
*/
void	ft_cd_absolute(t_cd *cd)
{
	if (cd->temp_tilde)
		cd->new_pwd = ft_strdup(cd->temp_tilde);
	else if (cd->temp_minus)
		cd->new_pwd = ft_strdup(cd->temp_minus);
	else if (!ft_getenv(cd->data, PWD))
		cd->new_pwd = ft_strdup(cd->pwd);
	else
		cd->new_pwd = ft_strdup(cd->dir);
	if (!(ft_strlen(cd->new_pwd) == 1)
		&& cd->new_pwd[ft_strlen(cd->new_pwd) - 1] == '/')
		ft_memset(cd->new_pwd + (ft_strlen(cd->new_pwd) - 1), 0, 1);
	ft_seek_replace(cd->data, PWD, cd->new_pwd);
	ft_seek_replace(cd->data, OLDPWD, cd->pwd);
}

/*
**	cd with relative path
*/
void	ft_cd_relative(t_cd *cd)
{
	int		i;

	cd->temp_path = ft_split(cd->dir, '/');
	cd->temp_pwd = ft_split(cd->pwd, '/');
	if (!ft_strncmp(cd->temp_path[0], TILDE, 1)
		|| !ft_strncmp(cd->temp_path[0], MINUS, 1))
	{
		ft_free_array(cd->temp_path);
		cd->temp_pwd = ft_replace_pwd(cd, cd->temp_path[0]);
		cd->temp_path = ft_remove_first(cd->temp_path, cd);
	}
	i = 0;
	while (cd->temp_path[i])
	{
		if (!ft_strncmp(cd->temp_path[i], PARENT, 2))
			cd->temp = ft_sup_pwd(cd);
		else if (ft_strncmp(cd->temp_path[i], CURRENT, 2) != 0)
			cd->temp = ft_append_pwd(i, cd);
		i++;
		cd->temp_pwd = cd->temp;
	}
	ft_setup_pwd_oldpwd(cd);
}
