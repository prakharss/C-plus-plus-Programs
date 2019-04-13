/*
all subsets of a set using backtracking
O() and S(s1+s2+s3+s4+......): sum of size of all subsets
*/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > ans;
int n,bits[100000]={0};

/*
//IB
void allSubsets(vector<int> &a,int i)
{
    if(i==n)
    {
        ans.push_back(temp);
    }
    else
    {
        allSubsets(a,i+1);
        
        temp.push_back(a[i]);
        allSubsets(a,i+1);
        temp.pop_back();
    }
}
*/

void allSubsets(int a[],int i)
{
    if(i==n)
    {
        vector<int> temp;
        for(int j=0;j<n;j++)
        {
            cout<<bits[j]<<" ";
            if(bits[j])
                temp.push_back(a[j]);
        }
        
        cout<<"\n";
        if(temp.size()>0)
            ans.push_back(temp);
    }
    else
    {
        bits[i]=1;
        allSubsets(a,i+1);
        
        bits[i]=0;
        allSubsets(a,i+1);
    }
}

int main()
{
    int i,j,row,col;
    cin>>n;
    int a[n];
    
    for(i=0;i<n;i++)
        cin>>a[i];
    
    sort(a,a+n);
    allSubsets(a,0);
    
    sort(ans.begin(),ans.end()); //we can sort vector of vector as well
    row=ans.size();
    for(i=0;i<row;i++)
    {   
        col=ans[i].size();
        for(j=0;j<col;j++)
            cout<<ans[i][j]<<" ";
        cout<<"\n";
    }
}

