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

    while (i < size_left && j < size_right) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
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
}

void merge_sort(std::vector<int> &arr, int left, int right) {
    if (left >= right)
        return;
    int mid = left + (right - left) / 2;
    merge_sort(arr, left, mid);
    merge_sort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

void pari(std::vector<int> &arr, int s, int n){
    merge_sort(arr,0,n-1);
    int l = 0; 
    int r = n - 1;
    int flag = 0;
    while (l < r){
        int sum = arr[l] + arr[r];
        if (sum == s){
            std:: cout << "Пара найдена: " << arr[l] << " и " << arr[r] << std::endl;
            l++;
            r--;
            flag = 1;
        } else {
            if (sum < s){
                l++;
            } else {
                r--;
            }
        }
    }
    if (flag == 0){
        std::cout << "Пары не найдены." << std::endl;
    }
}

int main(){
    std::mt19937 mt(10000);
    int n; std:: cin >> n;
    int s; std:: cin >> s;
    std::vector <int> arr(n);
    for (int i = 0; i < n;++i){
        arr[i] = mt();
    }
    pari(arr, s, n);
}
