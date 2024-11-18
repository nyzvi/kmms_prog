#include<iostream>
#include<vector>
#include<random>
#include<cmath>

void merge(std::vector <int> &arr, int left, int mid, int right) {
    int size_left = mid - left + 1;
    int size_right = right - mid;

    std::vector <int> L(size_left), R(size_right);

    for (int i = 0; i < size_left; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < size_right; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;
    int count;
    while (i < size_left && j < size_right) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
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

void merge_sort(std::vector<int> &arr, int left, int right) {
    int otvet;
    if (left >= right)
        return otvet;
    int mid = left + (right - left) / 2;
    otvet += merge_sort(arr, left, mid);
    otvet += merge_sort(arr, mid + 1, right);
    onvet += merge(arr, left, mid, right);
}
int main(){
    int n; std:: cin >> n;
    std:: vector <int> arr(n);
    for (int i = 0; i < n;++i){
        std:: cin >> arr[i];
    }
    std::cout << merge_sort(arr, 0, n - 1) << std::endl;
}
