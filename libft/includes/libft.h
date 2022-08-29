/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 00:12:18 by anjose-d          #+#    #+#             */
/*   Updated: 2022/08/13 20:30:23 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include "deftypes.h"

/* gnl define */
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

/* gnl define*/
# ifndef OPEN_MAX
#  define OPEN_MAX 256
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_dlist
{
	int				elem;
	struct s_dlist	*next;
	struct s_dlist	*prev;	
}				t_dlist;

/**
 * @brief Converts the initial portion of the string pointed to by str to int.
 *
 * @param str Pointer to the area of memory of the string to be converted.
 * @return (int) Returns the converted value.
 */
int			ft_atoi(const char *str);

/**
 * @brief Calculates the length of the string pointed to by s,
 * excluding the terminating null byte.
 *
 * @param str Pointer to the initial area of the string.
 * @return (size_t) Returns the number of characters
 * in the string pointed to by s.
 */
size_t		ft_strlen(const char *str);

/**
 * @brief Checks for an alphabetic character.
 *
 * @param c Character to be checked.
 * @return (int) Returns 1 if the character c is a letter and a 0 if not.
 */
int			ft_isalpha(int c);

/**
 * @brief Checks for a digit (0 through 9).
 *
 * @param c Character to be checked.
 * @return (int) Returns 1 if the character c is between or equal 0 to 9.
 */
int			ft_isdigit(int c);

/**
 * @brief Checks for an alphanumeric character; it is
 * equivalent to (isalpha(c) || isdigit(c)).
 *
 * @param c Character to be checked.
 * @return (int) Returns 1 if the character c is alphanumeric
 * (number or letter) and 0 if not.
 */
int			ft_isalnum(int c);

/**
 * @brief Checks whether c is a 7-bit unsigned char value that fits
 * into the ASCII character set.
 *
 * @param c Character to be checked.
 * @return (int) Returns 1 if the character c is between or
 * equal to 0 through 127
 */
int			ft_isascii(int c);

/**
 * @brief Checks for any printable character including space.
 *
 * @param c Character to be checked.
 * @return (int) Returns 1 if the character c is printable character,
 * including space.
 */
int			ft_isprint(int c);

int			ft_isspace(int c);

/**
 * @brief Set n bytes of s to 0.
 *
 * @param s Pointer to the start of the memory location.
 * @param n Number of bytes to be erased in s.
 */
void		ft_bzero(void *s, size_t n);

/**
 * @brief Copies up to size - 1 characters from the NUL-terminated string
 * src to dst, NUL-terminating the result.
 *
 * @param dst Pointer to the destination area of memory.
 * @param src Pointer to the source area of memory.
 * @param dstsize Number of bytes to be copied (Buffer size).
 * @return (size_t) Returns the total length of the string it tried to create
 */
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);

/**
 * @brief Appends the NUL-terminated string src to the end of dst.
 * It will append at most size - strlen(dst) - 1 bytes,
 * NUL-terminating the result.
 *
 * @param dst Pointer to the destination area of memory.
 * @param src Pointer to the source area of memory.
 * @param dstsize Number of bytes to be concatenated (Buffer size).
 * @return (size_t) Returns the total length of the string it tried to create
 */
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);

/**
 * @brief Convert a lowercase letter to uppercase.
 *
 * @param c Character to be converted.
 * @return (int) Returns the converted letter or c if the
 * conversion was not possible.
 */
int			ft_toupper(int c);

/**
 * @brief Convert a uppercase letter to lowercase.
 *
 * @param c Character to be converted.
 * @return (int) Returns the converted letter or c if the
 * conversion was not possible.
 */
int			ft_tolower(int c);

/**
 * @brief Locate character in string and returns a pointer to
 *  the first occurrence.
 *
 * @param s Pointer to the string memory area.
 * @param c Character to be searched inside the string s.
 * @return (char *) Returns a pointer to the first occurrence of
 * the character c in the string s or NULL if the character is not found.
 */
char		*ft_strchr(const char *s, int c);

/**
 * @brief Locate character in string and returns a
 * pointer to the last occurrence.
 *
 * @param s Pointer to the string memory area.
 * @param c Character to be searched inside the string s.
 * @return (char *) Returns a pointer to the last occurrence of the character c
 * in the string s or NULL if the character is not found.
 */
