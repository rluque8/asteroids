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

//  vector <Map::Planet> planets;//Vector of asteroids

  ofstream outfile ("init_conf.txt");
/*{
  outfile << num_asteroids << " " << num_iterations << " " << num_planets << " " << seed << "\n";
  for(int i=0;i<num_asteroids;i++){
    asteroids.push_back(Map::Asteroid());
    map.initializeAsteroid(&asteroids[i], i);
    cout << "Position of asteroid " << i << " is " << asteroids[i].x << endl;
    cout << "Position of asteroid "  << i << " is " << asteroids[i].y << endl;
    cout << "Mass of asteroid "  << i << " is " << asteroids[i].mass << endl;
    outfile << asteroids[i].x << " " << asteroids[i].y << " " << asteroids[i].mass << endl;
   }
  outfile.close();
}
else{
  cout << "Unable to create file";
  return -1;
}*/

asteroids.push_back(Map::Asteroid());
asteroids[0].x = 0;
asteroids[0].y = 5;
map.rebound(&asteroids[0]);

  cout << "Asteroids: " << num_asteroids << " Iterations: " << num_iterations
  << " Planets: " << num_planets << " Seed: " << seed << " \n";
  for(int i = 0; i < num_asteroids; i++){
    for(int j = 0; j < num_asteroids; j++){
      if( i == j){
        continue;
      }
      map.computeDistance(&asteroids[i], &asteroids[j]);
      cout << "Distance of " << i << " and " << j << " is " << asteroids[i].distances[j] << endl;
    }
  }



    return 0;
    }
  }
