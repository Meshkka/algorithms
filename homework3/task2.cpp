#include <iostream>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int* arr, int low, int high) {
    int pivot = arr[high];

    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);

    return i + 1;
}

void quickSortHelper(int* arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSortHelper(arr, low, pi - 1);
        quickSortHelper(arr, pi + 1, high);
    }
}

void quick_sort(int* arr, int size) {
    if (size <= 1) return;
    quickSortHelper(arr, 0, size - 1);
}

void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void testQuickSort(int* arr, int size, const char* testName) {
    std::cout << testName << ":" << std::endl;
    std::cout << "До сортировки:    ";
    printArray(arr, size);

    quick_sort(arr, size);

    std::cout << "После сортировки: ";
    printArray(arr, size);
    std::cout << std::endl;
}

int main() {
    setlocale(LC_ALL, "RU");
    int arr1[] = { 3, 43, 38, 29, 18, 72, 57, 61, 2, 33 };
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    testQuickSort(arr1, size1, "Тест 1");

    int arr2[] = { 88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74 };
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    testQuickSort(arr2, size2, "Тест 2");

    int arr3[] = { 24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62 };
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    testQuickSort(arr3, size3, "Тест 3");

    return 0;
}