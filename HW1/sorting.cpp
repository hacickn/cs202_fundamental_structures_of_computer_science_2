/*
 * Title: Sorting and Algorithm Efficiency
 * Author: Hacı Çakın
 * ID: 21802641
 * Section: 3
 * Assignment: 1
 * Description: .cpp file of sorting algorithms and performance analyzer
 */
#include <vector>
#include <iostream>
#include <cmath>
#include <stdio.h>

using namespace std;

#include "sorting.h"

/**
 * @brief it swap two values
 * @param a is the first value
 * @param b is the second value
 */
void Sorting::swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

/**
 * @brief it finds the index of largest one
 * @param arr is the array that will be sorted
 * @param size is the size of array
 * @param compCount is to trace the number of comparison
 * @param moveCount is to trace the number of movement
 * @return
 */
int Sorting::indexOfLargest(const int* arr, int size, int& compCount, int& moveCount) {
    int indexSoFar = 0;
    for (int currentIndex = 1; currentIndex < size; ++currentIndex) {
        compCount++;
        if (arr[currentIndex] > arr[indexSoFar]) {
            indexSoFar = currentIndex;
        }
    }
    return indexSoFar;
}

/**
 *  @brief it sorts an array in ascending order
 *  Idea: list is divided into two parts, the sorted part at the left end and the unsorted part at the right end
 *  Worst case: O(n^2)
 *  Best case: O(n^2)
 *  Average case: O(n^2)
 *  @param arr is an array that will be sorted
 *  @param size is the size of the array
 *  @param compCount is to trace the number of comparison
 *  @param moveCount is to trace the number of movement
 */
void Sorting::selectionSort(int* arr, const int size, int& compCount, int& moveCount) {
    for (int last = size - 1; last >= 1; --last) {
        int largest = indexOfLargest(arr, last + 1, compCount, moveCount);
        moveCount = moveCount + 3;
        swap(arr[largest], arr[last]);
    }
}

/**
 *  @brief it sorts an array in ascending order
 *  Idea: repeatedly breaks down a list into several sublists until each sublist consists of a single element
 *  and bring them together in ordered way
 *  Worst case: O(n*log(n))
 *  Best case: O(n*log(n))
 *  Average case: O(n*log(n))
 *  @param arr is an array that will be sorted
 *  @param size is the size of the array
 *  @param compCount is to trace the number of comparison
 *  @param moveCount is to trace the number of movement
 */
void Sorting::mergeSort(int* arr, const int size, int& compCount, int& moveCount) {
    mergeSort(arr, 0, size - 1, compCount, moveCount);
}

/**
 *  @brief it is helper for merge Sort which is above
 *  Worst case: O(n*log(n))
 *  Best case: O(n*log(n))
 *  Average case: O(n*log(n))
 *  @param arr is an array that will be sorted
 *  @param first is the index of the first element
 *  @param last is the index of the last element
 *  @param compCount is to trace the number of comparison
 *  @param moveCount is to trace the number of movement
 */
void Sorting::mergeSort(int* arr, int first, int last, int& compCount, int& moveCount) {
    if (first < last) {

        int mid = (first + last) / 2;    // index of midpoint

        mergeSort(arr, first, mid, compCount, moveCount); // recursive call

        mergeSort(arr, mid + 1, last, compCount, moveCount); // recursive call

        // merge the two halves
        merge(arr, first, mid, last, compCount, moveCount);
    }
}

/**
 * @brief it helps merge sort (it brings together two parts)
 * @param arr is the array that will be sorted
 * @param first is index of first element of the array
 * @param mid is the index of the middle
 * @param last is the index of the last element of array
 * @param compCount is to trace the number of comparison
 * @param moveCount is to trace the number of movement
 */
