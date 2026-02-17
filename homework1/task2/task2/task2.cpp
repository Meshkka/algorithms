#include <iostream>

int function(int* arr, int length, int point) {
    int left = 0;
    int right = length - 1;
    int result = length;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] <= point) {
            left = mid + 1;
        }
        else {
            result = mid;
            right = mid - 1;
        }
    }

    return length - result;
}

int main() {
    setlocale(LC_ALL, "RU");

    int arr[] = { 14, 16, 19, 32, 32, 32, 56, 69, 72 };
    int length = sizeof(arr) / sizeof(arr[0]);

    int point;
    std::cout << "Введите точку отсчёта: ";
    std::cin >> point;

    int count = function(arr, length, point);
    std::cout << "Количество элементов в массиве больших, чем " << point << ": " << count << std::endl;

    return 0;
}