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

	Engine (float SpeedX , float SpeedY ,
		sf::RenderWindow& Window , 
		sf::IntRect& BasePosition);

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

	virtual const sf::IntRect& getPosition ();

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
	BulletEngine (float SpeedX , float SpeedY ,
		      sf::RenderWindow& Window ,
		      sf::IntRect& BasePosition);
	
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

	//Overloading the get position function
	virtual const sf::IntRect& getPosition ();
    };

    class PlayerEngine : public Engine 
    {
    protected:
	Venom::BulletEngine Bullets;
    public:
	//Default constructor
	PlayerEngine ();
	
	//Argument constructor
	PlayerEngine (float SpeedX , float SpeedY ,
		      float BulletSpeedX , float BulletSpeedY ,
		      sf::RenderWindow& Window ,
		      sf::IntRect& BasePosition);
	
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
	EnemyEngine (float SpeedX , float SpeedY ,
		      float BulletSpeedX , float BulletSpeedY ,
		      sf::RenderWindow& Window ,
		      sf::IntRect& BasePosition);

	//Handle events function
	void handleEvents ();
    }; 
}

#endif /* _ENGINE_HPP_ */
