#include<iostream>
using namespace std;

bool BinarySearch(int arr[], int s , int e , int key ){
    //base case

    if (s>e){
        return false;
    }

    int mid = s+e/2;

    if ( arr[mid]==key){
        return key;
    }

    if ( arr[mid]<key ){
        return BinarySearch(arr, mid+1 , e, key);
    }

    else{
        BinarySearch(arr , s , e-1 , key);
    }
}


int main(){

 int arr[5]= {2,3,4,5,5};
 int size = 5 ; 
 int key = 3;


cout << " present or not "<< BinarySearch(arr , 0 , 5 , key ) << endl;








    return 0 ;
}