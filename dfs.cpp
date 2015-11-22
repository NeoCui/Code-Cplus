#include<iostream>
#include<vector>

using namespace std;

#define N 6

struct adj_matrix{
	vector<int> vertex;
	vector<vector<int> > edge;
};

int visited[N]={0};

void dfs_visit(adj_matrix& G, int u){
	int v;
	visited[u]=1;
	cout<<G.vertex[u]<<"->";
	for(v=0; v<N; ++v){
		if(G.edge[u][v]==1 && visited[v]!=1){
			dfs_visit(G,v);
		}
	}
}

void dfs(adj_matrix& G){
	int u;
	for(u=0; u<N; ++u){
		if(visited[u]!=1){
			dfs_visit(G,u);
		}
	}
}

int main(){
	int a[N]={1,2,3,4,5,6};
	int b[N][N]={{0,1,0,1,0,0},
				{0,0,0,0,1,0},
				{0,0,0,0,1,1},
				{0,1,0,0,0,0},
				{0,0,0,1,0,0},
				{0,0,0,0,0,1}};
	vector<int> vertexG(a,a+N);
	vector<vector<int> > edgeG;
	edgeG.resize(N);
	for(int i=0; i<N; ++i){
		for(int j=0; j<N; ++j)
			edgeG[i].push_back(b[i][j]);
	}
	adj_matrix Graph={vertexG,edgeG};
	dfs(Graph);
	cout<<"end"<<endl;
	return 0;
}
