#ifndef _MENU_HPP_
#define _MENU_HPP_

#include "Venom.hpp"
#include "Util.hpp"

namespace Venom
{
    class Menu
    {
	sf::Color Color;
	sf::RenderWindow* Window;
	std::vector <sf::Text> Text;
	std::vector <sf::String> Strings;
    public:
	Menu ();
	Menu (const std::string& String = "" , 
	      const sf::Color& Color = sf::Color (0 , 255 , 0) , 
	      sf::RenderWindow& Window);

	
    };
}

#endif /* _MENU_HPP_ */
