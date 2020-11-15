#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Entity.hpp"
#include "Platform.hpp"

class Player : public Entity
{
private:
	float speed;
	bool collision;
	bool onGround;
	float jheight;

public:
	Player(float i_x,float i_y,float i_w,float i_h,sf::Texture &playertxt);
	void update(bool &up,bool &down,bool &right,bool &left,std::vector <Platform> level);
	void collide(float xvel,float yvel,std::vector <Platform> level);
};