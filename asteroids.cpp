#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct asteroid{
  double x,y;
  double mass;
  double velocity;
};

void setPositionAsteroid(asteroid a);
void collision(asteroid a, asteroid b);

struct planet{
  double x=0,y=0;
  double gravity;
  double mass;
};


// Random distributions
// default_random_engine re{seed};
// uniform_real_distribution<double> xdist{0.0, std::nextafter(width,
// std :: numeric_limits<double>::max())};
// uniform_real_distribution<double> ydist{0.0, std::nextafter(height,
// std :: numeric_limits<double>::max())};
// normal_distribution<double> mdist{mass, sdm};

void collision(asteroid a, asteroid b){
  double aux= a.velocity;
  a.velocity=b.velocity;
  b.velocity=aux;
}

void setPositionAsteroid(asteroid a){
  a.x=xdist(re);
  a.y=ydist(re);
}

int main(){
  struct asteroid a1;
  setPositionAsteroid(a1);
  cout << "Position of asteroid " << a1.x << endl;

}
