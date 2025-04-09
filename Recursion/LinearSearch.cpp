#include<iostream>
using namespace std;


bool LinearSearch( int arr[] , int key , int size){

    if ( size==0){
        return 0 ;
    }

    if ( arr[0]==key){
        return true ;
    } else{
        int Reamingpart = LinearSearch(arr+1 , key , size-1);
        return Reamingpart;
    }
  

}

int main(){


    int arr[5]= { 2,3,4,5,6};
    int size = 5 ; 
    int key = 3 ; 

    bool ans = LinearSearch(arr , key , size);

    if( ans ){
        cout << "key is found "<< endl;
    }else{


        cout << " key is not found "<< endl;
    }
}