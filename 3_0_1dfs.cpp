#include <iostream>
#include <vector>
#include <list>

using std::vector;
using std::pair;

int visit(int curnt_postionon_path, int v, vector<vector<int>> &adj, vector<int> &visited){
  std::cout<<"visit\n";
  visited[curnt_postionon_path]=1;
  int reached_v=0;
  for(int j=0;j<adj[curnt_postionon_path].size();j++){
    std::cout<<j<<"--";
    if(!visited[adj[curnt_postionon_path][j]]){
	     if(adj[curnt_postionon_path][j]==v){ 
                reached_v=1;
                break;
	     }
       else{
         reached_v= visit(adj[curnt_postionon_path][j],v,adj,visited);
         if(reached_v){break;}
         } 
       }
    }
   std::cout<<"\n";
   return reached_v;
}

int reach(vector<vector<int> > &adj, int x, int y) {
  vector<int> visited(adj.size(),0);//visited or not array
  return visit(x,y,adj,visited);
}

int main() {
  size_t n, m;
  //std::cout<<"dn"<<n;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int x, y;
  std::cin >> x >> y;
  std::cout << reach(adj, x - 1, y - 1);
}
