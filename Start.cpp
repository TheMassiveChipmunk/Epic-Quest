#include "Start.hpp"

bool type (int iTotal , int iChoice)
{
    if (rand () % iTotal + 1 == iChoice)
    {
	return true;
    } 
    else
    {
	return false;
    }
}

Option startScreen (sf::RenderWindow* Window , sf::SoundBuffer* Buffer)
{
    //Variables
    int i = 0 , j = 0;
    float Angle = 0.5;
    float OpposeAngle = -0.5 , FowardAngle = 0.5;

    //Intro theme
    sf::Sound Intro (*Buffer);
    Intro.SetLoop (true);

    //Play the sound
    Intro.Play ();

    //Images
    sf::Image Images [5];

    //Textures
    sf::Texture Textures [5];
    
    //Sprites
    sf::Sprite Choices [4] , BackGround;

    //Events
    sf::Event Event;
    
    //Initialize all images    
    Images [0].LoadFromFile ("Data/Images/Menu/Start.png");
    Images [1].LoadFromFile ("Data/Images/Menu/About.png");
    Images [2].LoadFromFile ("Data/Images/Menu/Credits.png");
    Images [3].LoadFromFile ("Data/Images/Menu/Help.png");
    Images [4].LoadFromFile ("Data/Images/Menu/Menu.png");

    //Give all images a transparency mask    
    for (j = 0 ; j < 5 ; j++)
    {
	Images [j].CreateMaskFromColor (sf::Color (255 , 0 , 255));
    }
    
    //Give all textures a value    
    for (j = 0 ; j < 5 ; j++)
    {
	Textures [j].LoadFromImage (Images [j]);
    }
    
    //Give all sprites a value    
    for (j = 0 ; j < 4 ; j++)
    {
	Choices [j].SetTexture (Textures [j]);
    }
    
    //Set background
    BackGround.SetTexture (Textures [4]);
    
    //Give all items a position
    Choices [0].SetPosition (200 , 400);
    Choices [1].SetPosition (500 , 400);
    Choices [2].SetPosition (200 , 600);
    Choices [3].SetPosition (500 , 600);
    
    //Wait for user's choice
    while (Window->IsOpened ())
    {
	while (Window->PollEvent (Event))
	{
	    //Check if window is closed
	    if (Event.Type == sf::Event::Closed)
	    {
		Intro.Stop ();
		Window->Close ();
	    }
	    //Checks if key is pressed
	    if (Event.Type == sf::Event::KeyPressed)
	    {
		//If the user pressed escape
		if (sf::Keyboard::IsKeyPressed (sf::Keyboard::Escape))
		{
		    Intro.Stop ();
		    Window->Close ();
		}
		//Check is user presses left
		if (sf::Keyboard::IsKeyPressed (sf::Keyboard::Left) && i >= 0)
		{
		    if (i != 0)
		    {
			//Check rotation type
			if (type (ROTATION_LIMIT , ROTATION_START))
			{
			    Angle = OpposeAngle;
			}
			else
			{
			    Angle = FowardAngle;
			}
			Choices [i].SetRotation (0.0f);
		    }
		    i--;
		}
		//Checks if user presses right
		else if (sf::Keyboard::IsKeyPressed (sf::Keyboard::Right) && i < 4)
		{
		    if (i != 3)
		    {
			//Check rotation type
			if (type (ROTATION_LIMIT , ROTATION_START))
			{
			    Angle = OpposeAngle;
			}
			else
			{
			    Angle = FowardAngle;
			}
			Choices [i].SetRotation (0.0f);
		    }
		    i++;
		}
		//Checks if user presses down
		if (sf::Keyboard::IsKeyPressed (sf::Keyboard::Down) && i + 2 < 4)
		{
		    if (i != i + 2)
		    {
                        //Check rotation type
			if (type (ROTATION_LIMIT , ROTATION_START))
			{
			    Angle = OpposeAngle;
			}
			else
			{
			    Angle = FowardAngle;
			}
			Choices [i].SetRotation (0.0f);		   
		    }
		    i += 2;
		}
		//Checks if user presses up
		else if (sf::Keyboard::IsKeyPressed (sf::Keyboard::Up) && i - 2 >= 0)
		{
		    if (i != i - 2)
		    {
                        //Check rotation type
			if (type (ROTATION_LIMIT , ROTATION_START))
			{
			    Angle = OpposeAngle;
			}
			else
			{
			    Angle = FowardAngle;
			}
			Choices [i].SetRotation (0.0f);
		    }		    
		    i -= 2;
		}
		//Checks user's choice
		if (sf::Keyboard::IsKeyPressed (sf::Keyboard::Return))
		{
		    Intro.Stop ();
		    if (i == 0)
		    {
			return OPTION_START;
		    }
		    else if (i == 1)
		    {
			return OPTION_ABOUT;
		    }
		    else if (i == 2)
		    {
			return OPTION_CREDITS;
		    }
		    else if (i == 3)
		    {
			return OPTION_HELP;
		    }
		}
	    }

	}

	//Check for incorrect choices
	if (i <= 0)
	{
	    i = 0;
	}
	if (i >= 4)
	{
	    i = 3;
	}

	//Rotate current choice
	Choices [i].Rotate (Angle);


	//Clear previous
	Window->Clear ();

	//Draw background
	Window->Draw (BackGround);

	//Draw all the choices
	for (j = 0 ; j < 4 ; j++)
	{
	    Window->Draw (Choices [j]);
	}
	
	//Display window
	Window->Display ();
    }
    return OPTION_NONE;
}