char		*ft_strrchr(const char *s, int c);

/**
 * @brief Compares the two strings s1 and s2, only the
 * first (at most) n bytes of them.
 *
 * @param s1 Pointer to the area of memory of the first string.
 * @param s2 Pointer to the area of memory of the second string.
 * @param n Number of bytes to be compare between strings (buffer size).
 * @return (int) Returns an integer less than, equal to, or greater than zero
 * if s1 (or the first n bytes thereof) is found, to be less than, to match,
 * or be greater than s2.
 */
int			ft_strncmp(const char *s1, const char *s2, size_t n);

/**
 * @brief Locate the first occurrence of the null-terminated substring
 * in the bigstring, where not more than len characters are searched.
 *
 * @param haystack String to be searched by 'needle'.
 * @param needle String to be seached in 'haystack'.
 * @param len Number of bytes to search.
 * @return (char *) A pointer to the first character of the first occurrence of
 * little is returned. If the substring is empty, the big string is returned.
 * If substring occurs nowhere in big, NULL is returned.
 */
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);

/**
 * @brief Fills the first n bytes of the memory area pointed to by s
 * with the constant byte c.
 *
 * @param b Pointer of memory area.
 * @param c Constant byte to fill memory area.
 * @param len Number of bytes to fill.
 * @return (void *) Returns a pointer to the memory area s.
 */
void		*ft_memset(void *b, int c, size_t len);

/**
 * @brief Copies n bytes from memory area src to memory area dst.
 * The memory areas must not overlap.
 * Use memmove if the memory areas do overlap.
 *
 * @param dst Destination pointer of memory area.
 * @param src Source pointer of memory area.
 * @param n Number of bytes to be copy from src to dst.
 * @return (void *) Returns a pointer to dest.
 */
void		*ft_memcpy(void *dst, const void *src, size_t n);

/**
 * @brief Copies n bytes from memory area src to memory area dest.
 * The memory area may overlap.
 * The copy is always done in a non-destructive manner.
 *
 * @param dst Destination pointer of memory area.
 * @param src Source pointer of memory area.
 * @param len number of bytes to be copied from src to dst.
 * @return (void *) Returns a pointer to dest.
 */
void		*ft_memmove(void *dst, const void *src, size_t len);

/**
 * @brief Scans the initial n bytes of the memory area pointed by s
 *  for the first instance of c.
 *
 * @param s Pointer to the initial memory area.
 * @param c Character to be searched.
 * @param n Number of bytes to be scanned (Buffer size).
 * @return (void *) Returns a pointer to the matching byte of NULL
 *  if the character does not occur in the given memory area.
 */
void		*ft_memchr(const void *s, int c, size_t n);

/**
 * @brief Compares the first n bytes of the memory areas s1 and s2.
 *
 * @param s1 Pointer to the first memory area to be compared.
 * @param s2 Pointer to the second memory area to be compared.
 * @param n Number of bytes to be compared (Buffer size).
 * @return (int) Returns an integer less than, equal to, or greater than zero.
 * Nonzero return value, is the difference between s1 and s2.
 */
int			ft_memcmp(const void *s1, const void *s2, size_t n);

/**
 * @brief Allocate and free dynamic memory, setting the memory to zero.
 *
 * @param count Number of elements in array.
 * @param size Size of bytes for each element.
 * @return (void *) Returns a pointer to the allocated memory.
 * NULL if unsifficient memory is available or by successful call
 * to the function with size equal to zero
 */
void		*ft_calloc(size_t count, size_t size);

/**
 * @brief Allocated and returns a duplication of the str.
 *
 * @param s1 Pointer to the start of the string to be copied.
 * @return (char *) Returns a pointer to the duplicated string.
 * It returns NULL if insufficient memory was available.
 */
char		*ft_strdup(const char *s1);

/**
 * @brief Allocates and returns a substring from the string ’s’.
 * The substring begins at index ’start’ and is of maximum size ’len’.
 *
 * @param s The string from which to create the substring.
 * @param start The start index of the substring in the string 's'.
 * @param len The maximum length of the substring.
 * @return (char *) The substring. NULL if the allocation fails.
 */
