#include "print.hpp"
#include "MERGE.hpp"

int main(){
    int arr[] = {56, 23, 78, 2, 5, 65, 90, 52};
    const int arr_size = sizeof(arr) / sizeof(arr[0]);

    eshkere::print("Массив до сортировки:", arr, arr_size);

    eshkere::botan::merge_sort(arr, 0, arr_size - 1);

    eshkere::print("Массив после сортировки:", arr, arr_size);

    return 0;
}