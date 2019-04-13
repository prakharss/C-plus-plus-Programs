/*
all permutations of a string using simple recursion and backtracking
for complexity refer functions
figure out the recursion equation 
permuteNoBackTrackingStep give sorted order of permutations
*/

#include<bits/stdc++.h>
using namespace std;

string globalString;
vector<string> ans;
int n;

//O(n!) S(1)
void permuteUsingGlobalString(int start)
{
    if(start<n-1)
    {
        for(int i=start;i<n;i++)
        {
            swap(globalString[start],globalString[i]);
            permuteUsingGlobalString(start+1);
            swap(globalString[start],globalString[i]); //backtrack
        }
    }
    else
        ans.push_back(globalString);
}

//O(n!) S(1) //it give the sorted order //we can also sort vector of vector
void permuteNoBackTrackingStep(string str,int start)
{
    if(start<n-1)
    {
        for(int i=start;i<n;i++)
        {
            swap(str[start],str[i]);
            permuteNoBackTrackingStep(str,start+1); 
            //no need of backtracking step but answer will not be affected if u will do the backtrack step
        }
    }
    else
        ans.push_back(str);
}

int main()
{
    string str;
    cin>>str;
    globalString=str;
    n=str.size();
    
    permuteUsingGlobalString(0);
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
    
    ans.clear(); cout<<"\n";

    permuteNoBackTrackingStep(str,0);
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
}

