#include "../include/Level.hpp"

/*!
 * Remember that all of the current enemies have a number depending on the tile map vector
 */

/*!
 * Default level constructor.
 */
Venom::Level::Level ()
    : Alive (true) , Killable (true) , Kills (0) , Lives (LIVE_MAX) , Player (0) , Passed (0) , Window (0)
{
}

/*!
 * Argument constructor.
 * @param SetFile Tile set file.
 * @param MapFile Map file.
 * @param Window A reference to a sf::window.
 */
Venom::Level::Level (const std::string& SetFile , const std::string& MapFile , sf::RenderWindow& Window)
    : Alive (true) , Killable (true) , Kills (0) , Lives (LIVE_MAX) , Player (0) , Passed (0) , Window (&Window)
{
    this->loadSet (SetFile);
    this->loadMap (MapFile);
}

/*!
 * Default destructor.
 */
Venom::Level::~Level ()
{
    this->Window->close ();
    this->Music.stop ();
}

/*!
 * Get the amount of lives.
 * @Return Lives left.
 */
unsigned int Venom::Level::lives ()
{
    return this->Lives;
}

/*!
 * Current game state.
 * @return Game state.
 */
unsigned int Venom::Level::state (const unsigned int Kills)
{
    if (this->Kills < Kills && this->Alive)
    {
	return STATE_PLAYING;
    } 
    else if (this->Kills >= Kills && this->Alive)
    {
	return STATE_KILLED_ALL;
    }
    else if (!this->Alive)
    {
	return STATE_DEAD;
    }

    return STATE_PLAYING;
}

/*!
 * Get the bit flags switched on.
 * @param Flags String containing the flags delimited by |.
 * @return A integer with the bit flags turned on.
 */
unsigned int Venom::Level::getFlags (const std::string& Flags)
{
    //The flags turned on.
    unsigned int Bits = 0;

    //Vector holding all of the split strings.
    std::vector <std::string> Strings;
    Venom::split (Strings , Flags , "|");

    //Iterator
    std::vector <std::string>::iterator it;
    
    for (it = Strings.begin () ; it != Strings.end () ; it++)
    {
	if (Venom::toUpper (*it) == "TILE_MOVING")
	{
	    Bits = Bits | TILE_MOVING;
	}
	if (Venom::toUpper (*it) == "TILE_REPEAT")
	{
	    Bits = Bits | TILE_REPEAT;
	}
	if (Venom::toUpper (*it) == "TILE_ENEMY")
	{
	    Bits = Bits | TILE_ENEMY;
	}
	if (Venom::toUpper (*it) == "TILE_RANDOM_X")
	{
	    Bits = Bits | TILE_RANDOM_X;
	}
	if (Venom::toUpper (*it) == "TILE_RANDOM_Y")
	{
	    Bits = Bits | TILE_RANDOM_Y;
	}
	if (Venom::toUpper (*it) == "TILE_PLAYER")
	{
	    Bits = Bits | TILE_PLAYER;
	}
	if (Venom::toUpper (*it) == "TILE_ONE_UP")
	{
	    Bits = Bits | TILE_ONE_UP;
	}
	if (Venom::toUpper (*it) == "TILE_INVINCIBLE")
	{
	    Bits = Bits | TILE_INVINCIBLE;
	}
	if (Venom::toUpper (*it) == "TILE_DEFAULT")
	{
	    Bits = Bits | TILE_DEFAULT;
	}
    }

    return Bits;
}


/*! 
 * Load a tile set. 
 * @param SetFile Tile set file.
 * @return False on failure true otherwise.
 */