void Sorting::merge(int* arr, int first, int mid, int last, int& compCount, int& moveCount) {
    int tempArray[last + 1];    // temporary array

    int first1 = first;         // beginning of first subarray
    int last1 = mid;            // end of first subarray
    int first2 = mid + 1;       // beginning of second subarray
    int last2 = last;           // end of second subarray
    int index = first1;         // next available location in tempArray

    for (; (first1 <= last1) && (first2 <= last2); ++index) {
        compCount++;
        moveCount++;
        if (arr[first1] < arr[first2]) {
            tempArray[index] = arr[first1];
            ++first1;
        } else {
            tempArray[index] = arr[first2];
            ++first2;
        }
    }
    for (; first1 <= last1; ++first1, ++index) {
        moveCount++;
        tempArray[index] = arr[first1];
    }
    for (; first2 <= last2; ++first2, ++index) {
        moveCount++;
        tempArray[index] = arr[first2];
    }
    for (index = first; index <= last; ++index) {
        moveCount++;
        arr[index] = tempArray[index];
    }
}

/**
 *  @brief it sorts an array in ascending order
 *  Idea: array is divided two sublist which are (sublistOne[i]< pivot && sublistTwo[i] > pivot )
 *  Worst case: O(n^2)
 *  Best case: O(n*log(n))
 *  Average case: O(n*log(n))
 *  @param arr is an array that will be sorted
 *  @param size is the size of the array
 *  @param compCount is to trace the number of comparison
 *  @param moveCount is to trace the number of movement
 */
void Sorting::quickSort(int* arr, const int size, int& compCount, int& moveCount) {
    quickSort(arr, 0, size - 1, compCount, moveCount);
}

/**
 *  @brief it sorts an array in ascending order
 *  Idea: it is helper for quick sort which is above
 *  Worst case: O(n^2)
 *  Best case: O(n*log(n))
 *  Average case: O(n*log(n))
 *  @param arr is an array that will be sorted
 *  @param first is the index of the first element
 *  @param last is the index of the last element
 *  @param compCount is to trace the number of comparison
 *  @param moveCount is to trace the number of movement
 */
void Sorting::quickSort(int* arr, int first, int last, int& compCount, int& moveCount) {
    int pivotIndex = 0;

    if (first < last) {
        partition(arr, first, last, pivotIndex, compCount, moveCount);       // create the partition: S1, pivot, S2
        quickSort(arr, first, pivotIndex - 1, compCount, moveCount);        // recursive call
        quickSort(arr, pivotIndex + 1, last, compCount, moveCount);         // recursive call
    }
}

/**
 * @brief this methods divide the array according to pivot point value
 * @param arr is the array that will be used in partition
 * @param first is the index of the first element of the array
 * @param last is index of the last element of array
 * @param pivot is the pivot point in the array
 * @param compCount is to trace the number of comparison
 * @param moveCount is to trace the number of movement
 */
void Sorting::partition(int* arr, int first, int last, int& pivot, int& compCount, int& moveCount) {
    int pivotIndex = arr[first];
    moveCount++;

    int end = first;
    int unknown = first + 1;

    while (unknown <= last) {
        if (arr[unknown] < pivotIndex) {
            end++;
            swap(arr[unknown], arr[end]);
            moveCount = moveCount + 3;
        }
        compCount++;
        unknown++;
    }
    swap(arr[first], arr[end]);
    moveCount = moveCount + 3;
    pivot = end;
}

/**
 *  @brief it sorts an array in ascending order
 *  Idea: Create 10 container (0, 1, 2, 3, 4, 5, 6, 7, 8, 9) and then put element according to their digit,
 *  repeat this process
 *  Worst case: O(n)
 *  Best case: O(n)
 *  Average case: O(n)
 *  @param arr is an array that will be sorted
 *  @param size is the size of the array
 */
void Sorting::radixSort(int* arr, const int size) {
    int maxDigit = determineDigit(arr[0]);

    for (int a = 0; a < size; a++) {
        if (maxDigit < determineDigit(arr[a])) {
            maxDigit = determineDigit(arr[a]);
        }
    }

    radixSort(arr, size, maxDigit);
}

