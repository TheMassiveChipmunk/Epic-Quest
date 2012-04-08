#ifndef _CHARACTER_HPP_
#define _CHARACTER_HPP_

#include <vector>

#include <SFML/Graphics.hpp>

#include "Util.hpp"
#include "Box.hpp"
#include "Engine.hpp"
#include "Bullet.hpp"

namespace Venom
{
    /*!
     * Character base class.
     */
    class Character : public Engine
    {
    protected:
	/*! Character projectiles. */
	Venom::Bullet Bullets;
    public:
	/*!
	 * Default constructor for the Venom::Character class.
	 */
	Character ();
	
	/*!
	 * Copy constructor for the Venom::Character class
	 */
	Character (const Character& Source);
	
	/*!
	 * Argument constructor for the Venom::Character class.
	 * @param Position Character Position.
	 * @param VelX Character X velocity.
	 * @param VelY Character Y velocity.
	 * @param BulletVelX Bullet X velocity.
	 * @param BulletVelY Bullet Y velocity.
	 * @param BulletWidth Bullet Width.
	 * @param BulletHeight Bullet Height.
	 * @param Window Window to get input from.
	 */
	Character (Venom::Box& Position , float VelX , float VelY , float BulletVelX , 
		   float BulletVelY , float BulletWidth , float BulletHeight , sf::RenderWindow& Window);

	/*!
	 * Default destructor.
 	 */
	virtual ~Character ();

	/*!
	 * Default assignment operator for the Venom::Character class.
	 * @param Source Character to be copied.
	 */
	Venom::Character& operator= (const Character& Source); 

	/*!
	 * Update physics, input, and movement.
	 */
	virtual void update ();

	/*!
	 * Get amount of bullets for const Venom::Character objects.
	 * @return Amount of bullets.
	 */
	virtual std::size_t size () const;

	/*!
	 * Get amount of bullets.
	 * @return Amount of bullets.
	 */
	virtual std::size_t size ();

	/*!
	 * Get a bullet's position for const Venom::Character objects.
	 * @param Index The bullet to get.
	 * @return A bullet's position.
	 */
	virtual const Venom::Box& at (std::size_t Index) const;

	/*!
	 * Get a bullet's position.
	 * @param Index The bullet to get.
	 * @return A bullet's position.
	 */
	virtual const Venom::Box& at (std::size_t Index);

	/*!
	 * Handle all keyboard input.
	 */
	virtual void handleInput () = 0;
	
	/*!
	 * Shoot bullets.
	 */
	virtual void attack ();	
    };

}

#endif /* _CHARACTER_HPP_ */
