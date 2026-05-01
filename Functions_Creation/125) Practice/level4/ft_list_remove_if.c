void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
    while(*begin_list)
    {
        if (!cmp((*begin_list)->data, data_ref))
            *begin_list = (*begin_list)->next;
        else
            begin_list = &(*begin_list)->next;
    }
}

void ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
    while(begin_list)
    {
        f(begin_list->data);
        begin_list = begin_list->next;
    }
}

ft_list_foreach(sdls,
    ft_list_remove_if);