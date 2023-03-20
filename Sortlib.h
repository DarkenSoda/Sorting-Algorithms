#ifndef SORTLIB_H
#define SORTLIB_H
#include <algorithm>
namespace Sortlib {
    template <typename T>
    void Merge(T arr[], int low, int mid, int high) {
        int n1 = mid - low + 1;
        int n2 = high - mid;
        T left[n1], right[n2];
        for (int i = 0; i < n1; i++) {
            left[i] = arr[low + i];
        }

        for (int i = 0; i < n2; i++) {
            right[i] = arr[mid + i + 1];
        }

        int p1 = 0, p2 = 0, k = low;
        while (p1 < n1 && p2 < n2) {
            if (left[p1] <= right[p2]) {
                arr[k] = left[p1];
                p1++;
            }
            else {
                arr[k] = right[p2];
                p2++;
            }
            k++;
        }

        while (p1 < n1) {
            arr[k] = left[p1];
            p1++;
            k++;
        }

        while (p2 < n2) {
            arr[k] = right[p2];
            p2++;
            k++;
        }
    }

    template <typename T, int sz>
    void MergeSort(T(&arr)[sz], int low = 0, int high = sz - 1) {
        if (low >= high)
            return;
        int mid = (low + high) / 2;
        MergeSort(arr, low, mid);
        MergeSort(arr, mid + 1, high);
        Merge(arr, low, mid, high);
    }

    template <typename T, int sz>
    void InsertionSort(T(&arr)[sz]) {
        for (int i = 0; i < sz; i++) {
            for (int j = sz - 1; j > i; j--) {
                if (arr[j] < arr[j - 1])
                    std::swap(arr[j], arr[j - 1]);
            }
        }
    }

    template <typename T, int sz>
    void SelectionSort(T(&arr)[sz]) {
        for (int i = 0; i < sz - 1; i++) {
            int least = i;
            for (int j = i + 1; j < sz; j++) {
                if (arr[j] < arr[least])
                    least = j;
            }
            std::swap(arr[i], arr[least]);
        }
    }

    template <typename T, int sz>
    void BubbleSort(T(&arr)[sz]) {
        for (int i = sz - 1; i > 0; i--) {
            for (int j = 1; j <= i; j++) {
                if (arr[j] < arr[j - 1])
                    std::swap(arr[j], arr[j - 1]);
            }
        }
    }

    template <typename T, int sz>
    void ShellSort(T(&arr)[sz]) {
        for (int gap = sz / 2; gap > 0; gap /= 2) {
            for (int i = gap; i < sz; i++) {
                T temp = arr[i];
                int j = i;
                for (; j >= gap && temp < arr[j - gap]; j -= gap) {
                    arr[j] = arr[j - gap];
                }
                arr[j] = temp;
            }
        }
    }
    
    template <typename T>
    int Partition(T arr[], int low, int high) {
        T pivot = arr[low];
        int i = low;
        int j = high;
        while (i < j) {
            do {
                i++;
            } while (arr[i] <= pivot);
            
            do {
                j--;
            } while (arr[j] > pivot);
            
            if (i < j) {
                std::swap(arr[i], arr[j]);
            }
        }
        std::swap(arr[low], arr[j]);
        return j;
    }
    
    template <typename T, int sz>
    void QuickSort(T(&arr)[sz], int low = 0, int high = sz) {
        if (low < high) {
            int piv = Partition(arr, low, high);
            QuickSort(arr, low, piv);
            QuickSort(arr, piv + 1, high);
        }
    }

    void CountSort(int arr[], const int SIZE) {
        int max;
        max = *std::max_element(arr, arr + SIZE) + 1;
        int count[max];
        int result[SIZE];
        
        for (int i = 0; i < max; i++) {
            count[i] = 0;
        }
        
        for (int i = 0; i < SIZE; i++) {
            count[arr[i]]++;
        }

        for (int i = 1; i <= max; i++) {
            count[i] += count[i - 1];
        }

        for (int i = 0; i < SIZE; i++) {
            result[count[arr[i]] - 1] = arr[i];
            count[arr[i]]--;
        }
        
        for (int i = 0; i < SIZE; i++) {
            arr[i] = result[i];
        }
    }
};

#endif
