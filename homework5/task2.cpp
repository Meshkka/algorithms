#include <iostream>
#include <string>
#include <cmath>

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

void print_current_position(int* arr, int index) {
    if (index == 0) {
        std::cout << "0 root " << arr[index];
    }
    else {
        int level = 0;
        int temp = index + 1;
        while (temp > 1) {
            temp /= 2;
            level++;
        }

        int parent_index = (index - 1) / 2;

        if (index % 2 == 1) {
            std::cout << level << " left(" << arr[parent_index] << ") " << arr[index];
        }
        else {
            std::cout << level << " right(" << arr[parent_index] << ") " << arr[index];
        }
    }
}

bool has_parent(int index) {
    return index > 0;
}

bool has_left_child(int index, int size) {
    int left_child_index = 2 * index + 1;
    return left_child_index < size;
}

bool has_right_child(int index, int size) {
    int right_child_index = 2 * index + 2;
    return right_child_index < size;
}

int get_parent_index(int index) {
    return (index - 1) / 2;
}

int get_left_child_index(int index) {
    return 2 * index + 1;
}

int get_right_child_index(int index) {
    return 2 * index + 2;
}

void travel_pyramid(int* arr, int size) {
    int current_index = 0;
    std::string command;

    while (true) {
        std::cout << "Вы находитесь здесь: ";
        print_current_position(arr, current_index);
        std::cout << std::endl;

        std::cout << "Введите команду: ";
        std::cin >> command;

        if (command == "exit") {
            break;
        }
        else if (command == "up") {
            if (has_parent(current_index)) {
                current_index = get_parent_index(current_index);
                std::cout << "Ок" << std::endl;
            }
            else {
                std::cout << "Ошибка! Отсутствует родитель" << std::endl;
            }
        }
        else if (command == "left") {
            if (has_left_child(current_index, size)) {
                current_index = get_left_child_index(current_index);
                std::cout << "Ок" << std::endl;
            }
            else {
                std::cout << "Ошибка! Отсутствует левый потомок" << std::endl;
            }
        }
        else if (command == "right") {
            if (has_right_child(current_index, size)) {
                current_index = get_right_child_index(current_index);
                std::cout << "Ок" << std::endl;
            }
            else {
                std::cout << "Ошибка! Отсутствует правый потомок" << std::endl;
            }
        }
        else {
            std::cout << "Неизвестная команда! Доступные команды: up, left, right, exit" << std::endl;
        }
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
    travel_pyramid(arr1, size1);
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
    travel_pyramid(arr2, size2);
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
    travel_pyramid(arr3, size3);

    return 0;
}