char		*ft_substr(char const *s, unsigned int start, size_t len);

/**
 * @brief Allocates (with malloc(3)) and returns a new string,
 * which is the result of the concatenation of ’s1’ and ’s2’.
 *
 * @param s1 The prefix string.
 * @param s2 The suffix string.
 * @return (char *) The new string. NULL if the allocation fails.
 */
char		*ft_strjoin(char const *s1, char const *s2);

/**
 * @brief Allocates (with malloc(3)) and returns a copy of ’s1’
 * with the characters specified in ’set’ removed from
 * the beginning and the end of the string.
 *
 * @param s1 The string to be trimmed.
 * @param set The set of characters to trim.
 * @return (char *) The trimmed string. NULL if the allocation fails.
 */
char		*ft_strtrim(char const *s1, char const *set);

/**
 * @brief Allocates and returns an array of strings obtained by
 * splitting ’s’ using the character ’c’ as a delimiter.
 * The array must be ended by a NULL pointer.
 *
 * @param s The string to be split.
 * @param c The delimiter character
 * @return (char **) The array of new strings resulting from the split.
 * NULL if the allocation fails.
 */
char		**ft_split(char const *s, char c);

/**
 * @brief Allocates (with malloc(3)) and returns a string
 * representing the integer received as an argument.
 * Negative numbers must be handled.
 *
 * @param n The integer to convert.
 * @return (char *) The string representing the integer.
 * NULL if the allocation fails.
 */
char		*ft_itoa(int n);

/**
 * @brief Applies the function ’f’ to each character of the string ’s’
 * to create a new string resulting from successive applications of ’f’.
 *
 * @param s The string on which to iterate.
 * @param f The function to apply to each character.
 * @return (char *) The string created from the successive applications of ’f’.
 * Returns NULL if the allocation fails.
 */
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/**
 * @brief Applies the function f to each character of
 * the string passed as argument, and passing its index as first argument.
 * Each character is passed by address to f to be modified if necessary.
 *
 * @param s The string on which to iterate.
 * @param f The function to apply to each character.
 */
void		ft_striteri(char *s, void (*f)(unsigned int, char *));

/**
 * @brief Outputs the character ’c’ to the given file descriptor.
 *
 * @param c The character to output.
 * @param fd The file descriptor on which to write.
 */
void		ft_putchar_fd(char c, int fd);

/**
 * @brief Outputs the string ’s’ to the given file descriptor.
 *
 * @param s The string to output.
 * @param fd The file descriptor on which to write.
 */
void		ft_putstr_fd(char *s, int fd);

/**
 * @brief Outputs the string ’s’ to the given file descriptor,
 * followed by a newline.
 *
 * @param s The string to output.
 * @param fd The file descriptor on which to write.
 */
void		ft_putendl_fd(char *s, int fd);

/**
 * @brief Outputs the integer ’n’ to the given file descriptor.
 *
 * @param n The integer to output.
 * @param fd The file descriptor on which to write.
 */
void		ft_putnbr_fd(int n, int fd);

/**
 * @brief Allocates and returns a new element.
 * The variable ’content’ is initialized with the value
 * of the parameter ’content’. The variable ’next’ is initialized to NULL.
 *
 * @param content The content to create the new element with.
 * @return (t_list *) The new element.
 */
t_list		*ft_lstnew(void *content);

/**
 * @brief Adds the element ’new’ at the beginning of the list.
 *
 * @param lst The address of a pointer to the first node of a list.
 * @param new The address of a pointer to the element to be added to the list.
 */
void		ft_lstadd_front(t_list **lst, t_list *new);

/**
 * @brief Counts the number of elements in a list.
 *
 * @param lst The beginning of a list.
 * @return (int) Length of the list.
 */
int			ft_lstsize(t_list *lst);

/**
 * @brief Returns the last element of the list.
 *
 * @param lst The beginning of the list.
 * @return (t_list *) Last element of the list.
 */
t_list		*ft_lstlast(t_list *lst);

/**
 * @brief Adds the element 'new' at the end of the list.
 *
 * @param lst The address of a pointer to the first node of a list.
 * @param new The address of a pointer to the element to be added to the list.
 */
