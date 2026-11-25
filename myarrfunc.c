#include "myarrfunc.h"
#include <stdio.h>
#include <limits.h>
int fill_array(int *arrptr, size_t n) {
    for (size_t i = 0; i < n; i++) {
        printf("arr[%zu] = ", i);
        int res = scanf("%d", arrptr + i);
        if (res == EOF) {
            return 0;
        }
        while (res == 0) {
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF);
            printf("ошибка ввода arr[%zu] = ", i);
            res = scanf("%d", arrptr + i);
            if (res == EOF) {
                return 0;
            }
        }
    }
    return 1;
}
void print_array(int *arrptr, size_t n) {
    for (size_t i = 0; i < n; i++) {
        printf("элемент %zu: значение = %d, адресс = %p\n", i, *(arrptr + i), (void *)(arrptr + i));
    }
}
int max_in_range(int *arrptr, size_t n, size_t k, size_t m) {
    if (arrptr == NULL || n == 0 || k > m || m >= n) {
        return INT_MIN;
    }
    int max_val = *(arrptr + k);
    for (size_t i = k + 1; i <= m; i++) {
        if (*(arrptr + i) > max_val) {
            max_val = *(arrptr + i);
        }
    }
    return max_val;
}
double avg_in_range(int *arrptr, size_t n, size_t k, size_t m) {
    if (arrptr == NULL || n == 0 || k > m || m >= n) {
        return 0.0;
    }
    long long sum = 0;
    for (size_t i = k; i <= m; i++) {
        sum += *(arrptr + i);
    }
    return (double)sum / (double)(m - k + 1);
}
int count_above_k(int *arrptr, size_t n, int k) {
    if (arrptr == NULL || n == 0) {
        return -1;
    }
    int count = 0;
    for (size_t i = 0; i < n; i++) {
        if (*(arrptr + i) > k) {
            count++;
        }
    }
    return count;
}