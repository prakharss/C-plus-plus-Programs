/*
You are given an array of N integers, A1, A2 ,…, AN and an integer K. 
Return the of count of distinct numbers in all windows of size K
O(n) S(windowSize)
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> distinctNumbersInWindow(vector<int> A,int B) {
    int n,i,del;
    vector<int> vec;
    map<int,int> mp;
    
    n=A.size();
    if(B>n)
        return vec;
    
    for(i=0;i<n;i++)
    {
        mp[A[i]]++;
        if(i-B+1>=0)
        {
            vec.push_back(mp.size());
            
            del=A[i-B+1]; mp[del]--;
            if(!mp[del])
                mp.erase(del);
        }
    }
    
    return vec;
}

int main()
{
    int i,n,windowSize;
    cin>>n;
    vector<int> vec(n);
    vector<int> ans;

    for(i=0;i<n;i++)
    	cin>>vec[i];
    
    cin>>windowSize;
    ans=distinctNumbersInWindow(vec,windowSize);
    
    for(i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
    
    return 0;
}

