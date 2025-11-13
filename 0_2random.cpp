#include <iostream>
#include <random>
/*
https://www.cplusplus.com/reference/cstdlib/rand/
https://www.cplusplus.com/reference/random/
https://stackoverflow.com/questions/13445688/how-to-generate-a-random-number-in-c
*/
int main(){
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(1,6); // distribution in range [1, 6]

    std::cout << dist6(rng) << std::endl;
}
