#include<iostream>
#include<cstdlib>
#include<time.h>
#include "Sortlib.h"
using namespace std;

void GenerateRandomNumbers(int arr[], const int SIZE) {
    srand(time(0));
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand();
    }
}

int main() {
    int arr[20];
    GenerateRandomNumbers(arr, 20);
    Sortlib::ShellSort(arr);
    for (auto i : arr) cout << i << ' ';
    cout << '\n';
}