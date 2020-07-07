/*
Given a string S, check if the letters can be rearranged so that two characters that are adjacent to each other are not the same.
If possible, output any possible result.  If not possible, return the empty string.
leet code
*/

/*
put characters in alterante way starting from the character having highest frequency
*/

class Solution {
public:
    string reorganizeString(string S) {
        int n=S.size(),i,h;
        
        pair<int,int> hash[26];
        for(i=0;i<26;i++)
        {
            hash[i].first=0; hash[i].second=i;
        }
        
        for(i=0;i<n;i++)
            hash[S[i]-97].first++;
        
        sort(hash,hash+26);
        reverse(hash,hash+26);
        
        h=0; i=0;        
        while(i<n)
        {
            if(hash[h].first>0)
            {
                S[i]=(char) (hash[h].second+97);
                hash[h].first--;
                i=i+2;
            }
            else
                h++;
        }
        
        i=1;
        while(i<n)
        {
            if(hash[h].first>0)
            {
                char ch=(char) (hash[h].second+97);
                if(i-1>0)
                {
                    if(S[i-1]==ch)
                        return "";
                }
                
                if(i+1<n)
                {
                    if(S[i+1]==ch)
                        return "";
                }
                
                S[i]=ch;
                hash[h].first--;
                i=i+2;
            }
            else
                h++;
        }
        
        return S;
    }
};
