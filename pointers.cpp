#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    // int a = 10;
    // cout<< "Address of a :"<<&a<<endl;
    // int b=199;
    // int *p = &b;
    // cout<<b<<endl;
    // cout<<*p<<endl;
    // (*p)++;
    // cout<<*p;
    // float f = 10.5;
    // float p = 2.5;
    // float* ptr = &f;
    // (*ptr)++;
    // *ptr = p;
    // cout << *ptr << " " << f << " " << p;
    // int arr[10]={0,23,4};
    // cout << "Address of the first block of the array is: "<<arr<<endl;
    // cout << "Address of the first block of the array is: "<<&arr[0]<<endl;
    // cout << "Address of the first block of the array is: "<<*arr<<endl;
    // cout << "Address of the first block of the array is: "<<*(arr+1)<<endl;
    // cout << "Address of the first block of the array is: "<<*(arr)+1<<endl;
    // cout << "Address of the first block of the array is: "<<*arr+1<<endl;

    // int i =2;
    // cout<< i[arr]<<endl;

    // cout<<"q "<<arr<<endl;
    // cout<<"q2 "<<&arr<<endl;
    // cout<<"q2 "<<&arr[0]<<endl;
    // cout<<"fsjlkjfeioejoifjseofijseoifjsoeijfiosejfoie"<<endl;

    // int * p = &arr[0];

    // cout<<"q "<<p<<endl;
    // cout<<"q2 "<<&p<<endl;
    // cout<<"q2 "<<*p<<endl;

    // int a[10] = {1,2,3,4,5,5,6,7,8};
    // a= a+1; this cannot happen as one cannot change the addressing the symbol table
    // cout<< (a+1)<<endl;
    // cout<< (a)<<endl;
// cout works different than int in char
    // char cg[6] = "abcde";
    // char * p = &cg[0];
    // cout<<p<<endl;
    // cout<<*p<<endl;
    // cout<<&p<<endl;
    // cout<<&cg[0]<<endl;
    // cout<<&cg<<endl;
    // cout<<cg[2]<<endl;
    char s[]= "hello";
    char *p = s;
    cout << s[0] << " " << p[0];

    

    
    
    
    return 0;

}
