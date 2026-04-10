/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiguna <maiguna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 10:27:56 by maiguna           #+#    #+#             */
/*   Updated: 2026/01/30 16:30:37 by maiguna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>

/************ GNL ************/
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

/************ GNL ************/
char	*get_next_line(int fd);

/* ========================================================================== */
/*                              Linked List                                   */
/* ========================================================================== */

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/* ========================================================================== */
/*                              Checks & Conversions                          */
/* ========================================================================== */

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);

/* ========================================================================== */
/*                              String                                        */
/* ========================================================================== */

size_t	ft_strlen(const char *str);
int		ft_atoi(const char *nptr);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strdup(const char *src);
char	*ft_strnstr(const char *big, const char *little, size_t len);

/* ========================================================================== */
/*                              Memory                                        */
/* ========================================================================== */

void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t size);

/* ========================================================================== */
/*                              File Descriptor                               */
/* ========================================================================== */

void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);

/* ========================================================================== */
/*                              String Manipulation                           */
/* ========================================================================== */

char	*ft_itoa(int n);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);

/* ========================================================================== */
/*                              Linked List                                   */
/* ========================================================================== */

int		ft_lstsize(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstiter(t_list *lst, void (*f)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/* ========================================================================== */
/*                              Printf Functions                              */
/* ========================================================================== */

int		ft_printf(const char *format, ...);
int		ft_printchar(char c);
int		ft_printstr(const char *s);
int		ft_printnbr(int nbr);
int		ft_printnbr_unsigned(unsigned int nbr);
int		ft_printhex(unsigned int nbr);
int		ft_printhex_upper(unsigned int nbr);
int		ft_printp(void *nbr);
int		ft_printhex_pointeur(unsigned long nbr);

#endif