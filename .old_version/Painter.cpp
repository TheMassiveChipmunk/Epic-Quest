#include "Painter.hpp"

Venom::Painter::Painter ()
    : Window (0)
{
}

Venom::Painter::Painter (sf::RenderWindow& Window)
    : Window (&Window)
{
}

void Venom::Painter::addEngine (Venom::Engine& Engine , 
				const std::string& Path)
{
    sf::Texture Texture;
    
    Venom::loadTexture (Path , Texture);

    this->Paint.push_back (std::shared_ptr <sf::Texture> (new sf::Texture (Texture)));

    this->Engines.push_back (&Engine);
}

void Venom::Painter::draw ()
{
    //Paint iterator and engine iterator
    std::vector <Venom::Engine*>::iterator eIt;
    std::vector <std::shared_ptr <sf::Texture> >::iterator pIt; 

    unsigned int i = 0;

    //Set paint iterator to the beginning
    pIt = this->Paint.begin ();

    //Iterate and draw
    for (eIt = this->Engines.begin () ; eIt != this->Engines.end () ; eIt++ , pIt++)
    {
	for (i = 0 ; i < (*eIt)->size () ; i++)
	{
	    sf::Sprite Sprite;
		
	    Sprite.SetTexture (*(*pIt));
	    
	    Sprite.SetPosition ((*eIt)->at (i).Left ,
				(*eIt)->at (i).Top);
	    
	    this->Window->Draw (Sprite);
	}
    }
}

void Venom::Painter::setWindow (sf::RenderWindow& Window)
{
    this->Window = &Window;
}
