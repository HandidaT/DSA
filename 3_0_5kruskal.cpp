#include <algorithm>
#include <cassert>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using std::vector;
using std::pair;

struct edge {
  int u;
  int v;
  double weight;
  
  edge(int a, int b, double c) {
    u = a;
    v = b;
    weight = c;
  }
};

struct node {
  int x;
  int y;
  int parent;
  int rank;
	
  node(int a, int b, int c = -1, int d = 0) {
    x = a;
    y = b;
    parent = c;
    rank = d;
  }
};

bool compare(edge a, edge b) {
  //std::cout<<(a.weight < b.weight)<<std::endl;
  return a.weight < b.weight;
}

void create_set(vector<node> &nodes, vector<int> &x, vector<int> &y, int i) {
  nodes.push_back(node(x[i], y[i], i));
}

double weight(int x1, int y1, int x2, int y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int find(int i, vector<node> &nodes) {
  if (i != nodes[i].parent) {
    nodes[i].parent = find(nodes[i].parent, nodes);
  }
  return nodes[i].parent;
}

void Union(int u, int v, vector<node> &nodes) {
  int r1 = find(u, nodes);
  int r2 = find(v, nodes);
  if (r1 != r2) {
    if (nodes[r1].rank > nodes[r2].rank) {
      nodes[r2].parent = r1;
    } else {
      nodes[r1].parent = r2;
      if (nodes[r1].rank == nodes[r2].rank) {
        nodes[r2].rank++;
      }
    }
  }
}

double minimum_distance(vector<int> x, vector<int> y) {
  double result = 0.;
  int n = x.size();
  vector<node> nodes;
  for (int i = 0; i < n; i++) {
	create_set(nodes, x, y, i);
  }
  vector<edge> edges;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      std::cout<<i<<" "<<j<<" "<<x[i]<<y[i]<<" "<<x[j]<<y[j]<<"\n";
      edges.push_back(edge(i, j, weight(x[i], y[i], x[j], y[j])));
    }
  }
  std::cout<<edges.size()<<"\n";
  std::sort(edges.begin(), edges.end(), compare);
  for (int i = 0; i < edges.size(); i++) {
    edge current_edge = edges[i];
    int u = current_edge.u;
    int v = current_edge.v;
    if (find(u, nodes) != find(v, nodes)) {//finding representative of set of elements u and v
      result += current_edge.weight;
      std::cout<<result<<"\n";
      Union(u, v, nodes);
    }
  }
  return result;
}









//Clustering///////////////////////////////////////////////////////////////////////////////////////////////////////////
struct Node {
  int start, end;
  double dis;
  Node(int x, int y, double d) : start(x), end(y), dis(d){};
  bool operator<(const Node &a) const { return dis < a.dis; }
  // bool operator>(const Node &a) const { return dis < a.dis; }
  // 优先队列需要同时重载<和>
};
int Find(int x, vector<int> &parent) {
  if (x != parent[x])
    parent[x] = Find(parent[x], parent);
  return parent[x];
}
void Union_cluster(int x, int y, vector<int> &parent) {
  int left = Find(x, parent);
  int right = Find(y, parent);
  if (left != right) {
    parent[right] = left;
  }
}

double clustering(vector<int> x, vector<int> y, int k) {
  // write your code here
  int num = 0;
  vector<int> parent(x.size());
  vector<Node> q;               
  for (size_t i = 0; i < x.size(); i++) 
    parent[i] = i;
  for (size_t i = 0; i < x.size(); i++) {
    for (size_t j = i + 1; j < x.size(); j++) {
      double dis =
          sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
      q.push_back(Node(i, j, dis));
    }
  }
  std::sort(q.begin(), q.end());

  for (size_t i = 0; i < q.size(); i++) {
    Node v = q[i];
    if (Find(v.start, parent) !=
        Find(v.end, parent)) { 
      if (num == x.size() - k) 
        return v.dis;
      num++;                     
      Union_cluster(v.start, v.end, parent);
    }
  }
}

int main() {
/*
  size_t n;
  std::cin >> n;
  vector<int> x(n), y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cout << std::setprecision(10) << minimum_distance(x, y) << std::endl;

/home/han/Desktop/dnet/compsci/3DAA/crsra/ZbXGTnQSSm61xk50EvpuTw_b5653e5869ef44c680fb84b29011bd72_course3_2020_07_27/week5_spanning_trees/1_connecting_points

4
0 0
0 1
1 0
1 1
should output 3

5
0 0
0 2
1 1
3 0
3 2
should output 7.064495102



*/

  size_t n;
  int k;
  std::cin >> n;
  vector<int> x(n), y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cin >> k;
  std::cout << std::setprecision(10) << clustering(x, y, k) << std::endl;

/*
/home/han/Desktop/dnet/compsci/3DAA/crsra/ZbXGTnQSSm61xk50EvpuTw_b5653e5869ef44c680fb84b29011bd72_course3_2020_07_27/week5_spanning_trees/2_clustering

12
7 6
4 3
5 1
1 7
2 7
5 7
3 3
7 8
2 8
4 4
6 7
2 6
3
should output 2.828427125

8
3 1
1 2
4 6
9 8
9 9
8 9
3 11
4 12
4
should output 5


*/


}
