#include<iostream>
using namespace std;

int update(int& i){
    i--;
    return i;
}
int main(int argc, char const *argv[])
{
    // int u=23;
    //  int &k= u; //here k is the refernce variable for u
    // cout<<u<<endl;
    // u++;
    // cout<<u<<endl;
    // k++;
    // cout<<u<<endl;
    // update(u);
    // cout<<u<<endl;
    // return 0;
    int n;
    int m;
    cin>>n;
    cin>>m;
    int **arr = new int*[n]; //dynamically created array 
    for(int i=0; i<n; i++){
        int size;   // for jagged array
        cout<< "Enter the size of the row: "<<i+1<<endl;
        cin>>size;
        arr[i] = new int[size];

    }

    // enter the value
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }

    cout<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    for(int i=0; i<n; i++){
        delete [] arr[i];
    }
    delete []arr ;


}
