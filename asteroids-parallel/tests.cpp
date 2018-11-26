//To compile the file  g++ -std=c++14  tests.cpp -o test.out  -L /usr/lib/gcc/x86_64-linux-gnu/5/ -Wall -Wextra -Wno-deprecated -Werror -pedantic -pedantic-errors
#include  <stdlib.h>
#include <string>
#include <vector>
#include <random>
#include <iostream>
#include <chrono>
#include <fstream>
using namespace std;
using namespace std::chrono;





int main (){
  high_resolution_clock::time_point t1;
  high_resolution_clock::time_point t2;
  float duration;
  FILE * outFile;
  outFile = fopen("out_duration.txt", "w");
  //fprintf(outFile, "Iteration %d", i);
  cout << "Beginning" << endl;
  t1 = high_resolution_clock::now();

  system("./a.out 500 50 250 2000 1");
  t2 = high_resolution_clock::now();
  duration = duration_cast<microseconds>( t2 - t1 ).count();
  fprintf(outFile, "For 500 asteroids, 50 iterations, 250 planets and 2000 seed and 1 thread, sequential is: %.3f ms\n", duration);

  t1 = high_resolution_clock::now();
  system("./a.out 500 50 250 2000 2");
  t2 = high_resolution_clock::now();
  duration = duration_cast<microseconds>( t2 - t1 ).count();
  fprintf(outFile, "For 500 asteroids, 50 iterations, 250 planets and 2000 seed and 2 threads, sequential is: %.3f ms\n", duration);

  t1 = high_resolution_clock::now();
  system("./a.out 500 50 250 2000 4");
  t2 = high_resolution_clock::now();
  duration = duration_cast<microseconds>( t2 - t1 ).count();
  fprintf(outFile, "For 500 asteroids, 50 iterations, 250 planets and 2000 seed and 4 threads, sequential is: %.3f ms\n", duration);

  t1 = high_resolution_clock::now();
  system("./a.out 500 50 250 2000 8");
  t2 = high_resolution_clock::now();
  duration = duration_cast<microseconds>( t2 - t1 ).count();
  fprintf(outFile, "For 500 asteroids, 50 iterations, 250 planets and 2000 seed and 8 threads, sequential is: %.3f ms\n", duration);

  t1 = high_resolution_clock::now();
  system("./a.out 500 50 250 2000 16");
  t2 = high_resolution_clock::now();
  duration = duration_cast<microseconds>( t2 - t1 ).count();
  fprintf(outFile, "For 500 asteroids, 50 iterations, 250 planets and 2000 seed and 16 threads, sequential is: %.3f ms\n", duration);


cout << "Ending" << endl;
  fclose(outFile);

return 0;
}
