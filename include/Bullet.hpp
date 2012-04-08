#ifndef _BULLET_HPP_
#define _BULLET_HPP_

#include <vector>

#include <SFML/Graphics.hpp>

#include "Box.hpp"
#include "Util.hpp"
#include "Engine.hpp"

namespace Venom
{

    /*!
     * Bullet engine class.
     */

    class Bullet : public Engine
    {
	/*! Vector containing all bullet points */
	std::vector <Venom::Box> Points;
	
	/*! Bullet Width. */
	float Width;
	
	/*! Bullet Height. */
	float Height;
    public:
	/*!
	 * Default constructor for the Venom::Bullet class.
	 */
	Bullet ();

	/*!
	 * Copy constructor for the Venom::Bullet class.
	 * @param Source Venom::Bullet to be copied.
	 */
	Bullet (const Bullet& Source);

	/*!
	 * Argument constructor for the Venom::Bullet class.
	 * @param Position A reference to a position on the screen.
	 * @param VelX The X velocity of the bullet.
	 * @param VelY The Y velocity of the bullet.
	 * @param Width Bullet Width.
	 * @param Height Bullet Height.
	 * @param Window Window to get input from.
	 */
	Bullet (Venom::Box& Position , float VelX , float VelY , float Width , float Height , sf::RenderWindow& Window);

	/*!
	  Default destructor for the Venom::Bullet class.
	 */
	~Bullet ();

	/*!
	 * Default assignment operator for the Venom::Bullet class.
	 * @param Source Bullet to be copied.
	 */
	Venom::Bullet& operator= (const Venom::Bullet& Source);

	/*!
	 * Get the amount of bullets shot for const Venom::Bullet objects.
	 * @return The amount of bullets shot.
	 */
	std::size_t size () const;


	/*!
	 * Get the amount of bullets shot.
	 * @return The amount of bullets shot.
	 */
	std::size_t size ();

	/*!
	 * Gets a bullet at a specified index.
	 * @param Index The bullet to get.
	 * @return A const Venom::Box containing a bullets point.
	 */
	const Venom::Box& at (std::size_t Index);

	/*!
	 * Gets a bullet at a specified index for const Venom::Box objects.
	 * @param Index The bullet to get.
	 * @return A const Venom::Box containing a bullets point.
	 */
	const Venom::Box& at (std::size_t Index) const;
	
	/*!
	 * Update physics.
	 */
	virtual void update ();

	/*!
	 * Handles all window events.
	 */
	virtual void handleInput ();

	/*!
	 * Adds a bullet to the screen.
	 */
	virtual void attack ();
    };
}

#endif /* _BULLET_HPP_ */
