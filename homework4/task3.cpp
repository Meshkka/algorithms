#include <iostream>
#include <string>

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

int* remove_dynamic_array_head(int* arr, int& logical_size, int& actual_size) {
    if (logical_size <= 0) {
        std::cout << "Невозможно удалить первый элемент, так как массив пустой. До свидания!" << std::endl;
        return arr;
    }

    int new_logical_size = logical_size - 1;

    if (new_logical_size <= actual_size / 3) {
        int new_actual_size = actual_size / 3;
        if (new_actual_size < new_logical_size) {
            new_actual_size = new_logical_size;
        }

        int* new_arr = new int[new_actual_size];

        for (int i = 0; i < new_logical_size; ++i) {
            new_arr[i] = arr[i + 1];
        }

        delete[] arr;

        logical_size = new_logical_size;
        actual_size = new_actual_size;

        return new_arr;
    }
    else {
        for (int i = 0; i < new_logical_size; ++i) {
            arr[i] = arr[i + 1];
        }

        logical_size = new_logical_size;

        return arr;
    }
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

    std::string answer;
    while (true) {
        if (logical_size <= 0) {
            std::cout << "Невозможно удалить первый элемент, так как массив пустой. До свидания!" << std::endl;
            break;
        }

        std::cout << "Удалить первый элемент? ";
        std::cin >> answer;

        if (answer == "да" || answer == "yes" || answer == "y" || answer == "д") {
            arr = remove_dynamic_array_head(arr, logical_size, actual_size);

            print_dynamic_array(arr, logical_size, actual_size);
        }
        else {
            std::cout << "Спасибо! Ваш динамический массив: ";
            print_dynamic_array(arr, logical_size, actual_size);
            break;
        }
    }

    delete[] arr;

    return 0;
}