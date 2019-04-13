#include<bits/stdc++.h>
using namespace std;
typedef long long int li;

int main()
{
	li i,a,b,ans;
	cin>>a>>b;
	
    ans=1;    
    while(b>0)
    {
        if(b%2)
            ans=(ans*a)%c;  
        
        a=(a*a)%c; 
        b=b/2;
    }
    
    while(ans<0)
        ans=ans+c;    
    ans=ans%c;

    if(a==0 && b==0)
        cout<<0;
    else
    	cout<<ans;

	return 0;
}



