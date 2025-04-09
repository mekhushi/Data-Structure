#include<iostream>
using namespace std;

int power(int n){

    if ( n==0){
        return 1;
    }

    int ans  = n*power(n-1);
    return ans;


}


int main(){

    int n ; 
    cout << " enter the value of n ";
    cin>> n ;


    int finall = power(n);
    cout<<finall<< endl;




    return 0 ;
}