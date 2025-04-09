#include<iostream>
using namespace std;


int factorial(int n ){
 
    if ( n==0){
        return 1 ;
        
    }

    int smallprob = factorial(n-1);
    int bigproblem = n*factorial(n-1);

    return bigproblem ;

}



int main(){

    int n ; 
    cout << " enter the value of n ";
    cin>> n ; 

    int ans = factorial(n);

    cout<< ans << endl;
}











