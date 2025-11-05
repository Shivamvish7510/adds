#include<iostream>
#include<cmath>
#include <cstdlib>   // for rand() and srand()
#include <ctime>     // for time()
using namespace std;


int comparison_count =0;


int random_partition(int arr[], int low, int high){
    // Generate a random index between low and high
    int random_index = low + rand() % (high - low + 1);
    cout << "Random index chosen: " << random_index << endl;
    // Swap the element at the random index with the last element
    swap(arr[random_index], arr[high]);
    
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high; j++){
        comparison_count++;
        if(arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    cout << "Pivot chosen: " << pivot << endl;
    // cout << "Array after partitioning: ";
    // for(int k = low; k <= high; k++){
    //     cout << arr[k] << " ";
    // }

    cout << endl;
    // Return the index of the pivot element after partitioning
    cout<< "Partition index: " << i + 1 << endl;
    return i + 1;
}

void quick_sort(int arr[], int low, int high){
    if(low<high){
        int pi = random_partition(arr , low, high);
        quick_sort(arr, low , pi-1);
        quick_sort(arr, pi+1 , high);
    }
}

int main(){
    srand(time(0)); // Seed for random number generation
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    
    int arr[n];
    cout << "Enter " << n << " elements:\n";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    quick_sort(arr, 0, n - 1);
    
    cout << "\nSorted array: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    
    cout << "Number of comparisons made: " << comparison_count << endl;
    
    return 0;
}