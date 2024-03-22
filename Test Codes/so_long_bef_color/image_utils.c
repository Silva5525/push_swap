#include "animate.h"

#include "MLX42/include/MLX42/MLX42.h"

#define BPP sizeof(int32_t)

int32_t mlx_get_pixel(mlx_image_t* image, uint32_t x, uint32_t y);

static int put_pixel_valid(mlx_image_t* img, uint32_t x, uint32_t y)
{
    return (x < img->width && y < img->height);
}

void  put_img_to_img(mlx_image_t* dst, mlx_image_t* src, int x, int y)
{
  int i;
  int j;

  i = 0;
  while(i < src->width) {
    j = 0;
    while (j < src->height) {
      if (put_pixel_valid(src, i, j))
        mlx_put_pixel(dst, x + i, y + j, mlx_get_pixel(src, i, j));
      j++;
    }
    i++;
  }
}

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*hold;

	if (!lst || !*lst || !del)
		return ;
	while (*lst)
	{
		hold = *lst;
		*lst = (*lst)->next;
		if (hold -> content && del)
			del(hold -> content);
		free(hold);
	}
	*lst = NULL;
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*end;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	end = *lst;
	while (end -> next != NULL)
	{
		end = end -> next;
	}
	end -> next = new;
	return ;
}

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	if (new_node)
	{
		new_node -> content = content;
		new_node -> next = NULL;
	}
	return (new_node);
}

int	ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*current;

	size = 0;
	current = lst;
	while (current != NULL)
	{
		size++;
		current = current->next;
	}
	return (size);
}

static int get_rgba(int r, int g, int b, int a) 
{
  return (r << 24 | g << 16 | b << 8 | a);
}
/**
 * In MLX42 Colors are as follows:
 * 0000 0000 A (1st byte) -> uint8_t because it's 8 bits
 * 0000 0000 R (2nd byte)
 * 0000 0000 G (3rd byte)
 * 0000 0000 B (4th byte)
 **/

int32_t mlx_get_pixel(mlx_image_t* image, uint32_t x, uint32_t y)
{
  if (x > image->width || y > image->height)
    return 0xFF000000;
  uint8_t* pixelstart = image->pixels + (y * image->width + x) * BPP;
  return get_rgba(*(pixelstart), *(pixelstart + 1),
    * (pixelstart + 2), *(pixelstart + 3));
}

void	ft_lstiter_param(t_list *lst, void (*f)(void *, void *), void * ptr)
{
	t_list	*temp;

	temp = lst;
	while (temp != NULL)
	{
		f(temp->content, ptr);
		temp = temp->next;
	}
}

t_list		*ft_lstget(t_list *lst, int index)
{
	t_list	*n;
	int i;

	i = 0;
	n = lst;
	if (n == NULL)
		return (NULL);
	if (n->next == NULL)
		return (n);
	while (n != NULL)
	{
		if (i >= index)
			return (n);
		n = n->next;
		i++;
	}
	return (NULL);
}