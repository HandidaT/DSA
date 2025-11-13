#include <iostream>
#include <vector>
#include <map>
#include <bits/stdc++.h>


using std::vector;
using std::map;

int explore(int current_positionon_path, vector<int> &visited,vector<vector<int> > &adj, int &flag,map<int, bool> &ancestor){
    visited[current_positionon_path]=1;
    ancestor[current_positionon_path]=true;
    for(int j=0;j<adj[current_positionon_path].size();j++){
       if(!visited[adj[current_positionon_path][j]]){
	          flag=explore(adj[current_positionon_path][j],visited,adj,flag,ancestor);
       }
       else if(ancestor[adj[current_positionon_path][j]]){
		flag=1;//std::cout<<"Cycle present\n";
		return flag;//stop exploring when cycle found
       }
       if(flag) return flag;
    }//All vertices reachable from this current vertice are explored and no cycle detected,
     //so we can write false/0 for the ancestor of current vertice and backtrack i.e,
    ancestor[current_positionon_path]=0;//return back to caller explore function
    return flag;
}

int acyclic(vector<vector<int> > &adj) {
  int flag=0;
  //vector<int> ancestor(adj.size(),0);
  map<int,bool> ancestor;
  vector<int> visited(adj.size(),0);
  //return explore(0,ancestor,visited,adj);
  for(int i = 0; i < adj.size(); i++){
     if(!visited[i]){
	      ancestor.clear();
	      explore(i,visited,adj,flag,ancestor);
      }
      if(flag) return flag;
   }
   return 0;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);//only once as we are workig with directed graph
  }
  std::cout << acyclic(adj);
/*
/home/han/Desktop/dnet/compsci/3DAA/crsra/ZbXGTnQSSm61xk50EvpuTw_b5653e5869ef44c680fb84b29011bd72_course3_2020_07_27/week2_graph_decomposition2/1_cs_curriculum

4 4
1 2
4 1
2 3
3 1
should output 1

5 7
1 2
2 3
1 3
3 4
1 4
2 5
3 5
should output 0

*/
}
