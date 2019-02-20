#include <stdio.h>
#include "dlist.h"
#include "sort.h"
#include "iterator.h"

typedef struct _dlist_int
{
	dlist_node_t node;
	int data; 
} dlist_int_t;

static void __dlist_iterator_next(iterator_t *p_iter)
{
	*p_iter = ((dlist_node_t *)*p_iter)->p_next;
}

static void __dlist_iterator_prev(iterator_t *p_iter)
{
	*p_iter = ((dlist_node_t *)*p_iter)->p_prev;
}

static int __visit(void *p_arg, iterator_t it)
{
	printf("%d  ", ((dlist_int_t *)it)->data);
	return 0;
}

static int __compare(iterator_t it1, iterator_t it2)
{
	return ((dlist_int_t *)it1)->data - ((dlist_int_t *)it2)->data;
}

static void __swap(iterator_t it1, iterator_t it2)
{
	int data = ((dlist_int_t *)it1)->data;
	((dlist_int_t *)it1)->data = ((dlist_int_t *)it2)->data;
	((dlist_int_t *)it2)->data = data;
}

int main()
{
	iterator_if_t iterator_if;
	dlist_head_t head;
	dlist_int_t node[5];
	int i;
	int a[] = {55, 33, 22, 44, 11};
	
	dlist_init(&head);
	
	for(i = 0; i < 5; i ++)
	{
		node[i].data = a[i]; 
		dlist_add_tail(&head, &(node[i].node));
	}
	
	iterator_if_init(&iterator_if, __dlist_iterator_next, __dlist_iterator_prev);
	
	printf("\nBefore bubble sort: \n");	
	iterator_foreach(&iterator_if, dlist_begin_get(&head), dlist_end_get(&head), __visit, NULL); 
	
	iter_sort(&iterator_if, dlist_begin_get(&head), dlist_end_get(&head), __compare, __swap);
	
	printf("\nAfer bubble sort: \n");	
	iterator_foreach(&iterator_if, dlist_begin_get(&head), dlist_end_get(&head), __visit, NULL); 
	
	return 0;
}
