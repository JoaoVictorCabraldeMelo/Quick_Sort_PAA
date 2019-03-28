#include <bits/stdc++.h>
using namespace std;

 int partition(vector<int> &ar,int low , int high){

     int pivot = ar[high]; //pivot
     int i = low - 1; //Index of the smaller element

    for(int j = low; j <= high -1; j++){ 

        //If current element equal is smaller than or
        //equal to pivot
        if (ar[j] <= pivot) {
            i++; //increment index of the smaller element 
            swap(ar[i], ar[j]);
        }
    }
    swap(ar[i + 1], ar[high]);
    return(i + 1);
}


void quick_sort(vector<int> &ar, int low, int high){

    if(low < high) {

       int index = partition(ar,low, high);//index partiotining index ar[index]
       quick_sort(ar,low,index - 1);//Before index of partion
       quick_sort(ar,index + 1, high);//After index of partion
    }
}

int main () {

    vector<int> ar;

    for(int i = 100; i > 0;i--){
        ar.push_back(i);
    }

    int n = ar.size();

    cout << "Unsorted:" << endl;

    for(int i = 0; i < n; i++){
        cout <<"Index of " << i <<  " : " << ar[i] << endl; 
    }
    quick_sort(ar, 0, n - 1);

    cout << " -----------------------------------" << endl;

    cout << "Sorted:" << endl;

    for(int i = 0; i < n; i++){
        cout <<"Index of " << i <<  " : " << ar[i] << endl; 
    }

    return 0;
}