bool Venom::Level::loadSet (const std::string& SetFile)
{
    this->Kills = 0;
    this->TileSet.clear ();
    this->Characters.clear ();
    this->TileMap.clear ();
    this->Positions.clear ();

    std::ifstream Stream (SetFile.c_str ());

    //Is the stream open.
    if (Stream.is_open ())
    {	
	//Temp tile.
	Venom::Tile Temp;

	unsigned int i = 0;
	
	//While good
	while (Stream.good ())
	{
	    i++;

	    std::string FilePath ("");

	    //Bit flags
	    std::string Bits;
	    
	    //Get the texture file path.
	    Stream >> FilePath;

	    //If we are at the end then exit.
	    if (Stream.eof ())
	    {
		return true;
	    }
	    
	    //If we are commenting something.
	    if (FilePath [0] == '#')
	    {
		std::getline (Stream , FilePath);
		FilePath = "";
		
		i--;
	    }
	    
	    //If we are getting the background image.
	    else if (FilePath == "B_IMG")
	    {	
		FilePath = "";
		Stream >> FilePath;
		
		Venom::loadTexture (FilePath , this->BackGroundImg);
		
		this->BackImg.setTexture (this->BackGroundImg);
	    }
	    //If we are getting the background music.
	    else if (FilePath == "B_MUS")
	    {	
		FilePath = "";
		Stream >> FilePath;
		
		this->Music.stop ();
		this->Music.openFromFile (FilePath);
		this->Music.setLoop (true);
		this->Music.play ();
	    }
	    //We are getting a tile
	    else
	    {
		
		//Load the texture
		Venom::loadTexture (FilePath , Temp.TileTexture);
		
		//Get the bit flags.
		Stream >> Bits;
		
		//Check the bit flags.
		Temp.State = this->getFlags (Bits);

		//If it is moving then it has a velocity X and Y.
		if (Temp.State & TILE_MOVING && 
		    !(Temp.State & TILE_PLAYER) && 
		    !(Temp.State & TILE_ENEMY))
		{
		    Stream >> Temp.VelX;
		    Stream >> Temp.VelY;		
		}
		//If it is a character.
		else if (Temp.State & TILE_ENEMY || 
		    Temp.State & TILE_PLAYER)
		{
		    //Get velocities.
		    Stream >> Temp.VelX;
		    Stream >> Temp.VelY;
		    Stream >> Temp.BulletVelX;
		    Stream >> Temp.BulletVelY;
		    
		    //Get bullet file path.
		    Stream >> FilePath;
		    
		    Venom::loadTexture (FilePath , Temp.BulletTexture);
		}
		if (Temp.State & TILE_ONE_UP ||
		    Temp.State & TILE_INVINCIBLE)
		{
		    //Amount of kills to get.
		    Stream >> Temp.Misc;
		}
		
		//Add the tile.
		this->TileSet.insert (std::pair <unsigned int , Venom::Tile> (i , Temp));
	    }
	}
    }
    else
    {
	Venom::logMessage <std::string> ("Could not load file : " + SetFile);
	
	return false;
    }
    
    return true;
}    

/*! 
 * Load a map. 
 * @param MapFile Map file.
 * @return False on failure true otherwise.
 */	