void		ft_lstadd_back(t_list **lst, t_list *new);

/**
 * @brief Takes as a parameter an element and frees the memory of the
 * element’s content using the function ’del’ given as a parameter
 * and free the element. The memory of ’next’ must not be freed.
 *
 * @param lst The element to be freed.
 * @param del The address of the function used to delete the content.
 */
void		ft_lstdelone(t_list *lst, void (*del)(void *));

/**
 * @brief Deletes and frees the given element and every
 * successor of that element, using the function ’del’ and free(3).
 * Finally, the pointer to the list must be set to NULL.
 *
 * @param lst The address of a pointer to an element.
 * @param del The address of the function used to
 * delete the content of the element.
 */
void		ft_lstclear(t_list **lst, void (*del)(void *));

/**
 * @brief Iterates the list 'lst' and applies the function 'f'
 * to the content of each element.
 *
 * @param lst The address of a pointer to an element.
 * @param f The address of the function used to iterate on the list.
 */
void		ft_lstiter(t_list *lst, void (*f)(void *));

/**
 * @brief Iterates the list 'lst' and applies the function 'f'
 * to the content of each element. Creates a new list resulting of the
 * successive applications of the function 'f'. The 'del' function is used
 * to delete the content of an element if needed.
 *
 * @param lst The address of a pointer to an element.
 * @param f The address of the function used to iterate on the list.
 * @param del The address of the function used to delet
 * the content of an element if needed.
 * @return (t_list *) The string created from the successive
 * applications of ’f’. Returns NULL if the allocation fails.
 */
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/* Get the respective content from the respective index (starting from 0) */
void		*ft_lstget(t_list *lst, int index);

/* Get the index of the respective node */
int			ft_lstget_idx(t_list *lst, t_list *node);

/* remove 'old_node' from the list, but not free'd */
void		ft_lstrm_node(t_list **lst, t_list *old_node);

/* DOUBLE LINKED LISTS FUNCTIONS */
t_dlist		*ft_dlstnew(int elem);

/* find the last element in a double linked list */
t_dlist		*ft_dlstlast(t_dlist *lst);

/* PUT A NEW NODE IN THE BACK */
void		ft_dlstadd_back(t_dlist **lst, t_dlist *new);

/* PUT A NEW NOT IN THE FRONT */
void		ft_dlstadd_front(t_dlist **lst, t_dlist *new);

/* FIND THE SIZE OF THE DOUBLE LINKED LIST */
int			ft_dlstsize(t_dlist *lst);

/* FUNÇÃO PARA LIMPAR A LINKED LIST */
void		ft_dlstclear(t_dlist **lst, void (*del)(void *));

/* Remove um node especificado da lista */
void		ft_dlstrm_node(t_dlist **lst, t_dlist *old_node);

char		*get_next_line(int fd);
int			ft_putchar(char c);
int			ft_putstr(char *str);
int			ft_extcheck(char *file_name, char *ext);

/**
 * @brief Retrieves the index of the first appearance of c in str.
 * @param str String which c will be searched.
 * @param c The character i'll be searched for in str.
 * @return int Index of the first appearance of c in str.
 */
int			ft_str_find_idx(const char *str, int c);

/**
 * @brief Allocated and returns a duplication of the str of n size.
 * If n is bigger than src length, the latter it'll be considered.
 * @param src String which will be copied.
 * @param n Size of the string it'll be copied from src.
 * @return char* An allocated string from src with n size.
 */
char		*ft_strndup(const char *src, size_t n);

t_ull_type	ft_power(long long number, long int power);
int			ft_nbrsize(t_ull_type nbr, t_ull_type base_n);
int			ft_printf(const char *format, ...);

/*
Count the number of rows in a matrix. The matrix needs to end with a '\0'
*/
int			ft_mtxlen(char **mtx);

/*
Destroy all the content in a matrix
*/
void		ft_destroy_matrix(char **matrix);

/* Same thing as atoi but with bigger capacity of conversion */
long long	ft_atoi_llong(const char *str);

/* Check if the string corresponds to a valid number
 (valid to be converted with atoi for example) */
int			ft_is_numeric(char *str);

/* split a string in two, using idx as delimiter */
char		**ft_split_idx(char const *s, int idx);

#endif
