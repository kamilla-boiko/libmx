#include "libmx.h"

int mx_quicksort(char **arr, int left, int right) {
    int count = 0;
    char pivot = arr[(right - left) / 2];
    int i, j;
    for (i = left, j = rigth - 1; ; i++, j--) {
        while (mx_strlen(arr[i]) < mx_strlen(pivot)) {
            i++;
        }
        while (mx_strlen(arr[j]) > mx_strlen(pivot)) {
            j--;
        }
        if (i >= j) {
            break;
        }
        mx_swap_str(arr[i], arr[j]);
        count++;
    }
    mx_quicksort(arr, left, pivot - 1);
    mx_quicksort(arr, pivot + 1, right);
    }
    return count;
}