bool Venom::Level::loadMap (const std::string& MapFile)
{
    //Clear previous maps and characters.
    this->Characters.clear ();
    this->TileMap.clear ();
    this->Positions.clear ();

    //Load file.
    std::ifstream Stream (MapFile.c_str ());

    if (Stream.is_open ())
    {
	//Temp variables
	unsigned int i = 0;
	unsigned int j = 0;
	unsigned int X = 0;
	unsigned int Y = 0;
	
	while (Stream.good ())
	{
	    //Temp object.
	    Venom::TileObject Temp;
	    
	    //Get tile type.
	    Stream >> i;
	    
	    //If we are at the end of the file then exit.
	    if (Stream.eof ())
	    {
		return true;
	    }
	    
	    //If i is a valid tile.
	    if (i != 0)
	    {
	    
		Temp.Type = i;
	    
		//Set X and Y positions.
		Temp.Box.setX (X * TILE_WIDTH);
		Temp.Box.setY (Y * TILE_HEIGHT);

		//Set sprite texture.
		Temp.TileSprite.setTexture ((this->TileSet [i]).TileTexture);	    

		//Set position onto sprite.
		Temp.TileSprite.setPosition (X * TILE_WIDTH , Y * TILE_HEIGHT);

		//If the tile is a enemy
		if ((this->TileSet [Temp.Type]).State & TILE_ENEMY)
		{
		    //Add a box to the positions vector
		    Venom::Box* Box = new Venom::Box (X * TILE_WIDTH , Y * TILE_HEIGHT , 
						      this->TileSet [Temp.Type].TileTexture.getSize ().x ,
						      this->TileSet [Temp.Type].TileTexture.getSize ().y);
		    
		    //Add an enemy to the characters vector.
		    Venom::Enemy* Enemy = new Venom::Enemy (*Box , (this->TileSet [Temp.Type]).VelX , (this->TileSet [Temp.Type]).VelY , 
							    (this->TileSet [Temp.Type]).BulletVelX , (this->TileSet [Temp.Type]).BulletVelY ,
							    (this->TileSet [Temp.Type]).BulletTexture.getSize ().x , 
							    (this->TileSet [Temp.Type]).BulletTexture.getSize ().y , *(this->Window));
		    //The position on the tile map vector.
		    Temp.Character = j;

		    //Add to the positions and characters vector.
		    this->Positions.push_back (std::shared_ptr <Venom::Box> (Box));
		    this->Characters.insert (std::pair <unsigned int , std::shared_ptr <Venom::Enemy> > (j , std::shared_ptr <Venom::Enemy> (Enemy)));
		}
		
		if ((this->TileSet [Temp.Type]).State & TILE_PLAYER)
		{
		    //Add a box to the positions vector
		    Venom::Box* Box = new Venom::Box (X * TILE_WIDTH , Y * TILE_HEIGHT , 
						      this->TileSet [Temp.Type].TileTexture.getSize ().x , 
						      this->TileSet [Temp.Type].TileTexture.getSize ().y);

		    //Add a player to the characters vector.
		    Venom::Player* Player = new Venom::Player (*Box , (this->TileSet [Temp.Type]).VelX , (this->TileSet [Temp.Type]).VelY , 
							       (this->TileSet [Temp.Type]).BulletVelX , (this->TileSet [Temp.Type]).BulletVelY , 
							       (this->TileSet [Temp.Type]).TileTexture.getSize ().x , 
							       (this->TileSet [Temp.Type]).TileTexture.getSize ().y , 
							       *(this->Window));
		    
		    //The position on the tile map vector.
		    Temp.Character = j;

		    //Add to the positions and characters vector.		    
		    this->Positions.push_back (std::shared_ptr <Venom::Box> (Box));
		    this->Characters.insert (std::pair <unsigned int , std::shared_ptr <Venom::Player> > (j , std::shared_ptr <Venom::Player> (Player)));

		    //Set the player position.
		    this->Player = j;
		}
		
		//If the tile is a power up.
		if ((this->TileSet [Temp.Type]).State & TILE_ONE_UP ||
		    (this->TileSet [Temp.Type]).State & TILE_INVINCIBLE)
		{	
		    //Set the width and height.
		    Temp.Box.setDimensions (this->TileSet [Temp.Type].TileTexture.getSize ().x , 
					    this->TileSet [Temp.Type].TileTexture.getSize ().y);
		}
		
		j++;

		//Add a tile.
		this->TileMap.push_back (Temp);
	    }
		
	    X++;
	    
	    //Update X and Y positions.
	    if (X * TILE_WIDTH >= this->Window->getSize ().x)
	    {
		X = 0;
		Y++;
	    }
	    if (Y * TILE_HEIGHT >= this->Window->getSize ().y)
	    {
		break;
	    }
	}
    }
    else
    {
	Venom::logMessage <std::string> ("Could not load file : " + MapFile);
	
	return false;
    }
    
    return true;
}
/*!
 * Handle menu options.
 * @param Choices Menu choices.
 * @param Size amount of choices.
 * @Return Choice made.
 */
