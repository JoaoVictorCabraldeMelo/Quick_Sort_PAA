#include <bits/stdc++.h>
using namespace std;


int partition(vector<int> &arr, int low, int high){
    int pivot = arr[low];
    int i = low - 1; //Initiallize left index
    int j = high + 1; //Initiallize right index 
    
    //Find a value in left side that are
    // greater than the pivot 
    while(true){
        do{
            i++;
        }while(arr[i] < pivot);

        do{
            j--;
        }while(arr[j] > pivot);

        if(i >= j){
            return j;
        }
        swap(arr[i], arr[j]);
    }
}

int partition_r(vector<int> &arr, int low, int high){
    srand(time(NULL));
    int random = low + rand() % (high - low);
    swap(arr[random],arr[low]);
    return partition(arr, low, high);
} 

void quicksort(vector<int> &arr, int low, int high){
    if(low < high){
        int index = partition_r(arr,low,high);
        quicksort(arr,low,index);
        quicksort(arr, index + 1, high);
    }
}


int main () {

    vector<int> arr;

    for(int i = 100; i > 0; i--){
        arr.push_back(i);
    }

    int n = arr.size();

    quicksort(arr,0, n - 1);


    for(int i = 0; i < n;i++){
        cout << "Index : " << i << endl << "Valor : " << arr[i] << endl;
    }

    return 0;
}