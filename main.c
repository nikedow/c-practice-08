#include <stdio.h>
#include "myarrfunc.h"
#define MAX_SIZE 100
int main(void) {
    int arr[MAX_SIZE];
    size_t n = 0, k, m, tn;
    int filled = 0, ch, r, x;
    char c;
    while (1) {
        printf("\na   задать размер массива\n");
        printf("b   заполнить массив\n");
        printf("c   представление массива (значения, адреса)\n");
        printf("d   max_in_range\n");
        printf("e   avg_in_range\n");
        printf("f   count_above_k\n");
        printf("g   выход\n");
        printf("выберите пункт: ");
        r = scanf(" %c", &c);
        if (r == EOF) {
            break;
        }
        while ((ch = getchar()) != '\n' && ch != EOF);
        if (c == 'g') {
            break;
        }
        if (c >= 'c' && c <= 'f' && !filled) {
            printf("сначала задайте размер (a) и заполните массив (b)\n");
            continue;
        }
        switch (c) {
            case 'a':
                printf("введите размер (1-%d): ", MAX_SIZE);
                r = scanf("%zu", &tn);
                if (r == EOF) return 0;
                while ((ch = getchar()) != '\n' && ch != EOF);
                if (r != 1 || tn < 1 || tn > MAX_SIZE) printf("ошибка размера\n");
                else { n = tn; filled = 0; }
                break;
            case 'b':
                if (n == 0) printf("сначала задайте размер (a)\n");
                else if (!fill_array(arr, n)) return 0;
                else { while ((ch = getchar()) != '\n' && ch != EOF); filled = 1; }
                break;
            case 'c':
                print_array(arr, n);
                break;
            case 'd':
            case 'e':
                printf("введите k и m (0-%zu): ", n - 1);
                r = scanf("%zu %zu", &k, &m);
                if (r == EOF) return 0;
                while ((ch = getchar()) != '\n' && ch != EOF);
                if (r != 2 || k > m || m >= n) printf("ошибка диапазона\n");
                else if (c == 'd') printf("максимум: %d\n", max_in_range(arr, n, k, m));
                else printf("среднее: %.2f\n", avg_in_range(arr, n, k, m));
                break;
            case 'f':
                printf("введите k: ");
                r = scanf("%d", &x);
                if (r == EOF) return 0;
                while ((ch = getchar()) != '\n' && ch != EOF);
                if (r != 1) printf("ошибка ввода\n");
                else printf("количество больше %d: %d\n", x, count_above_k(arr, n, x));
                break;
            default:
                printf("неверный пункт меню\n");
        }
    }
    return 0;
}