std::string& Venom::Level::menu (std::string Choices [] , const int Size)
{
    int i = 0;
    int j = 0;

    bool Up = true;
    bool Down = true;
    
    const sf::Color SELECT_COLOR (255 , 255 , 100);
    const sf::Color DEFAULT_COLOR (0 , 100 , 255);

    std::vector <sf::Text> Drawables;

    for (i = 0 ; i < Size ; i++)
    {
	Drawables.push_back (sf::Text (Choices [i]));
    }

    for (i = 0 ; i < Size ; i++)
    {
	Drawables.at (i).setPosition (this->Window->getSize ().x / 2 - 100 , (i * 50) + (this->Window->getSize ().y / 2) - 100);
	Drawables.at (i).setColor (DEFAULT_COLOR);
    }
    
    i = 0;

    while (!sf::Keyboard::isKeyPressed (sf::Keyboard::Return))
    {
	//If we are adding volume.
	if (sf::Keyboard::isKeyPressed (sf::Keyboard::Add))
	{
	    //Add volume.
	    this->Music.setVolume (this->Music.getVolume () + 10.0f);
	    
	    if (this->Music.getVolume () > 10.0f)
	    {
		if (this->Music.getStatus () == sf::SoundSource::Status::Stopped)
		{
		    this->Music.play ();
		}
	    }
	}
	if (sf::Keyboard::isKeyPressed (sf::Keyboard::Subtract))
	{
	    //Subtract volume.
	    this->Music.setVolume (this->Music.getVolume () - 10.0f);
	    
	    if (this->Music.getVolume () <= 10.0f)
	    {
		if (this->Music.getStatus () == sf::SoundSource::Status::Playing)
		{
		    this->Music.stop ();
		}
	    }
	}

	if (sf::Keyboard::isKeyPressed (sf::Keyboard::Up) && Up)
	{
	    i--;
	    Up = false;
	}
	else if (!sf::Keyboard::isKeyPressed (sf::Keyboard::Up) && !Up)
	{
	    Up = true;
	}
	if (sf::Keyboard::isKeyPressed (sf::Keyboard::Down) && Down)
	{
	    i++;
	    Down = false;
	}
	else if (!sf::Keyboard::isKeyPressed (sf::Keyboard::Down) && !Down)
	{
	    Down = true;
	}
	
	if (i == Size)
	{
	    i = Size - 1;
	}
	if (i == -1)
	{
	    i = 0;
	}
	
	this->Window->clear ();
	this->Window->draw (BackImg);
	
	for (j = 0 ; j < Size ; j++)
	{
	    if (j == i)
	    {
		Drawables.at (i).setColor (SELECT_COLOR);
	    }
	    else
	    {
		Drawables.at (j).setColor (DEFAULT_COLOR);
	    }
	    
	    this->Window->draw (Drawables.at (j));
	}

	this->Window->display ();
    }

    return Choices [i];
}

/*!
 * Update all of the tiles.
 */
