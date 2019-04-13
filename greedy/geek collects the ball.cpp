/*
this is wrong for

1 4 5 8 8 8
2 8 9 9 9 

correct answer is 1 4 5 8 8 8 9 9 9 
my logic 1 4 5 8 9 9 9 
*/

#include <iostream>
using namespace std;

int main() {
	int n,m,i,j,k,s1,s2,sum,T;
	cin>>T;
	while(T--)
	{
	    cin>>n>>m;
    	int R1[n];
    	for(i=0;i<n;i++)
    	cin>>R1[i];
    	
    	int R2[m];
    	for(j=0;j<m;j++)
    	cin>>R2[j];
    	
    	i=j=s1=s2=sum=0;
    	while(i<n && j<m)
    	{
    		if(R1[i]<R2[j])
    		{
    			s1=s1+R1[i];
    			i++;
    		}
    		else if(R1[i]>R2[j])
    		{
    			s2=s2+R2[j];
    			j++;
    		}
    		else if(R1[i]==R2[j])
    		{
    			if(s1>=s2)
    			{
    			    sum=sum+s1;
    			}
    			else
    			{
    			    sum=sum+s2;
    			}
    			
    			i++; j++;	
    			s1=s2=0;
    		}
    	}
    	
    	for(k=i;k<n;k++)
    		s1=s1+R1[k];
    		
    	for(k=j;k<m;k++)
    		s2=s2+R2[k];
    		
    	if(s1>=s2)
    		sum=sum+s1;
    	else
    		sum=sum+s2;
    		
    	cout<<sum<<"\n";
	}
}