#include <iostream>
#include <vector>

using std::vector;
using std::pair;

int visit(int curr,int t, vector<vector<int>> &adj, vector<int> &visited){
	visited[curr]=1;
	int reached_flag=0;
	vector<int> curr_n_arr=adj[curr];
	int n_size=curr_n_arr.size();
	for(int i=0;i<n_size;i++){
		int curr_n=curr_n_arr[i];
		if(!visited[curr_n]){
			if(curr_n==t){
				reached_flag= 1;
				break;
			}else{
				reached_flag=visit(curr_n,t,adj,visited);
				if(reached_flag) break;
			}
		}
	}
	return reached_flag;
}

/*
int visit(int curnt_postionon_path, int v, vector<vector<int>> &adj, vector<int> &visited){
  visited[curnt_postionon_path]=1;
  int reached_flag=0;
  vector<int> current_neighbours_arr=adj[curnt_postionon_path];
  int n_size=current_neighbours_arr.size();//number of neighbouring vertices
  for(int i=0;i<n_size;i++){
      int current_neighbour=current_neighbours_arr[i];
      if(!visited[current_neighbour]){
          if(current_neighbour==v){
            reached_flag = 1;
            break;
          }else{
            reached_flag = visit(current_neighbour,v,adj,visited);
            if(reached_flag==1) return 1;
          }
  	}
  }
  //if(reached_flag==1) return 1;
  return reached_flag;
}*/
//were not looping(for) through all in adj in this func, as we're only supposed to find path b/t s and t vertices
int reach(vector<vector<int>> &adj, int s,int t){
	vector<int> visited(adj.size(),0);//visited or not array
	return visit(s,t,adj,visited);
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
  
/*
/home/han/Desktop/dnet/compsci/3DAA/crsra/ZbXGTnQSSm61xk50EvpuTw_b5653e5869ef44c680fb84b29011bd72_course3_2020_07_27/week1_graph_decomposition1/1_finding_exit_from_maze

4 4
1 2
3 2
4 3
1 4
1 4
should output 1

4 2
1 2
3 2
1 4
should output 0

*/
}
