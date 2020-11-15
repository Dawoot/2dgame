#include <SFML/Graphics.hpp>
#include "Entity.hpp"
#include "Platform.hpp"
#include "Hitbox.hpp"

void Platform::init(float i_x,float i_y,float i_w,float i_h){
	
	x = i_x;
	y = i_y;
	w = i_w;
	h = i_h;
	
	hitbox.top = y;
	hitbox.bottom = y + h;
	hitbox.right = x+w;
	hitbox.left = x;

	m_vertices.setPrimitiveType(sf::Quads); //gör så att man kan sätta hörn
	m_vertices.resize(4);//sätter 4 hörn

	//set vertice position
	m_vertices[0].position = sf::Vector2f(0.0f,0.0f);
	m_vertices[1].position = sf::Vector2f(i_w,0.0f);
	m_vertices[2].position = sf::Vector2f(i_w,i_h);
	m_vertices[3].position = sf::Vector2f(0.0f,i_h);
	//set texture vertices
	m_vertices[0].texCoords = sf::Vector2f(0.0f,0.0f);
	m_vertices[1].texCoords = sf::Vector2f(i_w,0.0f);
	m_vertices[2].texCoords = sf::Vector2f(i_w,i_h);
	m_vertices[3].texCoords = sf::Vector2f(0.0f,i_h);


	setPosition(i_x,i_y);
}