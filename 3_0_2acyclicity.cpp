#include <iostream>
#include <vector>
#include <map>
#include <bits/stdc++.h>


using std::vector;
using std::map;

int explore(int current_positionon_path, vector<int> &visited,vector<vector<int> > &adj,
            int &flag,map<int, bool> &recur_list){
    visited[current_positionon_path]=1;
    recur_list[current_positionon_path]=true;
    for(int j=0;j<adj[current_positionon_path].size();j++){
       if(!visited[adj[current_positionon_path][j]]){
	          flag=explore(adj[current_positionon_path][j],visited,adj,flag,recur_list);
       }
       else if(recur_list[adj[current_positionon_path][j]]){
	          flag=1;
            std::cout<<"Cycle present\n";
            return flag;//stop exploring when cycle found
       }
       if(flag) return flag;
    }//All vertices reachable from this current vertice are explored and no cycle detected,
     //so we can write false/0 for the recur_list of current vertice and backtrack i.e,
    recur_list[current_positionon_path]=0;//return back to calling explore function
    return flag;
}

int acyclic(vector<vector<int> > &adj) {
  int flag=0;
  //vector<int> recur_list(adj.size(),0);
  map<int,bool> recur_list;
  vector<int> visited(adj.size(),0);
  //return explore(0,recur_list,visited,adj);
  for(int i = 0; i < adj.size(); i++){
     if(!visited[i]){
	      recur_list.clear();
	      explore(i,visited,adj,flag,recur_list);
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
