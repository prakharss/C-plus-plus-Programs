/*
Probable logic for first non-repeating character in a stream
*/

/*
Psuedo Code

has[10000]={0}; start=0;
for(i=0;i<str.size();i++)
{
	has[str[i]]++;
	while(has[str[start]] >= 2)
		start++;

	if(start>i) 
		cout<<-1;
	else 
		cout<<str[start];
}
*/