#ifndef _UTIL_HPP
#define _UTIL_HPP

#include <iostream>
#include <fstream>
#include <sstream>

#include <string>

#include <SFML/Graphics.hpp>

#include "Box.hpp"

namespace Venom
{
    /*!
     * Default masking color.
     */
    const sf::Color MASK_COLOR (255 , 0 , 255);
    
    /*!
     * Draw text to a window.
     * @param Text Text to be drawn.
     * @param Window Window to draw to.
     * @param Size Text size.
     */
    void drawText (const std::string& Text , float Size , float X , float Y , sf::RenderWindow& Window);

    /*!
     * Sleep for X milli-seconds.
     * @param X milli-seconds to sleep.
     */
    void sleep (float X = 1.0f);
    
    /*!
     * Draw to a window.
     * @param Window Window to draw to.
     * @param Texture Texture to draw.
     * @param X X coordinate on the window.
     * @param Y Y coordinate on the window.     
     */
    void blit (const sf::Texture& Texture , float X , float Y , sf::RenderWindow& Window);

    /*!
     * Keep object in bounds.
     * @param Box The box to be checked.
     * @param Width The width to be checked.
     * @param Height The height to be checked.
     */
    void keepBounds (Venom::Box& Box , unsigned int Width , unsigned int Height);

    /*!
     * Split an std::string by delimiters.
     * @param Vector Vector holding all of the strings.
     * @param String String to be split.
     * @param Delim Delimiters.
     */
    void split (std::vector <std::string>& Vector , const std::string& String , const std::string& Delims);


    /*!
     * Output to console error.
     */
    const unsigned int CERR = 1;

    /*!
     * Output to console.
     */
    const unsigned int COUT = 2;

    /*!
     * Output to a file.
     */
    const unsigned int FOUT = 4;
    
    /*!
     * Where to output to.
     */
    const unsigned int LOG_MODE = 0;

    /*!
     * File to write to.
     */
    const std::string LOG_TXT = "Log.txt";

    /*!
     * Checks for an out of bound object.
     * @param Source Box to be checked.
     * @param Width The Width of the bounds.
     * @param Height The Height of the bounds.
     * @return True if in bounds false otherwise.
     */
    bool inBound (const Venom::Box& Source , float Width , float Height);

    /*!
     * Logs a message to the current output mode.
     * @param Message String containing a message.
     * @param Value Error value.
     */
    template <typename T>
    void logMessage (const std::string& Message , const T& Value);    
    

    /*!
     * Logs a message to the current output mode.
     * @param Value The message to be printed.
     */
    template <typename T> 
    void logMessage (const T& Value);

    /*!
     * Converts a value T to a string.
     * @param Value The value to be converted.
     * @param Buffer The string to receive the data.
     * @return The buffer.
     */
    template <typename T>
    std::string& toString (const T& Value , std::string& Buffer);
    
    /*!
     * Converts a string to value T.
     * @param Value String to be converted.
     * @param Buffer The T to receive the data.
     * @return T buffer.
     */
    template <typename T>
    auto toT (const std::string& Value , T& Buffer) -> T;
    
    /*!
     * Converts an entire std::string to uppercase.
     * @param String to be converted.
     * @return The new string.
     */
    std::string& toUpper (std::string& String);
    
    /*!
     * Loads a sf::Texture.
     * @param Path the file path of the image.
     * @param Texture the buffer to receive the data.
     * @return True on success false otherwise.
     */
    bool loadTexture (const std::string& Path , sf::Texture& Texture);
}

#include "Util.tcc"

#endif /* _UTIL_HPP_ */
