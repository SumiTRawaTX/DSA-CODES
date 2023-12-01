#include <iostream>
using namespace std;

void mergeArrays(int arr1[], int size1, int arr2[], int size2, int result[], int &resultSize, int index1 = 0, int index2 = 0) {
    // Base cases
    if (index1 == size1 && index2 == size2) {
        // Both arrays are exhausted
        return;
    }

    if (index1 == size1) {
        // First array is exhausted, copy remaining elements from the second array
        result[resultSize++] = arr2[index2++];
    } else if (index2 == size2) {
        // Second array is exhausted, copy remaining elements from the first array
        result[resultSize++] = arr1[index1++];
    } else {
        // Compare elements from both arrays and copy the smaller one
        if (arr1[index1] < arr2[index2]) {
            result[resultSize++] = arr1[index1++];
        } else {
            result[resultSize++] = arr2[index2++];
        }
    }

    // Recursive call for the next step
    mergeArrays(arr1, size1, arr2, size2, result, resultSize, index1, index2);
}

int main() {
    int arr1[] = {1, 3, 5, 7};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = {2, 4, 6, 8};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    int resultSize = 0;
    int result[size1 + size2];

    mergeArrays(arr1, size1, arr2, size2, result, resultSize);

    cout << "Merged Array: ";
    for (int i = 0; i < resultSize; i++) {
        cout << result[i] << " ";
    }

    return 0;
}
