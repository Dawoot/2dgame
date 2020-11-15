#include<iostream>
#include <vector>
#include "Entity.hpp"
#include "Player.hpp"
#include "Platform.hpp"
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;
int windowheight = 720, windowwidth = 1280;


float accelGravity=0.15;
float maxGravity=3;

int main()
{
	RenderWindow window(VideoMode(windowwidth, windowheight ), "Spel");

	bool game = window.isOpen();

	bool up, down, left, right;
	Texture playertxt;
	Texture platformtxt;
	std::vector <Platform> level;

	playertxt.loadFromFile("rsrc/images/maindefualt.png");
	platformtxt.loadFromFile("rsrc/images/dirt1.png");

	Player player(500.0f,500.0f,10,10,playertxt);

	

	int levelarray[][10] = {
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,0}};
	int sizeofArray=0;
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			if (levelarray[i][j] ==1)
			{
				Platform p(j*10+500,i*10+500,10,10,platformtxt);
				level.push_back(p);

			}
		}
	}
	
	View view(Vector2f(0.0f,0.0f),Vector2f(windowwidth,windowheight));
	
	view.zoom(0.39f);

	window.setFramerateLimit(144);

	while (game)
	{
		Event evnt;
		while (window.pollEvent(evnt))
		{
			if (evnt.type == Event::Closed)
			{
				window.close();
			}
		}
		
		up = Keyboard::isKeyPressed(Keyboard::W);
		down = Keyboard::isKeyPressed(Keyboard::S);
		left = Keyboard::isKeyPressed(Keyboard::A);
		right = Keyboard::isKeyPressed(Keyboard::D);

		window.clear(Color::Blue);
		window.setView(view);
		
		player.update(up,down,right,left,level);
		
		view.setCenter(Vector2f(player.x+player.w,player.y+player.h));
		
		for (Platform &p: level)
		{
			window.draw(p);
		}

		window.draw(player);
		
		window.display();

	}
	return EXIT_SUCCESS;
}