#include <bits/stdc++.h>
 
using namespace std;

int nb = 0 ;
void DFS(int v,map<int, vector<pair<int,int>>> &adj ,map<int, bool> &visited , int distance , int prec,int cap )
{

	visited[v] = true;

	if ( distance == 0 ) {
		nb++;
		return ;
	}

	

    for (int i = 0; i < adj[v].size(); i++)
	{

		if ((!visited[adj[v][i].first] ) and adj[v][i].first!= cap ) {
			if (distance - adj[v][i].second < 0) {
				adj[v][i].second = adj[v][i].second - distance - 1 ;
				nb++;
				
			}
			else {
				DFS(adj[v][i].first, adj, visited , distance - adj[v][i].second,v,cap);
			}
			
		}

            
	}
	
        
}

void solve()
{
    map<int, bool> visited;
    map<int,  vector<pair<int,int>>> adj;

	int n, r, cap;
    cin >> n >> r >> cap;

	for (int i = 0; i < r; i++)
	{
		int a,b,w ;
		cin >> a >> b >> w ;
		adj[a].push_back({b,w});
		adj[b].push_back({a,w});
	}
	
	int shoot ;
	cin >> shoot ;
	int path = shoot ;
	
	for (int i = 0; i < adj[cap].size(); i++)
	{
		DFS(adj[cap][i].first, adj, visited, shoot - adj[cap][i].second,0,cap);
	}
	
	
	cout << nb << endl ;

}
 
int main()
{
 
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int tt =1;
	//cin >> tt;
	
	for (int i = 1; i <= tt; i++)
		solve();
	
	
}

