#include <stdio.h>

int mx_strlen(const char *s) {
    int i = 0;
    while (s[i] != '\0') {
        i++;
    }
    return i;
}

void mx_swap_str(char **s1, char **s2) {
    char *temp = *s1;
    *s1 = *s2;
    *s2 = temp;
}

int mx_quicksort(char **arr, int left, int right) {
    int count = 0;
    if (arr == NULL || *arr == NULL) {
        return -1;
    }
    if (left < right) {
        int low = left;
        int high = right;
        int pivot = (high + low) / 2;
        while (low <= high) {
            while (mx_strlen(arr[low]) < mx_strlen(arr[pivot])) {
                low++;
            }
            while (mx_strlen(arr[high]) > mx_strlen(arr[pivot])) {
                high--;
            }
            if(low <= high) {
                if(mx_strlen(arr[low]) > mx_strlen(arr[high])) {
                    count++;
                    mx_swap_str(&arr[low], &arr[high]);
                }
                low++;
                high--;
            }
        }
        count += mx_quicksort(arr, left, high);
        count += mx_quicksort(arr, low, right);
    }
    return count;
}

int main() {
    char *arr[] = {"Michelangelo", "Donatello", "Leonardo", "Raphael"};
    printf("%d\n", mx_quicksort(arr, 0, 3));
    for (int i = 0; i <= 3; i++) {
        printf("%s ", arr[i]);
    }
    return 0;
}
