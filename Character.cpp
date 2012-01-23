#include "Character.hpp"

void Character::setWindow (sf::RenderWindow* Window)
{
    this->Window = Window;
}

void Character::setPosition (sf::IntRect Pos)
{
    this->Position = Pos;
    this->Sprite.SetPosition (this->Position.Left , this->Position.Top);
}

bool Character::loadTexture (std::string TexturePath)
{
    if (!this->Texture.LoadFromFile (TexturePath))
    {
	std::cerr << "Error loading : " << TexturePath << std::endl;
	return false;
    }
    else
    {
	this->Sprite.SetTexture (this->Texture);
	std::cerr << "Texture : " << TexturePath << " ... loaded!!!" << std::endl;
	return true;
    }
}
