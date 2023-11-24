#include <iostream>
#include <iomanip>
#include <cmath>

void fillArrayRecursive(double* arr, int size, int index) {
    if (index < size) {
        std::cin >> arr[index];
        fillArrayRecursive(arr, size, index + 1);
    }
}

void printArrayRecursive(const double* arr, int size, int index) {
    if (index < size) {
        std::cout << std::setw(8) << std::fixed << std::setprecision(2) << arr[index] << " ";
        printArrayRecursive(arr, size, index + 1);
    }
    else {
        std::cout << std::endl;
    }
}

int countZerosRecursive(const double* arr, int size, int index) {
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
    else {
        double sum = 0.0;
        for (int i = minIndex + 1; i < size; i++) {
            sum += arr[i];
        }
        return sum;
    }
}

void sortOddElementsRecursive(double* arr, int size, int i, int j) {
    if (i < size) {
        if (j < size) {
            if (std::abs(arr[i]) > std::abs(arr[j])) {
                std::swap(arr[i], arr[j]);
            }
            sortOddElementsRecursive(arr, size, i, j + 2);
        }
        else {
            sortOddElementsRecursive(arr, size, i + 2, i + 4);
        }
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

    fillArrayRecursive(arr, size, 0);
    printArrayRecursive(arr, size, 0);

    std::cout << "1.1. Number of elements equal to zero: " << countZerosRecursive(arr, size, 0) << std::endl;

    double sumAfterMinResult = sumAfterMinRecursive(arr, size, 1, arr[0], 0);
    std::cout << "1.2. Sum of elements after the minimum element: " << std::fixed << std::setprecision(2)
        << sumAfterMinResult << std::endl;

    sortOddElementsRecursive(arr, size, 0, 2);

    std::cout << "Modified Array: ";
    printArrayRecursive(arr, size, 0);

    delete[] arr;

    return 0;
}
