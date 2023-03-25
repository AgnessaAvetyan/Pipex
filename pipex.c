#include "pipex.h"

void    call_child(int *pipe_fd, char **argv, char **envp) 
{
    char    **cmd1;
    int     open_id;

    cmd1 = ft_split(argv[2], ' ');
    close(pipe_fd[0]);
    dup2(pipe_fd[1], 1);
    close(pipe_fd[1]);
    open_id = open(argv[1], O_RDONLY, 0777);
    if (open_id == -1)
    {
        ft_putstr_fd("An error has occured at opening the file\n", 2);
        exit(0);
    }
    dup2(open_id, 0);
    close(open_id);
    if (execve(get_path(envp, cmd1[0]), cmd1, envp) == -1)
    {
        ft_putstr_fd("Command not found\n", 2);
        exit(0);
    }

}

void    call_parent(int *pipe_fd, char **argv, char **envp)
{
    char    **cmd2;
    int     open_id;

    cmd2 = ft_split(argv[3], ' ');
    wait(0);
    open_id = open(argv[4], O_WRONLY | O_CREAT, 0777);
    if (open_id == -1)
    {
        ft_putstr_fd("An error has occured at opening the file\n", 2);
        exit(0);
    }
    close(pipe_fd[1]);
    dup2(pipe_fd[0], 0);
    close(pipe_fd[0]);
    dup2(open_id, 1);
    close(open_id);
    if (execve(get_path(envp, cmd2[0]), cmd2, envp) == -1)
    {
        ft_putstr_fd("Command not found\n", 2);
        exit(0);
    }
}

int     main(int argc, char **argv, char **envp)
{
    int     pipe_fd[2];
    pid_t   fork_id; 

    if (argc != 5)
    {
        ft_putstr_fd("Error: file1 cmd1 cmd2 file 2\n", 2);
        return (0);
    }
    if (pipe(pipe_fd) == -1)
        return (0);
    fork_id = fork();
    if (fork_id == -1)
    {
        ft_putstr_fd("Error\n", 2);
        return (0);
    }
    if (fork_id == 0)
        call_child(pipe_fd, argv, envp);
    else
        call_parent(pipe_fd, argv, envp);
    return (0);
} 