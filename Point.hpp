#ifndef _POINT_HPP_
#define _POINT_HPP_

#include "Venom.hpp"

namespace Venom
{
    //A point in space
    class Point
    {
	float X , Y;
    public:
	//Constructors
	Point ();
	Point (float X , float Y);
	Point (const Point& Source);

	//Destructor
	~Point ();

	//Mutate X and Y coordinates
	float setX (float X);
	float setY (float Y);
	void set (float X , float Y);
	
	float addX (float X);
	float addY (float Y);
	void move (float X , float Y);

	//Get X and Y coordinates
	float getX ();
	float getY ();	
	float getX () const;
	float getY () const;
	
	//Overloading assignment and comparison operators
	bool operator== (const Point& Source);
	bool operator== (const Point& Source) const;
	
	Point& operator= (const Point& Source);
    };
}

#endif /* _POINT_HPP_ */
