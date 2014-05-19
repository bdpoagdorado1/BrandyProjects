#include <stdlib.h>
#include <stdio.h>
#include <ctime>
#include <cmath>
#include "SDL.h"
#include "vec2.h"
#include "SDL_audio.h"
#include "SDL_Mixer.h"
#include "SDL_Image.h"
#include "Surface.h"
#include "Event.h"
#include "Sound.h"

const int LASER_WIDTH = 2;
const int LASER_HEIGHT = 10;
const int POSS_MAX_COLOR = 255;
const int W = 640; // width of window
const int H = 480; // height of window
//typedef vec2< int > vec2i;
//typedef vec2< float > vec2f;
//typedef vec2< double > vec2d;


class Planet
{
public:
	Planet( Surface & surface0, const vec2< float > & p0, const vec2< float > & v0, const Color & color0 )
		: surface(surface0), p(p0), v(v0), color(color0)
	{}
	void run()
	{
		p += v;
		if (p.get_y() > 479) p.set_y(0);
		surface.put_pixel( (int)p.get_x(), (int)p.get_y(), color );	////use red for expl
	}
private:
	Surface surface;
	vec2< float > p;
	vec2< float > v;
	Color color;
};
/*class MyRect 
{
public:
	MyRect(int x0, int y0, int height0 = 32, int width0 = 32) : p(x0, y0), height(height0), width(width0) {}
	MyRect & operator+=(const vec2< float > q)
	{
		//this x plus q x and this y plus q y
		p.set_x(q.get_x() + p.get_x()); 
	}
private:
	vec2< float > p;
	int height, width;
};*/

class Laser
{
public:
	Laser( Surface & surface0, const vec2< float > & p0, const vec2< float > & v0, const Color & color0 )
		: surface(surface0), p(p0), v(v0), color(color0)
	{}
	void run()
	{
		p += v;
		if ( p.get_y() >= 0 )
		{
			surface.put_rect( (int)p.get_x(), (int)p.get_y(), LASER_WIDTH, LASER_HEIGHT, color ); 	
		}
	}
	SDL_Rect get_rect()
	{
		SDL_Rect location;
		location.x = p.get_x();
		location.y = p.get_y();
		location.w = LASER_WIDTH;
		location.h = LASER_HEIGHT;
		return location;
	}
private:
	Surface surface;
	vec2< float > p; // get fun to expose x y of vec p
	vec2< float > v;
	Color color;
};

class Ship
{
public:
	Ship( Surface & surface0, const vec2< float > & p0, char filename[]=NULL )
		: surface(surface0), p(p0)
	{
		image = IMG_Load(filename);
	}
	void run( Keyboard * kbd = NULL )
	{
		SDL_Rect location;
		if ( kbd != NULL && kbd->keypressed(LEFTARROW) )
		{
			double x = p.get_x();
			if ( x > 1 )
			{
				p.set_x( x - 2 );
			}
		}
		else if ( kbd != NULL && kbd->keypressed(RIGHTARROW) )
		{
			double x = p.get_x();
			if ( x + image->w < 638 )
			{
				p.set_x( x + 2 );
			}
		}

		location.x = p.get_x();
		location.y = p.get_y();
		location.w = image->w;
		location.h = image->h;
		
		SDL_BlitSurface(image, NULL, surface.get(), &location);
	}

	SDL_Rect get_rect()
	{
		SDL_Rect location;
		location.x = p.get_x();
		location.y = p.get_y();
		location.w = image->w;
		location.h = image->h;
		return location;
	}

	vec2< float > get_p() const
	{
		return p;
	}
private:
	Surface & surface;
	SDL_Surface * image;
	vec2< float > p;
};


//------------------------------------------------------------------
// Simple Galaxian
//
//------------------------------------------------------------------

//----------------------------------------------------------------
// Process all input events
// There are only 4 types of input events:
// * User close the program
// * Rightarrow key is pressed
// * Leftarrow key is pressed
// * Space is pressed
// To simplify the program we only detect one keypress. For 
// instance we do not detect the spacebar if the leftarrow key is
// pressed. To simplify the program we use an integer variable to
// denote one of the 4 types of events.
//----------------------------------------------------------------
const int G_QUIT = 0;
const int G_LEFT = 1;
const int G_RIGHT = 2;
const int G_SPACE = 3;
const int G_NULL = -1; // no valid event

int get_event_code(Event & event, Keyboard & kbd)
{
	int G_event = G_NULL;

	if (event.poll())
	{
		switch (event.type())
		{
			case QUIT:
			{
				G_event = G_QUIT;
				break;
			}

			case KEYDOWN:
			case KEYUP:
			{
				kbd.update( event );
				G_event = ( kbd.keypressed( RIGHTARROW ) ? G_RIGHT :
							kbd.keypressed( LEFTARROW )  ? G_LEFT :
							kbd.keypressed( SPACE )      ? G_SPACE :
														   G_NULL );
				break;
			}
		}
	}
	return G_event;
}

