#include <iostream> 
#include "SFML/Graphics.hpp"
#include "string.h"
#include "windows.h"
#include <vector>

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

	vector <RectangleShape> snakearr;
	RectangleShape snakehe;
	snakehe.setPosition(Vector2f(750, 530));
	snakehe.setFillColor(Color::Blue);
	snakehe.setSize(Vector2f(10, 10));
	snakearr.push_back(snakehe);
	snakehe.setPosition(Vector2f(750, 540));
	snakearr.push_back(snakehe);
	snakehe.setPosition(Vector2f(750, 550));
	snakearr.push_back(snakehe);
	snakehe.setPosition(Vector2f(750, 560));
	snakearr.push_back(snakehe);
	snakehe.setPosition(Vector2f(750, 570));
	snakearr.push_back(snakehe);
	snakehe.setPosition(Vector2f(750, 580));
	snakearr.push_back(snakehe);
	snakehe.setPosition(Vector2f(750, 590));
	snakearr.push_back(snakehe);
	snakehe.setPosition(Vector2f(750, 600));
	snakearr.push_back(snakehe);
	snakehe.setPosition(Vector2f(750, 610));
	snakearr.push_back(snakehe);
	snakehe.setPosition(Vector2f(750, 620));
	snakearr.push_back(snakehe);

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
	fonrectangle.setPoint(0, Vector2f(50, 10));
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
		int scope = 0, snakearrsize = 9;
		Vector2f position, snakesize, epos;
		position = snake.getPosition();
		x = position.x;
		y = position.y;
		string direction = "up";
		float speed = 1;
		bool life = false, put = false;
		snakesize = snake.getSize();

		for (int i = 0; i < snakearrsize; i++) {
			window.draw(snakearr[i]);
		}

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
				if (x != snakearr[0].getPosition().x + 10) {
					direction = "left";
				}
			}
			if (Keyboard::isKeyPressed(Keyboard::W) || Keyboard::isKeyPressed(Keyboard::Up)) {
				if (y != snakearr[0].getPosition().y + 10) {
					direction = "up";
				}
			}
			if (Keyboard::isKeyPressed(Keyboard::S) || Keyboard::isKeyPressed(Keyboard::Down)) {
				if (y != snakearr[0].getPosition().y - 10) {
					direction = "down";
				}
			}
			if (Keyboard::isKeyPressed(Keyboard::D) || Keyboard::isKeyPressed(Keyboard::Right)) {
				if (x != snakearr[0].getPosition().x - 10) {
					direction = "right";
				}
			}
			if (Keyboard::isKeyPressed(Keyboard::R)) {
				speed += 0.1;
			}
			if (Keyboard::isKeyPressed(Keyboard::F)) {
				if (speed <= 0) {
					speed += 1;
				}
				speed -= 0.1;
			}

			//Move for snake
			if (direction == "up") {
					y -= speed;
			}
			else if (direction == "left") {
					x -= speed;
			}
			else if (direction == "right") {
					x += speed;
			}
			else if (direction == "down") {
					y += speed;
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
			//for (int i = 0; i < snakearrsize; i++) {
			//	if (y == snakearr[i].getPosition().y && x == snakearr[i].getPosition().x || y == snakearr[i].getPosition().y - 10 && x == snakearr[i].getPosition().x + 10) {
			//		life = false;
			//		gameovervalue = true;
			//	}
			//}
			epos = eat.getPosition();
			if ((static_cast<int>(x) <= static_cast<int>(epos.x + 10) && static_cast<int>(y) <= static_cast<int>(epos.y + 10) && static_cast<int>(x) >= static_cast<int>(epos.x) && static_cast<int>(y) >= static_cast<int>(epos.y)) || (static_cast<int>(x + 10) <= static_cast<int>(epos.x + 10) && static_cast<int>(y + 10) <= static_cast<int>(epos.y + 10) && static_cast<int>(x + 10) >= static_cast<int>(epos.x) && static_cast<int>(y + 10) >= static_cast<int>(epos.y))) {
				snakehe.setPosition(snakearr[snakearrsize - 1].getPosition().x + 10, snakearr[snakearrsize - 1].getPosition().y + 10);
				snakearr.push_back(snakehe);
				scope++;
				snakearrsize++;
				put = true;
				eat.setPosition(Vector2f(rand() % 450 + 500, rand() % 990 + 10));
			}
			if (put == true) {
				put = false;
			}
			snake.setPosition(x, y);
			if (snake.getPosition().x - snakearr[0].getPosition().x > 10 || snake.getPosition().x - snakearr[0].getPosition().x < -10) {
				if (snake.getPosition().x - snakearr[0].getPosition().x > 0) {
					snakearr[0].setPosition(snake.getPosition().x - 10, snake.getPosition().y);
				}
				else {
					snakearr[0].setPosition(snake.getPosition().x + 10, snake.getPosition().y);
				}
			}
			if (snake.getPosition().y - snakearr[0].getPosition().y > 10 || snake.getPosition().y - snakearr[0].getPosition().y < -10) {
				if (snake.getPosition().y - snakearr[0].getPosition().y > 0) {
					snakearr[0].setPosition(snake.getPosition().x, snake.getPosition().y - 10);
				}
				else {
					snakearr[0].setPosition(snake.getPosition().x, snake.getPosition().y + 10);
				}
			}
			for (int i = 1; i < snakearrsize; i++) {
				if (snakearr[i - 1].getPosition().x - snakearr[i].getPosition().x > 10 || snakearr[i - 1].getPosition().x - snakearr[i].getPosition().x < -10) {
					if (snakearr[i - 1].getPosition().x - snakearr[i].getPosition().x > 0) {
						snakearr[i].setPosition(snakearr[i - 1].getPosition().x - 10, snakearr[i - 1].getPosition().y);
					}
					else {
						snakearr[i].setPosition(snakearr[i - 1].getPosition().x + 10, snakearr[i - 1].getPosition().y);
					}
				}
				if (snakearr[i - 1].getPosition().y - snakearr[i].getPosition().y > 10 || snakearr[i - 1].getPosition().y - snakearr[i].getPosition().y < -10) {
					if (snakearr[i - 1].getPosition().y - snakearr[i].getPosition().y > 0) {
						snakearr[i].setPosition(snakearr[i - 1].getPosition().x, snakearr[i - 1].getPosition().y - 10);
					}
					else {
						snakearr[i].setPosition(snakearr[i - 1].getPosition().x, snakearr[i - 1].getPosition().y + 10);
					}

				}
			}
			textx.setString("X:" + to_string(x));
			texty.setString("Y:" + to_string(y));
			textspeed.setString("Speed:" + to_string(speed));
			textspeed.setFillColor(Color::Black);
			textspeed.setCharacterSize(20);
			textspeed.setFont(font);
			textspeed.setPosition(125, 140);
			textscope.setString("Scope:" + to_string(scope));
			window.draw(eat);
			window.draw(snake);
			for (int i = 0; i < snakearrsize; i++) {
				window.draw(snakearr[i]);
			}
			window.draw(fonrectangle);
			window.draw(textx);
			window.draw(textscope);
			window.draw(texty);
			window.draw(console);
			window.draw(textspeed);
			Sleep(10);
			window.display();
		};
		window.clear(Color::White);
		window.draw(rectangle);
		window.draw(fonrectangle);
		if (life == false) {
			window.draw(gameover);
		}
		textx.setString("X:" + to_string(x));
		texty.setString("Y:" + to_string(y));
		window.draw(snake);
		snakearr[0].setPosition(snake.getPosition().x,snake.getPosition().y);
		for (int i = 1; i < snakearrsize; i++) {
			snakearr[i].setPosition(snake.getPosition().x, snakearr[i - 1].getPosition().y + 10);
			window.draw(snakearr[i]);
		}
		window.draw(textx);
		window.draw(textscope);
		window.draw(textspeed);
		//window.draw(console);
		window.draw(texty);
		window.display();
	}

	return 0;
}
