#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define all(v) v.begin(),v.end()
#define pb(x) push_back(x)
#define f first
#define s second
#define vt vector
#define boost ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);  
const ll mod = 1e9+7;
int gcd(int a,int b){
	if(b==0)return a;
	
	return gcd(b,a%b);
}
const int V = 5;

//mst set keep track of the taken vertices
//key map for finding the minimum weighted edge
//parent array to keep track of the edge taken par[i] - i with wt g[par[i]][i]
void printMST(int parent[], int graph[V][V]) 
{ 
    cout<<"Edge \tWeight\n"; 
    for (int i = 1; i < V; i++) 
        cout<<parent[i]<<" - "<<i<<" \t"<<graph[i][parent[i]]<<" \n"; 
} 
  
int minKey(int key[],bool mst[]){
	int res = INT_MAX,v = 0;
	for(int i = 0;i<V;i++){
		if((mst[i]==false) and (key[i]<res)){ 
			v = i;
			res = key[i];
			}	
		}
	
	return v;	
}
void solve(int graph[V][V]){
	int par[V],key[V];
	bool mst[V];
	for (int i = 0; i < V; i++) 
       key[i] = INT_MAX, mst[i] = false; 
	
	
	par[0] = -1;	
	int cnt = V-1;
	
	while(cnt--){
		int u = minKey(key,mst);
		mst[u] = true;
		for(int v = 0;v<V;v++){
			if(graph[u][v] and mst[v]==false and graph[u][v]<key[v]){
				par[v] = u;key[v] = graph[u][v];
				}
		}
	}
	printMST(par,graph);
}
int main()
{	boost;
	/* Let us create the following graph 
        2 3 
    (0)--(1)--(2) 
    | / \ | 
    6| 8/ \5 |7 
    | / \ | 
    (3)-------(4) 
            9     */
    int graph[V][V] = { { 0, 2, 0, 6, 0 }, 
                        { 2, 0, 3, 8, 5 }, 
                        { 0, 3, 0, 0, 7 }, 
                        { 6, 8, 0, 0, 9 }, 
                        { 0, 5, 7, 9, 0 } }; 
  
    // Print the solution 
    solve(graph); 
  
    return 0; 
	
	//clk = clock()-clk;
	//cout<<"TIME CONSUMED: "<<(float)(clk)/CLOCKS_PER_SEC<<"sec\n";
}
