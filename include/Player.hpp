#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_

#include "Engine.hpp"
#include "Bullet.hpp"
#include "Character.hpp"
#include "Util.hpp"

namespace Venom
{
    class Player : public Character
    {
	/*! Time manager. */
	sf::Clock Clock;
    public:
	/*!
	 * Default constructor for the Venom::Player class.
	 */
	Player ();
	
	/*!
	 * Copy constructor for the Venom::Player class.
	 */
	Player (const Player& Source);

	/*!
	 * Argument constructor for the Venom::Player class.
	 * @param Position Player Position.
	 * @param VelX Player X velocity.
	 * @param VelY Player Y velocity.
	 * @param BulletVelX Bullet X velocity.
	 * @param BulletVelY Bullet Y velocity.
	 * @param BulletWidth Bullet Width.
	 * @param BulletHeight Bullet Height.
	 * @param Window Window to get input from.
	 */
	Player (Venom::Box& Position , float VelX , float VelY , float BulletVelX , 
		float BulletVelY , float BulletWidth , float BulletHeight , sf::RenderWindow& Window);

	/*!
	 * Default destructor for the Venom::Player class.
	 */
	~Player ();

	/*!
	 * Default assignment operator for the Venom::Player class.
	 * @param Source Player to be copied.
	 */
	Venom::Player& operator= (const Player& Source); 

	/*!
	 * Handle keyboard input.
	 */
	void handleInput ();
    };
}

#endif /* _PLAYER_HPP_ */
