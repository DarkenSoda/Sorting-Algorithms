#include<iostream>
#include "Sortlib.h"
using namespace std;


int main() {
    int arr[] = { 2, 3, 1 ,4, 6};
    Sortlib::MergeSort(arr);
    for (auto i : arr) cout << i << ' ';
    cout << '\n';
}