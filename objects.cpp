#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <stdlib.h>
#include <math.h>

using namespace std;
class Map {
public:

    const double gravity	= 6.674e-5;
    const double delta_t	= 0.1;
    const double dmin		= 2.0;
    const int width		= 200;
    const int height		= 200;
    const double ray_width	= 4;
    const double mass		= 1000;
    const double sdm		= 50;
   default_random_engine re;
   uniform_real_distribution<double> xdist;
   uniform_real_distribution<double> ydist;
   normal_distribution<double> mdist;

  struct Asteroid{
  double x,y;
  double mass;
  double velocity;
};

struct Planet{
  double x=0,y=0;
  double gravity;
  double mass;
};

    Map(int seed){
      re = default_random_engine{seed};
      Map::xdist =   uniform_real_distribution<double> {0.0, std::nextafter(width, numeric_limits<double>::max())};
      Map::ydist =   uniform_real_distribution<double> {0.0, std::nextafter(height, numeric_limits<double>::max())};
      Map::mdist =   normal_distribution<double> {mass, sdm};
        }

    void setPositionAsteroid(Asteroid *a){
      a->x = round(xdist(re));
      a->y = round(ydist(re));
        }
    void initializeAsteroid(Asteroid *a){
      a->x = round(xdist(re));
      a->y = round(ydist(re));
      a -> mass = round(mdist(re));
    }
    void collision(Asteroid a, Asteroid b){
      double aux= a.velocity;
      a.velocity=b.velocity;
      b.velocity=aux;
        }

double round(double number){
  return (int) (number * 1000.0)/1000.0;
}


};










// Random distributions
