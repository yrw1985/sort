#include "dlist.h"

int dlist_init(dlist_head_t *p_head)
{
	if (p_head == NULL)
	{
		return -1;
	}
	p_head -> p_next = p_head;
	p_head -> p_prev = p_head;
	return 0;
}

int dlist_add(dlist_head_t *p_head, dlist_node_t *p_pos, dlist_node_t *p_node)
{
}

int dlist_add_tail(dlist_head_t *p_head, dlist_node_t *p_node)
{
	if (p_head == NULL)
	{
		return -1;
	}
	p_node -> p_prev = p_head->p_prev; 
	p_node -> p_next = p_head;  
	p_head -> p_prev->p_next = p_node;  
	p_head -> p_prev = p_node; 

	return 0;
}

int dlist_add_head(dlist_head_t *p_head, dlist_node_t *p_node)
{
	return 0;
}

int dlist_del(dlist_head_t *p_head, dlist_node_t *p_node)
{
	return 0;
}

dlist_node_t *dlist_prev_get(dlist_head_t *p_head, dlist_node_t *p_pos)
{
	if (p_head != NULL)
	{
		return p_pos->p_prev;
	}
	return NULL;
}

dlist_node_t *dlist_next_get(dlist_head_t *p_head, dlist_node_t *p_pos)
{
	if (p_head != NULL)
	{
		return p_pos->p_next;
	}
	return NULL;
}

dlist_node_t *dlist_tail_get(dlist_head_t *p_head)
{
	if (p_head != NULL)
	{
		return p_head->p_prev;
	}
	return NULL;
}

dlist_node_t *dlist_begin_get(dlist_head_t *p_head)
{
	if (p_head != NULL)
	{
		return p_head->p_next;
	}
	return NULL;
}

dlist_node_t *dlist_end_get(dlist_head_t *p_head)
{
	if (p_head != NULL)
	{
		return p_head->p_prev;
	}
	return NULL;
}




