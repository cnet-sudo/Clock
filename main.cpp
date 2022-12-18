#include"SFMLWorldTime.h"
#include<math.h>

using namespace std;
using namespace sf;

int main()
{
    RenderWindow window(VideoMode(900, 900), L"����", Style::Default);
    Image icon;
  if (!icon.loadFromFile("Image/clock.png"))
    {
        return 3;
    }
    window.setIcon(128, 128, icon.getPixelsPtr());

    // ����������� ����    
    SFMLWorldTime etm(50, 50, 4, Color::Yellow);
       
    // ������ ���������� �����
    CircleShape circleTime(300.f);
    circleTime.setOrigin(150,150);
    circleTime.setPosition(303, 303);
    circleTime.setFillColor(Color::Blue);
    circleTime.setOutlineThickness(10);
    circleTime.setOutlineColor(Color::Yellow);

    // ����� ��
    const float PI = acos(-1.f);

    // ������� ���������� ����� ���������� ����������
    CircleShape PointMin;
    PointMin.setFillColor(Color::Yellow);
    float radiusNum = 280; // ������ ������������ �������
    float radiusPoint;
    float CenterClockX = 450;
    float CenterClockY = 450;
    float xPoint, yPoint;

    // ��������� ���������� ���������� ����� ���������� ����������
    Font fontTime;
    if (!fontTime.loadFromFile("lib/dockerthree.ttf")) return 777;
    Text TimeText;
    TimeText.setFont(fontTime);
    TimeText.setCharacterSize(30);
    TimeText.setFillColor(Color::Yellow);
    float numx, numy;
    
    
    // ������ ������� ���������� �����
    RectangleShape secArrow(Vector2f(2,280));                // ���������
    InitRect(secArrow, 453, 453, 1, 280, Color::Red);
    RectangleShape minArrow(Vector2f(8, 260));               // ��������
    InitRect(minArrow, 455, 455, 4, 260, Color::Yellow);
    RectangleShape hourArrow(Vector2f(12, 180));             // �������
    InitRect(hourArrow, 455, 455, 6, 180, Color::Yellow);
        
   while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
    
        window.clear(Color::Blue);
        window.draw(circleTime);  // ������ ���������� �����
        etm.drawTime(window);     // ����������� ����

        // ������� ���������� ����� 
        for (int a=0;a<60;a++)  {
        if (a % 5 == 0)  radiusPoint = 8; else  radiusPoint = 4;
        xPoint = CenterClockX + radiusNum * cos(-6*a*(PI/180)+PI/2);
        yPoint = CenterClockY - radiusNum * sin(-6*a*(PI/180) + PI/2);
        PointMin.setRadius(radiusPoint);
        PointMin.setOrigin(radiusPoint/2, radiusPoint/2);
        PointMin.setPosition(xPoint, yPoint);
        window.draw(PointMin);}

        // ��������� ���������� ���������� �����
        for (int i = 1; i <= 12; i++)
        {
            numx = CenterClockX + (radiusNum - 30) * cos(-30 * i * (PI / 180) + PI / 2);
            numy = CenterClockX - (radiusNum - 30) * sin(-30 * i * (PI / 180) + PI / 2);

            if (i <= 5) TimeText.setPosition(numx - 10, numy - 17);
            else  TimeText.setPosition(numx - 8, numy - 15);
        TimeText.setString(to_string(i));
        window.draw(TimeText);

        }

      secArrow.setRotation(6* etm.getsec());  // �������� ��������� ������� 
      minArrow.setRotation(6 * etm.getmin()+ etm.getsec()*0.1); // �������� �������� ������� 
      hourArrow.setRotation(30 * etm.gethour()+ etm.getmin()*0.5); // �������� ������� ������� 
      window.draw(hourArrow); // ������� �������
      window.draw(minArrow);  // �������� �������
      window.draw(secArrow);  // ���������
      window.display();
    }

    return 0;
}