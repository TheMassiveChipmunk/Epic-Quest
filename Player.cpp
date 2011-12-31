#include "Player.hpp"

Player::Player (sf::RenderWindow* Window , sf::Image PlayerImage , 
		sf::Image BulletImage , sf::IntRect PlayerRect , 
		sf::IntRect BulletRect , float PlayerSpeedX , float PlayerSpeedY
		, float BulletSpeedX , float BulletSpeedY , float Gravity)
{
    //Set window
    this->Window = Window;
    this->Window->Clear ();

    //Initialize images 
    this->CharacterImage = PlayerImage;
    this->BulletImage = BulletImage;
    
    //Create masks
    this->CharacterImage.CreateMaskFromColor (sf::Color (255 , 0 , 255));
    this->BulletImage.CreateMaskFromColor (sf::Color (255 , 0 , 255));
    
    //Initialize textures
    this->CharacterTexture.LoadFromImage (this->CharacterImage);
    this->BulletTexture.LoadFromImage (this->BulletImage);

    //Initialize sprites
    this->CharacterSprite.SetTexture (this->CharacterTexture);
    this->BulletSprite.SetTexture (this->BulletTexture);
    
    //Initialize game variables
    this->iBulletCounter = 0;
    this->iBulletLimit = 0;
    this->Gravity = Gravity;
    this->iLives = 5;
    this->Touchable = true;
    this->CanShoot = true;

    //Temp variable(s)
    int i = 0;

    //Initialize bullets
    for (i = 0 ; i < BULLET_MAX ; i++)
    {
	this->Bullets [i].Position.Left = PlayerRect.Left + BulletRect.Width;
	this->Bullets [i].Position.Top = PlayerRect.Top + BulletRect.Height;
	this->Bullets [i].Position.Width = BulletRect.Width;
	this->Bullets [i].Position.Height = BulletRect.Height;
	this->Bullets [i].Sprite = this->BulletSprite;
	this->Bullets [i].SpeedX = BulletSpeedX;
	this->Bullets [i].SpeedY = BulletSpeedY;
    }
    
    //Initialize player position
    this->Position.Left = PlayerRect.Left;
    this->Position.Top = PlayerRect.Top;
    this->Position.Width = PlayerRect.Width;
    this->Position.Height = PlayerRect.Height;
    this->CharacterSpeedX = PlayerSpeedX;
    this->CharacterSpeedY = PlayerSpeedY;
}

void Player::reload ()
{
    //Temp variable(s)
    int i = 0;

    //Check if we haven't shot
    if (this->iBulletCounter == 0)
    {
	return;
    }

    //Check if any bullets are in the screen
    for (i = 0 ; i < BULLET_MAX ; i++)
    {
	if (this->Bullets [i].Position.Top > 0)
	{
	    return;
	}
    }

    //All bullets have left the screen we can now reset them
    for (i = 0 ; i < BULLET_MAX ; i++)
    {
	this->Bullets [i].Position.Left = this->Position.Left + this->Bullets [i].Position.Width;
	this->Bullets [i].Position.Top = this->Position.Top + this->Bullets [i].Position.Height;
    }

    //Allow user to shoot once more
    this->CanShoot = true;
    
    //Reset bullet counter
    this->iBulletCounter = 0;
}

void Player::attack ()
{
    //Temp variable(s)
    int i = 0;

    //Check if shot all of our bullets
    if (this->iBulletCounter == BULLET_MAX)
    {
	this->CanShoot = false;
    }
   
    //Update all shot bullets
    for (i = 0 ; i < this->iBulletCounter ; i++)
    {
	this->Bullets [i].Position.Left += this->Bullets [i].SpeedX;
	this->Bullets [i].Position.Top -= this->Bullets [i].SpeedY;
	this->Bullets [i].Sprite.SetPosition (this->Bullets [i].Position.Left , this->Bullets [i].Position.Top);
    }

    //Update all bullets that have not been shot
    for (i = this->iBulletCounter ; i < BULLET_MAX ; i++)
    {
	this->Bullets [i].Position.Left = this->Position.Left + this->Bullets [i].Position.Width - 6;
	this->Bullets [i].Position.Top = this->Position.Top + this->Bullets [i].Position.Height;
    }
}

void Player::draw ()
{
    //Temp variable(s)
    int i = 0;
    
    //Clear window
    this->Window->Clear ();
    
    //Draw player
    this->Window->Draw (this->CharacterSprite);

    //Draw all bullets
    for (i = 0 ; i < this->iBulletCounter ; i++)
    {
	this->Window->Draw (this->Bullets [i].Sprite);
    }

    //Display window
    this->Window->Display ();
}

GameState Player::update ()
{
    //Temp variable(s)
    //int i = 0;
    float VelocityY = 0.0;

    //Event variables
    sf::Event Event;

    //Temp variables
    float X = this->Position.Left;
    float Y = this->Position.Top;

    //If Player is living
    if (this->iLives => 0)
    {
	//Get events
	while (Window->PollEvent (Event))
	{
	    if (Event.Type == sf::Event::Closed)
	    {
		return STATE_END;
	    }
	    if (sf::Keyboard::IsKeyPressed (sf::Keyboard::Escape))
	    {
		return STATE_END;
	    }
	    if (sf::Keyboard::IsKeyPressed (sf::Keyboard::Up))
	    {
		VelocityY = 5.0f;
		Y -= this->CharacterSpeedY;
	    }
	    else if (sf::Keyboard::IsKeyPressed (sf::Keyboard::Down))
	    {
		VelocityY = 0.f;
		Y += this->CharacterSpeedY;
	    }
	    if (sf::Keyboard::IsKeyPressed (sf::Keyboard::Right))
	    {
		X += this->CharacterSpeedX;
	    }
	    else if (sf::Keyboard::IsKeyPressed (sf::Keyboard::Left))
	    {
		X -= this->CharacterSpeedX;
	    }
	    if (sf::Keyboard::IsKeyPressed (sf::Keyboard::Space) && this->CanShoot)
	    {
		//Check if shot all of our bullets
		if (this->iBulletCounter == BULLET_MAX)
		{
		    this->CanShoot = false;
		}
		else
		{
		    this->iBulletCounter++;
		}
	    }
	    if (sf::Keyboard::IsKeyPressed (sf::Keyboard::LControl) || 
		sf::Keyboard::IsKeyPressed (sf::Keyboard::RControl))
	    {
		this->reload ();
	    }
	}
    }
    
    //Update bullets
    this->attack ();

    //Apply gravity
    VelocityY += this->Gravity;
    Y += VelocityY;
    
    //Apply values
    this->Position.Left = X;
    this->Position.Top = Y;

    //Move sprite
    this->CharacterSprite.SetPosition (X , Y);
    
    //Keep ship in borders

    //Check if to high
    if (this->Position.Top <= 0)
    {
	this->Position.Top = 0;
    }

    //Check if to low
    if (this->Position.Top >= 800 - this->Position.Height)
    {
	this->Position.Top = 800 - this->Position.Height - 2;
	//We are giving the ship a little effect
    }

    //Check if to far left
    if (this->Position.Left <= 0)
    {
	this->Position.Left = 0;
    }

    //Check if to far right
    if (this->Position.Left >= 800 - this->Position.Width)
    {
	this->Position.Left = 800 - this->Position.Width;
    }
    
    return STATE_PLAYING;
}
