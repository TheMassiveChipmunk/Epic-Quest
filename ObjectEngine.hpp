#ifndef _OBJECTENGINE_HPP_
#define _OBJECTENGINE_HPP_

#include "Venom.hpp"

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

	    /*    Set Movement    */
	    virtual void setMovement (bool (*) (sf::RenderWindow*));

	    /*    Get Position    */
	    virtual sf::IntRect getPosition ();
	    
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
	    
	    /*    Movement Function    */
	    bool (*Movement) (sf::RenderWindow*);

	    /*    Position   */
	    sf::IntRect Position;

	    /*    RenderWindow    */
	    sf::RenderWindow* Window;

	public:

	    /*    Default Constructor    */
	    ObjectEngine ();
	};
    }
}

#endif /* _OBJECTENGINE_HPP_ */


