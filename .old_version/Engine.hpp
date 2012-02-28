#ifndef _ENGINE_HPP_
#define _ENGINE_HPP_

#include "Venom.hpp"
#include "Util.hpp"

namespace Venom
{
    //The force of gravity
    const unsigned int GRAVITY = 30.f;
    
    class Engine
    {
    protected:
	float SpeedX;
	float SpeedY;

	sf::Time Time;
	sf::Clock Clock;
	sf::RenderWindow* Window;
	sf::IntRect* BasePosition;
    public:
	//Constructors

	Engine (float SpeedX , float SpeedY);

	Engine (sf::IntRect& BasePosition ,
		float SpeedX , float SpeedY ,
		sf::RenderWindow& Window);

	virtual ~Engine ();

	//Init the clock
	virtual void initClock ();
	
	//Updating functions
	virtual void update () = 0;
	virtual void attack () = 0;
	virtual void handleEvents () = 0;
	
	//Moving functions
	virtual void move (float X , float Y);
	virtual float moveX (float X);
	virtual float moveY (float Y);
	
	//Physics functions
	virtual float updateTime ();
	virtual float getDistance (const float Mps = 1.0f);
	virtual float getGravity (const float Mps = 1.0f);
	
	virtual bool collision (const sf::IntRect& Box);

	//Getters and Setters
	virtual void setWindow (sf::RenderWindow& Window);
	virtual void setPosition (sf::IntRect& BasePosition);

	virtual float setSpeedX (float SpeedX);
	virtual float setSpeedY (float SpeedY);
	virtual void setSpeed (float SpeedX , float SpeedY);
	
	//For the bullet engine
	//Size and at functions
	virtual std::size_t size ();
	virtual sf::IntRect& at (unsigned int Index);
		
	//Painter friend class
	friend class Painter;
    };

    class BulletEngine : public Engine
    {
    public:
	std::vector <sf::IntRect> BulletPoints;
    public:	
	//Default constructor
        BulletEngine ();

	//Argument constructor
	BulletEngine (sf::IntRect& BasePosition ,
		      float SpeedX , float SpeedY ,
		      sf::RenderWindow& Window);

	//Update function
	void update ();
	
	//Attack function
	void attack ();
	
	//Event handler
	void handleEvents ();

	//Set character rect
	void setBase (sf::IntRect& Base);
	
	//Get how many bullets
	std::size_t size ();

	//Return the location of a bullet
	sf::IntRect& at (unsigned int Index);	

	//If any bullets are on the screen
	bool empty ();
    };

    class PlayerEngine : public Engine 
    {
    protected:
	Venom::BulletEngine Bullets;
    public:
	//Default constructor
	PlayerEngine ();
	
	//Argument constructor
	PlayerEngine (sf::IntRect& BasePosition , float SpeedX , 
		      float SpeedY , float BulletSpeedX , 
		      float BulletSpeedY , sf::RenderWindow& Window);

	//Get bullet engine
	Venom::BulletEngine& getBullets ();

	//Update function
	void update ();
	
	//Attack function
	void attack ();

	//Handle events function
	virtual void handleEvents ();
    };

    class EnemyEngine : public PlayerEngine
    {
    public:
	//Default constructor
        EnemyEngine ();
	
	//Argument constructor
	EnemyEngine (sf::IntRect& BasePosition , float SpeedX , 
		     float SpeedY , float BulletSpeedX , 
		     float BulletSpeedY ,  sf::RenderWindow& Window);

	//Handle events function
	void handleEvents ();
    }; 
}

#endif /* _ENGINE_HPP_ */
