#include<iostream>
using namespace std;
int factorial(int n){
    
    // base case
    if(n==0)
        return 1; 
    
    return n * factorial(n-1);
    
}

int power(int m ){
    // base case
    if (m==0)
        return 1;
    int smallerProblem = power(m-1);
    int biggerProblem = 2 * smallerProblem;
    return biggerProblem;
}

int main()
{
    int n; 
    cout<<"enter the value you want to enter:  "<<endl;
    cin>>n;
    int ans = power(n);
    cout<<ans<<endl;
    return 0;
}
