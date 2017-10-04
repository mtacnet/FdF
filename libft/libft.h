/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 13:26:34 by mtacnet           #+#    #+#             */
/*   Updated: 2017/10/04 10:43:04 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFF_SIZE 10
# define READ_ERR -1
# define READ_LINE 1
# define READ_END 0

# include <unistd.h>
# include <string.h>
# include <ctype.h>
# include <stdlib.h>
# include <signal.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <sys/uio.h>
# include <sys/types.h>
# include <stdio.h>
# include <fcntl.h>
# include <dirent.h>

/*
	** STRUCTURE T_LIST
*/

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_elem
{
	char			*content;
	struct s_elem	*next;
}					t_elem;

/*
** FONCTIONS MEMORY
*/

int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				ft_memdel(void **ap);
void				ft_bzero(void *s, size_t n);
void				*ft_memalloc(size_t size);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);

/*
** FONCTIONS STR
*/

int					ft_atoi(const char *str);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					ft_strlenint(const char *s);
size_t				ft_strlen(const char *s);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strnstr(const char *big, const char *little, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strdup(char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strjoinfree(char *s1, char *s2, int mode);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
char				*ft_itoa(int n);
char				*ft_strrev(char *str);
char				**ft_strsplit(char const *s, char c);

/*
** FONCTIONS LIST
*/

t_elem				*new_list(void);
t_elem				*init_element(t_elem *element);
t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				push_elem(t_elem **lst, char *content);
void				supp_elem(t_elem **lst, char *arg);
void				push_back(t_elem **lst, char *content);
void				view_list(t_elem **lst);
void				cpy_lst(t_elem **lst_dest, t_elem **lst_src);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstrepel(t_list **alst, t_list *pnew);
void				freelst(t_elem **lst);
int					is_empty(t_elem **lst);

/*
** FONCTIONS ARRAY
*/

char				**list_to_tab(t_elem **lst);
void				tab_to_list(t_elem **lst, char **tab);
void				supp_elem_tab(char **tab, int value);
void				free_tab(char **tab);
void				view_tab(char **tab);

/*
** FONCTIONS IS
*/

int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_isalpha(int c);
int					ft_isprint(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isspace(int c);

/*
** FONCTIONS UTILES
*/

void				ft_swap(int *a, int *b);
size_t				ft_intlen(int c);
int					ft_countword(const char *str, char c);
int					get_next_line(const int fd, char **line);

#endif
