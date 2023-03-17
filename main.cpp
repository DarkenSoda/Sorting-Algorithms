#include<iostream>
#include "Sortlib.h"
using namespace std;


int main() {
    int arr[3] = { 2, 3, 1 };
    Sortlib::InsertionSort(arr, 3);
    for (auto i : arr) cout << i << ' ';
    cout << '\n';
}