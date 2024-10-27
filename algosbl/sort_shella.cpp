#include<algorithm>
#include<chrono>
#include<iostream>
#include<random>
#include<vector>


void shell_sort (std::vector <int> shell, std::vector <int> random_num, std::vector <int> size, int i){
    for(int b : shell){
        for (int j = b; j < i; j++) {
            int temp = random_num[i];
            int n = j;
            for(;n >= b && random_num[n-b] > temp;n -= b){
                random_num[n] = random_num[n-b];
                }
            random_num[n] = temp;
        }
    }
}


std::vector<int> gladkie(int n){
    int k = 0;
    std::vector<int> glad;
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
    return glad; 
}


int main(){
    std::mt19937 mt(10000);
    std::vector <int> size = {1000, 10000, 100000, 1000000};
    for (int i=0;i<4;i++){
        std::vector <int> random_numbers(size[i]);
         for(int j=0;j<size[i];j++){
            random_numbers[j] = mt();
        }
        std::vector<int> gladkie_shella = gladkie(size[i]);


        auto start_shella = std::chrono::high_resolution_clock::now();
        shell_sort(gladkie_shella, random_numbers, size, i);
        auto end_shella = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> duration_shella = end_shella - start_shella;
        std::cout << "Время выполнения с помощью сортировки Шелла: " << duration_shella.count() << "\n";


        auto start_sort = std::chrono::high_resolution_clock::now();
        std::sort(random_numbers.begin(), random_numbers.end());
        auto end_sort = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> duration_sort = end_sort - start_sort;
        std::cout << "Время выполнения с помощью встроенной сортировки: " << duration_sort.count() << "\n";
    }
}
