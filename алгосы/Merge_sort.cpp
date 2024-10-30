#include<iostream>
#include<vector>
#include<chrono>
#include<random>
#include<cmath>

int global_m = 10;

void merge(std::vector <int> &random_numbers_merge, int left, int mid, int right) {
    int size_left = mid - left + 1;
    int size_right = right - mid;

    std::vector <int> L(size_left), R(size_right);

    for (int i = 0; i < size_left; i++)
        L[i] = random_numbers_merge[left + i];
    for (int j = 0; j < size_right; j++)
        R[j] = random_numbers_merge[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;

    while (i < size_left && j < size_right) {
        if (L[i] <= R[j]) {
            random_numbers_merge[k] = L[i];
            i++;
        }
        else {
            random_numbers_merge[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < size_left) {
        random_numbers_merge[k] = L[i];
        i++;
        k++;
    }

    while (j < size_right) {
        random_numbers_merge[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(std::vector<int> &random_numbers_merge, int left, int right) {
    if (left >= right)
        return;
    int mid = left + (right - left) / 2;
    merge_sort(random_numbers_merge, left, mid);
    merge_sort(random_numbers_merge, mid + 1, right);
    merge(random_numbers_merge, left, mid, right);
}

void vstavka_sort(std::vector <int> &random_numbers_vstavka, int left, int right){
    for (int i = left + 1; i <= right; i++){
        int key = random_numbers_vstavka[i];
        int j = i - 1;
        while (j >= left && random_numbers_vstavka[j] > key){
            random_numbers_vstavka[j + 1] = random_numbers_vstavka[j];
            j--;
        }
        random_numbers_vstavka[j + 1] = key;
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
    if (left >= right)
        return;
    
    if (right - left + 1 <= global_m){
        vstavka_sort(random_numbers_vstavka, left, right);
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

    for (int i = 0; i < 4; i++){
        std::vector <int> random_numbers_merge(size[i]);
        std::vector <int> random_numbers_vstavka(size[i]);
        for(int j = 0; j < size[i]; j++){
            random_numbers_merge[j] = mt();
        }
        random_numbers_vstavka = random_numbers_merge;
        
        double minim = 1000000000;
        int maxim = -1000000;
        for (int m = size[i] / 2; m > 0; --m){
            global_m = m;

            auto start_merge = std::chrono::high_resolution_clock::now();
            merge_sort(random_numbers_merge, 0, size[i] - 1);
            auto end_merge = std::chrono::high_resolution_clock::now();
            std::chrono::duration <double, std::milli> duration_merge = end_merge - start_merge;

            auto start_vstavka = std::chrono::high_resolution_clock::now();
            merge_vstavka_sort(random_numbers_vstavka, 0, size[i] - 1);
            auto end_vstavka = std::chrono::high_resolution_clock::now();
            std::chrono::duration <double, std::milli> duration_vstavka = end_vstavka - start_vstavka;
            
            if (minim > std::abs(duration_vstavka.count() - duration_merge.count())) {
                minim = std::abs(duration_vstavka.count() - duration_merge.count());
                maxim = m;
            }
        }
        std::cout << "Минимальная разница во времени достигается при m = " << maxim << ". Если размер масива равен " << size[i] << "\n";
        std::cout << "\n";
    }
}
