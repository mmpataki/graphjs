#ifndef SL_LIST_INCLUDED
#define SL_LIST_INCLUDED

#include<stdlib.h>

struct s_list_node {
	void *data;
	struct s_list_node *next;
};

struct s_list_head {
	struct s_list_node *first, *last;
};

struct s_list_head *new_s_list_head();
struct s_list_node *new_slist_node(void *data);
void s_list_add(struct s_list_head *lst, void *data);

#define foreach_sl_list(n, l) for(n=l->first; n; n=n->next)
			

#endif // SL_LIST_INCLUDED
