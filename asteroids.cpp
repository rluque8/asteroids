//To compile the file gcc main.cpp -lstdc++ -o main
  #include "objects.h" //Header items to be used in the program (planet struct, asteroid struct and functions)

  #include <string>
  #include <vector>
  #include <iostream>
  using namespace std;


  int main (int argc, char **argv){
  vector <asteroid> asteroids;//Vector of asteroids
  int num_asteroids;
  int num_iterations;
  int num_planets;
  int seed;

  if(argc != 5){
    cout << " nasteroids-seq: Wrong arguments " << "\n";
        cout << " Correct use: " << "\n";
            cout << " nasteroids-seq num_asteroids num_iterations num_planets seed " << "\n";
return -1;
  }
else{
  cout << "Enter number of asteroids " << "\n";
  cin >> num_asteroids;
  cout << "Enter number of iterations " << "\n";
  cin >> num_iterations;
  cout << "Enter number of planets " << "\n";
  cin >> num_planets;
  cout << "Enter the seed " << "\n";
  cin >> seed;

  cout << "Asteroids: " << num_asteroids << " Iterations: " << num_iterations
  << " Planets: " << num_planets << " Seed: " << seed << " \n";
    for( int i = 0; i< num_asteroids; i++){
      asteroids.push_back(asteroid()); //Adding one element to the vector
      asteroids[i].mass = 3 * i + 5;
      cout << "Mass for asteroid " << i << " is " << asteroids[i].mass << "\n";
      asteroids[i].setPositionAsteroid(&asteroids[i]);
      //asteroids[i].x = 8;
      cout << "Position of asteroid " << asteroids[i].x << endl;
    }


    return 0;
  }
  }
