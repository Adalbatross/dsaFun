#include<iostream>
using namespace std;
bool palindrome(string str, int i, int j){
    if(i>j){
        return true;
    }
    else{
        if(str[i]==str[j]){
            return palindrome(str,i+1,j-1);
        }
        else{
            return false;
        }
    }
}
int main()
{
    string a;
    cout<<"enter the string you want to check for the palindrome"<<endl;
    cin>>a;
    int i=0;
    int j= a.length()-1;
    if(palindrome(a,i,j)){
        cout<<"The entered string is a palindrome"<<endl;
    }
    else{
        cout<<"The entered string is not a palindrome"<<endl;
    }
    return 0;
}
