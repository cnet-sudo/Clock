#include "SFMLWorldTime.h"

SFMLWorldTime::SFMLWorldTime(int x, int y, int size, sf::Color mycolor, std::string font)
{
    (size > 10) ? size = 10 : (size < 1) ? size = 1 : size = size;
    position_x = x;
    position_y = y;
    if (!time_font.loadFromFile(font)) exit(13);
    time_color = mycolor;
    font_size = size * 10;
    InitText();
}

void SFMLWorldTime::drawTime(sf::RenderWindow& window)
{

    what_time();
    std::string tmpstr;

    if (newtime.tm_hour < 10)
    {
        tmpstr = "0";
        tmpstr.append(std::to_string(newtime.tm_hour));
    }
    else tmpstr = std::to_string(newtime.tm_hour);
    tmpstr.append(":");
    if (newtime.tm_min < 10) tmpstr.append("0");
    tmpstr.append(std::to_string(newtime.tm_min));
    tmpstr.append(":");
    if (newtime.tm_sec < 10) tmpstr.append("0");
    tmpstr.append(std::to_string(newtime.tm_sec));

    clock_text.setPosition(position_x, position_y);
    clock_text.setString(tmpstr);
    window.draw(clock_text);
}

void SFMLWorldTime::InitText()
{
    clock_text.setFont(time_font);
    clock_text.setCharacterSize(font_size);
    clock_text.setFillColor(time_color);
}

void SFMLWorldTime::what_time()
{
    _time64(&long_time);
    err = _localtime64_s(&newtime, &long_time);
    if (err) exit(23);
}

void SFMLWorldTime::setposition(int x, int y)
{
    position_x = x;
    position_y = y;
}

void SFMLWorldTime::setcolor(sf::Color color)
{
    time_color = color;
    InitText();
}

void SFMLWorldTime::setTime_size(int size)
{
    (size > 10) ? size = 10 : (size < 1) ? size = 1 : size = size;
    font_size = size * 10;
    InitText();
}

int SFMLWorldTime::getsec()
{
    what_time();
    return newtime.tm_sec;
}

int SFMLWorldTime::getmin()
{
    what_time();
    return newtime.tm_min;
}

int SFMLWorldTime::gethour()
{
    what_time();
    return newtime.tm_hour;
}

void InitRect(sf::RectangleShape& rect, float x, float y, float xz, float yz, sf::Color mycolor)
{
    rect.setFillColor(mycolor);
    rect.setOrigin(xz, yz);
    rect.setPosition(x, y);
};







