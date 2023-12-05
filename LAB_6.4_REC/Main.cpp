#include <iostream>
#include <iomanip>
#include <cmath>

void fillArrayRecursive(double* arr, int size, int index = 0) {
    if (index < size) {
        std::cin >> arr[index];
        fillArrayRecursive(arr, size, index + 1);
    }
}

void printArrayRecursive(const double* arr, int size, int index = 0) {
    if (index < size) {
        std::cout << std::setw(8) << std::fixed << std::setprecision(2) << arr[index] << " ";
        printArrayRecursive(arr, size, index + 1);
    }
    else {
        std::cout << std::endl;
    }
}

int countZerosRecursive(const double* arr, int size, int index = 0) {
    if (index < size) {
        return (arr[index] == 0) + countZerosRecursive(arr, size, index + 1);
    }
    return 0;
}

double sumAfterMinRecursive(const double* arr, int size, int currentIndex, double minElement, int minIndex) {
    if (currentIndex < size) {
        if (arr[currentIndex] < minElement) {
            minElement = arr[currentIndex];
            minIndex = currentIndex;
        }
        return sumAfterMinRecursive(arr, size, currentIndex + 1, minElement, minIndex);
    }
    else if (minIndex + 1 < size) {
        return arr[minIndex + 1] + sumAfterMinRecursive(arr, size, currentIndex, minElement, minIndex + 1);
    }
    else {
        return 0.0;
    }
}

void sortOddElementsRecursive(double* arr, int size, int i = 0) {
    if (i < size - 1) {
        if (static_cast<int>(arr[i]) % 2 != 0) {
            for (int j = i + 1; j < size; j++) {
                if (static_cast<int>(arr[j]) % 2 != 0 && std::abs(arr[i]) > std::abs(arr[j])) {
                    std::swap(arr[i], arr[j]);
                }
            }
        }
        sortOddElementsRecursive(arr, size, i + 1);
    }
}

int main() {
    int size;

    std::cout << "Enter the size of the array: ";
    std::cin >> size;

    if (size <= 0) {
        std::cerr << "Invalid array size\n";
        return 1;
    }

    double* arr = new double[size];

    fillArrayRecursive(arr, size);
    printArrayRecursive(arr, size);

    std::cout << "1.1. Number of elements equal to zero: " << countZerosRecursive(arr, size) << std::endl;

    double sumAfterMinResult = sumAfterMinRecursive(arr, size, 0, arr[0], 0);
    std::cout << "1.2 Sum of elements after min element: " << sumAfterMinResult << std::endl;

    sortOddElementsRecursive(arr, size);

    std::cout << "Modified Array: ";
    printArrayRecursive(arr, size);

    delete[] arr;

    return 0;
}