void test_galaxian()
{
	Surface surface;
	Event event;
	Keyboard kbd( event );

	bool quit = false;

	const int NUM_PLANETS = 100; //
	Color black = {0,0,0};

	Planet * planet[100];
	for ( int i = 0; i < NUM_PLANETS; i++ )
	{
		int x = (double)(rand() % W);
		int y = (double)(rand() % H);
		double vy = (double) rand() / (RAND_MAX);
		vec2< float > p(x, y);
		vec2< float > v(0, vy*4);
		Color color = {POSS_MAX_COLOR * vy, POSS_MAX_COLOR * vy, POSS_MAX_COLOR * vy};
		planet[i] = new Planet(surface, p, v, color);
	}

	vec2< float > p(W/2 - 20, H - 40);
	Ship ship(surface, p, "GalaxianGalaxip.gif");

	Ship * enemy[100];
	for ( int i=0; i<100; i++ )
	{
		int row = i / 5;
		int col = i % 5;
		vec2< float > p( 20 + row*30, 20 + col*30 );
		enemy[i] = new Ship( surface, p, "GalaxianAquaAlien.gif" );
	}

	Laser * laser = NULL;

	int score = 0;
	Sound sound1( "ChatTag.wav" );

	int G_event = G_NULL;
	while ( G_event != G_QUIT )
	{
		G_event = get_event_code( event, kbd );

		//----------------------------------------------------------------
		// Lock the surface and clear the surface with black.
		//----------------------------------------------------------------
		surface.lock();
		surface.put_rect( 0, 0, W, H, black );

		//----------------------------------------------------------------
		// Draw the game statistics
		//----------------------------------------------------------------
		surface.put_text("Score", 4, 4, POSS_MAX_COLOR, POSS_MAX_COLOR, POSS_MAX_COLOR, "arial.ttf", 18 );
		char str[100];
		//itoa(score, str, 2);
		itoa(score, str, 10);
		surface.put_text(str, 100, 4, POSS_MAX_COLOR, POSS_MAX_COLOR, POSS_MAX_COLOR, "arial.ttf", 18 );///convert score to a string

		//----------------------------------------------------------------
		// Update each game object
		//----------------------------------------------------------------
		for ( int i=0; i<NUM_PLANETS; i++ )
		{
			planet[i]->run();
		}

		ship.run( &kbd );

		// create laser object if spacebar was pressed
		if ( G_event == G_SPACE )
		{
			vec2< float > p = ship.get_p();
			p.set_x( p.get_x() + 15 );
			vec2< float > v( 0, -4 );
			Color red = {POSS_MAX_COLOR,0,0};
			laser = new Laser( surface, p, v, red );
		}

		if ( laser != NULL )
		{
			laser->run();
		}

		for ( int i=0; i<100; i++ )
		{
			if (enemy[i] != NULL) 
				enemy[i]->run( 0 );
		}

		//----------------------------------------------------------------
		// Collision detection and collision resolution
		//----------------------------------------------------------------
		if ( laser != NULL )
		{
			SDL_Rect laser_rec = laser->get_rect();
			for (int i = 0; i < 100; i++)
			{
				if (enemy[i] != NULL)
				{
					SDL_Rect alien_rec = enemy[i]->get_rect();
					if ((laser_rec.x >= alien_rec.x && laser_rec.x <= alien_rec.x + alien_rec.w 
						&& laser_rec.y >= alien_rec.y && laser_rec.y <= alien_rec.y + alien_rec.h)||
						(laser_rec.x + laser_rec.w >= alien_rec.x && laser_rec.x + laser_rec.w <= alien_rec.x + alien_rec.w 
						&& laser_rec.y >= alien_rec.y && laser_rec.y <= alien_rec.y + alien_rec.h)||
						(laser_rec.x >= alien_rec.x && laser_rec.x <= alien_rec.x + alien_rec.w 
						&& laser_rec.y + laser_rec.h >= alien_rec.y && laser_rec.y + laser_rec.h <= alien_rec.y + alien_rec.h)||
						(laser_rec.x + laser_rec.w >= alien_rec.x && laser_rec.x + laser_rec.w <= alien_rec.x + alien_rec.w
						&& laser_rec.y + laser_rec.h >= alien_rec.y && laser_rec.y + laser_rec.h <= alien_rec.y + alien_rec.h))
					{
						enemy[i] = NULL;
						++score;
						laser = NULL;
						Color color = {POSS_MAX_COLOR,0,0}; 
						for (int j = 0; j < 100; ++j)
						{
							int x = alien_rec.x + (rand() % alien_rec.w + 1);
							int y = alien_rec.y + (rand() % alien_rec.h + 1);
							sound1.play();
							surface.put_pixel( x, y, color );
						}
						break;
					}
				}
			}
		}

		//----------------------------------------------------------------
		// Unlock and flip the surface. Insert some delay.
		//----------------------------------------------------------------
		surface.unlock();
		surface.flip();
		SDL_Delay(10); // be nice: delay 10 milliseconds
	}
}



int main( int argc, char* argv[] )
{
	srand( (unsigned int)time(0) );

	test_galaxian();

	return 0;
}
