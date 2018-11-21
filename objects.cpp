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
    double velocityX;
    double velocityY;
    int asteroid_id; //Le damos un id al asteroide para identificarlo luego en el mapeo
    map<int, double> distances;
  };

  struct Planet{
    int planet_id;
    double x,y;
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
  void initializePlanet(Planet *p, int id){
    p->planet_id = id; //Creating planets on module 4 to set the axis
    switch (id%4) {
      case 0:
      p->x = 0;
      p->y = round(ydist(re));
      p->mass = round(mdist(re)*10);
      break;
      case 1:
      p->x = round(xdist(re));
      p->y = 0 ;
      p->mass =round(mdist(re)*10);
      break;
      case 2:
      p->x = width;
      p->y = round(ydist(re));
      p->mass =round(mdist(re)*10);
      break;
      case 3:
      p->x = round(xdist(re));
      p->y = height;
      p->mass =round(mdist(re)*10);
      break;
    }
  }
  double computeDistance(Asteroid *a, Asteroid *b){
    double distance = sqrt(pow((a->x - b->x),2) + pow((a->y - b->y),2));
    a->distances.insert(make_pair(b->asteroid_id, distance)); //Stores the key vaue pair in asteroids map
    return distance;
  }

  void collision(Asteroid a, Asteroid b){
    double aux= a.velocityX;
    double auxY=a.velocityY;
    a.velocityX=b.velocityX;
    a.velocityY=b.velocityY;
    b.velocityX=aux;
    b.velocityY=auxY;
  }


  void normalMode(Asteroid *a, Asteroid *b){
    double slope;
    slope = ((a->y)-(b->y))/((a->x)-(b->x));
    if (slope>1 || slope<-1){
      slope=slope- ((int)(slope)/1);

    }
    double alpha=atan(slope);
    double afx=(gravity*(a->mass)*(b->mass))/(pow((sqrt(pow((a->x - b->x),2) + pow((a->y - b->y),2))),2))*cos(alpha);
    if(afx>200){
      afx=200;
    }
    double afy=(gravity*(a->mass)*(b->mass))/(pow((sqrt(pow((a->x - b->x),2) + pow((a->y - b->y),2))),2))*sin(alpha);
    if(afy>200){
      afy=200;
    }
    double accelerationA=(afx/a->mass)+(afy/a->mass);
    double accelerationB=((-afx)/b->mass)+((-afy)/b->mass);
    a->velocityX=a->velocityX+accelerationA*delta_t;
    a->velocityY=a->velocityY+accelerationA*delta_t;
    b->velocityX=b->velocityX+accelerationB*delta_t;
    b->velocityY=b->velocityY+accelerationB*delta_t;
    a->x=a->x+a->velocityX*delta_t;
    a->y=a->y+a->velocityY*delta_t;
    b->x=b->x+b->velocityX*delta_t;
    b->y=b->y+b->velocityY*delta_t;
  }

      void rebound(Asteroid *a){
        if(a->x<=0){
          a->x=2;
          cout << "Rebound bc asteroid x < 0" << endl;
        }
        else if(a->y<=0){
          a->y=2;
          cout << "Rebound bc asteroid y < 0" << endl;
        }
        else if (a->x>= width){
          a->x=(width-2);
          cout << "Rebound bc asteroid x > 200" << endl;
        }
        else if (a->y>=height){
          a->y=(height-2);
          cout << "Rebound bc asteroid x > 200" << endl;
        }
        a->velocity[0]*=-1;
        a->velocity[1]*=-1;
        cout << "X: " << a->x << "Y " << a->y;
      }
      double round(double number){
      return (int) (number * 1000.0)/1000.0;
      }

};










// Random distributions
