#include<iostream>
using namespace std;

void leftRotate(int arr[],int n,int k)
{
    for(int i=k;i<k+n;i++)
    {
        cout<<arr[i%n]<<" ";
    }
}


int main()
{
    int arr[] = {1, 3, 5, 7, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
 
    int k = 2;
    leftRotate(arr, n, k);
    cout << endl;
 
    k = 3;
    leftRotate(arr, n, k);
    cout << endl;
 
    k = 4;
    leftRotate(arr, n, k);
    cout << endl;
 
    return 0;
}