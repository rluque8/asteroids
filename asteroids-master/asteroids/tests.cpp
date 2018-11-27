//To compile the file  g++ -std=c++14  asteroids.cpp objects.cpp  -L /usr/lib/gcc/x86_64-linux-gnu/5/ -Wall -Wextra -Wno-deprecated -Werror -pedantic -pedantic-errors
#include  <stdlib.h>
#include <string>
#include <iostream>
#include <chrono>
#include <fstream>
#define NUM_ITERATIONS 10
using namespace std;
using namespace std::chrono;





int main (){

  double tMean=0;
  high_resolution_clock::time_point t1;
  high_resolution_clock::time_point t2;
  float duration;
  FILE * outFile;
  outFile = fopen("out_duration_part1000.txt", "w");
  //fprintf(outFile, "Iteration %d", i);
  cout << "Beginning" << endl;
	fprintf(outFile, "RESULTS SEQUENTIAL IMPLEMENTATION\n");


/*
fprintf(outFile, "For 150 asteroids, 50 iterations, 100 planets and 2000 seed: \n");
for (int k=0;k<NUM_ITERATIONS;k++){
  t1 = high_resolution_clock::now();
  system("./a.out 150 50 100 2000");
  t2 = high_resolution_clock::now();
  duration = duration_cast<microseconds>( t2 - t1 ).count();
fprintf(outFile,"Iteration: %d\n requires : %.3f ms\n",k+1, duration);
	tMean+=duration;
}
tMean/=NUM_ITERATIONS;
fprintf(outFile, "The average out of 10 iterations is: %.3f ms\n", tMean);
tMean=0;


fprintf(outFile, "For 150 asteroids, 100 iterations, 100 planets and 2000 seed: \n");
for (int k=0;k<NUM_ITERATIONS;k++){
  t1 = high_resolution_clock::now();
  system("./a.out 150 100 100 2000");
  t2 = high_resolution_clock::now();
  duration = duration_cast<microseconds>( t2 - t1 ).count();
fprintf(outFile,"Iteration: %d\n requires : %.3f ms\n",k+1, duration);
	tMean+=duration;
}
tMean/=NUM_ITERATIONS;
fprintf(outFile, "The average out of 10 iterations is: %.3f ms\n", tMean);
tMean=0;




fprintf(outFile, "For 150 asteroids, 200 iterations, 100 planets and 2000 seed: \n");
for (int k=0;k<NUM_ITERATIONS;k++){
  t1 = high_resolution_clock::now();
  system("./a.out 150 200 100 2000");
  t2 = high_resolution_clock::now();
  duration = duration_cast<microseconds>( t2 - t1 ).count();
fprintf(outFile,"Iteration: %d\n requires : %.3f ms\n",k+1, duration);
	tMean+=duration;
}
tMean/=NUM_ITERATIONS;
fprintf(outFile, "The average out of 10 iterations is: %.3f ms\n", tMean);
tMean=0;


*/
/*
fprintf(outFile, "For 250 asteroids, 50 iterations, 250 planets and 2000 seed: \n");
for (int k=0;k<NUM_ITERATIONS;k++){
  t1 = high_resolution_clock::now();
  system("./a.out 250 50 250 2000");
  t2 = high_resolution_clock::now();
  duration = duration_cast<microseconds>( t2 - t1 ).count();
fprintf(outFile,"Iteration: %d\n requires : %.3f ms\n",k+1, duration);
	tMean+=duration;
}
tMean/=NUM_ITERATIONS;
fprintf(outFile, "The average out of 10 iterations is: %.3f ms\n", tMean);
tMean=0;

fprintf(outFile, "For 250 asteroids, 100 iterations, 250 planets and 2000 seed: \n");
for (int k=0;k<NUM_ITERATIONS;k++){
  t1 = high_resolution_clock::now();
  system("./a.out 250 100 250 2000");
  t2 = high_resolution_clock::now();
  duration = duration_cast<microseconds>( t2 - t1 ).count();
fprintf(outFile,"Iteration: %d\n requires : %.3f ms\n",k+1, duration);
	tMean+=duration;
}
tMean/=NUM_ITERATIONS;
fprintf(outFile, "The average out of 10 iterations is: %.3f ms\n", tMean);
tMean=0;


fprintf(outFile, "For 250 asteroids, 200 iterations, 250 planets and 2000 seed: \n");
for (int k=0;k<NUM_ITERATIONS;k++){
  t1 = high_resolution_clock::now();
  system("./a.out 250 200 250 2000");
  t2 = high_resolution_clock::now();
  duration = duration_cast<microseconds>( t2 - t1 ).count();
fprintf(outFile,"Iteration: %d\n requires : %.3f ms\n",k+1, duration);
	tMean+=duration;
}
tMean/=NUM_ITERATIONS;
fprintf(outFile, "The average out of 10 iterations is: %.3f ms\n", tMean);
tMean=0;

*/
fprintf(outFile, "For 500 asteroids, 50 iterations, 500 planets and 2000 seed: \n");
for (int k=0;k<NUM_ITERATIONS;k++){
  t1 = high_resolution_clock::now();
  system("./a.out 500 50 500 2000");
  t2 = high_resolution_clock::now();
  duration = duration_cast<microseconds>( t2 - t1 ).count();
fprintf(outFile,"Iteration: %d\n requires : %.3f ms\n",k+1, duration);
	tMean+=duration;
}
tMean/=NUM_ITERATIONS;
fprintf(outFile, "The average out of 10 iterations is: %.3f ms\n", tMean);
tMean=0;

fprintf(outFile, "For 500 asteroids, 100 iterations, 500 planets and 2000 seed: \n");
for (int k=0;k<NUM_ITERATIONS;k++){
  t1 = high_resolution_clock::now();
  system("./a.out 500 100 500 2000");
  t2 = high_resolution_clock::now();
  duration = duration_cast<microseconds>( t2 - t1 ).count();
fprintf(outFile,"Iteration: %d\n requires : %.3f ms\n",k+1, duration);
	tMean+=duration;
}
tMean/=NUM_ITERATIONS;
fprintf(outFile, "The average out of 10 iterations is: %.3f ms\n", tMean);
tMean=0;

fprintf(outFile, "For 500 asteroids, 200 iterations, 500 planets and 2000 seed: \n");
for (int k=0;k<NUM_ITERATIONS;k++){
  t1 = high_resolution_clock::now();
  system("./a.out 500 200 500 2000");
  t2 = high_resolution_clock::now();
  duration = duration_cast<microseconds>( t2 - t1 ).count();
fprintf(outFile,"Iteration: %d\n requires : %.3f ms\n",k+1, duration);
	tMean+=duration;
}
tMean/=NUM_ITERATIONS;
fprintf(outFile, "The average out of 10 iterations is: %.3f ms\n", tMean);
tMean=0;


cout << "Ending" << endl;
  fclose(outFile);

return 0;
}
