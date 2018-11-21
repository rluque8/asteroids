//To compile the file  g++ -std=c++14  asteroids.cpp objects.cpp  -L /usr/lib/gcc/x86_64-linux-gnu/5/ -Wall -Wextra -Wno-deprecated -Werror -pedantic -pedantic-errors
#include "objects.cpp" //Header items to be used in the program (planet struct, asteroid struct and functions)
#include  <stdlib.h>
#include <string>
#include <vector>
#include <random>

#include <iostream>
#include <fstream>
using namespace std;


  int main (int argc, char **argv){


  // int num_asteroids;
  // int num_iterations;
  // int num_planets;
  // int seed;

  if(argc != 5){
    cout << " nasteroids-seq: Wrong arguments " << "\n";
        cout << " Correct use: " << "\n";
            cout << " nasteroids-seq num_asteroids num_iterations num_planets seed " << "\n";
    return -1;
  }
else{
  int num_asteroids=atoi(argv[1]);
  int num_iterations=atoi(argv[2]);
  int num_planets=atoi(argv[3]);
  int seed=atoi(argv[4]);
  Map map =  Map(seed);
  vector <Map::Asteroid> asteroids;//Vector of asteroids
  vector <Map::Planet> planets;//Vector of asteroids

  ofstream initfile ("init_conf.txt");
  ofstream outfile ("out.txt");

if(initfile.is_open()){
  initfile << num_asteroids << " " << num_iterations << " " << num_planets << " " << seed << "\n";
  for(int i=0;i<num_asteroids;i++){
    asteroids.push_back(Map::Asteroid());
    map.initializeAsteroid(&asteroids[i], i);
    // cout << "Position of asteroid " << i << " is " << asteroids[i].x << endl;
    // cout << "Position of asteroid "  << i << " is " << asteroids[i].y << endl;
    // cout << "Mass of asteroid "  << i << " is " << asteroids[i].mass << endl;
    initfile << asteroids[i].x << " " << asteroids[i].y << " " << asteroids[i].mass << endl;
   }

   //Initializing the planets
   for(int i=0;i<num_planets;i++){
     planets.push_back(Map::Planet());
     map.initializePlanet(&planets[i], i);
    //  cout << "Position of planet " << i << " is " << planets[i].x << endl;
    //  cout << "Position of planet "  << i << " is " << planets[i].y << endl;
    //  cout << "Mass of planet "  << i << " is " << planets[i].mass << endl;
     initfile << planets[i].x << " " << planets[i].y << " " << planets[i].mass << endl;
    }
    // cout << "Asteroids: " << num_asteroids << " Iterations: " << num_iterations
    // << " Planets: " << num_planets << " Seed: " << seed << " \n";

  initfile.close();

}else{
  cout << "Unable to create file";
  return -1;
}





for(int k = 0; k < num_iterations; k++){
//initializing normal flow of the program
cout << "Iteration: " << k << endl;
  for(int i = 0; i < num_asteroids; i++){
    for(int j = 0; j < max(num_asteroids, num_planets); j++){
      if( i == j){
        continue;
      }
      if(j < num_asteroids-1){
        map.computeDistance(&asteroids[i], &asteroids[j]); //COmputing Distance between asteroids
        cout << "Asteroids " <<  " Distance of " << i << " and " << j << " is " << asteroids[i].distances[j] << endl;
        map.normalMode(&asteroids[i],&asteroids[j]);
      }

      if(j > num_planets-1){
        continue;
      }else{
        cout << "J is: " << j << endl;
        map.computeDistancePlanets(&asteroids[i], &planets[j]); //COmputing Distance between asteroids and planets
        cout << "Planets " <<  " Distance of " << i << " and " << j << " is " << asteroids[i].distances_planets[j] << endl;
        map.normalModePlanet(&asteroids[i],&planets[j]);
      }
    }
  }
}

FILE * outFile;
outFile = fopen("out.txt", "w");
for(int k = 0; k < num_asteroids; k++){ //Writting final results
    cout << asteroids[k].x << " " << asteroids[k].y << " " << asteroids[k].mass << " VelocityX " << asteroids[k].velocityX << " VelocityY " << asteroids[k].velocityY << endl;
    fprintf(outFile, "%f %f %f %f %f\n", asteroids[k].x, asteroids[k].y, asteroids[k].velocityX, asteroids[k].velocityY, asteroids[k].mass);
    //outfile << asteroids[k].x << " " << asteroids[k].y << " " <<asteroids[k].mass << endl;
  }
  fclose(outFile);



    return 0;
    }
  }
