#include<bits/stdc++.h>
using namespace std;

void checkArray(int arr[])  //it will take less time - this is also reference
{
    arr[0]=1;
}

void checkArrayRef(int *arr)  //it will take less time - this is also reference
{
    *arr=2;
}

void checkVector(vector<int> vec)  //it will take some more time - this is not reference
{
    vec[0]=1;
}

void checkVectorRef(vector<int> &vec)  //it will take less time - this is also reference
{
    vec[0]=2;
}

int main()
{
    int i,j,n;
    cin>>n;
    
    int arr[n]; arr[0]=0;
    checkArray(arr);
    cout<<arr[0]<<"\n";
    checkArrayRef(arr);
    cout<<arr[0]<<"\n";
    
    vector<int> vec; vec.push_back(0);
    checkVector(vec);
    cout<<vec[0]<<"\n";
    checkVectorRef(vec);
    cout<<vec[0]<<"\n";

    return 0;
}