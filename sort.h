#pragma once

#include "iterator.h"

typedef int (*compare_t)(iterator_t it1, iterator_t it2);
typedef void (*swap_t)(iterator_t it1, iterator_t it2);

void iter_sort(iterator_if_t *p_if, iterator_t begin, iterator_t end, compare_t compare, swap_t swap);