void Venom::Level::update ()
{
    //If the lives are 0 then we are done.
    if (this->Lives == 0)
    {
	this->Alive = false;
	return;
    }
    //If 100 enemies have passed then we loose 1 life.
    if (this->Passed % 100 == 0 &&
	this->Passed >= 100)
    {
	this->Lives--;
	this->Passed++;
    }
    //If the amount of kills is a multiple of a 100 add a life.
    if (this->Kills % 100 == 0 && 
	this->Kills >= 100)
    {
	this->Lives++;
	this->Kills++;
    }

    //Temporary event variable.
    sf::Event Event;

    //While there is an event.
    while (this->Window->pollEvent (Event))
    {
	//If we are closing then exit the program.
	if (Event.type == sf::Event::Closed)
	{
	    this->Window->close ();
	    this->Music.stop ();
	    exit (0);
	}	
	if (sf::Keyboard::isKeyPressed (sf::Keyboard::Escape))
	{
	    std::string Choice ("");
	    std::string Choices [] = {
		"RESUME" , "HELP" , "QUIT"
	    };
	    
	    Choice = this->menu (Choices , 3);
	    
	    if (Choice == "RESUME")
	    {
	    }
	    else if (Choice == "QUIT")
	    {
		this->Window->close ();
		this->Music.stop ();
		exit (0);
	    }
	    else if (Choice == "HELP")
	    {	
		Venom::logMessage <std::string> ("Help option not implemented! :(");
	    }
	}        
     
	//If we are adding volume.
	if (sf::Keyboard::isKeyPressed (sf::Keyboard::Add))
	{
	    //Add volume.
	    this->Music.setVolume (this->Music.getVolume () + 10.0f);
	    
	    if (this->Music.getVolume () > 10.0f)
	    {
		if (this->Music.getStatus () == sf::SoundSource::Status::Stopped)
		{
		    this->Music.play ();
		}
	    }
	}
	if (sf::Keyboard::isKeyPressed (sf::Keyboard::Subtract))
	{
	    //Subtract volume.
	    this->Music.setVolume (this->Music.getVolume () - 10.0f);
	    
	    if (this->Music.getVolume () <= 10.0f)
	    {
		if (this->Music.getStatus () == sf::SoundSource::Status::Playing)
		{
		    this->Music.stop ();
		}
	    }
	}
    }
    
    //Vector iterator.
    std::vector <TileObject>::iterator vit;
    
    //Map iterators.
    std::map <unsigned int , std::shared_ptr <Venom::Character> >::iterator mit;
    std::map <unsigned int , std::shared_ptr <Venom::Character> >::iterator mit2;
    
    //Default iterators.
    unsigned int i = 0;
    unsigned int j = 0;

    //If a player collides with an enemy.
    for (mit = this->Characters.begin () ; mit != this->Characters.end () ; mit++)
    {	
	//Update
	mit->second->update ();

	//Set all tiles to the correct position.
	this->TileMap.at (mit->first).TileSprite.setPosition (mit->second->getX () , mit->second->getY ());

	if (this->Clock.getElapsedTime ().asMilliseconds () > 1500)
	{
	    if (this->TileSet [this->TileMap.at (mit->first).Type].State & TILE_ENEMY && 
		!(this->TileSet [this->TileMap.at (mit->first).Type].State & TILE_PLAYER))
	    {
		//If we are able to be killed.
		if (this->Killable)
		{
		    //If collided.
		    if (this->Characters [this->Player]->collides ((mit->second->get ())))
		    {
			//Reduce amount of lives.
			this->Lives--;
			
			//Restart clock.
			this->Clock.restart ();
			
			//Set sprite gray.
			this->TileMap.at (this->Player).TileSprite.setColor (DEATH_COLOR);
			
			break;
		    }
		    //Check for player bullet collision.
		    for (i = 0 ; i < mit->second->size () ; i++)
		    {	    
			if (this->Characters [this->Player]->collides (mit->second->at (i))  && this->Killable)
			{
			    //Reduce amount of lives.
			    this->Lives--;
			    
			    //Restart clock.
			    this->Clock.restart ();

			    //Set sprite gray.
			    this->TileMap.at (this->Player).TileSprite.setColor (DEATH_COLOR);
			    
			    break;
			}
		    }
		}
	    }
	    
	}

	//Reset old color.
	if (this->Clock.getElapsedTime ().asMilliseconds () > 1450 &&
	    this->Clock.getElapsedTime ().asMilliseconds () < 1500 &&
	    this->Killable) 
	{
	    this->TileMap.at (this->Player).TileSprite.setColor (sf::Color (255 , 255 , 255));
	}
	
	//Make player kill-able again.
	if (this->Clock.getElapsedTime ().asSeconds () > 10 && !(this->Killable))
	{
	    this->Killable = true;
	} 
	
	//Check for enemy bullet collision.
	for (i = 0 ; i  < this->Characters [this->Player]->size () ; i++)
	{
	    if (this->TileSet [this->TileMap.at (mit->first).Type].State & TILE_ENEMY)
	    {
		if (mit->second->collides (this->Characters [this->Player]->at (i)) && 
		    !(this->TileSet [this->TileMap.at (mit->first).Type].State & TILE_PLAYER))
		{
		    //Add a kill.
		    this->Kills++;		
		    
		    //Set out of map.
		    mit->second->set (-100.0f , -100.0f);
		}
	    }
	}

	//Check for enemy collision.
	for (mit2 = this->Characters.begin () ; mit2 != this->Characters.end () ; mit2++)
	{
	    //If we are not check a player and the current m is not m2.
	    if (j != this->Player && mit2->first != mit->first)
	    {
		//If the enemies collide then reset them.
		if (mit2->second->collides (mit->second->get ()))
		{
		    if (this->TileSet [this->TileMap.at (mit2->first).Type].State & TILE_RANDOM_X)
		    {
			mit2->second->set (static_cast <float> (rand () % (this->Window->getSize ().x - TILE_WIDTH)) , 0.0f);
		    }
		    if (this->TileSet [this->TileMap.at (mit2->first).Type].State & TILE_RANDOM_Y)
		    {
			mit2->second->set (0.0f ,  static_cast <float> (rand () % (this->Window->getSize ().y - TILE_HEIGHT)));
		    }
		}
	    }	    

	    j++;
	}
    }
    
    j = 0;
    
    for (vit = this->TileMap.begin () ; vit != this->TileMap.end () ; vit++)
    {
	//Is the sprite moving
	if (this->TileSet [vit->Type].State & TILE_MOVING)
	{
	    //If the sprite is a power up.
	    if (this->TileSet [vit->Type].State & TILE_INVINCIBLE ||
		this->TileSet [vit->Type].State & TILE_ONE_UP)
	    {
		//If the kills are great than the amount needed then move the sprite.
		if (this->Kills >= this->TileSet [vit->Type].Misc)
		{
		    if (vit->TileSprite.getPosition ().x <= this->Window->getSize ().x &&
			vit->TileSprite.getPosition ().x >= 0 &&
			vit->TileSprite.getPosition ().y <= this->Window->getSize ().y &&
			vit->TileSprite.getPosition ().y >= 0)
		    {
			vit->TileSprite.setPosition (vit->TileSprite.getPosition ().x + this->TileSet [vit->Type].VelX ,
						     vit->TileSprite.getPosition ().y + this->TileSet [vit->Type].VelY);
			vit->Box.set (vit->TileSprite.getPosition ().x , 
				      vit->TileSprite.getPosition ().y);
		    }
		}
	    }
	    else
	    {
		//Move the sprite.
		vit->TileSprite.setPosition (vit->TileSprite.getPosition ().x + this->TileSet [vit->Type].VelX ,
					     vit->TileSprite.getPosition ().y + this->TileSet [vit->Type].VelY);
	    }
	}
	
	//Check if we want to repeat the sprite.
	if (this->TileSet [vit->Type].State & TILE_REPEAT && 
	    (vit->TileSprite.getPosition ().y > this->Window->getSize ().y || 
	     vit->TileSprite.getPosition ().y < 0))
	{
	    //If the tile is an enemy.
	    if (this->TileSet [vit->Type].State & TILE_ENEMY)
	    {
		this->Characters [vit->Character]->set (vit->Box.get ());
		this->Passed++;
	    }
	    else
	    {
		vit->TileSprite.setPosition (vit->Box.getX () , vit->Box.getY ());
	    }
	    //If the tile wants a random X coordinate.
	    if (this->TileSet [vit->Type].State & TILE_RANDOM_X)
	    {
		if (this->TileSet [vit->Type].State & TILE_ENEMY || this->TileSet [vit->Type].State & TILE_PLAYER)
		{
		    this->Characters [vit->Character]->set (static_cast <float> (rand () % (this->Window->getSize ().x - TILE_WIDTH)) , 0.0f);
		}
		else
		{		    
		    vit->TileSprite.setPosition (rand () % (this->Window->getSize ().x - TILE_WIDTH) , 0.0f);
		}
	    }
	    //If the tile wants a random Y coordinate.
	    if (this->TileSet [vit->Type].State & TILE_RANDOM_Y)
	    {
		if (this->TileSet [vit->Type].State & TILE_ENEMY || this->TileSet [vit->Type].State & TILE_PLAYER)
		{
		    this->Characters [vit->Character]->set (0.0f ,  rand () % (this->Window->getSize ().y - TILE_HEIGHT));
		}
		else
		{
		    vit->TileSprite.setPosition (0.0f , rand () %  (this->Window->getSize ().y - TILE_HEIGHT));
		}
	    }
	    
	}
	//If the tile is a power up.
	if (this->TileSet [vit->Type].State & TILE_ONE_UP ||
	    this->TileSet [vit->Type].State & TILE_INVINCIBLE)
	{
	    //If the tile can be activated.
	    if (this->Kills >= this->TileSet [vit->Type].Misc)
	    {
		//If the player collided.
		if (this->Characters [this->Player]->collides (vit->Box))
		{
		    //Activate the tile.
		    if (this->TileSet [vit->Type].State & TILE_ONE_UP)
		    {
			this->Lives++;
			vit->Box.set (-100.0f , -100.0f);
			vit->TileSprite.setPosition (-100.0f , -100.0f);
		    }
		    if (this->TileSet [vit->Type].State & TILE_INVINCIBLE)
		    {
			this->Killable = false;
			vit->Box.set (-100.0f , -100.0f);
			vit->TileSprite.setPosition (-100.0f , -100.0f);
			this->TileMap.at (this->Player).TileSprite.setColor (DEATH_COLOR);
		    }
		}
	    }
	}
    }
}


