#include<iostream>
#include<map>
#include<vector>
#include<queue>
#include<list>

using namespace std;


class Graph{
	map<int, vector<int> > adjlist;
	map<int, bool> vis;
	list<int> order;
public:
	Graph(){

	}

	void addEdge(int u, int v){
		adjlist[u].push_back(v);
	}

	void dfshelper(int u){
		vis[u] = true;
		for(auto i : adjlist[u]){
			if(!vis[i])
				dfshelper(i);
		}
		order.push_front(u);

	}

	void topological_dfs(){
		for(auto i : adjlist){
			int node = i.first;
			if(!vis[node]){
				dfshelper(node);
			}
		}
		print_order();
	}

	void print_order(){
		int sz = order.size()-1;
		for(auto ele : order){
			cout << ele;if(sz-->0){cout<<" -> ";}
		}
	}

};

int main(){

	Graph g;
	g.addEdge(1,2);
	g.addEdge(1,3);
	g.addEdge(2,4);
	g.addEdge(3,4);
	// g.addEdge(5,0);
	// g.addEdge(5,2);
	// g.addEdge(2,3);
	// g.addEdge(3,1);
	// g.addEdge(4,1);
	// g.addEdge(4,0);
	g.topological_dfs();
	cout<<endl;

	return 0;
}