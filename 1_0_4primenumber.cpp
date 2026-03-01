#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isPrime(int n)
{
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}

void Eratosthenes_Sieve_Primeslist(int upper)
{
    vector<bool> primes(upper, true);

    primes[0] = primes[1] = false;

    for(int i = 2; i*i <= upper; i++)
        if(primes[i])
            for(int j = i*i; j <=upper; j+=i)
                primes[j] = false;

    for(int i = 0; i < primes.size(); i++)
        if(primes[i])
            cout << i << " ";
}

void Eratosthenes_Sieve(int upper, vector<int>& primes)
{
    int limit = sqrt(upper);
    vector<bool> mark(limit + 1, true);

    mark[0] = mark[1] = false;

    for(int i = 2; i * i <= limit; i++)
        if(mark[i])
            for(int j = i * i; j <= limit; j += i)
                mark[j] = false;

    for(int i = 2; i <= limit; i++)
        if(mark[i])
            primes.push_back(i);
}

void Segmented_Sieve(int lowerbound, int upperbound)
{
    vector<int> primes;
    Eratosthenes_Sieve(upperbound, primes);

    vector<bool> smark(upperbound - lowerbound + 1, true);

    for(int p : primes)
    {
        int base = max(p * p,
                       ((lowerbound + p - 1) / p) * p);

        for(int j = base; j <= upperbound; j += p)
            smark[j - lowerbound] = false;
    }

    if(lowerbound == 1)
        smark[0] = false;

    cout << "Primes in range: ";
    for(int i = 0; i < smark.size(); i++)
        if(smark[i])
            cout << i + lowerbound << " ";
}

int main(){
    isPrime(11) ? cout << " true\n" : cout << " false\n";
    isPrime(15) ? cout << " true\n" : cout << " false\n";

  int t;
  // cout<<endl<<"Enter the number of test cases: ";
  // cin>>t;
  //i is there to show the test case number in ascending order. Without i, test cases are numbered in descending order because condition in while loop is t--.
  // int i=t;
  // while(t--){
  //   int l, u;
  //   cout<<endl<<endl<<"----------------Test case ";
    
  //   //if t was entered 10, t would be 9 because of t-- in while condition.
  //   //so t=9, i=10(i equaled to t before t-- while condition). Hence 9+2-10==11-10==1.
  //   cout<<t+2-i<<"----------------"<<endl;
    
  //   i-=2;
  //   //without i-=2, if i is as t was before loop (10), then in next loop t=8, 8+2-10==10-10=0.
  //   //if i is i--, 8+2-9==10-9==1. if i is i-=2, 8+2-8==10-8==2 and so on...
    
  //   cout<<"Enter lower bound: ";
  //   cin>>l; 
  //   cout<<"Enter upper bound: ";
  //   cin>>u;
  //   cout<<endl;
    
  //   Segmented_Sieve(l,u);
  // }

  cout<<endl<<"Enter the number: ";
  cin>>t;
  Eratosthenes_Sieve_Primeslist(t);
}

