/*
rain water trapped in building blocks of width 1
O(n) S(1)
*/

#include<bits/stdc++.h>
using namespace std;

int solutionWithoutExtraSpace(int A[],int n)
{
    int left=0,right=n-1;
    int res=0;
    int maxleft=0,maxright=0;
    while(left<=right)
    {
        if(A[left]<=A[right])
        {
            if(A[left]>=maxleft) 
                maxleft=A[left]; //no water will be there on top of this block
            else 
            {
                int t=maxleft-A[left];
                //cout<<left<<" "<<t<<"\n";
                res=res+(maxleft-A[left]);
            }
            left++;
        }
        else
        {
            if(A[right]>=maxright) 
                maxright=A[right]; //no water will be there on top of this block
            else 
            {
                int t=maxright-A[right];
                //cout<<right<<" "<<t<<"\n";
                res=res+(maxright-A[right]);
            }
            right--;
        }
    }
    
    return res;
}

int solutionWithExtraSpace(int A[],int n) {
    
    int i,ans,mx;
    int maxLeft[n],maxRight[n];
    
    mx=A[0]; maxLeft[0]=mx;
    for(i=1;i<n;i++)
    {
        mx=max(mx,A[i]);
        maxLeft[i]=mx;
    }
    
    mx=A[n-1]; maxRight[n-1]=mx;
    for(i=n-2;i>=0;i--)
    {
        mx=max(mx,A[i]);
        maxRight[i]=mx;
    }
    
    ans=0;
    for(i=0;i<n;i++)
        ans=ans+(min(maxLeft[i],maxRight[i])-A[i]);
    
    return ans;
}


int main()
{
    int n,i;
    cin>>n;
    int a[n];
    
    for(i=0;i<n;i++)
        cin>>a[i];
    
    cout<<solutionWithoutExtraSpace(a,n)<<" ";
    cout<<solutionWithExtraSpace(a,n);
        
	return 0;
}
