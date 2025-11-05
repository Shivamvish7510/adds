#include <iostream>
#include <cstdlib>   // for rand(), srand()
#include <ctime>     // for time()

using namespace std;

// Swap two elements
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Partition function (like in QuickSort)
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Randomized partition: choose a random pivot
int randomizedPartition(int arr[], int low, int high) {
    int randomIndex = low + rand() % (high - low + 1);
    swap(arr[randomIndex], arr[high]);  // move pivot to end
    return partition(arr, low, high);
}

// Randomized Select algorithm
int randomizedSelect(int arr[], int low, int high, int i) {
    if (low == high)
        return arr[low];

    int pivotIndex = randomizedPartition(arr, low, high);
    int k = pivotIndex - low + 1; // position of pivot in current subarray

    if (i == k)
        return arr[pivotIndex];       // pivot is the i-th smallest element
    else if (i < k)
        return randomizedSelect(arr, low, pivotIndex - 1, i); // left subarray
    else
        return randomizedSelect(arr, pivotIndex + 1, high, i - k); // right subarray
}

int main() {
    srand(time(0)); // Seed for random pivot selection

    int n, i;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements:\n";
    for (int j = 0; j < n; j++)
        cin >> arr[j];

    cout << "Enter i (to find the i-th smallest element): ";
    cin >> i;

    if (i < 1 || i > n) {
        cout << "Invalid i! It must be between 1 and " << n << endl;
        return 0;
    }

    int result = randomizedSelect(arr, 0, n - 1, i);

    cout << "\nThe " << i << "-th smallest element is: " << result << endl;
    return 0;
}
