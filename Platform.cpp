#include <SFML/Graphics.hpp>
#include "Entity.hpp"
#include "Platform.hpp"
#include "Hitbox.hpp"

Platform::Platform(float i_x,float i_y,float i_w,float i_h,sf::Texture &platformtxt){

	size.x = i_w;
	size.y = i_h;


	hitbox.top = i_y;
	hitbox.bottom = size.y + i_y;
	hitbox.right = size.x+i_x;
	hitbox.left = i_x;
	setTexture(platformtxt);
	setPosition(i_x,i_y);
}