#include <bits/stdc++.h> 
using namespace std;
string  reverse(string str, int i){
    if(i>str.length()-i-1){
        return str ;
    }
    swap(str[i],str[str.length()-i-1]);
    // cout<<arr<<endl;
    return reverse(str,i+1);
    
}
int main()
{
    string a;
    cout<<"Enter the string you want to reverse ";
    cin>>a;
    int i= 0;
    int j = a.length()-1;
    string reverse1 = reverse(a,i);
    if(a==reverse1){
        cout<<"The entered string is a palindrome"<<endl;
    }
    else{
        cout<<"The entered string is not a palindrome"<<endl;
    }

    cout<<"The reversed string is "<<a<<endl;
    return 0;
}
