#include "ObjectEngine.hpp"

/*                                                   Object Engine Base Class                                                                                */

/*
  @Params : None
  @Type : Constructor
  @Return Type : None
*/

Venom::ObjectEngine::ObjectEngine::ObjectEngine ()
{
    /*    Not Implemented    */

    this->Position.Left = 0;
    this->Position.Top = 0;
}

/*
  @Params : Rect to be checked
  @Type : Class Method
  @Return Type : boolean
*/

bool Venom::ObjectEngine::ObjectEngine::isCollision (sf::IntRect& Rect)
{
    /*    Check it does intersect    */
    if (this->Position.Intersects (Rect))
    {
	//Check if the collision function is set
	if (this->Collision != 0)
	{	
	    //Use the collision function on the rect
	    this->Collision (Rect);
	}
	
	//There was a collision
	return true;
    }
    else
    {
	//There was not a collision
	return false;
    }
}

/*
  @Params : X speed
  @Type : Class Method
  @Return Type : void
 */

void Venom::ObjectEngine::ObjectEngine::moveX (float X)
{
    /*    Increase the X    */
    this->Position.Left += X;
}

/*
  @Params : Y speed
  @Type : Class Method
  @Return Type : void
 */

void Venom::ObjectEngine::ObjectEngine::moveY (float Y)
{
    /*    Increase the Y    */
    this->Position.Top += Y;
}

/*
  @Params : X and Y speed
  @Type : Class Method
  @Return Type : void
 */

void Venom::ObjectEngine::ObjectEngine::move (float X , float Y)
{
    /*    Increase the Y    */
    this->moveY (Y);

    /*    Increase the X    */
    this->moveX (X);
}

/*
  @Params : None
  @Type : Class Method
  @Return Type : void
 */

void Venom::ObjectEngine::ObjectEngine::update ()
{
    /*    Check if the event method has been set    */
    if (this->Event != 0)
    {
	/*    Move the object    */

	/*    Current direction    */
	Venom::Enums::Event Dir;

	/*    Set the direction    */
	Dir = this->Event (this->Window);
	
	/*    Check which directions have been set    */
	if (Dir & Venom::Enums::Event::DOWN)
	{
	    this->moveY (this->SpeedY);
	}
	if (Dir & Venom::Enums::Event::UP)
	{
	    this->moveY (-(this->SpeedY));
	}
	if (Dir & Venom::Enums::Event::RIGHT)
	{
	    this->moveX (this->SpeedY);
	}
	if (Dir & Venom::Enums::Event::LEFT)
	{
	    this->moveX (-(this->SpeedY));
	}
    }
}

/*
  @Params : Width
  @Type : Class Method
  @Return Type : void
 */

void Venom::ObjectEngine::ObjectEngine::setWidth (float Width)
{
    /*    Set Width    */
    this->Width = Width;
}

/*
  @Params : Height
  @Type : Class Method
  @Return Type : void
 */

void Venom::ObjectEngine::ObjectEngine::setHeight (float Height)
{
    /*    Set Width    */
    this->Height = Height;
}

/*
  @Params : Width and Height
  @Type : Class Method
  @Return Type : void
*/

void Venom::ObjectEngine::ObjectEngine::setDimensions (float Width ,
				  float Height)
{
    /*    Set Width and Height    */
    this->setWidth (Width);
    this->setHeight (Height);
}

/*
  @Params : Speed X
  @Type : Class Method
  @Return Type : void
 */

void Venom::ObjectEngine::ObjectEngine::setSpeedX (float SpeedX)
{
    /*    Set SpeedX    */
    this->SpeedX = SpeedX;
}

/*
  @Params : Speed Y
  @Type : Class Method
  @Return Type : void
 */

void Venom::ObjectEngine::ObjectEngine::setSpeedY (float SpeedY)
{
    /*    Set SpeedY    */
    this->SpeedY = SpeedY;
}

/*
  @Params : Speed
  @Type : Class Method
  @Return Type : void
 */

void Venom::ObjectEngine::ObjectEngine::setSpeed (float SpeedX ,
			    float SpeedY)
{
    /*    Set Speed    */
    this->setSpeedX (SpeedX);    
    this->setSpeedY (SpeedY);
}

