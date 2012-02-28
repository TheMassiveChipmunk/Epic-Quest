#ifndef _BOX_HPP_
#define _BOX_HPP_

#include "Venom.hpp"
#include "Point.hpp"

namespace Venom
{
    class Box
    {
	Venom::Point Point;
	float Width , Height;
    public:
	//Constructors
	Box ();
	Box (const Box& Source);
	Box (float X , float Y , float Width , float Height);
	Box (const Venom::Point& Point , float Width , float Height);

	//Destructor
	~Box ();
	
	//Mutate X and Y coordinates
	float setX (float X);
	float setY (float Y);
	void set (float X , float Y);
	void set (const Venom::Point& Source);
	
	float addX (float X);
	float addY (float Y);
	void move (float X , float Y);
	
	//Mutate Width and Height
	float setWidth (float Width);
	float setHeight (float Height);
	void setDimensions (float Width , float Height);

	//Get point
	const Venom::Point& getPoint ();
	const Venom::Point& getPoint () const;

	//Get X and Y coordinates
	float getX ();
	float getY ();
	float getX () const;
	float getY () const;
	
	//Get Width and Height
	float getWidth ();
	float getHeight ();
	float getWidth () const;
	float getHeight () const;

	//Check if any boxes are colliding
	bool collides (const Box& Source);
	bool collides (const Box& Source) const;

	//Assignment and comparison operator
	Box& operator= (const Box& Source);
	bool operator== (const Box& Source);
	bool operator== (const Box& Source) const;
    };
}

#endif /* _BOX_HPP_ */