/**
 * @brief it finds how many digit number have
 * @param number is the number that will be used in to determine digit of it
 * @return is the integer that is from number
 */
int Sorting::determineDigit(int number) {
    int digits = 0;
    if (number < 0) {
        digits = 1;
    }

    while (int(number != 0)) {
        number /= 10;
        digits++;
    }

    return digits;
}

/**
 * @brief it sorts an array in ascending order(helper radixSort which is above)
 * @param arr the array that will be sorted
 * @param size the size of the array
 * @param numDigits is the digit that is found
 */
void Sorting::radixSort(int* arr, int size, int numDigits) {
    for (int a = 0; a < numDigits; a++) {
        int array[10][size];
        int countArray[10] = {0};
        int currentPosition = 0;
        int current;

        for (int b = 0; b < size; b++) {
            int k = ((int) (arr[b] / pow(10, a))) % 10;
            int pos = countArray[((int) (arr[b] / pow(10, a))) % 10];
            array[k][pos] = arr[b];
            countArray[(int) (arr[b] / pow(10, a)) % 10] = pos + 1;
        }

        for (int b = 0; b < 10; b++) {
            current = 0;
            while (current < countArray[b]) {
                arr[currentPosition++] = array[b][current];
                current++;
            }
        }
    }
}


/**
 * @brief it print the array
 * @param arr is the array that will be printed
 * @param size is the size of the array
 */
void Sorting::displayArray(const int* arr, const int size) {
    cout << "{ ";
    for (int a = 0; a < size - 1; a++) {
        cout << arr[a] << ", ";
    }
    cout << arr[size - 1];
    cout << " }" << endl;
}

/**
 * @brief this method creates random array with given sizes
 * @param arr1 is the first array
 * @param arr2 is the second array
 * @param arr3 is the third array
 * @param arr4 is the fourth array
 * @param size is the size of the arrays
 */
void Sorting::createRandomArrays(int*& arr1, int*& arr2, int*& arr3, int*& arr4, const int size) {
    for (int a = 0; a < size; a++) {
        int random = rand() % size + 1;
        arr1[a] = random;
        arr2[a] = random;
        arr3[a] = random;
        arr4[a] = random;
    }
}

/**
 * @brief this method creates ascending array with given sizes
 * @param arr1 is the first array
 * @param arr2 is the second array
 * @param arr3 is the third array
 * @param arr4 is the fourth array
 * @param size is the size of the arrays
 */
void Sorting::createAscendingArrays(int*& arr1, int*& arr2, int*& arr3, int*& arr4, const int size) {
    for (int a = 0; a < size; a++) {
        arr1[a] = a + 1;
        arr2[a] = a + 1;
        arr3[a] = a + 1;
        arr4[a] = a + 1;
    }
}

/**
 * @brief this method creates descending array with given sizes
 * @param arr1 is the first array
 * @param arr2 is the second array
 * @param arr3 is the third array
 * @param arr4 is the fourth array
 * @param size is the size of the arrays
 */
void Sorting::createDescendingArrays(int*& arr1, int*& arr2, int*& arr3, int*& arr4, const int size) {
    for (int a = 0; a < size; a++) {
        arr1[a] = size - a;
        arr2[a] = size - a;
        arr3[a] = size - a;
        arr4[a] = size - a;
    }
}

/**
 * @brief this method runs each sorting algorithm for each given sizes and orders
 */
