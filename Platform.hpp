#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.hpp"

class Platform : public Entity
{
private:
	
public:
	void init(float i_x,float i_y,float i_w,float i_h);
};