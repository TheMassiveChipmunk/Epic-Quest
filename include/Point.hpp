#ifndef _POINT_HPP_
#define _POINT_HPP_

namespace Venom
{
    /*!
     * A point in space.
     */
    class Point
    {
	/*! X coordinate. */
	float X;
	
	/*! Y coordinate. */
	float Y;
    public:
	/*!
	 * Default constructor for the Venom::Point class.
	 */
	Point ();
	
	/*!
	 * Argument constructor for the Venom::Point class.
	 * @param X New X coordinate.
	 * @param Y New Y coordinate.
	 */
	Point (float X , float Y);
	
	/*!
	 * Copy constructor for the Venom::Point class.
	 * @param Source Venom::Point to be copied.
	 */
	Point (const Point& Source);

	/*!
	 * Destructor for the Venom::Point class.
	 */
	virtual ~Point ();

	/*!
	 * Set the X coordinate.
	 * @param X New X coordinate.
	 * @return The new X coordinate.
	 */
	float setX (float X);
	
	/*!
	 * Set the Y coordinate.
	 * @param Y New Y coordinate.
	 * @return The new Y coordinate.
	 */
	float setY (float Y);
	
	/*!
	 * Set X and Y coordinates.
	 * @param X New X coordinate.
	 * @param Y New Y coordinate.
	 */
	void set (float X , float Y);
	
	/*!
	 * Add X to X coordinate.
	 * @param X Amount to increment X by.
	 * @return New X coordinate.
	 */
	float addX (float X);
	
	/*!
	 * Add Y to Y coordinate.
	 * @param Y Amount to increment Y by.
	 * @return New Y coordinate.
	 */
	float addY (float Y);

	/*!
	 * Add X and Y to the current position.
	 * @param X Amount to increment X by.
	 * @param Y Amount to increment Y by.
	 */
	void add (float X , float Y);

	/*!
	 * Gets the current X coordinate.
	 * @return X coordinate.
	 */
	float getX ();

	/*!
	 * Gets the current Y coordinate.
	 * @return Y coordinate.
	 */
	float getY ();	

	/*!
	 * Gets the current X coordinate for const Venom::Point objects.
	 * @return X coordinate.
	 */
	float getX () const;

	/*!
	 * Gets the current Y coordinate for const Venom::Point objects.
	 * @return Y coordinate.
	 */	
	float getY () const;
	
	/*!
	 * Checks if both Venom::Points are exactly equal.
	 * @return True if they are equal otherwise false.
	 */
	bool operator== (const Point& Source);
	
	/*!
	 * Checks if both Venom::Points are exactly equal for const Venom::Point objects.
	 * @return True if they are equal otherwise false.
	 */
	bool operator== (const Point& Source) const;

	/*!
	 * Copies two Venom::Points
	 * @return A reference to this.
	 */
	Point& operator= (const Point& Source);
    };
}

#endif /* _POINT_HPP_ */
