#ifndef _UTIL_HPP_
#define _UTIL_HPP_

//Include the common header
#include "Common.hpp"

/*
  @Version 1.0
  @Author Felix Sanchez

  This is the util namespace
  
  The Util namespace contains:
  Splitter Class
  Debugging functions
  SFML Graphics functions
  String manipulation functions
*/


/*    Default Mask Color    */
#define MASK_COLOR sf::Color (255 , 0 , 255)

/*    Are we writing to a file    */
const bool FILE_MODE = true;

/*    File to write to    */
const std::string LOG_FILE = "Log.txt";



/*    Util Namespace    */

namespace Util
{    
    /*    Splitter class    */

    class Splitter
    {
	/*    Token vector    */

	std::vector <std::string> Tokens;
    public:
	/*    Splitter default constructor    */
	
	Splitter ();
	
	/*    Splitter class argument constructor    */
	
	Splitter (const std::string& ,
		  const std::string&);

	/*    Returns the vector size    */

	unsigned int size ();

	/*    Returns a token     */

	std::string at (unsigned int);

	/*    Splits the string    */

	void split (const std::string& , 
		    const std::string&);

	/*    Overloading the index operator*/

	std::string operator[] (unsigned int);
    };



    /*    Debugging functions*/

    void logMessage (const std::string&);

    /*    Graphics functions    */


    /*    SFML Blit    */

    void sfBlit (const sf::Texture& ,
		 sf::RenderWindow& , 
		 float , float);

    /*    SFML Load Texture    */

    bool loadTexture (sf::Texture& , const std::string&);

    /*    String Manipulation*/
    
    /*    To Uppercase    */
    
    std::string& toUpper (std::string&);

    /*    Check if the string is a number*/

    bool isDigit (const std::string&);
    
}

#endif /* _UTIL_HPP_ */

