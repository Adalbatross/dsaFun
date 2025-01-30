#include<iostream>
using namespace std;
int check(int arr[], int size){
    //base condition
    if (size == 0 || size == 1){
        return 1;
    }
    if(arr[0]>arr[1]){
        return 0;
    }
    else{
        int part = check(arr+1,size-1);
        return part;
    }
}

int sumArray(int arr[], int size){
    if(size == 0){
        return 0;
    } else {
        return arr[0] + sumArray(arr + 1, size - 1);
    }
}
bool linearSearch(int arr[], int size, int number){
    //base case 
    if(size ==0 ){
        return false;
    }
    if (arr[0]==number){
        return true;
    }

    else{
        bool ans = linearSearch(arr+1,size-1, number);
        return ans;
    }

}  
bool binarySearch(int arr[], int number, int start, int end){
    
    int mid= (start +end)/2;
    if(start>end){
        return false;
    }
    if(arr[mid]==number){
        return true;
    }
    else if (arr[mid]>number)
    {
        return binarySearch(arr,number,start,mid-1);
    }
    else{
        return binarySearch(arr,number,mid+1,end);
    }
    
}  
int main(int argc, char const *argv[])
{
    int arr[7] = {1,2,3,4,5,6,7};
    int size = 7;
    int key  = 3;
    int jr= check(arr, size);
    if (jr==1)
    {
        cout<<"the array is sorted"<<endl;
    }
    else{
        cout<<"The array is not sorted"<<endl;
    }
    int ans = sumArray(arr,size);
    cout<<"the sum of the array : "<<ans<<endl;
    int check = binarySearch(arr, key, 0,size);
    if (check)
    {
        cout<<"Element is present in the array"<<endl;
    }
    else{
        cout<<"Element is not present in the array"<<endl;
    }
    

    return 0;
}
