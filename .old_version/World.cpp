#include "World.hpp"

Venom::World::World ()
    :IsPlayer (false) , Window (0) 
{
}

Venom::World::World (sf::RenderWindow& Window)
    :IsPlayer (false) , 
     Painter (Window) , 
     Window (&Window) 
{
}

void Venom::World::spawnEnemy (sf::IntRect& BasePosition , 
			       float SpeedX , float SpeedY , 
			       float BulletSpeedX , float BulletSpeedY , 
			       const std::string& EnemyPath , 
			       const std::string& BulletPath)
{
    static unsigned int Count = 0;

    Venom::EnemyEngine* Enemy = new Venom::EnemyEngine (BasePosition , SpeedX , 
							SpeedY , BulletSpeedX ,
							BulletSpeedY , *(this->Window));    
    Enemy->setWindow (*(this->Window));
    
    if (this->Window != 0)
    {
	this->Engines.push_back (std::shared_ptr <Venom::Engine> (Enemy));	
	
	this->Painter.addEngine (*(this->Engines.at (Count)) , EnemyPath); 
	this->Painter.addEngine (Enemy->getBullets () , BulletPath);

	Count++;
    }
    else
    {
	Venom::logMessage ("Window not made!!");
    }
} 

void Venom::World::spawnPlayer (sf::IntRect& BasePosition , 
				float SpeedX , float SpeedY , 
				float BulletSpeedX , float BulletSpeedY , 
				const std::string& PlayerPath , 
				const std::string& BulletPath)
{
    //Venom::copyRect (BasePosition , this->Player.at (0));
    this->Player.setPosition (BasePosition);

    this->Player.setSpeed (SpeedX , SpeedY);
    this->Player.setWindow (*(this->Window));
    this->Player.getBullets ().setSpeed (BulletSpeedX , 
					 BulletSpeedY);
    
    
    this->Painter.addEngine (this->Player , PlayerPath); 
    this->Painter.addEngine (this->Player.getBullets () , BulletPath);
    
    this->IsPlayer = true;
}

void Venom::World::draw ()
{
    this->Painter.draw ();
    this->Window->Display ();
}

void Venom::World::update ()
{
    std::vector <std::shared_ptr <Venom::Engine> >::iterator it;

    if (this->IsPlayer)
    {
	this->Player.update ();
    }

    for (it = this->Engines.begin () ; it != this->Engines.end () ; it++)
    {
	(*it)->update ();
    }

    if (this->IsPlayer)
    {
	for (it = this->Engines.begin () ; it != this->Engines.end () ; it++)
	{
	    unsigned int i = 0;
	    
	    for (i = 0 ; i < (*it)->size () ; i++)
	    {
		if (this->Player.collision ((*it)->at (i)))
		{
		    this->Player.at (0).Top = 302.0f;
		    this->Player.at (0).Left = 100.0f;
		}
	    }
	}
    }
}
