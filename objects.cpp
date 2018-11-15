#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <stdlib.h>
#include <math.h>
#include <cmath>
#include <map>
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
  int asteroid_id; //Le damos un id al asteroide para identificarlo luego en el mapeo
  map<int, double> distances;
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
    void initializeAsteroid(Asteroid *a, int id){
      a->x = round(xdist(re));
      a->y = round(ydist(re));
      a -> mass = round(mdist(re));
      a->asteroid_id = id;
    }

    void computeDistance(Asteroid *a, Asteroid *b){
      double distance = sqrt(pow((a->x - b->x),2) + pow((a->y - b->y),2));
      a->distances.insert(make_pair(b->asteroid_id, distance)); //Stores the key vaue pair in asteroids map
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
