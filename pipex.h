#ifndef PIPEX_H
#define PIPEX_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

size_t	ft_strlen(const char *str);
int		ft_countword(char *s, char c);
int		ft_wordlen(char *s, char c);
int		get_index(char **envp);
int     ft_strncmp(const char *str1, const char *str2, size_t n);
char	**ft_free(char **a);
char	**ft_split(char const *s, char c);
char	*ft_strncpy(char *dest, const char *src, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
char    *get_path(char **envp, char *cmd);
void	ft_putstr_fd(char *s, int fd);
void    call_parent(int *pipe_fd, char **argv, char **envp);
void    call_child(int *pipe_fd, char **argv, char **envp);

#endif