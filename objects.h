#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <stdlib.h>
#include <math.h>

using namespace std;
class Map {
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
public:
   Map(int seed){
  re = {seed};
   xdist = {0.0, std::nextafter(width, numeric_limits<double>::max())};
   ydist = {0.0, std::nextafter(height, numeric_limits<double>::max())};
   mdist = {mass, sdm};
 }
    struct asteroid{

    double x,y;
    double mass;
    double velocity;

    void setPositionAsteroid(asteroid *a){
      a->x = xdist(re);
      a->y = ydist(re);
    }

    void collision(asteroid a, asteroid b){
      double aux= a.velocity;
      a.velocity=b.velocity;
      b.velocity=aux;
    }
  };
  struct planet{
    double x=0,y=0;
    double gravity;
    double mass;
  };


};










// Random distributions
