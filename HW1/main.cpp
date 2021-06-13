/*
 * Title: Sorting and Algorithm Efficiency
 * Author: Hacı Çakın
 * ID: 21802641
 * Section: 3
 * Assignment: 1
 * Description: It is main.cpp to call methods from sorting
 */

#include <iostream>
#include "sorting.h"

using namespace std;


int main() {
    // Just sort the array {12,7,11,18,19,9,6,14,21,3,17,20,5,12,14,8} with selection sort,
    // merge sort, quick sort and radix sort
    Sorting sorting;
    int arrayForSelectionSort[] = {12, 7, 11, 18, 19, 9, 6, 14, 21, 3, 17, 20, 5, 12, 14, 8};
    int compCountForSelectionSort = 0;
    int movCountForSelectionSort = 0;

    int arrayForMergeSort[] = {12, 7, 11, 18, 19, 9, 6, 14, 21, 3, 17, 20, 5, 12, 14, 8};
    int compCountForMergeSort = 0;
    int movCountForMergeSort = 0;

    int arrayForQuickSort[] = {12, 7, 11, 18, 19, 9, 6, 14, 21, 3, 17, 20, 5, 12, 14, 8};
    int compCountForQuickSort = 0;
    int movCountForQuickSort = 0;

    int arrayForRadixSort[] = {12, 7, 11, 18, 19, 9, 6, 14, 21, 3, 17, 20, 5, 12, 14, 8};

    cout << "QUESTION 2 PART C " << endl;
    cout << "Selection Sort       ----------------------------------------------------------" << endl;
    sorting.selectionSort(arrayForSelectionSort, 16, compCountForSelectionSort, movCountForSelectionSort);
    cout << "CompCount: " << compCountForSelectionSort << "        movCount: " << movCountForSelectionSort << endl;
    sorting.displayArray(arrayForSelectionSort, 16);
    cout << endl;

    cout << "Merge Sort           ----------------------------------------------------------" << endl;
    sorting.mergeSort(arrayForMergeSort, 16, compCountForMergeSort, movCountForMergeSort);
    cout << "CompCount: " << compCountForMergeSort << "        movCount: " << movCountForMergeSort << endl;
    sorting.displayArray(arrayForMergeSort, 16);
    cout << endl;

    cout << "Quick Sort           ----------------------------------------------------------" << endl;
    sorting.quickSort(arrayForQuickSort, 16, compCountForQuickSort, movCountForQuickSort);
    cout << "CompCount: " << compCountForQuickSort << "        movCount: " << movCountForQuickSort << endl;
    sorting.displayArray(arrayForQuickSort, 16);
    cout << endl;

    cout << "Radix Sort           ----------------------------------------------------------" << endl;
    sorting.radixSort(arrayForRadixSort, 16);
    sorting.displayArray(arrayForRadixSort, 16);
    cout << endl;

    // for each scenario(ascending, descending, random) and for each sizes(6000, 10000, 14000, 18000, 22000, 26000, 30000),
    // trials for each sorting algorithm
    cout << "Performance Analyze  ----------------------------------------------------------" << endl;
    sorting.performanceAnalysis();
    return 0;
}
