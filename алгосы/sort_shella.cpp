#include<algorithm>
#include<chrono>
#include<iostream>
#include<random>
#include<vector>


void shell_sort (std::vector <int> gladkie_shella, std::vector <int> &random_numbers_shella, std::vector <int> size, int i){
    for(int b : gladkie_shella){
        for (int j = b; j < i; j++) {
            int temp = random_numbers_shella[i];
            int n = j;
            for(;n >= b && random_numbers_shella[n - b] > temp;n -= b){
                random_numbers_shella[n] = random_numbers_shella[n - b];
                }
            random_numbers_shella[n] = temp;
        }
    }
}


std::vector <int> gladkie(int n){
    int k = 0;
    std::vector<int> glad;
    std::vector<int> glad_reverse;
    int pow3 = 1;
    while (pow3 <= n){
        int pow2 = pow3;
        while (pow2 <= n){
            glad.push_back(pow2);
            pow2 *= 2;
            k++;
        }
        pow3 *= 3;
    }
    sort(glad.begin(),glad.end());
    int c = 0;
    for (int b = 0; b <= k; ++b){
        glad_reverse[c] = glad[k-c-1];
        ++c;
    }
    return glad_reverse;
}


int main(){
    std::mt19937 mt(10000);
    std::vector <int> size = {1000, 10000, 100000, 1000000};
    for (int i = 0; i < 4; i++){
        std::vector <int> random_numbers_shella(size[i]);
        std::vector <int> random_numbers_sort(size[i]);
         for(int j = 0; j < size[i]; j++){
            random_numbers_shella[j] = mt();
        }
        std::vector <int> gladkie_shella = gladkie(size[i]);
        random_numbers_sort = random_numbers_shella;


        auto start_shella = std::chrono::high_resolution_clock::now();
        shell_sort(gladkie_shella, random_numbers_shella, size, i);
        auto end_shella = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> duration_shella = end_shella - start_shella;
        std::cout << "Время выполнения с помощью сортировки Шелла: " << duration_shella.count() << "\n";


        auto start_sort = std::chrono::high_resolution_clock::now();
        std::sort(random_numbers_sort.begin(), random_numbers_sort.end());
        auto end_sort = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> duration_sort = end_sort - start_sort;
        std::cout << "Время выполнения с помощью встроенной сортировки: " << duration_sort.count() << "\n";
        for (int j = 0; j <= size[i]; ++j){
            if (random_numbers_shella[j] != random_numbers_sort[j]){
                std:: cout << "Не правильно отсортировано" << "\n";
                break;
            }
        }
        std::cout << "";
    }
}
