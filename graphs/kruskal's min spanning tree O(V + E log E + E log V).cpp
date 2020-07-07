/*
Time complexity: O(V + E*log(E) + E*log(V)) = initialisation + sorting + union1 
*/

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
const int MAX = 1e4 + 5;    //max no. of nodes possible
int id[MAX], V, E, sz[MAX];
pair <long long, pair<int, int> > p[MAX];

//O(V)
void initialize(int V)
{
    for(int i = 1;i <= V;++i)
        {
        	parent[i] = i;
        	sz[i] = 1;
		}
}

//O(log(V))
int root(int x)
{
    while(id[x] != x)
    {
        x = id[x]; //we can also add path compression step here
    }
    return x;
}

//O(log(V))
void union1(int x, int y)
{
    int p = root(x);
    int q = root(y);
    if(sz[p]<sz[q])            //this is for weighted union i.e union by rank to minimize the height of the components
    {
    	parent[p] = parent[q];
    	sz[q] = sz[q] + sz[p];
	} 
	else
	{
		parent[q] = parent[p];
    	sz[p] = sz[p] + sz[q];
	}
}

//O(E * log(V))
long long kruskal()
{
    int x, y, cnt;
    long long cost, minimumCost = 0;

    cnt=0;
    for(int i = 0;i < E;++i)
    {
        // Selecting edges one by one in increasing order from the beginning
        x = p[i].second.first;
        y = p[i].second.second;
        cost = p[i].first;
        
		// Check if the selected edge is creating a cycle or not
        if(cnt<V-1 && root(x) != root(y))  //if(root(x) != root(y)) - this will also work 
        {
            minimumCost += cost;
            union1(x, y);
            cnt++;
        }

        if(cnt==V)
            break;    
    }

    return minimumCost;
}

int main()
{
    int x, y;
    long long weight, cost, minimumCost;
    cin >> V >> E;
    initialize(V);
    for(int i = 0;i < E;++i)
    {
        cin >> x >> y >> weight;  
        p[i] = make_pair(weight, make_pair(x, y));
    }

    // Sort the edges in the ascending order
    sort(p, p + E);
    minimumCost = kruskal();
    cout << minimumCost << endl;
    return 0;
}


/*
3 3
0 1 1 
1 2 3
2 0 2
*/