/*!
 * Draw all of the bullets.
 */
void Venom::Level::drawBullets ()
{
    //If we are dead then draw "Game Over"
    if (!this->Alive)
    {
	Venom::drawText ("Game Over!" , 50.0f , this->Window->getSize ().x / 2 , this->Window->getSize ().y / 2 , *(this->Window));
	return;
    }
    
    //Map iterator.
    std::map <unsigned int , std::shared_ptr <Venom::Character> >::iterator it;
    
    //Default iterator.
    unsigned int i = 0;

    //Show kills, lives, and enemies passed.
    std::string Kills ("");
    std::string Lives ("");
    std::string Passed ("");
    std::stringstream Stream;
    
    //Print the values.
    Stream << "Lives : " << this->Lives << std::endl;
    Stream << "Kills : " << this->Kills << std::endl;
    Stream << "Passed : " << this->Passed << std::endl;

    //Get the values.
    std::getline (Stream , Kills);
    std::getline (Stream , Lives);
    std::getline (Stream , Passed);

    //Draw kills, lives, and enemies passed.
    Venom::drawText (Kills , 20.0f , this->Window->getSize ().x - 150 , this->Window->getSize ().y - 150, *(this->Window));
    Venom::drawText (Lives , 20.0f , this->Window->getSize ().x - 150 , this->Window->getSize ().y - 100 , *(this->Window));
    Venom::drawText (Passed , 20.0f , this->Window->getSize ().x - 150 , this->Window->getSize ().y - 50 , *(this->Window));

    //Draw all of the bullets.
    for (it = this->Characters.begin () ; it != this->Characters.end () ; it++)
    {	
	for (i = 0 ; i < it->second->size () ; i++)
	{
	    sf::Sprite Sprite (this->TileSet [this->TileMap.at (it->first).Type].BulletTexture);
	    
	    Sprite.setPosition (it->second->at (i).getX () , it->second->at (i).getY ());
	    
	    this->Window->draw (Sprite);	    
	}
    }
}

/*!
 * Draw to the window.
 */
void Venom::Level::draw ()
{
    //Vector iterator.
    std::vector <TileObject>::iterator it;    
    
    //Draw background.
    this->Window->draw (this->BackImg);
    
    for (it = this->TileMap.begin () ; it !=this->TileMap.end () ; it++)
    {	
	//Is the sprite a power up.
	if (this->TileSet [it->Type].State & TILE_ONE_UP ||
	    this->TileSet [it->Type].State & TILE_INVINCIBLE)
	{
	    //Check if can draw a power up.
	    if (this->Kills >= this->TileSet [it->Type].Misc)
	    {	
		//If not out of bounds.
		if (it->TileSprite.getPosition ().x <= this->Window->getSize ().x &&
		    it->TileSprite.getPosition ().x >= 0 &&
		    it->TileSprite.getPosition ().y <= this->Window->getSize ().y &&
		    it->TileSprite.getPosition ().y >= 0)
		{
		    this->Window->draw (it->TileSprite);
		}
	    }
	}
	//Draw the sprite.
	else
	{
	    this->Window->draw (it->TileSprite);
	}
    }
    
    this->drawBullets ();
}
