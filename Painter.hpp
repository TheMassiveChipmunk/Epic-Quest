#ifndef _PAINTER_HPP_
#define _PAINTER_HPP_

#include "Venom.hpp"
#include "Util.hpp"
#include "Engine.hpp"

namespace Venom
{
    class Painter
    {
	sf::RenderWindow* Window;
	std::vector <Venom::Engine*> Engines;
	std::vector <std::shared_ptr <sf::Texture> > Paint;
    public:
	Painter ();
	Painter (sf::RenderWindow& Window);
	
	void addEngine (Venom::Engine& Engine , 
			const std::string& Path);

	void draw ();
    };
}

#endif /* _PAINTER_HPP_ */
