#include <iostream>
#include <vector>
#include <map>
#include <bits/stdc++.h>


using std::vector;
using std::map;

int explore(int current_positionon_path, vector<int> &visited,vector<vector<int> > &adj,
            int &flag,map<int, bool> &ancestor,vector<int> &sortedflag,vector<int> &sorted){
    visited[current_positionon_path]=1;
    ancestor[current_positionon_path]=true;
    vector<int> current_neighbours_arr=adj[current_positionon_path];
    int n_size=current_neighbours_arr.size();
    for(int j=0;j<n_size;j++){
        std::cout<<"\n--"<<current_positionon_path+1<<" "<<current_neighbours_arr[j]+1<<" "<<sortedflag[current_neighbours_arr[j]];
        if(!sortedflag[current_neighbours_arr[j]]){
            if(!visited[current_neighbours_arr[j]]){
                    explore(current_neighbours_arr[j],visited,adj,flag,ancestor,sortedflag,sorted);
            }
            else if(ancestor[current_neighbours_arr[j]]){
                    flag=1;
                    std::cout<<"Cycle presentt\n";
                    return flag;//stop exploring when cycle found
            }
            if(flag) return flag;
        }
    }
    sorted.push_back(current_positionon_path);
    std::cout<<"\n-"<<current_positionon_path+1;
    sortedflag[current_positionon_path]=1;
//All vertices reachable from this current vertice are explored and no cycle detected, so we can write false/0 for
//ancestor of current vertice and backtrack i.e, backtracking from currnt u, its no longer a parent
    ancestor[current_positionon_path]=0;//so mark it 0/false
    return flag;//return back to calling explore function
}

int acyclic(vector<vector<int> > &adj) {
  int flag=0;
  vector<int> sortedflag(adj.size(),0);
  vector<int> sorted;
  map<int,bool> ancestor;
  vector<int> visited(adj.size(),0);
  //return explore(0,ancestor,visited,adj);
  for(int i = 0; i < adj.size(); i++){
    std::cout<<"\n---";
     if(!visited[i]){
	      ancestor.clear();
	      explore(i,visited,adj,flag,ancestor,sortedflag,sorted);
      }
      if(flag) return flag;
   }
   std::cout<<"\n";
  for (int j = (sorted.size()-1); j > -1; j--) {
    std::cout << sorted[j] + 1 << " ";
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
  int cyclic = acyclic(adj);
  std::cout <<"\ncyclic ="<< cyclic;
/*
/home/han/Desktop/dnet/compsci/3DAA/crsra/ZbXGTnQSSm61xk50EvpuTw_b5653e5869ef44c680fb84b29011bd72_course3_2020_07_27/week2_graph_decomposition2/2_order_of_courses

4 3
1 2
4 1
3 1
should output 4 3 1 2

4 1
3 1
should output 4 3 2 1 or 2 3 1 4 (1 should be after 3 in putput)

5 7
2 1
3 2
3 1
4 3
4 1
5 2
5 3
should output 5 4 3 2 1

*/
}
