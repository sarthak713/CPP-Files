#include<iostream>
#include<math.h>
using namespace std;
/*
Square Root through Binary Search

- Return only integer part, no decimals

Input: 25, 27, 8 
Output: 5,  5, 2

    - Answer always lies between 0 to n
    - This range is called Search Space
*/

long long int squareRoot(int n){
    int l=0;
    int r=n;
    long long int ans=-1;
    while(l<=r){
        long long int mid=l+(r-l)/2;
        long long int square = mid*mid;
        if(square==n){
            return mid;
        }
        else if(square<n){
            ans=mid;
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    return ans;
}

double morePrecision(int n,int precision,int tempSol){
    double factor = 1;
    double ans=tempSol;
    for(int i=0; i<precision; i++){
        factor/=10;     // to make it 0.1 & add it to n, to check square
                        // next time it becomes 0.01 then 0.001 ans so on to make precision
        for(double j=ans; j*j<n; j+=factor){    
// this starts from ansolute number, then keeps on adding nums after decimal 
// checks if new ans is less than n that is square
            ans=j;
        }
    }
    return ans;
}

int main(){

    // int n=37;
    int n=101;
    cout<<squareRoot(n)<<endl;

    int tempSolution = squareRoot(n);
    cout<<morePrecision(n,3,tempSolution)<<endl;





    
    return 0;
}