#ifndef _BOX_HPP_
#define _BOX_HPP_

#include "Venom.hpp"
#include "Point.hpp"

namespace Venom
{
    /*!
     * A box representing a box in space.
     */
    class Box
    {
	/* X and Y coordinates */
	Venom::Point Point;
	
	/* Venom::Box Width */
	float Width; 
	
	/* Venom::Box Height */
	float Height;
    public:
	/*!
	 * Default constructor for the Venom::Box class.
	 */
	Box ();
	
	/*!
	 * Copy constructor for the Venom::Box class.
	 * @param Source Venom::Box to be copied.
	 */
	Box (const Box& Source);

	/*!
	 * Argument constructor for the Venom::Box class.
	 * @param X coordinate.
	 * @param Y coordinate.
	 * @param Width Venom::Box Width.
	 * @param Height Venom::Box Height.
	 */
	Box (float X , float Y , float Width , float Height);

	/*!
	 * Argument constructor for the Venom::Box class.
	 * @param Point X and Y coordinates.
	 * @param Width Venom::Box Width.
	 * @param Height Venom::Box Height.
	 */
	Box (const Venom::Point& Point , float Width , float Height);

	/*!
	 * Destructor
	 */
	virtual ~Box ();
	
	/*!
	 * Set the X coordinate.
	 * @param X The new X coordinate.
	 * @return New X coordinate.
	 */
	float setX (float X);
	
	/*!
	 * Set the Y coordinate.
	 * @param Y The new Y coordinate.
	 * @return New Y coordinate.
	 */
	float setY (float Y);
	
	/*!
	 * Set the X and Y coordinates.
	 * @param X New X coordinate.
	 * @param Y New Y coordinate.
	 */
	void set (float X , float Y);
	
	/*!
	 * Set the position.
	 * @param Source Point to be copied.
	 */
	void set (const Venom::Point& Source);

	/*!
	 * Add X to the X coordinate.
	 * @param X Amount to increment the X axis.
	 * @return The new X coordinate.
	 */
	float addX (float X);
	
	/*!
	 * Add Y to the Y coordinate.
	 * @param Y Amount to increment the Y axis.
	 * @return The new Y coordinate.
	 */
	float addY (float Y);
	
	/*!
	 * Add X and Y to the X and Y coordinates.
	 * @param X Amount to increment the X axis.
	 * @param Y Amount to increment the Y axis.
	 */
	void move (float X , float Y);
	
	/*!
	 * Set the Width of the Venom::Box.
	 * @param Width The new Venom::Box Width.
	 * @return The new Venom::Box Width.
	 */
	float setWidth (float Width);
	
	/*!
	 * Set the Height of the Venom::Box.
	 * @param Height The new Venom::Box height.
	 * @return The new Venom::Box Height.
	 */
	float setHeight (float Height);
	
	/*!
	 * Set the Width and Height of the Venom::Box.
	 * @param Width The new Venom::Box Width.
	 * @param Height The new Venom::Box Height.
	 */
	void setDimensions (float Width , float Height);

	/*!
	 * Get Venom::Box's position.
	 * @return Venom::Box's position.
	 */
	const Venom::Point& getPoint ();
	
	/*!
	 * Get Venom::Box's position for const Venom::Box objects.
	 * @return Venom::Box's position.
	 */
	const Venom::Point& getPoint () const;

	/*!
	 * Get the X coordinate of the Venom::Box.
	 * @return X coordinate.
	 */
	float getX ();
	
	/*!
	 * Get the Y coordinate of the Venom::Box.
	 * @return Y coordinate.
	 */
	float getY ();
	
	/*!
	 * Get the X coordinate of the Venom::Box for const Venom::Box objects.
	 * @return X coordinate.
	 */
	float getX () const;
	
	/*!
	 * Get the Y coordinate of the Venom::Box for const Venom::Box objects.
	 * @return Y coordinate.
	 */
	float getY () const;
	
	/*!
	 * Get the Venom::Box Width.
	 * @return The Venom::Box's Width.
	 */
	float getWidth ();
	
	/*!
	 * Get the Venom::Box Height.
	 * @return The Venom::Box's Height.
	 */
	float getHeight ();

	/*!
	 * Get the Venom::Box Width for const Venom::Box objects.
	 * @return The Venom::Box's Width.
	 */	
	float getWidth () const;
		
	/*!
	 * Get the Venom::Box Height for const Venom::Box objects.
	 * @return The Venom::Box's Height.
	 */	
	float getHeight () const;

	/*!
	 * Check if a Venom::Box collides with another Venom::Box.
	 * @param Source Venom::Box to be checked.
	 * @return True if the collide otherwise false.
	 */
	bool collides (const Box& Source);
	
	/*!
	 * Check if a Venom::Box collides with another Venom::Box for const Venom::Box objects.
	 * @param Source Venom::Box to be checked.
	 * @return True if the collide otherwise false.
	 */
	bool collides (const Box& Source) const;

	/*!
	 * Copies to Venom::Box objects.
	 * @param Source Venom::Box to be checked.
	 * @return A reference to this.
	 */
	Box& operator= (const Box& Source);

	/*!
	 * Checks if two Venom::Boxes are exactly equal.
	 * @param Source Venom::Box to be checked.
	 * @return True if they are equal otherwise false.
	 */
	bool operator== (const Box& Source);
	
	/*!
	 * Checks if two Venom::Boxes are exactly equal for const Venom::Box objects..
	 * @param Source Venom::Box to be checked.
	 * @return True if they are equal otherwise false.
	 */
	bool operator== (const Box& Source) const;
    };
}

#endif /* _BOX_HPP_ */
