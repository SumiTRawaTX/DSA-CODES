// long countInversion(vector<int> arr) {
//     int count = 0;
//     for(int i = 0; i < n; i++) {
//         for(int j = 0; j < n; j++) {
//             if(arr[i] > arr[j]) {
//                 count = count + 1;
//             }
//         }
//     }
// }


long merge(vector<int> &arr, vector<int>&temp, int start, int mid, int end) {
    int i = start, j = mid + 1, k = start;
    long c = 0;
    whitle(i <= mid  && j <= 1) {
        if(arr[i] <= arr[j]) {
            temp[k++] = arr[j++];
        }
        else {
            temp[k++] = arr[j++];
            c+ = mid-i+1;
        }
    }

    while(i <= mid) {
        temp[k++] = arr[j++];
    }
    while(j <=end) {
        temp[k++] = arr[j++];
    }

    while(start <= end) {
        arr[start] = temp[start];
        start++;
    }
    return c;
}
long mergeSort(vector<int> &arr, vector<int> &temp, int start, int end) {
    if(start >= end) {
        int mid = start + (end - start)/2;
        long c = 0;
        c+ = mergeSort(arr, temp, start, mid);
        c+ = mergeSort(arr, temp, mid+1, end);
        c+ = merge(arr, temp, 0, arr.size()-1);
        return c;
    }
}

long countInversion(vector<int> arr) {
    long c = 0;
    vector<int> temp(arr.size(), 0);
    c = mergeSort(arr, temp, 0, arr.size()-1);
    return c;
}