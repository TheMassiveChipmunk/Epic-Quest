#ifndef _ENEMY_HPP_
#define _ENEMY_HPP_

#include <ctime>
#include <cstdlib>

#include "Util.hpp"
#include "Point.hpp"
#include "Engine.hpp"
#include "Character.hpp"

namespace Venom
{

    /*!
     * Enemy manager class.
     */
    class Enemy : public Character
    {
	/*! Clock to check if we should shoot again. */
	sf::Clock Clock;
    public:
	/*!
	 * Default constructor for the Venom::Enemy class.
	 */
	Enemy ();
	
	/*!
	 * Copy constructor for the Venom::Enemy class.
	 */
	Enemy (const Enemy& Source);
	
	/*!
	 * Argument constructor for the Venom::Enemy class.
	 * @param Position Enemy Position.
	 * @param VelX Enemy X velocity.
	 * @param VelY Enemy Y velocity.
	 * @param BulletVelX Bullet X velocity.
	 * @param BulletVelY Bullet Y velocity.
	 * @param BulletWidth Bullet Width.
	 * @param BulletHeight Bullet Height.
	 * @param Window Window to get input from.
	 */
	Enemy (Venom::Box& Position , float VelX , float VelY , float BulletVelX , 
	       float BulletVelY , float BulletWidth , float BulletHeight , sf::RenderWindow& Window);
	
	/*!
	 * Default destructor for the Venom::Enemy class.
	 */
	~Enemy ();

	/*!
	 * Default assignment operator for the Venom::Enemy class.
	 * @param Source Enemy to be copied.
	 */
	Venom::Enemy& operator= (const Enemy& Source); 

	/*!
	 * Handle keyboard input.
	 */
	void handleInput ();
    };    
}

#endif /* _ENEMY_HPP_ */
