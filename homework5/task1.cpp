#include <iostream>

void print_pyramid(int* arr, int size) {
    std::cout << "Пирамида:" << std::endl;

    for (int i = 0; i < size; ++i) {
        int level = 0;
        int temp = i + 1;
        while (temp > 1) {
            temp /= 2;
            level++;
        }

        std::cout << level << " ";

        if (i == 0) {
            std::cout << "root " << arr[i];
        }
        else {
            int parent_index = (i - 1) / 2;

            if (i % 2 == 1) {
                std::cout << "left(" << arr[parent_index] << ") " << arr[i];
            }
            else {
                std::cout << "right(" << arr[parent_index] << ") " << arr[i];
            }
        }

        std::cout << std::endl;
    }
}

int main() {
    setlocale(LC_ALL, "RU");

    int arr1[] = { 1, 3, 6, 5, 9, 8 };
    int size1 = sizeof(arr1) / sizeof(arr1[0]);

    std::cout << "Исходный массив: ";
    for (int i = 0; i < size1; ++i) {
        std::cout << arr1[i];
        if (i < size1 - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;

    print_pyramid(arr1, size1);
    std::cout << std::endl;

    int arr2[] = { 94, 67, 18, 44, 55, 12, 6, 42 };
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    std::cout << "Исходный массив: ";
    for (int i = 0; i < size2; ++i) {
        std::cout << arr2[i];
        if (i < size2 - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;

    print_pyramid(arr2, size2);
    std::cout << std::endl;

    int arr3[] = { 16, 11, 9, 10, 5, 6, 8, 1, 2, 4 };
    int size3 = sizeof(arr3) / sizeof(arr3[0]);

    std::cout << "Исходный массив: ";
    for (int i = 0; i < size3; ++i) {
        std::cout << arr3[i];
        if (i < size3 - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;

    print_pyramid(arr3, size3);

    return 0;
}