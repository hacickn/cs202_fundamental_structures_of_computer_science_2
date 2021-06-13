/*
 * Title: Sorting and Algorithm Efficiency
 * Author: Hacı Çakın
 * ID: 21802641
 * Section: 3
 * Assignment: 1
 * Description: Header file of sorting algorithms and performance analyzer
 */

#ifndef CS202_HW1_SORTING_H
#define CS202_HW1_SORTING_H

#include <stdio.h>
#include <iostream>
#include <string>
#include <cmath>
#include <time.h>  // for timer
#include <stdlib.h>  //rand
#include <iomanip>
#include <sstream>
#include <stdexcept>

using namespace std;
/**
 * It is a sorting class to perform sorting actions
 */
class Sorting {
public:
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
    void selectionSort(int* arr, const int size, int& compCount, int& moveCount);

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
    void mergeSort(int* arr, const int size, int& compCount, int& moveCount);

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
    void quickSort(int* arr, const int size, int& compCount, int& moveCount);

    /**
     * @brief this methods divide the array according to pivot point value
     * @param arr is the array that will be used in partition
     * @param first is the index of the first element of the array
     * @param last is index of the last element of array
     * @param pivot is the pivot point in the array
     * @param compCount is to trace the number of comparison
     * @param moveCount is to trace the number of movement
     */
    void partition(int* arr, int first, int last, int& pivot, int& compCount, int& moveCount);

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
    void quickSort(int* arr, int first, int last, int& compCount, int& moveCount);

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
    void radixSort(int* arr, const int size);

    /**
     * @brief it sorts an array in ascending order(helper radixSort which is above)
     * @param arr the array that will be sorted
     * @param size the size of the array
     * @param numDigits is the digit that is found
     */
    void radixSort(int* arr, int size, int numDigits);

    /**
     * @brief it finds how many digit number have
     * @param number is the number that will be used in to determine digit of it
     * @return is the integer that is from number
     */
    int determineDigit(int number);

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
    void mergeSort(int* arr, int first, int last, int& compCount, int& moveCount);

    /**
     * @brief it helps merge sort (it brings together two parts)
     * @param arr is the array that will be sorted
     * @param first is index of first element of the array
     * @param mid is the index of the middle
     * @param last is the index of the last element of array
     * @param compCount is to trace the number of comparison
     * @param moveCount is to trace the number of movement
     */
    void merge(int* arr, int first, int mid, int last, int& compCount, int& moveCount);

    /**
     * @brief it finds the index of largest one
     * @param arr is the array that will be sorted
     * @param size is the size of array
     * @param compCount is to trace the number of comparison
     * @param moveCount is to trace the number of movement
     * @return
     */
    int indexOfLargest(const int arr[], int size, int& compCount, int& moveCount);

    /**
     * @brief it swap two values
     * @param a is the first value
     * @param b is the second value
     */
    void swap(int& a, int& b);

    /**
     * @brief it print the array
     * @param arr is the array that will be printed
     * @param size is the size of the array
     */
    void displayArray(const int* arr, const int size);

    /**
     * @brief this method creates random array with given sizes
     * @param arr1 is the first array
     * @param arr2 is the second array
     * @param arr3 is the third array
     * @param arr4 is the fourth array
     * @param size is the size of the arrays
     */
    void createRandomArrays(int*& arr1, int*& arr2, int*& arr3, int*& arr4, const int size);

    /**
     * @brief this method creates ascending array with given sizes
     * @param arr1 is the first array
     * @param arr2 is the second array
     * @param arr3 is the third array
     * @param arr4 is the fourth array
     * @param size is the size of the arrays
     */
    void createAscendingArrays(int*& arr1, int*& arr2, int*& arr3, int*& arr4, const int size);

    /**
     * @brief this method creates descending array with given sizes
     * @param arr1 is the first array
     * @param arr2 is the second array
     * @param arr3 is the third array
     * @param arr4 is the fourth array
     * @param size is the size of the arrays
     */
    void createDescendingArrays(int*& arr1, int*& arr2, int*& arr3, int*& arr4, const int size);

    /**
     * @brief this method runs each sorting algorithm for each given sizes and orders
     */
    void performanceAnalysis();

    /**
     * @brief this method helps performanceAnalysis() method to perform sorting actions
     * @param sortingType is the type of sorting(selection, quick, merge, radix)
     * @param arr1 is the first array with sizes 600
     * @param arr2 is the second array with sizes 1000
     * @param arr3 is the third array with sizes 1400
     * @param arr4 is the fourth array with sizes 1800
     * @param arr5 is the fifth array with sizes 2200
     * @param arr6 is the sixth array with sizes 2600
     * @param arr7 is the seventh array with sizes 3000
     */
    void performSorting(string sortingType, int*& arr1, int*& arr2, int*& arr3, int*& arr4, int*& arr5, int*& arr6,
                        int*& arr7);

    /**
     * @brief this method helps performSorting() method to print results to console
     * @param size is the size of the array
     * @param elapsedTime is the time that passes for sorting algorithm perform
     * @param compCount is the number of comparison during the sorting
     * @param movCount is the number of movement during the sorting
     * @param isRadix is the check whether sorting is performed by radix algorithm(because
     * it does not have compCount and movCount)
     */
    void printResult(int size, double elapsedTime, int compCount, int movCount, bool isRadix);

    /**
     * @brief it is for convert integer to string
     * @param num is the integer
     * @return is the string
     */
    string to_string(const int num) const;
};


#endif //CS202_HW1_SORTING_H
