//To compile the file  g++ -std=c++14  asteroids.cpp objects.cpp  -L /usr/lib/gcc/x86_64-linux-gnu/5/ -Wall -Wextra -Wno-deprecated -Werror -pedantic -pedantic-errors
#include  <stdlib.h>
#include <string>
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

  system("./a.out 250 50 250 2000");
  t2 = high_resolution_clock::now();

  duration = duration_cast<microseconds>( t2 - t1 ).count();


  fprintf(outFile, "For 250 asteroids, 50 iterations, 250 planets and 2000 seed, sequential is: %.3f ms\n", duration);
  t1 = high_resolution_clock::now();
  system("./a.out 500 50 250 2000");
  t2 = high_resolution_clock::now();
  duration = duration_cast<microseconds>( t2 - t1 ).count();
  fprintf(outFile, "For 500 asteroids, 50 iterations, 250 planets and 2000 seed, sequential is: %.3f ms\n", duration);

  t1 = high_resolution_clock::now();
  system("./a.out 1000 50 250 2000");
  t2 = high_resolution_clock::now();
  duration = duration_cast<microseconds>( t2 - t1 ).count();
  fprintf(outFile, "For 1000 asteroids, 50 iterations, 250 planets and 2000 seed, sequential is: %.3f ms\n", duration);

  t1 = high_resolution_clock::now();
  system("./a.out 250 100 250 2000");
  t2 = high_resolution_clock::now();
  duration = duration_cast<microseconds>( t2 - t1 ).count();
  fprintf(outFile, "For 250 asteroids, 100 iterations, 250 planets and 2000 seed, sequential is: %.3f ms\n", duration);

  t1 = high_resolution_clock::now();
  system("./a.out 500 100 250 2000");
  t2 = high_resolution_clock::now();
  duration = duration_cast<microseconds>( t2 - t1 ).count();
  fprintf(outFile, "For 500 asteroids, 100 iterations, 250 planets and 2000 seed, sequential is: %.3f ms\n", duration);

  t1 = high_resolution_clock::now();
  system("./a.out 1000 100 250 2000");
  t2 = high_resolution_clock::now();
  duration = duration_cast<microseconds>( t2 - t1 ).count();
  fprintf(outFile, "For 1000 asteroids, 100 iterations, 250 planets and 2000 seed, sequential is: %.3f ms\n", duration);

  t1 = high_resolution_clock::now();
  system("./a.out 250 200 250 2000");
  t2 = high_resolution_clock::now();
  duration = duration_cast<microseconds>( t2 - t1 ).count();
  fprintf(outFile, "For 250 asteroids,200 iterations, 250 planets and 2000 seed, sequential is: %.3f ms\n", duration);

  t1 = high_resolution_clock::now();
  system("./a.out 500 200 250 2000");
  t2 = high_resolution_clock::now();
  duration = duration_cast<microseconds>( t2 - t1 ).count();
  fprintf(outFile, "For 500 asteroids, 200 iterations, 250 planets and 2000 seed, sequential is: %.3f ms\n", duration);

  t1 = high_resolution_clock::now();
  system("./a.out 1000 200 250 2000");
  t2 = high_resolution_clock::now();
  duration = duration_cast<microseconds>( t2 - t1 ).count();
  fprintf(outFile, "For 1000 asteroids, 200 iterations, 250 planets and 2000 seed, sequential is: %.3f ms\n", duration);

  //Fixed asteroid, planet number changes

  t1 = high_resolution_clock::now();
  system("./a.out 250 50 500 2000");
  t2 = high_resolution_clock::now();
  duration = duration_cast<microseconds>( t2 - t1 ).count();
  fprintf(outFile, "For 250 asteroids, 50 iterations, 500 planets and 2000 seed, sequential is: %.3f ms\n", duration);

  t1 = high_resolution_clock::now();
  system("./a.out 250 50 1000 2000");
  t2 = high_resolution_clock::now();
  duration = duration_cast<microseconds>( t2 - t1 ).count();
  fprintf(outFile, "For 250 asteroids, 50 iterations, 1000 planets and 2000 seed, sequential is: %.3f ms\n", duration);

  t1 = high_resolution_clock::now();
  system("./a.out 250 100 500 2000");
  t2 = high_resolution_clock::now();
  duration = duration_cast<microseconds>( t2 - t1 ).count();
  fprintf(outFile, "For 250 asteroids, 100 iterations, 500 planets and 2000 seed, sequential is: %.3f ms\n", duration);

  t1 = high_resolution_clock::now();
  system("./a.out 250 100 1000 2000");
  t2 = high_resolution_clock::now();
  duration = duration_cast<microseconds>( t2 - t1 ).count();
  fprintf(outFile, "For 250 asteroids, 100 iterations, 1000 planets and 2000 seed, sequential is: %.3f ms\n", duration);

  t1 = high_resolution_clock::now();
  system("./a.out 250 200 500 2000");
  t2 = high_resolution_clock::now();
  duration = duration_cast<microseconds>( t2 - t1 ).count();
  fprintf(outFile, "For 250 asteroids, 200 iterations, 500 planets and 2000 seed, sequential is: %.3f ms\n", duration);

  t1 = high_resolution_clock::now();
  system("./a.out 250 200 1000 2000");
  t2 = high_resolution_clock::now();
  duration = duration_cast<microseconds>( t2 - t1 ).count();
  fprintf(outFile, "For 1000 asteroids, 200 iterations, 250 planets and 2000 seed, sequential is: %.3f ms\n", duration);

  t1 = high_resolution_clock::now();
  system("./a.out 500 50 500 2000");
  t2 = high_resolution_clock::now();
  duration = duration_cast<microseconds>( t2 - t1 ).count();
  fprintf(outFile, "For 500 asteroids, 50 iterations, 500 planets and 2000 seed, sequential is: %.3f ms\n", duration);

  t1 = high_resolution_clock::now();
  system("./a.out 500 50 1000 2000");
  t2 = high_resolution_clock::now();
  duration = duration_cast<microseconds>( t2 - t1 ).count();
  fprintf(outFile, "For 500 asteroids, 50 iterations, 1000 planets and 2000 seed, sequential is: %.3f ms\n", duration);

  t1 = high_resolution_clock::now();
  system("./a.out 500 100 500 2000");
  t2 = high_resolution_clock::now();
  duration = duration_cast<microseconds>( t2 - t1 ).count();
  fprintf(outFile, "For 500 asteroids, 50 iterations, 500 planets and 2000 seed, sequential is: %.3f ms\n", duration);

  t1 = high_resolution_clock::now();
  system("./a.out 500 100 1000 2000");
  t2 = high_resolution_clock::now();
  duration = duration_cast<microseconds>( t2 - t1 ).count();
  fprintf(outFile, "For 500 asteroids, 50 iterations, 1000 planets and 2000 seed, sequential is: %.3f ms\n", duration);

  t1 = high_resolution_clock::now();
  system("./a.out 500 200 500 2000");
  t2 = high_resolution_clock::now();
  duration = duration_cast<microseconds>( t2 - t1 ).count();
  fprintf(outFile, "For 500 asteroids, 50 iterations, 500 planets and 2000 seed, sequential is: %.3f ms\n", duration);

  t1 = high_resolution_clock::now();
  system("./a.out 500 200 1000 2000");
  t2 = high_resolution_clock::now();
  duration = duration_cast<microseconds>( t2 - t1 ).count();
  fprintf(outFile, "For 500 asteroids, 50 iterations, 1000 planets and 2000 seed, sequential is: %.3f ms\n", duration);


    t1 = high_resolution_clock::now();
    system("./a.out 1000 50 500 2000");
    t2 = high_resolution_clock::now();
    duration = duration_cast<microseconds>( t2 - t1 ).count();
    fprintf(outFile, "For 1000  asteroids, 50 iterations, 500 planets and 2000 seed, sequential is: %.3f ms\n", duration);

    t1 = high_resolution_clock::now();
    system("./a.out 1000 50 1000 2000");
    t2 = high_resolution_clock::now();
    duration = duration_cast<microseconds>( t2 - t1 ).count();
    fprintf(outFile, "For 1000 asteroids, 50 iterations, 1000 planets and 2000 seed, sequential is: %.3f ms\n", duration);

    t1 = high_resolution_clock::now();
    system("./a.out 1000 100 500 2000");
    t2 = high_resolution_clock::now();
    duration = duration_cast<microseconds>( t2 - t1 ).count();
    fprintf(outFile, "For 1000 asteroids, 50 iterations, 500 planets and 2000 seed, sequential is: %.3f ms\n", duration);

    t1 = high_resolution_clock::now();
    system("./a.out 1000  100 1000 2000");
    t2 = high_resolution_clock::now();
    duration = duration_cast<microseconds>( t2 - t1 ).count();
    fprintf(outFile, "For 1000  asteroids, 50 iterations, 1000 planets and 2000 seed, sequential is: %.3f ms\n", duration);

    t1 = high_resolution_clock::now();
    system("./a.out 1000  200 500 2000");
    t2 = high_resolution_clock::now();
    duration = duration_cast<microseconds>( t2 - t1 ).count();
    fprintf(outFile, "For 1000  asteroids, 50 iterations, 500 planets and 2000 seed, sequential is: %.3f ms\n", duration);

    t1 = high_resolution_clock::now();
    system("./a.out 1000 200 1000 2000");
    t2 = high_resolution_clock::now();
    duration = duration_cast<microseconds>( t2 - t1 ).count();
    fprintf(outFile, "For 1000 asteroids, 50 iterations, 1000 planets and 2000 seed, sequential is: %.3f ms\n", duration);
cout << "Ending" << endl;
  fclose(outFile);

return 0;
}
