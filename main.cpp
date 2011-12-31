#include <iostream>

#include <SFML/Graphics.hpp>

#include "Start.hpp"
#include "Player.hpp"

int main(int argc, char *argv[])
{

    //Seed the random number generator
    srand ((unsigned) time (NULL));

    //See what out user chooses to do
    Option Choice = OPTION_NONE;

    //Video mode
    sf::VideoMode VMode (800 , 800 , 32);
    
    //Window
    sf::RenderWindow Window (sf::VideoMode (400 , 400 , 32) , "Loading Epic Quest Sounds" , sf::Style::None);

    //Enable Vertical Sync
    Window.EnableVerticalSync (true);
    
    //Sound buffers get initialized in main so we do not have to load it multiple times 
    sf::SoundBuffer MenuIntro , Level1Intro;
    
    //Loading screen images
    sf::Texture Texture;
    sf::Sprite Loading;
    Texture.LoadFromFile ("Data/Images/Menu/Loading.png");
    Loading.SetTexture (Texture);
    
    //Draw to window
    Window.Draw (Loading);
    Window.Display ();

    //Load sounds
    //MenuIntro.LoadFromFile ("Data/Sounds/Menu/Intro.ogg");
    //Level1Intro.LoadFromFile ("Data/Sounds/Level1/Theme.ogg");
    
    //Set window back to defaults
    Window.Create (VMode , "Epic Quest");
    
    //Enable Vertical Sync
    Window.EnableVerticalSync (true);

    //Get choice
    Choice = startScreen (&Window , &MenuIntro);

    //Make player
    sf::Image BulletImage;
    sf::Image PlayerImage;
    
    BulletImage.LoadFromFile ("Data/Images/Level1/Bullet.png");
    PlayerImage.LoadFromFile ("Data/Images/Level1/Player.png");

    std::cout << "Loaded images??" << std::endl;
    Player Ship (&Window , PlayerImage , BulletImage , 
		 sf::IntRect (0 , 0 , 47 , 76) , sf::IntRect (0 , 0 , 22, 13) , 
		 6.0f , 9.0f , 0.0f , 7.0f , 1.0f);

    std::cout << "Made player" << std::endl;
    //Act accordingly
    while (Choice != OPTION_NONE && Window.IsOpened ())
    {	
	if (Choice == OPTION_START)
	{	    
	    std::cout << "In loop" << std::endl;
	    while (Ship.update () == STATE_PLAYING)
	    {
	    	Ship.draw ();
	    }
	}
	else if (Choice == OPTION_HELP)
	{
	}
	else if (Choice == OPTION_CREDITS)
	{
	}
	else if (Choice == OPTION_ABOUT)
	{
	}
	Choice = startScreen (&Window , &MenuIntro);
    }
    return 0;
}
