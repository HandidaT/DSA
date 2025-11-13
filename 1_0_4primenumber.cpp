#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isPrime(int n)
{
    // Corner case
    if (n <= 1)
        return false;
  
    // Check from 2 to n-1
    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;
  
    return true;
}

void Eratosthenes_Sieve(int upper,vector<int>& primeNumbers){
  vector<bool> mark(sqrt(upper),true);
  
  mark[0]=false;
  mark[1]=false;
  
  cout<<"Prime numbers below the squareroot of upperbound are: ";
  
  for(int i=0; i<=sqrt(upper); i++){
    if(mark[i]==true){
      for(int j=i*2;j<=sqrt(upper);j+=i){
        mark[j]=false;
      }
    }
     
    if(mark[i]==true){
      primeNumbers.push_back(i);
      cout<<i<<" ";
    }
  }
  
  cout<<endl<<endl;
}

void Segmented_Sieve(int upperbound,int lowerbound){
  vector<bool> smark(upperbound-lowerbound+1,true);//smark is like isprime in codingninjas video
  vector<int> primes;
  vector<int> sprime;
  
  Eratosthenes_Sieve(upperbound,primes);
  
  for(int i=0;i<primes.size();i++){
    int currPrime=primes[i];
    int base=(floor(lowerbound/currPrime))*currPrime;
    if(base<lowerbound){
      base=base+currPrime;
    }
    
    for(int j=base;j<=upperbound;j+=currPrime){
      smark[j-lowerbound]=false;
    }
    
    if(base==currPrime){
      smark[base-lowerbound]=true;
    }
  }
  
  cout<<"Prime numbers between lower and upper bound are: ";
  
  for(int i=0;i<=upperbound-lowerbound;i++){
    if(smark[i]==true){
      sprime.push_back(i+lowerbound);
      cout<<i+lowerbound<<" ";
    }
  }
  cout<<endl;
}

int main(){
    isPrime(11) ? cout << " true\n" : cout << " false\n";
    isPrime(15) ? cout << " true\n" : cout << " false\n";

/*
  int t;
  cout<<endl<<"Enter the number of test cases: ";
  cin>>t;
  //i is there to show the test case number in ascending order. Without i, test cases are numbered in descending order because condition in while loop is t--.
  int i=t;
  while(t--){
    int l, u;
    cout<<endl<<endl<<"----------------Test case ";
    
    //if t was entered 10, t would be 9 because of t-- in while condition.
    //so t=9, i=10(i equaled to t before t-- while condition). Hence 9+2-10==11-10==1.
    cout<<t+2-i<<"----------------"<<endl;
    
    i-=2;
    //without i-=2, if i is as t was before loop (10), then in next loop t=8, 8+2-10==10-10=0.
    //if i is i--, 8+2-9==10-9==1. if i is i-=2, 8+2-8==10-8==2 and so on...
    
    cout<<"Enter lower bound: ";
    cin>>l; 
    cout<<"Enter upper bound: ";
    cin>>u;
    cout<<endl;
    
    Segmented_Sieve(u,l);
  }*/
}

