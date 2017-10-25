/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmhla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 00:49:44 by emmmhla           #+#    #+#             */
/*   Updated: 2017/06/18 13:07:42 by emmmhla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# include <pthread.h>
# include <unistd.h>
# include <sys/mman.h>
# include <sys/resource.h>
# include <sys/time.h>
# include "libft.h"
# include "ft_printf.h"

# define FREE_BLOCK 0
# define USED_BLOCK 1

# define RESIZE_OK 2
# define RESIZE_FAIL 3

# define TINY_MAX 100
# define SMALL_MAX 1000
# define MEDIUM_MAX 5000

typedef struct			s_header
{
	size_t				size;
	size_t				used;
	int					is_free;
	struct s_header		*next;
}						t_header;

typedef struct			s_mem_chain
{
	t_header			*head;
	t_header			*tail;
}						t_mem_chain;

typedef struct			s_book_keeper
{
	t_mem_chain			tiny;
	t_mem_chain			small;
	t_mem_chain			medium;
	t_mem_chain			large;
}						t_book_keeper;

extern pthread_mutex_t	g_global_lock;
extern t_book_keeper	g_book_keeper;

void					ft_free(void *ptr);
void					print_mem_chain(void *chain, char *name);
void					show_alloc_mem(void);
void					divide_zone(void **head, void **tail, size_t size);
void					free_chains(void);

void					*ft_malloc(size_t size);
void					*ft_realloc(void *ptr, size_t size);
void					*map_block(size_t size);
void					*allocate_new_block(size_t size, t_mem_chain *chain);
void					*allocate_new_zone(size_t size);
void					*allocate_tiny(size_t size);
void					*allocate_small(size_t size);
void					*allocate_medium(size_t size);
void					*allocate_large(size_t size);

size_t					get_aligned_size(size_t size);
size_t					get_actual_zone_size(size_t size);

t_header				*get_free_block(size_t size, t_mem_chain chain);

#endif
