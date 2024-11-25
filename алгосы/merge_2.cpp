#include <iostream>
#include <vector>

int merge(std::vector<int> &arr, int left, int mid, int right) {
    int size_left = mid - left + 1;
    int size_right = right - mid;

    std::vector<int> L(size_left), R(size_right);

    for (int i = 0; i < size_left; i++) { 
        L[i] = arr[left + i];
    }
    for (int j = 0; j < size_right; j++) {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0;
    int k = left;
    int count = 0;
    while (i < size_left && j < size_right) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
            count += (size_left - i);
        }
        k++;
    }

    while (i < size_left) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < size_right) {
        arr[k] = R[j];
        j++;
        k++;
    }
    return count;
}



int merge_sort(std::vector<int> &arr, int left, int right) {
    int otvet = 0;
    if (left >= right) {
        return otvet;
    }
    int mid = left + (right - left) / 2;
    otvet += merge_sort(arr, left, mid);
    otvet += merge_sort(arr, mid + 1, right);
    otvet += merge(arr, left, mid, right);
    return otvet;
}



int main() {
    int n; std::cin >> n;
    std::vector<int> arr(n); std::vector<int> arr_clone(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    arr_clone = arr;

    int k = 0;
    int pari = merge_sort(arr, 0, n - 1);
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            if (arr_clone[i] > arr_clone[j]){
                k += 1;
            }
        }
    }
    if (k == pari) {
        std::cout << "Интересных пар в массиве " << pari << std::endl;
    }
}
