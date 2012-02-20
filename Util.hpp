#ifndef _UTIL_HPP
#define _UTIL_HPP

#include "Venom.hpp"

namespace Venom
{
    //Default mask color
    const sf::Color MASK_COLOR (255 , 0 , 255);
    
    //Output modes and out mode
    const unsigned int CERR = 0x1;
    const unsigned int COUT = 0x2;
    const unsigned int FOUT = 0x4;
    const unsigned int LOG_MODE = CERR;

    //File to write to
    const std::string LOG_TXT = "Log.txt";

    //Log a message to the current LOG_TXT
    template <typename T>
    void logMessage (const std::string& Message ,
		     const T& Value);    
    

    //Overloading for just a message to the current LOG_TXT 
    template <typename T> 
    void logMessage (const T& Value);

    //Convert any value to a string
    template <typename T>
    inline std::string& toString (const T& Value , 
				  std::string& Buffer);
    
    //Convert a string to any value
    template <typename T>
    inline auto toT (const std::string& Value ,
		     T& Buffer) -> T;
    
    //Convert a string to upper case
    std::string& toUpper (std::string& String);

    //Load a texture
    bool loadTexture (const std::string& Path , 
		      sf::Texture& Texture);
}

#include "Util.tcc"

#endif /* _UTIL_HPP_ */
