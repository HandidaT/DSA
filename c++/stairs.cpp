/*Ques 1:“Given a stair with n steps, implement a method to count how many possible ways are there to reach the top of the staircase, given that, at every step you can either take 1 step, 2 steps, or 3 steps.”


Ques 2: Create a Stock Management application in C++

*/

#include <iostream>
using namespace std;
 
class Staircase {
 

public:
    int steps(int n)
    {
        if (n == 1 || n == 0)
            return 1;
        else if (n == 2)
            return 2;
 
        else
            return steps(n - 3) + steps(n - 2)
                                   + steps(n - 1);
    }
};
 
//Main function
int main()
{
    Staircase s;
    int n = 34;
    cout << s.steps(n);
    return 0;
}
