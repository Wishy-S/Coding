#include <bits/stdc++.h>
using namespace std;
void solve(vector<vector<int>>grid){
//0 0 0 0 1 0 0
//0 0 0 0 0 0 0
//0 0 0 2 0 0 0
//0 0 0 0 0 0 0
//0 3 0 0 0 0 0
	
	
	//(1,0) (0,1) (-1,0) (0,-1) (1,1) (-1,-1) (1,-1) (-1,1)
	int n = grid.size();
	int m = grid[0].size();
	//while matrix contain any zeros 
	queue<pair<int,int>>q;
	for(int i=0;i<n;i++){
		for(int j = 0;j<m;j++){
			if(grid[i][j]!=0){q.push({i,j});}
			}
		}
	auto is_valid = [&](int x,int y){
		return x>=0 and x<n and y>=0 and y<m and grid[x][y]==0;
		};
	
	
	int row[] = {1,0,-1,0,1,-1,1,-1};
	int col[] = {0,1,0,-1,1,-1,-1,1};
	while(!q.empty()){	
		auto p = q.front();
		q.pop();
		for(int i = 0;i<8;i++){
			int n_row = row[i]+p.first;
			int n_col = col[i]+p.second;
			
			if(!is_valid(n_row,n_col)){
				continue;
				}
			grid[n_row][n_col] = grid[p.first][p.second];
			q.push({n_row,n_col});
			}
	}
	cout<<'\n';
	
	for(int i = 0;i<n;i++){
		for(int j =0;j<m;j++){
			cout<<grid[i][j]<<' ';
			}
			cout<<'\n';
		}
	
}
int main(){
	int n,m;cin>>n>>m;
	
	vector<vector<int>>grid(n,vector<int>(m));
	
	for(int i =0 ;i<n;i++){
		for(int j = 0;j<m;j++)cin>>grid[i][j];	
	}
	
	
	solve(grid);	
}
