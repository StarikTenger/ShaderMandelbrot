#include "DrawSystem.h"
#include "GetMilliCount.h"
#include <math.h>
#include <algorithm>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <iostream>



DrawSystem::DrawSystem(){
	window = new sf::RenderWindow(sf::VideoMode(600, 600), "Long live the King!");
	loadTextures();
	textureSpr.loadFromFile("image.png");

	shader.loadFromFile("shader.frag", sf::Shader::Fragment);
}

DrawSystem::~DrawSystem(){}

void DrawSystem::drawScene() {
	w = window->getSize().x;
	h = window->getSize().y;
	window->setView(sf::View(sf::FloatRect(0, 0, w, h)));
	cam.border = { w, h };

	sf::Sprite spr;
	spr.setPosition(0, 0);
	spr.setTexture(textureSpr);

	shader.setUniform("iResolution", sf::Vector2f(w, h));
	shader.setUniform("scale", (float)cam.scale);
	shader.setUniform("camPos", sf::Vector2f(cam.pos.x, -cam.pos.y));
	shader.setUniform("iTime", float(getMilliCount() / 1000.));


	window->draw(spr, &shader);
}

void DrawSystem::drawInterface() {
	
}

void DrawSystem::draw() {
	window->clear();

	drawScene();
	
	drawInterface();
}
