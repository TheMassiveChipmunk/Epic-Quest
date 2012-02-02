#include "ObjectEngine.hpp"
/*
  @Params : None
  @Type : Constructor
  @Return Type : None
*/

Venom::ObjectEngine::ObjectEngine::ObjectEngine ()
{
    /*    Not Implemented    */
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
  @Params : X and Y speed
  @Type : Class Method
  @Return Type : void
 */

void Venom::ObjectEngine::ObjectEngine::move (float X , 
			 float Y)
{
    /*    Increase the Y    */
    this->Position.Top += Y;

    /*    Increase the X    */
    this->Position.Left += X;
}

/*
  @Params : None
  @Type : Class Method
  @Return Type : void
 */

void Venom::ObjectEngine::ObjectEngine::update ()
{
    /*    Check if the movement method has been set    */
    if (this->Movement != 0)
    {
	/*    Check if we set the window    */
	if (this->Window != 0)
	{
	    
	    /*    If the event was a moving one    */
	    if (this->Movement (this->Window))
	    {
		/*    Move current position*/
		this->move (this->SpeedX ,
			    this->SpeedY);
	    }
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
  @Params : Movement Function
  @Type : Class Method
  @Return Type : void
*/

void Venom::ObjectEngine::ObjectEngine::setMovement (bool (*Movement) (sf::RenderWindow*))
{
    /*    Set Movement    */
    this->Movement = Movement;
}


/*
  @Params : Get Position
  @Type : Class Method
  @Return Type : sf::IntRect
*/

sf::IntRect Venom::ObjectEngine::ObjectEngine::getPosition ()
{
    /*    Return the Position    */
    return this->Position;
}
