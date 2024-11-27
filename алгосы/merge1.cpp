#include<iostream>
#include<algorithm>
#include<vector>
#include<chrono>
#include<random>
#include<cmath>

int global_m = 10;

void vstavka_sort(std::vector <int> &random_numbers_vstavka, int left, int right){
    for (int i = left + 1; i <= right; i++){
        int j = i + 1;
        while (j >= left && random_numbers_vstavka[j] > random_numbers_vstavka[i]){
            std::swap(random_numbers_vstavka[j + 1], random_numbers_vstavka[j]);
            j--;
        }
    }
}

void merge_vstavka(std::vector<int> &random_numbers_vstavka, int left, int mid, int right) {
    int size_left = mid - left + 1;
    int size_right = right - mid;

    std::vector<int> L(size_left), R(size_right);

    for (int i = 0; i < size_left; i++)
        L[i] = random_numbers_vstavka[left + i];
    for (int j = 0; j < size_right; j++)
        R[j] = random_numbers_vstavka[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;

    while (i < size_left && j < size_right) {
        if (L[i] <= R[j]) {
            random_numbers_vstavka[k] = L[i];
            i++;
        }
        else {
            random_numbers_vstavka[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < size_left) {
        random_numbers_vstavka[k] = L[i];
        i++;
        k++;
    }

    while (j < size_right) {
        random_numbers_vstavka[k] = R[j];
        j++;
        k++;
    }
}

void merge_vstavka_sort(std::vector<int> &random_numbers_vstavka, int left, int right) {
    if (right - left + 1 <= global_m){
        vstavka_sort(random_numbers_vstavka, left, right);
        return;
    } else {    
        int mid = left + (right - left) / 2;
        merge_vstavka_sort(random_numbers_vstavka, left, mid);
        merge_vstavka_sort(random_numbers_vstavka, mid + 1, right);
        merge_vstavka(random_numbers_vstavka, left, mid, right);
    }
}

int main(){
    std::mt19937 mt(10000);
    std::vector <int> size = {1000, 10000, 100000, 1000000, 1000000};
    for (int i = 0; i < 5; ++i){
        int n = size[i];
        std::vector <int> random_numbers_vstavka(n);
        std::vector <int> clone(n);
        for (int j = 0; j < n; ++j){
            random_numbers_vstavka[j] = mt();
        }
        random_numbers_vstavka = clone;
        int good_m = 0;

        double minim = 10000000000;
        for (int m = 10; m < 200; ++m) {
            global_m = m;
            
            auto start_vstavka = std::chrono::high_resolution_clock::now();
            merge_vstavka_sort(random_numbers_vstavka, 0, n - 1);
            auto end_vstavka = std::chrono::high_resolution_clock::now();
            std::chrono::duration <double, std::milli> duration_vstavka = end_vstavka - start_vstavka;

            std::sort(clone.begin(), clone.end());
            
            std::cout << duration_vstavka.count() << "   " << global_m << std::endl;

            if (minim > duration_vstavka.count()){
                minim = duration_vstavka.count();
                good_m = global_m;
            }
        }
        std::cout << "Наименьшее время достигается при m = " << good_m << ". Если длина массива равна " << n << std::endl;
        int k = 0;
        for(int q = 0; q < n; ++q){
            if (random_numbers_vstavka[q] == clone[q]){
                k += 1;
            }
            if (k == n){
                std:: cout << "Массивы отсортированы правильно" << std::endl;
            }
        }
    }
}
