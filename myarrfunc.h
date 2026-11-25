#ifndef MYARRFUNC_H
#define MYARRFUNC_H
#include <stddef.h>
int fill_array(int *arrptr, size_t n);
void print_array(int *arrptr, size_t n);
int max_in_range(int *arrptr, size_t n, size_t k, size_t m);
double avg_in_range(int *arrptr, size_t n, size_t k, size_t m);
int count_above_k(int *arrptr, size_t n, int k);
#endif
