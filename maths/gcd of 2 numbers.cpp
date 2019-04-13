/*
gcd of two number a and b
O(log max(a,b)) O(log (a*b)) O(log a + log b) S(1)
*/

#include<bits/stdc++.h>
using namespace std;

int gcd_iter(int a,int b)
{
	int temp;
	while(b)
	{
		temp=a%b;
		a=b;
		b=temp;
	}

	return a;
}

int gcd_rec(int a,int b)
{
    if (b==0)
        return a;
    return gcd_rec(b,a%b);
}

int gcd_subtraction_method(int a,int b)
{
	while(a!=b)
	{
		if(a>b)
			a=a-b;
		else if(b>a)
			b=b-a;
	}
    
    return a;
}

int gcd_defined_method(int a,int b)
{
	return __gcd(a,b);
}

int main()
{
	int a,b;
	cin>>a>>b;
	cout<<gcd_iter(a,b)<<" ";
	cout<<gcd_rec(a,b)<<" ";
	cout<<gcd_subtraction_method(a,b)<<" ";
	cout<<gcd_defined_method(a,b);

	return 0;
}
