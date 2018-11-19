#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <stdlib.h>
#include <math.h>

using namespace std;
class Map {
  public:
  extern const double gravity	= 6.674e-5;
  extern const double delta_t	= 0.1;
  extern const double dmin		= 2.0;
  extern const int width		= 200;
  extern const int height		= 200;
  extern const double ray_width	= 4;
  extern const double mass		= 1000;
  extern const double sdm		= 50;
  static default_random_engine re;
  static uniform_real_distribution<double> xdist;
  static uniform_real_distribution<double> ydist;
  static normal_distribution<double> mdist;


    Map(unsigned long seed){
       re = static_cast<unsigned int> (default_random_engine{seed});
       xdist =   uniform_real_distribution<double> {0.0, std::nextafter(width, numeric_limits<double>::max())};
       ydist =   uniform_real_distribution<double> {0.0, std::nextafter(height, numeric_limits<double>::max())};
       mdist =   normal_distribution<double> {mass, sdm};
        }

    struct Asteroid{
    double x,y;
    double mass;
    double velocity;

    void setPositionAsteroid(Asteroid *a){
      a->x = xdist(re);
      a->y = ydist(re);
    }

    void collision(Asteroid a, Asteroid b){
      double aux= a.velocity;
      a.velocity=b.velocity;
      b.velocity=aux;
    }
  };
  struct Planet{
    double x=0,y=0;
    double gravity;
    double mass;
  };

vector <Asteroid> asteroids;//Vector of asteroids
};










// Random distributions