/*
  @Params : Window
  @Type : Class Method
  @Return Type : void
 */

void Venom::ObjectEngine::ObjectEngine::setWindow (sf::RenderWindow& Window)
{
    /*    Set Window    */
    this->Window = &Window;
}

/*
  @Params : Collision Function
  @Type : Class Method
  @Return Type : void
*/

void Venom::ObjectEngine::ObjectEngine::setCollision (void (*Collision) (sf::IntRect&))
{
    /*    Set Collision    */
    this->Collision = Collision;
}


/*
  @Params : Event Function
  @Type : Class Method
  @Return Type : void
*/

void Venom::ObjectEngine::ObjectEngine::setEvent (Venom::Enums::Event (*Event) (sf::RenderWindow*))
{
    /*    Set Event    */
    this->Event = Event;
}


/*
  @Params : None
  @Type : Class Method
  @Return Type : sf::IntRect
*/

sf::IntRect& Venom::ObjectEngine::ObjectEngine::getPosition ()
{
    /*    Return the Position    */
    return this->Position;
}

/*                                                   Bullet Engine Class                                                                                    */

/*
  @Params : None
  @Type : Constructor
  @Return Type : None
 */

Venom::ObjectEngine::BulletEngine::BulletEngine ()
{
    /*    Set the values to zero    */
    this->Window = 0;
    this->setSpeed (0.0f , 0.0f);
    this->setDimensions (0.0f , 0.0f);
}

/*
  @Params : Window , Speed , Dimensions , Collision , Event functions
  @Type : Constructor
  @Return Type : None
 */


Venom::ObjectEngine::BulletEngine::BulletEngine (float XSpeed , float YSpeed ,
						 float Width , float Height ,
						 sf::IntRect Position , sf::RenderWindow* Window ,
						 void (*Collision) (sf::IntRect&) , 
						 Venom::Enums::Event (*Event) (sf::RenderWindow*))
{
    /*    Set variables   */

    this->setSpeed (XSpeed , YSpeed);
    this->setDimensions (Width , Height);
    this->Position.Left = Position.Left;
    this->Position.Top = Position.Top;
    this->Position.Width = Position.Width;
    this->Position.Height = Position.Height;
    this->setEvent (Event);
    this->setCollision (Collision);    
}

/*
  @Params : Index
  @Type : Class Method
  @Return Type : sf::IntRect&
 */

sf::IntRect Venom::ObjectEngine::BulletEngine::at (unsigned int Index)
{
    /*    Return a null point    */
    if (this->BulletPoints.empty ())
    {
	return sf::IntRect (0 , 0 , 0 , 0);
    }

    /*    Return a point    */
    return this->BulletPoints.at (Index);
}

/*
  @Params : None
  @Type : Class Method
  @Return Type : void
 */

void Venom::ObjectEngine::BulletEngine::update ()
{
    /*    Make an event    */
    Venom::Enums::Event Event;
    
    /*    Set the event    */
    Event = this->Event (this->Window);

    /*    Check which flags have been set    */    
    if (Event & Venom::Enums::SHOT)
    {
	/*    Add a point    */
	this->BulletPoints.push_back (sf::IntRect (this->Position.Left + this->Width , 
						   this->Position.Top , this->Width , this->Height));
    }
    
    /*    Update all show points    */
    std::vector <sf::IntRect>::iterator it;
    
    for (it = this->BulletPoints.begin () ; it < this->BulletPoints.end () ; it++)
    {
	it->Left += SpeedX;
	it->Top += SpeedY;
    }

    /*    Check for out of map points    */
    for (it = this->BulletPoints.begin () ; it < this->BulletPoints.end () ; it++)
    {
	/*    Erase all of the out of map points    */
	if (it->Top > (float) this->Window->GetHeight () - it->Height)
	{
	    this->BulletPoints.erase (it);
	}
	else if (it->Top < 0 - it->Height)
	{
	    this->BulletPoints.erase (it);
	}
	else if (it->Left> (float) this->Window->GetWidth () - it->Width)
	{
	    this->BulletPoints.erase (it);
	}
	else if (it->Left < 0 - it->Width)
	{
	    this->BulletPoints.erase (it);
	}
    }
}
