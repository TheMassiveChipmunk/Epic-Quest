#include "Engine.hpp"

//Constructors

Venom::Engine::Engine (float SpeedX , float SpeedY)
    :SpeedX (SpeedX) ,
     SpeedY (SpeedY) ,
     BasePosition (0)
{
}

Venom::Engine::Engine (float SpeedX , float SpeedY ,
		       sf::RenderWindow& Window ,
		       sf::IntRect& BasePosition)
    :SpeedX (SpeedX) , 
     SpeedY (SpeedY) ,
     Window (&Window) , 
     BasePosition (&BasePosition)
{
}

//Virtual destructor
Venom::Engine::~Engine ()
{
}

//Start the clock
inline void Venom::Engine::initClock ()
{
    this->Clock.Restart ();
}

//Move X
inline float Venom::Engine::moveX (float X)
{
    this->BasePosition->Left += X;
    return this->BasePosition->Left;
}

//Move Y
inline float Venom::Engine::moveY (float Y)
{
    this->BasePosition->Top += Y;
    return this->BasePosition->Top;
}

//Move BOTH X and Y
inline void Venom::Engine::move (float X , float Y)
{
    this->moveX (X);
    this->moveY (Y);
}

//Update elapsed time
inline float Venom::Engine::updateTime ()
{
    this->Time = this->Clock.GetElapsedTime();
    
    this->Clock.Restart ();

    return this->Time.AsSeconds ();
}

//Get gravity
inline float Venom::Engine::getGravity (const float Mps)
{
    return 9.8f * (Mps * Mps);
}

//Get distance traveled
inline float Venom::Engine::getDistance (const float Mps)
{
    //Return 1/2 (Gravity * Time ^ 2)
    
    return static_cast <float> (
	0.5f * 
	(this->getGravity (Mps) * 
	 this->Time.AsSeconds () * this->Time.AsSeconds ()));
}

//Check for collision
inline bool Venom::Engine::collision (const sf::IntRect& Box)
{
    return this->BasePosition->Intersects (Box);
}

//Set window
inline void Venom::Engine::setWindow (sf::RenderWindow& Window)
{
    this->Window = &Window;
}

//Get position
inline const sf::IntRect& Venom::Engine::getPosition ()
{
    return *(this->BasePosition);
}

//Set base position
inline void Venom::Engine::setPosition (sf::IntRect& BasePosition)
{
    this->BasePosition->Left = BasePosition.Left;
    this->BasePosition->Top = BasePosition.Top;
    this->BasePosition->Width = BasePosition.Width;
    this->BasePosition->Height = BasePosition.Height;
} 

//Default size function
inline int Venom::Engine::size ()
{
    return -1;
}

//Default at function 
inline sf::IntRect& Venom::Engine::at (unsigned int Index)
{
    return *(this->BasePosition);
}

////////////////////////////////////////////////////Bullet Engine//////////////////////////////////////////////////////////
//Constructor
Venom::BulletEngine::BulletEngine ()
    :Engine (0.0f , 0.0f) 
{
    //Log that we are using a default constructor
    Venom::logMessage ("Using default bullet constructor!!");
}

Venom::BulletEngine::BulletEngine (float SpeedX , float SpeedY ,
				   sf::RenderWindow& Window ,
				   sf::IntRect& BasePosition)
    :Engine (SpeedX , SpeedY ,
	     Window , BasePosition)
{
}

//Update function
void Venom::BulletEngine::update ()
{
//    this->handleEvents ();
    
    //Update time
    this->updateTime ();

    std::vector <sf::IntRect>::iterator it;    

    //Update all shot bullets
    for (it = this->BulletPoints.begin () ; it != this->BulletPoints.end () ; it++)
    {
	it->Top -= this->getDistance (this->SpeedY);
	it->Left += this->getDistance (this->SpeedX);

	//it->Top += this->getDistance (Venom::GRAVITY);
    }

    //Check for out of bound points
    for (it = this->BulletPoints.begin () ; it != this->BulletPoints.end () ; it++)
    {
	//If out of bound erase from vector
	if (static_cast <unsigned int> (it->Top) >= this->Window->GetHeight () - it->Height
	    && this->BulletPoints.size () > 1)
	{
	    this->BulletPoints.erase (it);
	    
	    //If there is only one bullet
	    if (this->BulletPoints.size () < 2)
	    {
		break;
	    }
	}
	if (it->Top <= 0 - it->Top 
	    && this->BulletPoints.size () > 1)
	{
	    this->BulletPoints.erase (it);
	
	    //If there is only one bullet
	    if (this->BulletPoints.size () < 2)
	    {
		break;
	    }
	}
	if (static_cast <unsigned int> (it->Left) >= this->Window->GetWidth () - it->Width
	    && this->BulletPoints.size () > 1)
	{
	    this->BulletPoints.erase (it);
	    
	    //If there is only one bullet
	    if (this->BulletPoints.size () < 2)
	    {
		break;
	    }
	}
	if (it->Left <= 0 - it->Left
	    && this->BulletPoints.size () > 1)
	{
	    this->BulletPoints.erase (it);
	
	    //If there is only one bullet
	    if (this->BulletPoints.size () < 2)
	    {
		break;
	    }
	}
    } 
}

