#include "sort.h"

void iter_sort(iterator_if_t *p_if, iterator_t begin, iterator_t end, compare_t compare, swap_t swap)
{
	int flag = 1;
	iterator_t it1 = begin;
	iterator_t it2 = end;
	iterator_t it_next;
	
	if(begin == end)
	{
		return;
	}

	while(it2 != begin)
	{
		it1 = begin;
		flag = 1;
		while(it1 != it2)
		{
			it_next = it1;
			iterator_next(p_if, &it_next);
			if(compare(it1, it_next) > 0)
			{
				swap(it1, it_next);
				flag = 0;
			}
			it1 = it_next;
		}
		if(flag) return;
		iterator_prev(p_if, &it2);
	} 
}


