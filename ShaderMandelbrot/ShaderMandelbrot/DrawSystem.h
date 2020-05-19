#pragma once
#include <map>
#include <SFML/Graphics.hpp>
#include "Color.h"
#include "Camera.h"
#include "Mouse.h"

class DrawSystem {
public:
	sf::RenderWindow* window;
	Camera cam;
	bool fullscreenMode = 0;
	DrawSystem();
	~DrawSystem();
	Mouse mouse;
	double w, h;
	double blockSize = 1;

	// SHADER!!!
	sf::Texture textureSpr;
	sf::Shader shader;

	void draw();
	void drawScene();
	void drawInterface();
	sf::Font font;
	
private:
	// basics
	Color fromHSV(double H, double S, double V);
	void fillRect(double x, double y, double width, double height, Color color);
	void fillCircle(double x, double y, double r, Color color);
	void strokeRect(double x, double y, double width, double height, Color color);
	void line(double x, double y, double x1, double y1, Color color);
	void image(std::string name, double x, double y, double width, double height, double angle);
	void image(std::string name, double x, double y, double width, double height, double angle, Color color);
	void text(std::string str, double x, double y, int size, Color color);

	// basics using Vec2d
	void fillRect(Vec2 pos, Vec2 box, Color color);
	void fillCircle(Vec2 pos, Vec2 box, double r, Color color);
	void strokeRect(Vec2 pos, Vec2 box, Color color);
	void line(Vec2 pos, Vec2 pos1, Color color);
	void image(std::string name, Vec2 pos, Vec2 box, double angle);
	void image(std::string name, Vec2 pos, Vec2 box, double angle, Color color);
	void text(std::string str, Vec2 pos, int size, Color color);

	// objects
	
	//load
	std::map<std::string, sf::Texture*> textures;
	void loadTexture(std::string name, std::string path);
	void loadTextures();
};
