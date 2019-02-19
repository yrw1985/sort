#include "iterator.h"

void iterator_if_init(iterator_if_t *p_if, iterator_next_t pfn_next, iterator_prev_t pfn_prev)
{
	p_if->pfn_next = pfn_next;
	p_if->pfn_prev = pfn_prev;
}

void iterator_next(iterator_if_t *p_if, iterator_t *p_iter)
{
	p_if->pfn_next(p_iter);
}

void iterator_prev(iterator_if_t *p_if, iterator_t *p_iter)
{
	p_if->pfn_prev(p_iter);
}

void iterator_foreach(iterator_if_t *p_if, iterator_t begin, iterator_t end, visit_t visit, void *p_arg)
{
	iterator_t it = begin;
	while(it != end)
	{
		if (visit(p_arg, it) < 0) 
		{
			return;
		}
		iterator_next(p_if, &it);
	}
	visit(p_arg, it);
}
