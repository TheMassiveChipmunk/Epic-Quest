#ifndef _WORLD_HPP_
#define _WORLD_HPP_

#include "Venom.hpp"
#include "Engine.hpp"
#include "Util.hpp"
#include "Painter.hpp"

namespace Venom
{
    class World
    {
	bool IsPlayer;
	Venom::Painter Painter;
	sf::RenderWindow* Window;
	Venom::PlayerEngine Player;
	std::vector <std::shared_ptr <Venom::Engine> > Engines;	
    public:
	World ();
	World (sf::RenderWindow& Window);
	
	void spawnEnemy (sf::IntRect& BasePosition , 
			 float SpeedX , float SpeedY , 
			 float BulletSpeedX , float BulletSpeedY , 
			 const std::string& EnemyPath , 
			 const std::string& BulletPath); 
	
	void spawnPlayer (sf::IntRect& BasePosition , 
			  float SpeedX , float SpeedY , 
			  float BulletSpeedX , float BulletSpeedY , 
			  const std::string& PlayerPath , 
			  const std::string& BulletPath);

	void draw ();
	void update ();
    };
}

#endif /* _WORLD_HPP_ */
