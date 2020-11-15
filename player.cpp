#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Entity.hpp"
#include "Player.hpp"
#include "Platform.hpp"

extern float accelGravity;
extern float maxGravity;

Player::Player(float i_x,float i_y,float i_w,float i_h,sf::Texture &playertxt){
	jheight = 3.5f;
	speed = 1.0f;

	size.x = i_w;
	size.y = i_y;
	setPosition(i_x,i_y);
}
void Player::update(bool &up,bool &down,bool &right,bool &left,std::vector<Platform> level){

	if (up && onGround)velocity.y = jheight*-1; 

	if (!onGround)
	{
		velocity.y+=accelGravity;
		if (velocity.y>maxGravity) velocity.y=maxGravity;
	}

	if (down)velocity.y = 1.0f;
	if (right) velocity.x = 1.0f;
	if(left) velocity.x = -1.0f;
	if (!right && !left)velocity.x=0.0f; 
	
	onGround = false;
	
	move(velocity.x*speed,0);
	
	collide(velocity.x*speed,0,level);
	
	move(0, velocity.y);
	
	collide(0,velocity.y*speed,level);

	setPosition(x,y);
}
void Player::collide(float xvel,float yvel,std::vector<Platform> level){
	for (Platform &p:level)
	{
		if (getPosition().x < p.hitbox.right &&
			getPosition().x+w > p.hitbox.left &&
			getPosition().y < p.hitbox.bottom &&
			getPosition().y+h > p.hitbox.top)
		collision = true;	
		else collision = false;
		if (collision)
		{
			if (xvel>0)
			{
				setPosition(level[i].hitbox.left-w;,getPosition().y);
				velocity.x = 0.f;
			}
			if (xvel<0)
			{
				setPosition(level[i].hitbox.right,getPosition().y);
				velocity.x = 0.f;
			}
			if (yvel<0)
			{
				setPosition(getPosition().x,level[i].hitbox.bottom);
				velocity.y = 0.f;
			}
			if (yvel>0)
			{
				setPosition(getPosition().x,level[i].hitbox.top-h);
				velocity.y = 0.f;
				onGround = true;	
			}
		}
	}
}