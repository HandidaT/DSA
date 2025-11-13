#include <iostream>
#include <chrono>

int main() {
  // Record start time
  auto start = std::chrono::high_resolution_clock::now();

  // Your code to be timed
  // ...

  // Record end time
  auto end = std::chrono::high_resolution_clock::now();

  // Calculate elapsed time in nanoseconds
  auto elapsed_time = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

  // Print result (convert to desired units)
  std::cout << "Elapsed time: " << elapsed_time.count() / 1e9 << " seconds" << std::endl;

  return 0;
}
