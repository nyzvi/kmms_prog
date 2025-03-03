#include "MERGE.hpp"

void eshkere::botan::merge(int* const arr, int left, int mid, int right){
    int size_left = mid - left + 1;
    int size_right = right - mid;

    int L[size_left];
    int R[size_right];

    for (int i = 0; i < size_left; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < size_right; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;

    while (i < size_left && j < size_right) {
        if (L[i] <= R[j]) {
            arr[k] = L[i++];
        }
        else {
            arr[k] = R[j++];
        }
        k++;
    }

    while (i < size_left) {
        arr[k++] = L[i++];
    }

    while (j < size_right) {
        arr[k++] = R[j++];
    }
}

void eshkere::botan::merge_sort(int* const arr, int left, int const right){
    if (left >= right){
        return;
    } else {    
        int mid = left + (right - left) / 2;
        eshkere::botan::merge_sort(arr, left, mid);
        eshkere::botan::merge_sort(arr, mid + 1, right);
        eshkere::botan::merge(arr, left, mid, right);
    }
}