void Sorting::performanceAnalysis() {
    const int sizes[] = {6000, 10000, 14000, 18000, 22000, 26000, 30000};

    int* size600Array1 = new int[6000];
    int* size600Array2 = new int[6000];
    int* size600Array3 = new int[6000];
    int* size600Array4 = new int[6000];

    int* size1000Array1 = new int[10000];
    int* size1000Array2 = new int[10000];
    int* size1000Array3 = new int[10000];
    int* size1000Array4 = new int[10000];

    int* size1400Array1 = new int[14000];
    int* size1400Array2 = new int[14000];
    int* size1400Array3 = new int[14000];
    int* size1400Array4 = new int[14000];

    int* size1800Array1 = new int[18000];
    int* size1800Array2 = new int[18000];
    int* size1800Array3 = new int[18000];
    int* size1800Array4 = new int[18000];

    int* size22000Array1 = new int[22000];
    int* size22000Array2 = new int[22000];
    int* size22000Array3 = new int[22000];
    int* size22000Array4 = new int[22000];

    int* size26000Array1 = new int[26000];
    int* size26000Array2 = new int[26000];
    int* size26000Array3 = new int[26000];
    int* size26000Array4 = new int[26000];

    int* size30000Array1 = new int[30000];
    int* size30000Array2 = new int[30000];
    int* size30000Array3 = new int[30000];
    int* size30000Array4 = new int[30000];


    for (int a = 0; a < 3; a++) {
        if (a == 0) {
            createRandomArrays(size600Array1, size600Array2, size600Array3, size600Array4, sizes[0]);
            createRandomArrays(size1000Array1, size1000Array2, size1000Array3, size1000Array4, sizes[1]);
            createRandomArrays(size1400Array1, size1400Array2, size1400Array3, size1400Array4, sizes[2]);
            createRandomArrays(size1800Array1, size1800Array2, size1800Array3, size1800Array4, sizes[3]);
            createRandomArrays(size22000Array1, size22000Array2, size22000Array3, size22000Array4, sizes[4]);
            createRandomArrays(size26000Array1, size26000Array2, size26000Array3, size26000Array4, sizes[5]);
            createRandomArrays(size30000Array1, size30000Array2, size30000Array3, size30000Array4, sizes[6]);


            cout << "-----------------------------------------------------------------------" << endl;
            cout << "RANDOM ARRAYS----------------------------------------------------------" << endl;
            cout << "-----------------------------------------------------------------------" << endl;
            cout << "Analysis of Selection Sort" << endl;
            cout << "Array Size          Elapsed time        compCount           moveCount" << endl;
            performSorting("selectionSort", size600Array1, size1000Array1, size1400Array1, size1800Array1,
                           size22000Array1, size26000Array1, size30000Array1);


            cout << "Analysis of Merge Sort" << endl;
            cout << "Array Size          Elapsed time        compCount           moveCount" << endl;
            performSorting("mergeSort", size600Array2, size1000Array2, size1400Array2, size1800Array2,
                           size22000Array2, size26000Array2, size30000Array2);

            cout << "Analysis of Quick Sort" << endl;
            cout << "Array Size          Elapsed time        compCount           moveCount" << endl;
            performSorting("quickSort", size600Array3, size1000Array3, size1400Array3, size1800Array3,
                           size22000Array3, size26000Array3, size30000Array3);

            cout << "Analysis of Radix Sort" << endl;
            cout << "Array Size          Elapsed time        compCount           moveCount" << endl;
            performSorting("radixSort", size600Array4, size1000Array4, size1400Array4, size1800Array4,
                           size22000Array4, size26000Array4, size30000Array4);
        } else if (a == 1) {
            createAscendingArrays(size600Array1, size600Array2, size600Array3, size600Array4, sizes[0]);
            createAscendingArrays(size1000Array1, size1000Array2, size1000Array3, size1000Array4, sizes[1]);
            createAscendingArrays(size1400Array1, size1400Array2, size1400Array3, size1400Array4, sizes[2]);
            createAscendingArrays(size1800Array1, size1800Array2, size1800Array3, size1800Array4, sizes[3]);
            createAscendingArrays(size22000Array1, size22000Array2, size22000Array3, size22000Array4, sizes[4]);
            createAscendingArrays(size26000Array1, size26000Array2, size26000Array3, size26000Array4, sizes[5]);
            createAscendingArrays(size30000Array1, size30000Array2, size30000Array3, size30000Array4, sizes[6]);

            cout << "-----------------------------------------------------------------------" << endl;
            cout << "ASCENDING ARRAYS----------------------------------------------------------" << endl;
            cout << "-----------------------------------------------------------------------" << endl;
            cout << "Analysis of Selection Sort" << endl;
            cout << "Array Size          Elapsed time        compCount           moveCount" << endl;
            performSorting("selectionSort", size600Array1, size1000Array1, size1400Array1, size1800Array1,
                           size22000Array1, size26000Array1, size30000Array1);


            cout << "Analysis of Merge Sort" << endl;
            cout << "Array Size          Elapsed time        compCount           moveCount" << endl;
            performSorting("mergeSort", size600Array2, size1000Array2, size1400Array2, size1800Array2,
                           size22000Array2, size26000Array2, size30000Array2);

            cout << "Analysis of Quick Sort" << endl;
            cout << "Array Size          Elapsed time        compCount           moveCount" << endl;
            performSorting("quickSort", size600Array3, size1000Array3, size1400Array3, size1800Array3,
                           size22000Array3, size26000Array3, size30000Array3);

            cout << "Analysis of Radix Sort" << endl;
            cout << "Array Size          Elapsed time        compCount           moveCount" << endl;
            performSorting("radixSort", size600Array4, size1000Array4, size1400Array4, size1800Array4,
                           size22000Array4, size26000Array4, size30000Array4);
        } else if (a == 2) {
            createDescendingArrays(size600Array1, size600Array2, size600Array3, size600Array4, sizes[0]);
            createDescendingArrays(size1000Array1, size1000Array2, size1000Array3, size1000Array4, sizes[1]);
            createDescendingArrays(size1400Array1, size1400Array2, size1400Array3, size1400Array4, sizes[2]);
            createDescendingArrays(size1800Array1, size1800Array2, size1800Array3, size1800Array4, sizes[3]);
            createDescendingArrays(size22000Array1, size22000Array2, size22000Array3, size22000Array4, sizes[4]);
            createDescendingArrays(size26000Array1, size26000Array2, size26000Array3, size26000Array4, sizes[5]);
            createDescendingArrays(size30000Array1, size30000Array2, size30000Array3, size30000Array4, sizes[6]);

            cout << "-----------------------------------------------------------------------" << endl;
            cout << "DESCENDING ARRAYS----------------------------------------------------------" << endl;
            cout << "-----------------------------------------------------------------------" << endl;
            cout << "Analysis of Selection Sort" << endl;
            cout << "Array Size          Elapsed time        compCount           moveCount" << endl;
            performSorting("selectionSort", size600Array1, size1000Array1, size1400Array1, size1800Array1,
                           size22000Array1, size26000Array1, size30000Array1);


            cout << "Analysis of Merge Sort" << endl;
            cout << "Array Size          Elapsed time        compCount           moveCount" << endl;
            performSorting("mergeSort", size600Array2, size1000Array2, size1400Array2, size1800Array2,
                           size22000Array2, size26000Array2, size30000Array2);

            cout << "Analysis of Quick Sort" << endl;
            cout << "Array Size          Elapsed time        compCount           moveCount" << endl;
            performSorting("quickSort", size600Array3, size1000Array3, size1400Array3, size1800Array3,
                           size22000Array3, size26000Array3, size30000Array3);

            cout << "Analysis of Radix Sort" << endl;
            cout << "Array Size          Elapsed time        compCount           moveCount" << endl;
            performSorting("radixSort", size600Array4, size1000Array4, size1400Array4, size1800Array4,
                           size22000Array4, size26000Array4, size30000Array4);
        }
    }


    delete[] size600Array1;
    delete[] size600Array2;
    delete[] size600Array3;
    delete[] size600Array4;

    delete[] size1000Array1;
    delete[] size1000Array2;
    delete[] size1000Array3;
    delete[] size1000Array4;

    delete[] size1400Array1;
    delete[] size1400Array2;
    delete[] size1400Array3;
    delete[] size1400Array4;

    delete[] size1800Array1;
    delete[] size1800Array2;
    delete[] size1800Array3;
    delete[] size1800Array4;

    delete[] size22000Array1;
    delete[] size22000Array2;
    delete[] size22000Array3;
    delete[] size22000Array4;

    delete[] size26000Array1;
    delete[] size26000Array2;
    delete[] size26000Array3;
    delete[] size26000Array4;

    delete[] size30000Array1;
    delete[] size30000Array2;
    delete[] size30000Array3;
    delete[] size30000Array4;
}

