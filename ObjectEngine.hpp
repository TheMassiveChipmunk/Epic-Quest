#ifndef _OBJECTENGINE_HPP_
#define _OBJECTENGINE_HPP_

/*
  This is the object engine namespace for the venom namespace
  
  @Author : Felix Sanchez
  @Version : 1.0
  
  Object Class contains :
  The ObjectEngine Base Class

 */

#include "Venom.hpp"
#include "Enums.hpp"

/*    Venom Namespace    */

namespace Venom
{
    /*    ObjecEngine Namespace    */

    namespace ObjectEngine
    {
	/*    Object Engine Base Class    */

	class ObjectEngine
	{
	protected:
	    /*    Collision Method    */
	    virtual bool isCollision (sf::IntRect&);
	    
	    /*    Movement Method    */
	    virtual void move (float , 
			       float);
	    
	    /*    Move the X Method    */
	    virtual void moveX (float);

	    /*    Move the Y Method    */
	    virtual void moveY (float);

	    /*    Update Method    */
	    virtual void update ();

	    /*    Set Width    */
	    virtual void setWidth (float);

	    /*    Set Height    */
	    virtual void setHeight (float);

	    /*    Set X Speed    */
	    virtual void setSpeedX (float);
	    
	    /*    Set Y Speed*/
	    virtual void setSpeedY (float);	    

	    /*    Set Speed    */
	    virtual void setSpeed (float , 
				   float);

	    /*    Set dimensions    */
	    virtual void setDimensions (float , 
					float);
	    
	    /*    Set RenderWindow*/
	    virtual void setWindow (sf::RenderWindow&);

	    /*    Set Collision    */
	    virtual void setCollision (void (*) (sf::IntRect&));

	    /*    Set Event    */
	    virtual void setEvent (Venom::Enums::Event (*) (sf::RenderWindow*));

	    /*    Get Position    */
	    virtual sf::IntRect& getPosition ();
	    	    
	    /*    SpeedX    */
	    float SpeedX;

	    /*    SpeedY    */
	    float SpeedY;

	    /*    Width    */
	    float Width;
	    
	    /*    Height    */
	    float Height;
	    
	    /*    Collision Function    */
	    void (*Collision) (sf::IntRect&);
	    
	    /*    Event Function    */
	    Venom::Enums::Event (*Event) (sf::RenderWindow*);

	    /*    Position   */
	    sf::IntRect Position;

	    /*    RenderWindow    */
	    sf::RenderWindow* Window;

	public:
	    /*    Default Constructor    */
	    ObjectEngine ();
	};
	
	/*    Bullet Engine Class    */

	class BulletEngine : protected ObjectEngine
	{
	    /*    Vector containing all of the bullet points*/
	    std::vector <sf::IntRect> BulletPoints;
	public:
	    /*    Default Constructor    */
	    BulletEngine ();

	    /*    Argument Constructor    */
	    BulletEngine (float , float , 
			  float , float ,
			  sf::IntRect , sf::RenderWindow* ,
			  void (*) (sf::IntRect&) ,
			  Venom::Enums::Event (*) (sf::RenderWindow*));

	    /*    Overloading the previous update function    */
	    void update ();

	    /*    Getting a bullet point   */
	    sf::IntRect at (unsigned int);
	};
    }
}

#endif /* _OBJECTENGINE_HPP_ */
