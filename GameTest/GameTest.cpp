#include <iostream> 
#include "SFML/Graphics.hpp"
#include "string.h"

using namespace std;
using namespace sf;


int main()
{
	RenderWindow window(VideoMode(1620, 1080), " Test");

	Font font;
	font.loadFromFile("Alkatra-VariableFont_wght.ttf");
	//Texts
	Text textx;
	textx.setFont(font);
	textx.setFillColor(Color::Black);
	textx.setCharacterSize(20);
	textx.setPosition(125, 20);

	Text texty;
	texty.setFont(font);
	texty.setFillColor(Color::Black);
	texty.setCharacterSize(20);
	texty.setPosition(125, 50);

	Text console;
	console.setFont(font);
	console.setFillColor(Color::Black);
	console.setCharacterSize(20);
	console.setPosition(125, 200);

	//Shape
	RectangleShape snake;
	snake.setSize(Vector2f(10, 10));
	snake.setFillColor(Color::Blue);
	snake.setPosition(750, 520);

	RectangleShape rectangle(Vector2f(500, 1000));
	rectangle.setFillColor(Color::White);
	rectangle.setOutlineThickness(5);
	rectangle.setOutlineColor(Color::Green);
	rectangle.setPosition(500, 10);

	CircleShape eat;
	eat.setRadius(5);
	eat.setPosition(560, 400);
	eat.setFillColor(Color::Yellow);
	//UI
	ConvexShape fonrectangle;
	fonrectangle.setPointCount(8);
	fonrectangle.setPoint(0,Vector2f(50,10));
	fonrectangle.setPoint(1, Vector2f(300, 10));
	fonrectangle.setPoint(2, Vector2f(320, 40));
	fonrectangle.setPoint(3, Vector2f(320, 540));
	fonrectangle.setPoint(4, Vector2f(300, 580));
	fonrectangle.setPoint(5, Vector2f(50, 580));
	fonrectangle.setPoint(6, Vector2f(30, 540));
	fonrectangle.setPoint(7, Vector2f(30, 40));
	fonrectangle.setFillColor(Color::Blue);

	Text gameover;
	gameover.setFont(font);
	gameover.setFillColor(Color::Red);
	gameover.setCharacterSize(80);
	gameover.setPosition(530, 390);
	gameover.setString("GAME OVER!");

	Text textscope;
	textscope.setFont(font);
	textscope.setCharacterSize(20);
	textscope.setFillColor(Color::Black);
	textscope.setString("Scope: 0");
	textscope.setPosition(125, 80);

	Text textspeed;
	textscope.setFont(font);
	textscope.setCharacterSize(20);
	textscope.setFillColor(Color::Black);
	textscope.setString("Speed: 0.1");
	textscope.setPosition(125, 110);


	bool gameovervalue = false;
	//Life programnm
	while (window.isOpen())
	{
		window.clear(Color::White);
		window.draw(rectangle);
		window.draw(fonrectangle);
		
		Event event;//Close
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed) {
				window.close();
			}

		}
		//Variables
		float x, y;
		int scope = 0;
		Vector2f position,snakesize,epos;
		position = snake.getPosition();
		x = position.x;
		y = position.y;
		string direction = "up";
		float speed = 1;
		bool life = false, put = false;
		snakesize = snake.getSize();

		if (x <= 500 || x >= 990) {
			snake.setPosition(750, 520);
		}
		if (y <= 10 || y >= 1000) {
			snake.setPosition(750, 520);
		}

		//Keybpard events
		if (Keyboard::isKeyPressed(Keyboard::W)) {
			if (gameovervalue == false) {
			life = true;
			direction = "up";
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::A)) {
			if (gameovervalue == false) {
				life = true;
				direction = "left";
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::D)) {
			if (gameovervalue == false) {
				life = true;
				direction = "right";
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::S)) {
			if (gameovervalue == false) {
				life = true;
				direction = "down";
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Enter)) {
			gameovervalue = false;
			life = true;
		}
		//Life game
		while (life == true) {
			window.clear(Color::White);
			window.draw(rectangle);
			//Clouse event
			while (window.pollEvent(event))
			{
				if (event.type == Event::Closed) {
					window.close();
					return 0;
				}

			}
			//Keyboard event
			if (Keyboard::isKeyPressed(Keyboard::A) || Keyboard::isKeyPressed(Keyboard::Left)) {
				direction = "left";
			}
			if (Keyboard::isKeyPressed(Keyboard::W) || Keyboard::isKeyPressed(Keyboard::Up)) {
				direction = "up";
			}
			if (Keyboard::isKeyPressed(Keyboard::S) || Keyboard::isKeyPressed(Keyboard::Down)) {
				direction = "down";
			}
			if (Keyboard::isKeyPressed(Keyboard::D) || Keyboard::isKeyPressed(Keyboard::Right)) {
				direction = "right";
			}
			if (Keyboard::isKeyPressed(Keyboard::R)) {
				speed += 0.001;
			}
			if (Keyboard::isKeyPressed(Keyboard::F)) {
				if (speed <= 0 ) {
					speed += 1;
				}
				speed -= 0.001;
			}

			//Move for snake
			if (direction == "up") {
				y -= 1 * speed;
			}
			else if (direction == "left") {
				x -= 1 * speed;
			}
			else if (direction == "right") {
				x += 1 * speed;
			}
			else if (direction == "down") {
				y += 1 * speed;
			}
			if (x <= 500 || x >= 990) {
				life = false;
				gameovervalue = true;
				window.draw(gameover);
			}
			if (y <= 10 || y >= 1000) {
				life = false;
				gameovervalue = true; 
				window.draw(gameover);
			}
			epos = eat.getPosition();
			if ((static_cast<int>(x) <= static_cast<int>(epos.x + 10) && static_cast<int>(y) <= static_cast<int>(epos.y + 10) && static_cast<int>(x) >= static_cast<int>(epos.x) && static_cast<int>(y) >= static_cast<int>(epos.y)) || (static_cast<int>(x + 10) <= static_cast<int>(epos.x + 10) && static_cast<int>(y + 10) <= static_cast<int>(epos.y + 10) && static_cast<int>(x + 10) >= static_cast<int>(epos.x) && static_cast<int>(y + 10) >= static_cast<int>(epos.y)) ) {
				scope++;
				put = true;
				eat.setPosition(Vector2f(rand() % 450 + 500, rand() % 990 + 10));
			}
			if (put == true) {
				put = false;
			}
			snake.setPosition(x, y);
			textspeed.setString("Speed:" + to_string(speed));
			textx.setString("X:" + to_string(x));
			texty.setString("Y:" + to_string(y));
			console.setString("Speed:" + to_string(speed));
			textscope.setString("Scope:" + to_string(scope));
			window.draw(eat);
			window.draw(snake);
			window.draw(fonrectangle);
			window.draw(textx);
			window.draw(textscope);
			window.draw(textspeed);
			window.draw(texty);
			window.draw(console);
			window.display();
		};
		if (life == false) {
			window.draw(gameover);
		}
		textx.setString("X:" + to_string(x));
		texty.setString("Y:" + to_string(y));
		window.draw(snake);
		window.draw(textx);
		window.draw(textscope);
		window.draw(textspeed);
		//window.draw(console);
		window.draw(texty);
		window.display();
	}

	return 0;
}
