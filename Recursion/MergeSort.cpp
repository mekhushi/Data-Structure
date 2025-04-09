#include <iostream> 


void merge(int arr[], int s, int mid, int e) {
    // Calculate lengths of the two temporary subarrays
    int len1 = mid - s + 1;
    int len2 = e - mid;

    // Create temporary arrays dynamically
    int *first = new int[len1];
    int *sec = new int[len2];

    // --- Copy data to temporary arrays ---
    // Copy first half (from s to mid)
    for (int i = 0; i < len1; i++) {
        first[i] = arr[s + i];
    }
    // Copy second half (from mid+1 to e)
    for (int i = 0; i < len2; i++) {
        sec[i] = arr[mid + 1 + i];
    }

    // --- Merge the temporary arrays back into arr[s...e] ---
    int index1 = 0;    // Initial index of first subarray
    int index2 = 0;    // Initial index of second subarray
    int k = s;         // Initial index of merged subarray (k replaces Mainarr)

    // Merge while both subarrays have elements
    while (index1 < len1 && index2 < len2) {
        if (first[index1] <= sec[index2]) {
            arr[k] = first[index1];
            index1++;
        } else {
            arr[k] = sec[index2];
            index2++;
        }
        k++; // Move to the next position in the main array
    }

    // --- Copy remaining elements, if any ---
    // If elements are left in 'first'
    while (index1 < len1) {
        arr[k] = first[index1];
        index1++;
        k++;
    }

    // If elements are left in 'sec'
    while (index2 < len2) {
        arr[k] = sec[index2];
        index2++;
        k++;
    }

    // --- Free the allocated memory ---
    delete[] first;
    delete[] sec;
}

// Main Merge Sort function (using camelCase convention)
// arr[]: The array to be sorted
// s: Starting index
// e: Ending index
void mergeSort(int arr[], int s, int e) {
    // Base case: If the segment has 0 or 1 element, it's already sorted
    if (s >= e) {
        return;
    }

    // Find the middle point to divide the array into two halves
    // Using s + (e - s) / 2 is safer against potential integer overflow for large s, e
    int mid = s + (e - s) / 2;

    // Recursively sort the first half
    mergeSort(arr, s, mid);
    // Recursively sort the second half
    mergeSort(arr, mid + 1, e);

    // Merge the two sorted halves
    merge(arr, s, mid, e);
}


void printArray(int A[], int size) {
    for (int i = 0; i < size; i++)
        std::cout << A[i] << " ";
    std::cout << std::endl;
}

// Main function to test the merge sort
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Given array is \n";
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1); // Call merge sort

    std::cout << "\nSorted array is \n";
    printArray(arr, arr_size);
    return 0;
}