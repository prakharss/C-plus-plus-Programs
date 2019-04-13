/*
number of subarrays having even sum
explanation - https://cs.stackexchange.com/questions/87421/find-number-of-even-subarrays-on-explanation-needed
we have provided 2 type of answers 
O(n) S(1)
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i,n,ans,sum,oddSum,evenSum;
    cin>>n;
    int a[n];

    for(i=0;i<n;i++)
    	cin>>a[i];
    
    ans=0; sum=0; oddSum=0; evenSum=1;
    for(i=0;i<n;i++)
    {
        sum=sum+a[i];
        if(sum%2==0)
        {
            ans=ans+evenSum;
            evenSum++;
        }
        else
        {
            ans=ans+oddSum;
            oddSum++;
        } 
    }
    
    cout<<ans<<"\n";
    //or 
    cout<<(evenSum*(evenSum-1))/2 + (oddSum*(oddSum-1))/2;
    //both will give the same answer
    
    return 0;
}

