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

int distance(vector<vector<int> > &adj, int s, int t) {
  const int inf=-1;
  vector <int> dist(adj.size(),inf);
  //for(int u=0;u<adj.size();u++){ vector seems faster than for loop
    //dist[u]=500;//setting infinity. 500 is more than no of nodes so == infinity
    //std::cout<<u<<" ";
  //}
  dist[s]=0;
  queue<int> Q;
  Q.push(s);
  //std::cout<<Q.front()<<Q.empty()<<std::endl;
  while(!Q.empty()){
    int u=Q.front();
    //std::cout<<"#"<<u<<" ";
    Q.pop();
    for(int v=0;v<adj[u].size();v++){
       int nxt=adj[u][v];  //creating nxt seems fast as adj[u][v] is called
       if(dist[nxt]==inf){ //several times in this for loop
          Q.push(nxt);
      //    std::cout<<"("<<Q.front()<<" "<<Q.back()<<") ";
          dist[nxt]=dist[u]+1;
          if(nxt==t){ return dist[nxt];}
       }
    }
  }

  return -1;
}





































int main() {

	Arr_queue *q=new Arr_queue(2);
	q->enqueue(4);
	q->enqueue(7);
	q->enqueue(9);
	q->display();
	delete q;
/*
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, s, t);*/
}
