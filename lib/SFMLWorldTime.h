#pragma once
#include <SFML/Graphics.hpp>


class SFMLWorldTime
{
	struct tm newtime;
	__time64_t long_time;
	errno_t err;

	int position_x, position_y;

	int font_size;

	sf::Font time_font;

	sf::Color time_color;

	sf::Text clock_text;

	void InitText();

	void what_time();

public:

	SFMLWorldTime(int x = 50, int y = 50, int size = 3, sf::Color mycolor = sf::Color::White, std::string font = "lib/Ёлектро.ttf");

	void setposition(int x, int y);

	void setcolor(sf::Color color);

	void setTime_size(int size);

	int getsec();

	int getmin();

	int gethour();

	void drawTime(sf::RenderWindow& window);

};


void InitRect(sf::RectangleShape& rect, float x, float y, float xz, float yz, sf::Color mycolor);