/**
 * @brief this method helps performanceAnalysis() method to perform sorting actions
 * @param sortingType is the type of sorting(selection, quick, merge, radix)
 * @param arr1 is the first array with sizes 6000
 * @param arr2 is the second array with sizes 10000
 * @param arr3 is the third array with sizes 14000
 * @param arr4 is the fourth array with sizes 18000
 * @param arr5 is the fifth array with sizes 22000
 * @param arr6 is the sixth array with sizes 26000
 * @param arr7 is the seventh array with sizes 30000
 */
void Sorting::performSorting(string sortingType, int*& arr1, int*& arr2, int*& arr3, int*& arr4, int*& arr5, int*& arr6,
                             int*& arr7) {
    const int sizes[] = {6000, 10000, 14000, 18000, 22000, 26000, 30000};
    int* listOfArrays[7] = {arr1, arr2, arr3, arr4, arr5, arr6, arr7};
    int compCount = 0;
    int movCount = 0;
    double timeElapsed;
    clock_t counter;

    for (int a = 0; a < 7; a++) {
        movCount = 0;
        compCount = 0;

        if (sortingType == "selectionSort") {
            counter = clock();
            selectionSort(listOfArrays[a], sizes[a], compCount, movCount);
        } else if (sortingType == "mergeSort") {
            counter = clock();
            mergeSort(listOfArrays[a], sizes[a], compCount, movCount);
        } else if (sortingType == "quickSort") {
            counter = clock();
            quickSort(listOfArrays[a], sizes[a], compCount, movCount);
        } else if (sortingType == "radixSort") {
            counter = clock();
            radixSort(listOfArrays[a], sizes[a]);
        }
        counter = clock() - counter;
        timeElapsed = (double) counter * 1000 / CLOCKS_PER_SEC;
        if (sortingType == "radixSort") {
            printResult(sizes[a], timeElapsed, compCount, movCount, true);
        } else {
            printResult(sizes[a], timeElapsed, compCount, movCount, false);
        }
    }

    cout << endl;
}

