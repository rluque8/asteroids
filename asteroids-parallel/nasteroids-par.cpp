//To compile the file  g++ -std=c++14  asteroids.cpp objects.cpp  -L /usr/lib/gcc/x86_64-linux-gnu/5/ -Wall -Wextra -Wno-deprecated -Werror -pedantic -pedantic-errors
#include "objects.cpp" //Header items to be used in the program (planet struct, asteroid struct and functions)
#include <stdlib.h>
#include <omp.h>
#include <string>
#include <vector>
#include <random>

#include <iostream>
#include <fstream>
using namespace std;


int main (int argc, char **argv){

  omp_set_num_threads(atoi(argv[5]));

  if(argc != 6){ //CAAAAAAAAMMMMMBBIIIIIIIIAAAARRRR a 5
    cout << " nasteroids-par: Wrong arguments " << "\n";
    cout << " Correct use: " << "\n";
    cout << " nasteroids-par num_asteroids num_iterations num_planets seed " << "\n";
    return -1;
  }
  else{
    int num_asteroids=atoi(argv[1]);
    int num_iterations=atoi(argv[2]);
    int num_planets=atoi(argv[3]);
    int seed=atoi(argv[4]);
    int j;
    Map map =  Map(seed);
    vector <Map::Asteroid> asteroids;//Vector of asteroids
    vector <Map::Planet> planets;//Vector of asteroids

    ofstream initfile ("init_conf.txt");
    ofstream outfile ("out.txt");

    if(initfile.is_open()){
      initfile << num_asteroids << " " << num_iterations << " " << num_planets << " " << seed << "\n";
      //Initializing the asteroids
      for(int i=0;i<num_asteroids;i++){
        asteroids.push_back(Map::Asteroid());
        map.initializeAsteroid(&asteroids[i], i);
        initfile << asteroids[i].x << " " << asteroids[i].y << " " << asteroids[i].mass << endl;
      }

      //Initializing the planets
      for(int i=0;i<num_planets;i++){
        planets.push_back(Map::Planet());
        map.initializePlanet(&planets[i], i);
        initfile << planets[i].x << " " << planets[i].y << " " << planets[i].mass << endl;
      }

      initfile.close();

    }else{
      cout << "Unable to create file";
      return -1;
    }

    for(int k = 0; k < num_iterations; k++){
      #pragma omp for private(j)
      for(int i = 0; i < num_asteroids; i++){
        for(j = 0; j < max(num_asteroids, num_planets); j++){
          if( i == j){
            continue;
          }
          if(j < num_asteroids-1){
            map.computeDistance(&asteroids[i], &asteroids[j]); //Computing Distance between asteroids
          }

          if(j > num_planets-1){
            continue;
          }else{
            map.computeDistancePlanets(&asteroids[i], &planets[j]); //Computing Distance between asteroids and planets
          }
        }
      }
      #pragma omp barrier //Barrier to synchronize all the threads before getting into the computation and avoid critical sections
      #pragma omp for private(j)
      for(int i = 0; i < num_asteroids; i++){
        for(j = 0; j < max(num_asteroids, num_planets); j++){
          if( i == j){
            continue;
          }
          if(j < num_asteroids-1){
            map.normalMode(&asteroids[i],&asteroids[j]); //Computing Normal movement of asteroids
          }

          if(j > num_planets-1){
            continue;
          }else{
            map.normalModePlanet(&asteroids[i],&planets[j]); //Computing normal movement of asteroids and planets
          }
        }
      }
    }

    FILE * outFile; //Creating output file to save the final values after the iterations
    outFile = fopen("out.txt", "w");
    for(int k = 0; k < num_asteroids; k++){ //Writting final results
      fprintf(outFile, "%.3f %.3f %.3f %.3f %.3f\n", asteroids[k].x, asteroids[k].y, asteroids[k].velocityX, asteroids[k].velocityY, asteroids[k].mass);
    }
    fclose(outFile);




    return 0;

  }
}