//Attack function
void Venom::BulletEngine::attack ()
{
    this->BulletPoints.push_back (sf::IntRect 
				  (this->BasePosition->Left , 
				   this->BasePosition->Top - this->BasePosition->Height ,
				   this->BasePosition->Width ,
				   this->BasePosition->Height));
}

//Check if any bullets are on the screen
bool Venom::BulletEngine::empty ()
{
    return this->BulletPoints.empty ();
}

//Get how many bullets are on the screen
int Venom::BulletEngine::size ()
{
    return static_cast <int> (this->BulletPoints.size ());
}

//Get a bullet
sf::IntRect& Venom::BulletEngine::at (unsigned int Index)
{
    return this->BulletPoints.at (Index);
}

//Set the base
void Venom::BulletEngine::setBase (sf::IntRect& Base)
{
    this->BasePosition = &Base;
}

//Set speed
float Venom::BulletEngine::setSpeedX (float SpeedX)
{
    this->SpeedX = SpeedX;
    return this->SpeedX;
}

float Venom::BulletEngine::setSpeedY (float SpeedY)
{
    this->SpeedY = SpeedY;
    return this->SpeedY;
}

void Venom::BulletEngine::setSpeed (float SpeedX , float SpeedY)
{
    this->setSpeedX (SpeedX);
    this->setSpeedY (SpeedY);
}

//Overloading the get position function
const sf::IntRect& Venom::BulletEngine::getPosition ()
{
    return *(this->BasePosition);
}

//Event handler
void Venom::BulletEngine::handleEvents ()
{
}

////////////////////////////////////////////////////Player Engine//////////////////////////////////////////////////////////

//Default constructor
Venom::PlayerEngine::PlayerEngine ()
    :Engine (0.0f , 0.0f) ,
     Bullets ()
{    
    this->Bullets.setSpeed (0.0f , 0.0f);

    //Log that we are using a default constructor
    Venom::logMessage <std::string> ("Using default player constructor!!");
}

//Argument constructor
Venom::PlayerEngine::PlayerEngine (float SpeedX , float SpeedY ,
				   float BulletSpeedX , float BulletSpeedY ,
				   sf::RenderWindow& Window ,
				   sf::IntRect& BasePosition)
    :Engine (SpeedX , SpeedY ,
	     Window , BasePosition) ,
     Bullets (BulletSpeedX , BulletSpeedY ,
	      Window , BasePosition)
{    
    
}


//Update function
void Venom::PlayerEngine::update ()
{
    this->handleEvents ();
    
    this->Bullets.update ();

    //Update gravity
    //this->moveY (this->getDistance (Venom::GRAVITY));

    this->updateTime ();
}

//Handle events function
void Venom::PlayerEngine::handleEvents ()
{
    static bool Released = true;

    if (this->Window == 0)
    {
	Venom::logMessage <std::string> ("You have not initialized the window");
	return;
    }
    else
    {
	sf::Event Event;

	while (this->Window->PollEvent (Event))
	{
	    if (Event.Type == sf::Event::Closed)
	    {
		this->Window->Close ();
	    }
	    if (sf::Keyboard::IsKeyPressed (sf::Keyboard::Down))
	    {
		this->moveY (this->getDistance (this->SpeedY));
	    }
	    if (sf::Keyboard::IsKeyPressed (sf::Keyboard::Up))
	    {
		this->moveY (-(this->getDistance (this->SpeedY)));
	    }
	    if (sf::Keyboard::IsKeyPressed (sf::Keyboard::Right))
	    {
		this->moveX (this->getDistance (this->SpeedX));
	    }
	    if (sf::Keyboard::IsKeyPressed (sf::Keyboard::Left))
	    {
		this->moveX (-(this->getDistance (this->SpeedX)));
	    }
	    if (sf::Keyboard::IsKeyPressed (sf::Keyboard::Space) && Released)
	    {
		this->attack ();
		Released = false;
	    }
	    if (Event.Type == sf::Event::KeyReleased)
	    {
		if (Event.Key.Code == sf::Keyboard::Space)
		{
		    Released = true;
		}
	    }
	}
    }
}

//Attack function
void Venom::PlayerEngine::attack ()
{
    //Use the bullet engine
    this->Bullets.attack ();
}

//Get bullet engine
Venom::BulletEngine& Venom::PlayerEngine::getBullets ()
{
    return this->Bullets;
}
