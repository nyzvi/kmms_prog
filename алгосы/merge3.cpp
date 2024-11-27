#include <iostream> 
#include <vector> 
 
int merge(std::vector <int> &arr, int left, int mid, int right, unsigned int s) { 
    int size_left = mid - left + 1; 
    int size_right = right - mid; 
 
    std::vector <int> L(size_left); 
    std::vector <int> R(size_right); 
 
    for (int i = 0; i < size_left; i++) { 
        L[i] = arr[left + i]; 
    } 
    for (int i = 0; i < size_right; i++) { 
        R[i] = arr[mid + i + 1]; 
    } 
 
    int i = 0, j = 0; 
    int k = left; 
    while (i < size_left && j < size_right) { 
        if (L[i] <= R[j]) { 
            arr[k++] = L[i++]; 
        } else { 
            arr[k++] = R[j++]; 
        } 
    } 
 
    while (i < size_left) { 
        arr[k++] = L[i++]; 
    } 
 
    while (j < size_right) { 
        arr[k++] = R[j++]; 
    } 
 
    i = left; 
    j = right; 
    int count = 0; 
    while (i < j) { 
        int sum = arr[i] + arr[j]; 
        if (sum == s) { 
            std::cout << "Найдена пара: (" << arr[i] << ", " << arr[j] << ")" << std::endl; 
            count++; 
            i++; 
            j--; 
        } else { 
            if (sum < s) { 
                i++; 
            } else { 
                j--; 
            } 
        } 
    } 
    return count; 
} 
 
int merge_sort(std::vector <int> &arr, int left, int right, unsigned s) { 
    int otvet = 0; 
    if (left >= right) { 
        return otvet; 
    } 
    int mid = left + (right - left) / 2; 
    otvet += merge_sort(arr, left, mid, s); 
    otvet += merge_sort(arr, mid + 1, right, s); 
    otvet += merge(arr, left, mid, right, s); 
    return otvet; 
} 
 
int main() { 
    int n, s = 0; 
    std::cin >> n; 
    std::cin >> s; 
    std::vector <int> arr(n); 
 
    for (int i = 0; i < n; i++) { 
        std:: cin >> arr[i]; 
    } 
 
    int count = 0; 
    for (int i = 0; i < n; i++) { 
        for (int j = i + 1; j < n; j++){ 
            if (arr[i] + arr[j] == s) { 
                count++; 
            } 
        } 
    } 
 
    int count_merge = merge_sort(arr, 0, n-1, s); 
 
    if (count_merge == 0) { 
        std::cout << "Пары не найдены" << std::endl; 
    } else if (count_merge == count){ 
        std::cout << "Все пары были найдены" << std::endl; 
    } 
}
