/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csteudin <csteudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 10:51:38 by csteudin          #+#    #+#             */
/*   Updated: 2024/03/27 17:01:52 by csteudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <fcntl.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef unsigned char	t_uint8;
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;
// LIBFT
void		ft_bzero(void *ptr, size_t nb);
int			ft_strlen(const char *str);
char		*ft_strdup(const char *str);
size_t		ft_strlcat(char *dest, const char *src, size_t n);
char		*ft_strchr(const char *str, int ch);
char		*ft_strrchr(const char *str, int ch);
char		*ft_strnstr(const char *hay, const char *ned, size_t n);
int			ft_strncmp(const char *str1, const char *str2, size_t n);
int			ft_atoi(const char *str);
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
void		*ft_memset(void *ptr, int value, size_t num);
void		*ft_memcpy(void *dest, const void *src, size_t nb);
void		*ft_memmove(void *dest, const void *src, size_t numb);
void		*ft_memchr(const void *str, int ch, size_t n);
int			ft_memcmp(const void *str1, const void *str2, size_t n);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(char c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
char		*ft_strmapi(const char *s, char (*f)(unsigned int, char));
void		*ft_calloc(size_t nmemb, size_t size);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s, char const *set);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
char		**ft_split(const char *s, char c);
char		*ft_itoa(int nb);
t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
char		*ft_strcpy(char *dest, const char *src);
char		*ft_strncpy(char *dest, const char *src, size_t n);
char		*ft_strcat(char *dest, char *src);
char		*ft_strncat(char *dest, char *src, size_t n);
int			ft_strcmp(const char *str1, const char *str2);
char		*ft_strstr(const char *haystack, const char *needle);
int			ft_strequ(char const *s1, char const *s2);
int			ft_strnequ(char const *s1, char const *s2, size_t n);
char		*ft_strmap(const char *s, char (*f)(char));
void		*ft_memalloc(size_t size);
void		ft_memdel(void **ap);
char		*ft_strnew(size_t size);
void		ft_strdel(char **as);
void		ft_strclr(char *s);
void		ft_striter(char *s, void (*f)(char *));
void		*ft_memccpy(void *dest, const void *src, int c,	size_t n);
char		*ft_strncpy(char *dest, const char *src, size_t n);
// PRINTF
int			ft_printf(const char *str, ...);
int			ft_putnbr_base_len(unsigned int num, char *base, int *res);
int			handle_char(va_list args);
int			handle_string(va_list args);
int			handle_base_nb(va_list args, char *base);
int			handle_un_base_nb(va_list args, char *base);
int			handle_adress(va_list args);
int			ft_putadress(unsigned long num);
// GET NEXT LINE
char		*get_next_line(int fd);
int			get_new_line(int fd, char **line, char *buffer);
char		*get_new_buffer(char *line, char **buffer);
int			clean_up(char **line, char *buffer);
int			redo_line(char **dst, char *src);
#endif
