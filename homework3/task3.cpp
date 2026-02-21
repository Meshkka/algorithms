#include <iostream>

void count_sort(int* arr, int size) {
    if (size <= 1) return;

    const int MIN_VALUE = 10;
    const int MAX_VALUE = 24;
    const int RANGE = MAX_VALUE - MIN_VALUE + 1;

    int* count = new int[RANGE]();

    for (int i = 0; i < size; i++) {
        if (arr[i] >= MIN_VALUE && arr[i] <= MAX_VALUE) {
            count[arr[i] - MIN_VALUE]++;
        }
        else {
            std::cout << "Предупреждение: значение " << arr[i]
                << " вне диапазона [10, 24]!" << std::endl;
        }
    }

    int index = 0;
    for (int i = 0; i < RANGE; i++) {
        for (int j = 0; j < count[i]; j++) {
            arr[index++] = i + MIN_VALUE;
        }
    }

    delete[] count;
}

void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void testCountSort(int* arr, int size, const char* testName) {
    std::cout << testName << ":" << std::endl;
    std::cout << "До сортировки:    ";
    printArray(arr, size);

    count_sort(arr, size);

    std::cout << "После сортировки: ";
    printArray(arr, size);
    std::cout << std::endl;
}

int main() {
    setlocale(LC_ALL, "RU");
    int arr1[] = { 19, 14, 22, 22, 17, 22, 13, 21, 20, 24,
                  18, 10, 17, 16, 17, 20, 22, 11, 20, 16,
                  14, 13, 10, 22, 18, 14, 16, 24, 19, 17 };
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    testCountSort(arr1, size1, "Тест 1");

    int arr2[] = { 16, 17, 14, 20, 22, 20, 17, 22, 16, 19,
                  23, 24, 20, 22, 21, 18, 14, 16, 17, 21,
                  10, 11, 19, 23, 11, 11, 17, 17, 11, 21,
                  17, 11, 17, 16, 12, 11, 16, 22, 23, 16 };
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    testCountSort(arr2, size2, "Тест 2");

    int arr3[] = { 21, 15, 19, 18, 23, 12, 18, 18, 19, 23,
                  12, 20, 15, 22, 21, 18, 19, 20, 12, 16,
                  20, 14, 17, 13, 10, 23, 19, 14, 10, 22,
                  19, 12, 24, 23, 22, 15, 13, 22, 18, 18,
                  11, 23, 24, 17, 10 };
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    testCountSort(arr3, size3, "Тест 3");

    return 0;
}