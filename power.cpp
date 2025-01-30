#include<iostream>
using namespace std;
long long power(int u, int k){
    if(k==0){
        return 1;
    }
    else{
        if(k%2==0){
            return power(u,k/2)*power(u,k/2);
        }
        else{
            return u*power(u,k/2)*power(u,k/2);
        }
    }
}
int main()
{
    cout<<power(2,30);
    return 0;
}
