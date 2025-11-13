#include <iostream>
#include <vector>
#include <queue>


//Array implementation of queue. Very similar to c++ vector data structure. Capacity only increases, be wary.
class Arr_queue{
public:
   int front, rear, capacity,**array;

   Arr_queue(int c){
     front = 0,rear = 0;
     capacity=c;
     array=new (int*);
     *array=new int[capacity];
   }

   void enqueue(int data){
     if(capacity == rear){
         capacity=capacity*2;
         int *array1=new int[capacity];
		 for(int i=0;i<rear;i++){
		     array1[i]=(*array)[i];
	     }
	     delete [] (*array);
	     *array=array1;
	     std::cout<<"Queue is full";
         (*array)[rear]=data;
         rear++;
     }
     else{
         (*array)[rear]=data;
         rear++;
     }
   }

   void dequeue(){
      if(front==rear){
          std::cout<<"empty";
      }
      else{
          for(int i=0;i<capacity;i++){
              array[i]=array[i+1];
          }
          rear--;
      }
      std::cout<<front<<"--"<<rear<<"--"<<capacity<<"\n";
   }

   void display(){
      for(int i=0;i<rear;i++){
          std::cout<<(*array)[i]<<"\n";
      }
      std::cout<<"\n";
   }
   ~Arr_queue(){
   	  delete [] (*array);
      delete array;
   };
};

int distance(std::vector<std::vector<int> > &adj, int s, int t) {
  const int inf=-1;//dist[u]=500;//setting infinity. 500 is more than no of nodes so == infinity
  std::vector <int> dist(adj.size(),inf);
  dist[s]=0;
  std::queue<int> Q;
  Q.push(s);
  while(!Q.empty()){
    int u=Q.front();
    Q.pop();
    for(int v=0;v<adj[u].size();v++){
       int nxt=adj[u][v];  //creating nxt seems fast as adj[u][v] is called
       if(dist[nxt]==inf){ //several times in this for loop
          Q.push(nxt);//std::cout<<"("<<Q.front()<<" "<<Q.back()<<") ";
          dist[nxt]=dist[u]+1;
          if(nxt==t){ return dist[nxt];}
       }
    }
  }
  return -1;
}

int main() {
/*
	Arr_queue *q=new Arr_queue(2);
	q->enqueue(4);
	q->enqueue(7);
	q->enqueue(9);
	q->display();
	delete q;*/

  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int> > adj(n, std::vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, s, t);
  
/*
/home/han/Desktop/dnet/compsci/3DAA/crsra/ZbXGTnQSSm61xk50EvpuTw_b5653e5869ef44c680fb84b29011bd72_course3_2020_07_27/week3_paths_in_graphs1/1_flight_segments
5 4
5 2
1 3
3 4
1 4
3 5
should output -1

4 4
1 2
4 1
2 3
3 1
2 4
should output 2
*/
}
