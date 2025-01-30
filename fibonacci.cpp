#include<iostream>
using namespace std;
void number(int n,string arr[]){
    if (n==0){
        return;
    }
    int digit = n % 10;
    number(n/10, arr);
    cout<<arr[digit]<<" ";
    

 }
int main(int argc, char const *argv[])
{
    string arr[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    cout<<" The number in words is : ";
    number(n, arr);

    
    return 0;
}
