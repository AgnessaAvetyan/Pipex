#include "pipex.h"

int		get_index(char **envp)
{
	int i;

	i = 0;
	while (envp[i])
	{
		if(!(ft_strncmp(envp[i], "PATH=", 5)))
			return (i);
		i++;
	}
	return (0);
}

char    *get_path(char **envp, char *cmd)
{
    char	**array;
    char	*path;
	char	*tmp;
	int		open_id;
	int		i;
	int		j;

	i = get_index(envp);
	if (cmd[0] == '/')
		return (cmd);
	else
	{
		j = 0;
		array = ft_split(envp[i] + 5, ':');
		while (array[j])
		{
			tmp = ft_strjoin(array[j], "/");
			path = ft_strjoin(tmp, cmd);
			open_id = open(path, O_RDONLY);
			if (open_id > -1)
			{
				close(open_id);
				free(tmp);
				ft_free(array);
				return (path);
			}
			free(path);
            free(tmp);
			j++;
		}
		ft_free(array);
	}
	return (0);
}