#include "Enemy.hpp"

Enemy::Enemy ()
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

void Player::draw ()
{
    //Temp variable(s)
    int i =0;

    //Draw enemy
    this->Window->Draw (this->CharacterSprite);
    
    //Draw bullets
    for (i = 0 ; i < this->iBulletCounter ; i++)
    {
	this->Window->Draw (this->Bullets [i].Sprite);
    }

    //Display window
    //this->Window->Display ();
}
