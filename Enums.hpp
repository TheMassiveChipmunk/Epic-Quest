#ifndef _ENUMS_HPP_
#define _ENUMS_HPP_

#include "Venom.hpp"

/*
  This file contains the venom enumerations

  @Author : Felix Sanchez
  @Version : 1.0

  Note : I can't use a seperate .cpp file for the 
  operators the compiler does not let me

  The enums namespace contains :
  The Direction enum
 */

namespace Venom
{
    namespace Enums
    {
	/*
	  Event Enum
	 */
	
	enum Event
	{
	    UP = 1 , 
	    DOWN = 2 , 
	    RIGHT = 4 , 
	    LEFT  = 8 ,
	    SHOT = 16 ,

	    NONE = 64
	};
	
	
       /*
	 @Params : Two Directions to be checked
	 @Type : Enum OR operator overload
	 @Return Type : Venom::Enums::Direction
       */
	
	inline Venom::Enums::Event operator| (const Venom::Enums::Event& First , 
						  const Venom::Enums::Event& Second)
	{
	    /*    Return a cast of the used Events    */
	    return (Venom::Enums::Event) ((int) First | (int) Second);
	}
    }
}

#endif /* _ENUMS_HPP_ */
