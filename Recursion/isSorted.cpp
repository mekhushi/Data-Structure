#include<iostream>
using namespace std;

bool iSorted(int arr[], int size){
    if ( size==0 || size==1){
        return 1;
    }
     if (arr[0]>arr[1]){
        return false;
     }

     int Reamingpart = iSorted(arr+1 , size-1);
     return Reamingpart;
}


int main(){

 int arr[5] = {2,3,4,5,0};
 int size =5;

 bool ans = iSorted(arr , size);

 if ( ans){
    cout << "array is sorted"<< endl;

 }
 else{
    cout << " array is not sorted ";
 }




    return 0 ;
}