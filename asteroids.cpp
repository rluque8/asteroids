//To compile the file gcc main.cpp -lstdc++ -o main
  #include "objects.h" //Header items to be used in the program (planet struct, asteroid struct and functions)

  #include <string>
  #include <vector>
  #include <iostream>
  using namespace std;


  int main (int argc, char **argv){

  vector <asteroid> asteroids;//Vector of asteroids
  int asteroid_number = 0;

  cout << "Enter number of asteroids " << "\n";
  cin >> asteroid_number;
    for( int i = 0; i< asteroid_number; i++){
      asteroids.push_back(asteroid()); //Adding one element to the vector
      asteroids[i].mass = 3 * i + 5;
      cout << "Mass for asteroid " << i << " is " << asteroids[i].mass << "\n";
      asteroids[i].setPositionAsteroid(&asteroids[i]);
      //asteroids[i].x = 8;
      cout << "Position of asteroid " << asteroids[i].x << endl;
    }


    return 0;
  }
