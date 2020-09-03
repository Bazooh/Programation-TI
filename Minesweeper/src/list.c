
#include "list.h"

void	addPos(t_list *elem, t_pos pos) {
    t_list *new;

    while(elem->next) {
        elem = elem->next;
    }

    if (!(new = (t_list*)malloc(sizeof(t_list)))) {
        return ;
    }

    new->pos = pos;
    new->next = NULL;

    elem->next = new;
}

void    deleteList(t_list *elem) {
    t_list *tmp;

    while (elem) {
        tmp = elem->next;
        free(elem);
        elem = tmp;
    }
}

t_list  *deleteGoNext(t_list *elem) {
    t_list *tmp = elem->next;
    free(elem);
    return (tmp);
}