/**
 * @brief this method helps performSorting() method to print results to console
 * @param size is the size of the array
 * @param elapsedTime is the time that passes for sorting algorithm perform
 * @param compCount is the number of comparison during the sorting
 * @param movCount is the number of movement during the sorting
 * @param isRadix is the check whether sorting is performed by radix algorithm(because
 * it does not have compCount and movCount)
 */
void Sorting::printResult(int size, double elapsedTime, int compCount, int movCount, bool isRadix) {
    string sizeString = to_string(size);
    string doubleString = to_string(elapsedTime) + " ms";
    string compString = to_string(compCount);
    string movString = to_string(movCount);

    cout << sizeString;
    for (int a = 20; a > sizeString.length(); a--) {
        cout << " ";
    }

    cout << doubleString;
    for (int a = 20; a > doubleString.length(); a--) {
        cout << " ";
    }

    if (!isRadix) {
        cout << compString;
        for (int a = 20; a > compString.length(); a--) {
            cout << " ";
        }

        cout << movString;
        for (int a = 20; a > movString.length(); a--) {
            cout << " ";
        }
    }
    cout << endl;

}

/**
 * @brief it is for convert integer to string
 * @param num is the integer
 * @return is the string
 */
string Sorting::to_string(const int num) const {
    stringstream stream;
    stream << num;
    return stream.str();
}