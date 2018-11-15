#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct asteroid{
  double x,y;
  double mass;
  double velocity;
};


struct planet{
  double x=0,y=0;
  double gravity;
  double mass;
};

void setPositionAsteroid(asteroid a){
  a.x= 8;//xdist(8);
  a.y= 6; //ydist(8);
}

void collision(asteroid a, asteroid b){
  double aux= a.velocity;
  a.velocity=b.velocity;
  b.velocity=aux;
}


// Random distributions
// default_random_engine re{seed};
// uniform_real_distribution<double> xdist{0.0, std::nextafter(width,
// std :: numeric_limits<double>::max())};
// uniform_real_distribution<double> ydist{0.0, std::nextafter(height,
// std :: numeric_limits<double>::max())};
// normal_distribution<double> mdist{mass, sdm};
