//
// Created by Bazooh on 17/11/2019.
//

#ifndef PROJETS_LIST_H
#define PROJETS_LIST_H

#include "minesweeper.h";

typedef struct      s_list {
    t_pos           pos;
    struct s_list   *next;
}                   t_list;

void	addPos(t_list *elem, t_pos pos);
void    deleteList(t_list *elem);
t_list  *deleteGoNext(t_list *elem);

#endif //PROJETS_LIST_H
