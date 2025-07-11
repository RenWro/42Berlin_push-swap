/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwrobles <rwrobles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:00:29 by rwrobles          #+#    #+#             */
/*   Updated: 2025/06/15 13:49:23 by rwrobles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

// Color prefixes avoids conflicts
# define LIBFT_GREY      "\033[0;90m"
# define LIBFT_RED       "\033[0;31m"
# define LIBFT_PURPLE    "\033[0;35m"
# define LIBFT_CYAN      "\033[0;36m"
# define LIBFT_RESET     "\033[0m"

// Macro buffer to avoid redefinitions
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

// Linked structure for dinamic size and non contiguous alloc
typedef struct s_element
{
	void				*content;
	struct s_element	*next;
	struct s_element	*prev;
}	t_element;

typedef struct s_list
{
	t_element	*first;
	t_element	*last;
	int			size;
}	t_list;

typedef struct s_fl
{
	t_list		*first;
	t_list		*last;
	size_t		size;
}	t_fl;

// Std Libft
int			ft_isalpha(int argument);
int			ft_isdigit(int argument);
int			ft_isalnum(int argument);
int			ft_isascii(int argument);
int			ft_isprint(int argument);
size_t		ft_strlen(const char *str);
void		*ft_memset(void *s, int argument, size_t length);
void		ft_bzero(void *s, size_t length);
void		*ft_memcpy(void *dest, const void *src, size_t length);
void		*ft_memmove(void *dest, const void *src, size_t length);
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
size_t		ft_strlcat(char *dest, const char *src, size_t dest_size);
int			ft_toupper(int argument);
int			ft_tolower(int argument);
char		*ft_strchr(const char *str, int argument);
char		*ft_strrchr(const char *str, int argument);
int			ft_strncmp(const char *s1, const char *s2, size_t size);
void		*ft_memchr(const void *str, int argument, size_t size);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
char		*ft_strnstr(const char *str, const char *to_find, size_t size);
int			ft_atoi(const char *str);
long long	ft_atoll(const char *str);
int			ft_strisinteger(char *str);
void		*ft_calloc(size_t nbr_elements, size_t element_size);
char		*ft_strdup(char *src);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstadd_before(t_fl *lst, t_list *ref, t_list *el);
void		ft_lstadd_after(t_fl *lst, t_list *ref, t_list *el);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void*));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list		*ft_lstnewelement(void *content);
void		ft_free_ptr(char **ptr);
t_element	*ft_lstpop(t_list *lst, int index);

#endif