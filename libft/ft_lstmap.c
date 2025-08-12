#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*new;
	void	*cnt;

	result = NULL;
	while (lst)
	{
		cnt = f(lst->content);
		new = ft_lstnew(cnt);
		if (!new)
		{
			del(cnt);
			ft_lstclear(&result, del);
			return (NULL);
		}
		ft_lstadd_back(&result, new);
		lst = lst->next;
	}
	return (result);
}
