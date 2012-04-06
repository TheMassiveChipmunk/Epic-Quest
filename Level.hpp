#ifndef _LEVEL_HPP_
#define _LEVEL_HPP_

#include <iostream>
#include <sstream>
#include <fstream>

#include <map>
#include <vector>
#include <string>

#include <memory>

#include <ctime>
#include <cstdlib>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Util.hpp"
#include "Box.hpp"
#include "Bullet.hpp"
#include "Enemy.hpp"
#include "Player.hpp"

namespace Venom
{
    /*! Is the tile moving. */
    const unsigned int TILE_MOVING = 1;
    
    /*! Is the tile repeating after it gets out-of-bounds.*/
    const unsigned int TILE_REPEAT = 2;
    
    /*! When the player collides with the tile does it lose points. */
    const unsigned int TILE_ENEMY = 4;

    /*! Random X coordinates. */
    const unsigned int TILE_RANDOM_X = 8;

    /*! Random Y coordinates. */
    const unsigned int TILE_RANDOM_Y = 16;

    /*! Is the tile a player. */
    const unsigned int TILE_PLAYER = 32;

    /*! Is the tile an "one up". */
    const unsigned int TILE_ONE_UP = 64;
    
    /*! Is the tile an "invincible". */
    const unsigned int TILE_INVINCIBLE = 128;

    /*! Default tile. */
    const unsigned int TILE_DEFAULT = 256;

    /*! Tile Width. */
    const unsigned int TILE_WIDTH = 50;
    
    /*! Tile Height. */
    const unsigned int TILE_HEIGHT = 50;

    /*! Maximum amount lives. */
    const unsigned int LIVE_MAX = 10;

    /*! State of living. */
    const unsigned int STATE_PLAYING = 1;
    
    /*! Killed all on screen enemies. */
    const unsigned int STATE_KILLED_ALL = 2;

    /*! State of death. */
    const unsigned int STATE_DEAD = 4;

    /*! Tile structure. */
    struct Tile
    {
	float Misc;
	float VelX;
	float VelY;
	float BulletVelX;
	float BulletVelY;
	unsigned int State;
	sf::Texture TileTexture;
	sf::Texture BulletTexture;
    };

    /*! Tile object structure. */
    struct TileObject
    {
	Venom::Box Box;
	unsigned int Type;
	sf::Sprite TileSprite;
	unsigned int Character;
    };

    /*! Handles player and enemy objects. */
    class Level
    {
	/*! Are we alive. */
	bool Alive;
	
	/*! Can we be killed. */
	bool Killable;

	/*Amount of kills */
	unsigned int Kills;
	
	/*! Amount of lives left. */
	unsigned int Lives;
	
	/*! Player position on the vector. */
	unsigned int Player;
	
	/*! Amount of enemies passed. */
	unsigned int Passed;

	/*! General purpose clock. */
	sf::Clock Clock;
	
	/*! Drawing window. */
	sf::RenderWindow* Window;

	/*! Background music. */
	sf::Music Music;
	
	/*! Background sprite. */
	sf::Sprite BackImg;
	
	/*! Background texture. */
	sf::Texture BackGroundImg;
	
	/*! Map holding the tile set. */
	std::map <unsigned int , Venom::Tile> TileSet;
	
	/*! Map holding all characters. */
	std::map <unsigned int , std::shared_ptr <Venom::Character> > Characters;

	/*! Vector holding all tileobjects. */
	std::vector <Venom::TileObject> TileMap;
	
	/*! All Venom::Box positions. */
	std::vector <std::shared_ptr <Venom::Box> > Positions;
    public:
	/*! Default constructor. */
	Level ();

	/*!
	 * Argument constructor.
	 * @param SetFile Tile set file.
	 * @param MapFile Map file.
	 * @param Window A reference to a sf::window.
	 */
	Level (const std::string& SetFile , const std::string& MapFile , sf::RenderWindow& Window);

	/*! Default destructor. */
	~Level ();

	/*! 
	 * Load a tile set. 
	 * @param SetFile Tile set file.
	 * @return False on failure true otherwise.
	 */
	bool loadSet (const std::string& SetFile);
	 
	/*! 
	 * Load a map. 
	 * @param MapFile Map file.
	 * @return False on failure true otherwise.
	 */	
	bool loadMap (const std::string& MapFile);

	/*!
	 * Current game state.
	 * @param Kills Amount of kills before end of game.
	 * @return Game state.
	 */
	unsigned int state (const unsigned int Kills);

	/*!
	 * Get the bit flags switched on.
	 * @param Flags String containing the flags delimited by |.
	 * @return A integer with the bit flags turned on.
	 */
	unsigned int getFlags (const std::string& Flags);

	/*!
	 * Update all of the tiles.
	 */
	void update ();

	/*!
	 * Draw all of the bullets.
	 */
	void drawBullets ();

	/*!
	 * Draw to the window.
	 */
	void draw ();
    };
}


#endif /* _LEVEL_HPP_ */
