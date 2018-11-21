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
   staticuniform_real_distribution<double> xdist;
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
  double x=0,y=0;
  double gravity;
  double mass;
};


//////////////////////////////////////////////////////////////////////////////////////

/*       Function creating the random position of the asteroids by seed             */

//////////////////////////////////////////////////////////////////////////////////////

    Map(int seed){
      re = default_random_engine{seed};
      Map::xdist =   uniform_real_distribution<double> {0.0, std::nextafter(width, numeric_limits<double>::max())};
      Map::ydist =   uniform_real_distribution<double> {0.0, std::nextafter(height, numeric_limits<double>::max())};
      Map::mdist =   normal_distribution<double> {mass, sdm};
        }


//////////////////////////////////////////////////////////////////////////////////////

/*    Function setting the position of the asteroid calculated in Map(int seed)     */

//////////////////////////////////////////////////////////////////////////////////////

    void setPositionAsteroid(Asteroid *a){
      a->x = round(xdist(re));
      a->y = round(ydist(re));
        }


//////////////////////////////////////////////////////////////////////////////////////

/*    Function setting the position, mass and id of the asteroid using xdist        */
/*    & ydist calculated in Map(int seed)                                           */

//////////////////////////////////////////////////////////////////////////////////////


    void initializeAsteroid(Asteroid *a, int id){
      a->x = round(xdist(re));
      a->y = round(ydist(re));
      a -> mass = round(mdist(re));
      a->asteroid_id = id;
    }


//////////////////////////////////////////////////////////////////////////////////////

/*    Function computing the distance between two asteroids                         */
/*    & saving the info inside the Asteriod a & b                                   */

//////////////////////////////////////////////////////////////////////////////////////

    double computeDistance(Asteroid *a, Asteroid *b){
      double distance = sqrt(pow((a->x - b->x),2) + pow((a->y - b->y),2));
      a->distances.insert(make_pair(b->asteroid_id, distance)); //Stores the key value pair in asteroids map



//LO HE CAMBIADO QUARDANDOLO EN B TAMBIEN => NO HAY QUE CALCULAR ASTEROID B ASTEROID A => MENOS COMPUTING TIME
 b->distances.insert(make_pair(a->asteroid_id, distance));

	return distance;
    }




//////////////////////////////////////////////////////////////////////////////////////

/*    Function computing the distance between asteroid & planet                     */
/*    & saving the info inside the Asteriod a & b                                   */

//////////////////////////////////////////////////////////////////////////////////////

    double computeDistance(Asteroid *a, Planet *b){
      double distance = sqrt(pow((a->x - b->x),2) + pow((a->y - b->y),2));
      a->distances.insert(make_pair(b->asteroid_id, distance)); //Stores the key value pair in asteroids map



//LO HE CAMBIADO QUARDANDOLO EN B TAMBIEN => NO HAY QUE CALCULAR ASTEROID B ASTEROID A => MENOS COMPUTING TIME
 b->distances.insert(make_pair(a->asteroid_id, distance));

	return distance;
    }


//////////////////////////////////////////////////////////////////////////////////////

/*         Function computing the change of the velocity (exchange of velocities    */
/*         in x and y) when a collision occurs                                      */

//////////////////////////////////////////////////////////////////////////////////////

    void collision(Asteroid a, Asteroid b){
      double aux= a.velocityX;
	double auxY=a.velocityY;
      a.velocityX=b.velocityX;
	a.velocityY=b.velocityY;
      b.velocityX=aux;
  	b.velocityY=auxY;
        }

//////////////////////////////////////////////////////////////////////////////////////

/*  Function computing the normal mode behavior of asteroids taking into account    */
/*  the positions of the asteroids and how do they interact                         */

//////////////////////////////////////////////////////////////////////////////////////

void normalMode(Asteroid *a, Asteroid *b){
	double slope;
	slope = ((a->y)-(b->y))/((a->x)-(b->x));
	if (slope>1 || slope<-1){
	slope=slope- (cast_to_int(slope)/1);
	
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


//////////////////////////////////////////////////////////////////////////////////////

/*  Function computing the normal mode behavior of asteroid & planet                */
/*  taking into account the positions of the asteroids and how do they interact     */

//////////////////////////////////////////////////////////////////////////////////////

    void normalMode(Asteroid *a, Planet *b){
	double slope;
	slope = ((a->y)-(b->y))/((a->x)-(b->x));
	if (slope>1 || slope<-1){
	slope=slope- (static_cast<int>(slope)/1);
	
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
	a->velocityX=a->velocityX+accelerationA*delta_t;
	a->velocityY=a->velocityY+accelerationA*delta_t;
	a->x=a->x+a->velocityX*delta_t;
	a->y=a->y+a->velocityY*delta_t;
}



//////////////////////////////////////////////////////////////////////////////////////

/*                      Function rounding with 3 decimals                           */

//////////////////////////////////////////////////////////////////////////////////////

double round(double number){
  return (int) (number * 1000.0)/1000.0;
}


};










// Random distributions
