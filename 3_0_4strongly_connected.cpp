#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;
using std::pair;

void dfs1(int current,vector<vector<int> > &adj,vector<bool> &visited,vector<int> &order){
	visited[current]=true;
	for(size_t i=0;i<adj[current].size();i++){
	  if(!visited[adj[current][i]]){
 	 	dfs1(adj[current][i],adj,visited,order);
 	 	}
	}
	order.push_back(current);
	}
	
void dfs2(int current,vector<vector<int> > &transpose,vector<bool> &visited){
	visited[current]=true;
	for(size_t i=0;i<transpose[current].size();i++){
	  if(!visited[transpose[current][i]])
	  dfs2(transpose[current][i],transpose,visited);
	}
}

int number_of_SCCs(vector<vector<int> > adj) {
     int result = 0;
     //write your code here
     vector<bool> visited(adj.size());
     vector<int> order;
     for(size_t i=0;i<adj.size();i++){
       if(!visited[i]){
            dfs1(i,adj,visited,order);
            }
     }
     
     vector<vector<int> > transpose(adj.size());//Graph transpose
     for(size_t i =0;i<adj.size();i++){
       for(size_t j=0;j<adj[i].size();j++){
         std::cout<<"\n"<<adj[i][j]+1<<" "<<i+1;
         transpose[adj[i][j]].push_back(i);
       }
     }
     reverse(order.begin(),order.end());
     fill(visited.begin(),visited.end(),0);
     for(size_t i =0;i<order.size();i++){
       if(!visited[order[i]]){
           dfs2(order[i],transpose,visited);
           result++;
       }
     }
     std::cout<<"\n";
     return result;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  std::cout<< number_of_SCCs(adj);
   /*
   for(int j=0;j<V;j++){
      for(int k=0;k<adj.size();k++)
   	std::cout<<adj[j][k]<<"\n";
   }*/
}
