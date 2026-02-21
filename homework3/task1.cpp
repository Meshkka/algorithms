#include <iostream>

void merge(int* arr, int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    int* leftArr = new int[n1];
    int* rightArr = new int[n2];

    for (int i = 0; i < n1; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        rightArr[j] = arr[middle + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        }
        else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }

    delete[] leftArr;
    delete[] rightArr;
}

void mergeSortHelper(int* arr, int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        mergeSortHelper(arr, left, middle);
        mergeSortHelper(arr, middle + 1, right);

        merge(arr, left, middle, right);
    }
}

void merge_sort(int* arr, int size) {
    if (size <= 1) return;
    mergeSortHelper(arr, 0, size - 1);
}

void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void testMergeSort(int* arr, int size) {
    std::cout << "До сортировки:    ";
    printArray(arr, size);

    merge_sort(arr, size);

    std::cout << "После сортировки: ";
    printArray(arr, size);
    std::cout << std::endl;
}

int main() {
    setlocale(LC_ALL, "RU");
    int arr1[] = { 3, 43, 38, 29, 18, 72, 57, 61, 2, 33 };
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    std::cout << "Тест 1:\n";
    testMergeSort(arr1, size1);

    int arr2[] = { 88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74 };
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    std::cout << "Тест 2:\n";
    testMergeSort(arr2, size2);

    int arr3[] = { 24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62 };
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    std::cout << "Тест 3:\n";
    testMergeSort(arr3, size3);

    return 0;
}