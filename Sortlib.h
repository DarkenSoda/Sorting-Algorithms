#ifndef SORTLIB_H
#define SORTLIB_H
#include <algorithm>
namespace Sortlib
{
    template <typename T>
    void Merge(T arr[], int low, int mid, int high)
    {
        int n1 = mid - low + 1;
        int n2 = high - mid;
        T left[n1], right[n2];
        for (int i = 0; i < n1; i++)
        {
            left[i] = arr[low + i];
        }

        for (int i = 0; i < n2; i++)
        {
            right[i] = arr[mid + i + 1];
        }

        int p1 = 0, p2 = 0, k = low;
        while (p1 < n1 && p2 < n2)
        {
            if (left[p1] <= right[p2])
            {
                arr[k] = left[p1];
                p1++;
            }
            else
            {
                arr[k] = right[p2];
                p2++;
            }
            k++;
        }

        while (p1 < n1)
        {
            arr[k] = left[p1];
            p1++;
            k++;
        }

        while (p2 < n2)
        {
            arr[k] = right[p2];
            p2++;
            k++;
        }
    }

    template <typename T, int sz>
    void MergeSort(T (&arr)[sz], int low = 0, int high = sz - 1)
    {
        if (low >= high)
            return;
        int mid = (low + high) / 2;
        MergeSort(arr, low, mid);
        MergeSort(arr, mid + 1, high);
        Merge(arr, low, mid, high);
    }

    template <typename T, int sz>
    void InsertionSort(T (&arr)[sz])
    {
        for (int i = 0; i < sz; i++)
        {
            for (int j = sz - 1; j > i; j--)
            {
                if (arr[j] < arr[j - 1])
                    std::swap(arr[j], arr[j - 1]);
            }
        }
    }

    template <typename T, int sz>
    void SelectionSort(T (&arr)[sz])
    {
        for (int i = 0; i < sz - 1; i++)
        {
            int least = i;
            for (int j = i + 1; j < sz; j++)
            {
                if (arr[j] < arr[least])
                    least = j;
            }
            std::swap(arr[i], arr[least]);
        }
    }

    template <typename T, int sz>
    void BubbleSort(T (&arr)[sz])
    {
        for (int i = sz - 1; i > 0; i--)
        {
            for (int j = 1; j <= i; j++)
            {
                if (arr[j] < arr[j - 1])
                    std::swap(arr[j], arr[j - 1]);
            }
        }
    }

    template <typename T, int sz>
    void ShellSort(T (&arr)[sz])
    {
        for (int gap = sz / 2; gap > 0; gap /= 2)
        {
            for (int i = gap; i < sz; i++)
            {
                T temp = arr[i];
                int j = i;
                for (; j >= gap && temp < arr[j - gap]; j -= gap)
                {
                    arr[j] = arr[j - gap];
                }
                arr[j] = temp;
            }
        }
    }
    template <typename T>
    int partition(T arr[], int l, int h)
    {
        int p = arr[l];
        int i = l;
        int j = h;
        while (i < j)
        {
            do
            {
                i++;
            } while (arr[i] <= p);
            do
            {
                j--;
            } while (arr[j] > p);
            if (i < j)
            {
                std::swap(arr[i], arr[j]);
            }
        }
        std::swap(arr[l], arr[j]);
        return j;
    }
    template <typename T, int sz>
    void quick_sort(T (&arr)[sz], int l = 0, int h = sz)
    {
        if (l < h)
        {
            int piv = partition(arr, l, h);
            quick_sort(arr, l, piv);
            quick_sort(arr, piv + 1, h);
        }
    }

    void CountSort(int arr[], int n)
    {

        int m;
        m = *std::max_element(arr, arr + n) + 1;
        int c[m];
        int b[n];
        for (int i = 0; i < m; i++)
        {
            c[i] = 0;
        }
        for (int i = 0; i < n; i++)
        {
            c[arr[i]]++;
        }

        for (int i = 1; i <= m; i++)
        {
            c[i] += c[i - 1];
        }

        for (int i = 0; i < n; i++)
        {
            b[c[arr[i]] - 1] = arr[i];
            c[arr[i]]--;
        }
        for (int i = 0; i < n; i++)
        {
            arr[i] = b[i];
        }
    }
};

#endif
