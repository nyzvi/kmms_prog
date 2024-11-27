#include <iostream>
#include <vector>
#include <random>
#include <chrono>

void create_drevo(std::vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 3 * i + 1;
    int middle = 3 * i + 2;
    int right = 3 * i + 3;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (middle < n && arr[middle] > arr[largest]) {
        largest = middle;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        create_drevo(arr, n, largest);
    }
}

void heap_sort(std::vector<int>& arr) {
    int n = arr.size();

    for (int i = n / 3; i >= 0; --i) {
        create_drevo(arr, n, i);
    }

    for (int i = n - 1; i > 0; --i) {
        std::swap(arr[0], arr[i]);
        create_drevo(arr, i, 0);
    }
}

int main() {
    std::mt19937 mt(10000);
    std::vector <int> size = {1000, 10000, 100000, 1000000, 10000000, 100000000};
    for (int n : size) {
        std::vector <int> arr(n);
        std::vector <int> clone(n);
        for (int j = 0; j < n; j++) {
            arr[j] = mt();
        }
        clone = arr;

        auto start = std::chrono::high_resolution_clock::now();
        heap_sort(arr);
        auto end = std::chrono::high_resolution_clock::now();;
        std::chrono::duration <double, std::milli> duration = end - start;

        std::sort(clone.begin(), clone.end());

        if (std::equal(arr.begin(), arr.end(), clone.begin())) {
            std:: cout << "Размер: " << n << " , время сортировки " << duration.count() << std::endl;
        }
    }
}
