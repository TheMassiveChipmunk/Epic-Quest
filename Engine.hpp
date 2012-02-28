#ifndef _ENGINE_HPP_
#define _ENGINE_HPP_

#include "Venom.hpp"
#include "Point.hpp"
#include "Box.hpp"

namespace Venom
{
    class Engine
    {	
	float SpeedX;
	float SpeedY;
	float Acceleration;
	Venom::Box* Position;
    public:
	//Constructors
	Engine ();
	Engine (const Engine& Source);
	Engine (Venom::Box& Source , float Acceleration);

	//Destructor
	virtual ~Engine ();

	//Mutate X and Y coordinates
	virtual float moveX (float X);
	virtual float moveY (float Y);
	virtual void move (float X , float Y);

	virtual float setX (float X);
	virtual float setY (float Y);
	virtual void set (float X , float Y);
	virtual void set (const Venom::Point& Source);

	//Get position
	virtual float getX ();
	virtual float getY ();
	virtual float getX () const;
	virtual float getY () const;
	
	virtual const Venom::Box& getPosition ();
	virtual const Venom::Box& getPosition () const;

	//Overloading assignment and comparison operator
	bool operator== (const Engine& Source);
	Venom::Engine& operator= (const Engine& Source);
    };
}

#endif /* _ENGINE_HPP_ */
