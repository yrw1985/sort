#pragma once

typedef void *iterator_t;
typedef void (*iterator_next_t)(iterator_t *p_iter);
typedef void (*iterator_prev_t)(iterator_t *p_iter);
typedef int (*visit_t)(void *p_arg, iterator_t it);

typedef struct _iterator_if
{
	iterator_next_t pfn_next;
	iterator_prev_t pfn_prev; 
} iterator_if_t;


void iterator_if_init(iterator_if_t *p_if, iterator_next_t pfn_next, iterator_prev_t pfn_prev);
void iterator_next(iterator_if_t *p_if, iterator_t *p_iter);
void iterator_prev(iterator_if_t *p_if, iterator_t *p_iter);
void iterator_foreach(iterator_if_t *p_if, iterator_t begin, iterator_t end, visit_t visit, void *p_arg);

