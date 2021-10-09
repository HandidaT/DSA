#include <iostream>
#include <vector>
#include <map>
#include <bits/stdc++.h>


using std::vector;
using std::map;

int explore(int current_positionon_path, vector<int> &visited,vector<vector<int> > &adj,
            int &flag,map<int, bool> &parent_or_not){
    visited[current_positionon_path]=1;
    parent_or_not[current_positionon_path]=true;//marking currnt parent u
    vector<int> current_neighbours_arr=adj[current_positionon_path];
    int n_size=current_neighbours_arr.size();//number of neighbouring vertices
    for(int j=0;j<n_size;j++){
      int current_neighbour=current_neighbours_arr[j];
       if(!visited[current_neighbour]){
	          flag=explore(current_neighbour,visited,adj,flag,parent_or_not);
       }
       else if(parent_or_not[current_neighbour]){//if descendent v is parent u
	          flag=1;
            std::cout<<"Cycle present\n";
            return flag;//stop exploring when cycle found
       }
       if(flag) return flag;
    }//All vertices reachable from this current vertice are explored and no cycle detected,
     //so we can write false/0 for the parent_or_not of current vertice and backtrack i.e,
                                          //backtracking from currnt u, its no longer a parent
    parent_or_not[current_positionon_path]=0;//so mark it 0/false
    return flag;//return back to calling explore function
}

int acyclic(vector<vector<int> > &adj) {
  int flag=0;
  //vector<int> parent_or_not(adj.size(),0);
  map<int,bool> parent_or_not;
  vector<int> visited(adj.size(),0);
  //return explore(0,parent_or_not,visited,adj);
  for(int i = 0; i < adj.size(); i++){
     if(!visited[i]){
	      parent_or_not.clear();
	      explore(i,visited,adj,flag,parent_or_not);
      }
      if(flag==1){
        return flag;
       }
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
}
