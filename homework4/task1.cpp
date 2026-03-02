#include <iostream>

void print_dynamic_array(int* arr, int logical_size, int actual_size) {
    std::cout << "Динамический массив: ";
    for (int i = 0; i < actual_size; ++i) {
        if (i < logical_size) {
            std::cout << arr[i];
        }
        else {
            std::cout << "_";
        }

        if (i < actual_size - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}

int main() {
    setlocale(LC_ALL, "RU");

    int actual_size, logical_size;

    std::cout << "Введите фактический размер массива: ";
    std::cin >> actual_size;

    do {
        std::cout << "Введите логический размер массива: ";
        std::cin >> logical_size;

        if (logical_size > actual_size) {
            std::cout << "Ошибка! Логический размер массива не может превышать фактический!" << std::endl;
        }
    } while (logical_size > actual_size);

    int* arr = new int[actual_size];

    for (int i = 0; i < logical_size; ++i) {
        std::cout << "Введите arr[" << i << "]: ";
        std::cin >> arr[i];
    }

    print_dynamic_array(arr, logical_size, actual_size);

    delete[] arr;

    return 0;
}
