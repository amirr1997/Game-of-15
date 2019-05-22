#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include<iostream>
#include<iomanip>
#include<vector>
#include<ctime>
#include<cstdlib>
#include<string>
#include<sstream>
#include "Util.h"
#include <SFML/Audio.hpp>
#include <math.h>

void base_vec(std::vector<std::vector<int>>& base_vec)
{
	int count{ 0 };
	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			count++;
			base_vec[i][j] = count;
		}
	}
	base_vec[3][3] = 0;
}

void vector(std::vector<std::vector<int>>& num, int& i, int& j, int& x_yellow, int& y_yellow)
{
	srand(time(NULL));
	int x;
	int count{ 1 };
	for (size_t l = 0; l < 4; l++)
	{
		for (size_t k = 0; k < 4; k++)
		{
			num[l][k] = count;
			count++;
		}
	}
	num[3][3] = 0;
	for (size_t m = 0; m < 1000; m++)
	{
		x = rand() % 4;
		switch (x)
		{
		case 0:
			move_up(num, i, j);
			break;
		case 1:
			move_down(num, i, j);
			break;
		case 2:
			move_right(num, i, j);
			break;
		case 3:
			move_left(num, i, j);
			break;
		default:
			break;
		}
	}
	for (size_t m = 0; m < 4; m++)
	{
		for (size_t n = 0; n < 4; n++)
		{
			if (num[m][n] == 0)
			{
				i = m;
				j = n;
				break;
			}
		}
	}
}

void create_shapes(sf::RenderWindow& window, std::vector<std::vector<sf::CircleShape>>& shape,int& i, int& j,int& x_yellow,int& y_yellow)
{
	shape.clear();
	std::vector<sf::CircleShape> shape2;
	sf::CircleShape circle{ 40 };
	circle.setFillColor(sf::Color(150, 150, 150));
	circle.setOutlineThickness(2);
	circle.setOutlineColor(sf::Color::Black);
	for (size_t v{}; v < 4; v++)
	{
		shape2.push_back(circle);
	}
	for (size_t v = 0; v < 4; v++)
	{
		shape.push_back(shape2);
	}
	shape[i][j].setFillColor(sf::Color::Yellow);
	x_yellow = i;
	y_yellow = j;
	for (size_t m = 0; m < 4; m++)
	{
		for (size_t n = 0; n < 4; n++)
		{
			shape[m][n].setPosition(sf::Vector2f(84.0 * (n)+200.0, 84.0 * (m)+150.0));
		}
	}
}

void set_background(sf::ConvexShape& convex, sf::Texture& texture1)
{
	sf::Vector2f point1(0, 0), point2(800, 0), point3(800, 600), point4(0, 600);
	convex.setPoint(0, point1);
	convex.setPoint(1, point2);
	convex.setPoint(2, point3);
	convex.setPoint(3, point4);
	convex.setTexture(&texture1);
}

void set_victory_logo(sf::ConvexShape& convex, sf::Texture& texture2)
{
	sf::Vector2f point1(0, 0), point2(800, 0), point3(800, 600), point4(0, 600);
	convex.setPoint(0, point1);
	convex.setPoint(1, point2);
	convex.setPoint(2, point3);
	convex.setPoint(3, point4);
	convex.setTexture(&texture2);
}

void set_replay_logo(sf::ConvexShape& convex, sf::Texture& texture3)
{
	sf::Vector2f point1(50, 50), point2(150, 50), point3(150, 150), point4(50, 150);
	convex.setPoint(0, point1);
	convex.setPoint(1, point2);
	convex.setPoint(2, point3);
	convex.setPoint(3, point4);
	convex.setTexture(&texture3);
}

void draw_text(sf::RenderWindow& window, std::vector<std::vector<sf::CircleShape>>& shape, std::vector<std::vector<int>>& num, sf::Text& text, std::ostringstream& out)
{
	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			out.str("");
			out.clear();
			if (num[i][j] != 0)
				out << num[i][j];
			text.setString(out.str());
			if (num[i][j]>9)
			{
				text.setPosition(sf::Vector2f(shape[i][j].getPosition().x + shape[i][j].getRadius() - 15,
				shape[i][j].getPosition().y + shape[i][j].getRadius() - 15));
			}
			else
			{
				text.setPosition(sf::Vector2f(shape[i][j].getPosition().x + shape[i][j].getRadius() - 10,
				shape[i][j].getPosition().y + shape[i][j].getRadius() - 15));

			}
			window.draw(text);
		}
	}
}

void drawing_shapes(sf::RenderWindow& window, std::vector<std::vector<sf::CircleShape>>& shape, std::vector<std::vector<bool>>& boolean)
{
	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			if (shape[i][j].getFillColor() != sf::Color::Yellow)
			{
				window.draw(shape[i][j]);
			}
		}
	}
}

void process_event(sf::RenderWindow& window, std::vector<std::vector<sf::CircleShape>>& shape, std::vector<std::vector<bool>>& boolean, int& i_boolean, int& j_boolean, int& x_yellow, int& y_yellow, std::vector<std::vector<int>>& num,bool& boolean1,int& count1,std::vector<bool>& boolean_theme, sf::Sound& sound)
{
	int x;
	int y;
	sf::Event event;
	while (window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			window.close();
			break;
		case sf::Event::Resized:
			break;
		case sf::Event::MouseMoved:
			break;
		case::sf::Event::MouseButtonPressed:
			x = event.mouseButton.x;
			y = event.mouseButton.y;
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				bool_cover(boolean_theme, x, y);
				cover(window, shape, x, y, boolean);
				cover_repeat(window, x, y, boolean1);
				realize_boolean(boolean, window, shape, i_boolean, j_boolean);
				realize_yellow(window, shape, x_yellow, y_yellow);
				moving(window, i_boolean, j_boolean, shape, x_yellow, y_yellow, boolean, num,count1,sound);
			}
			break;
		case sf::Event::MouseButtonReleased:
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				false_cover(boolean);
				boolean1 = false;
			}
			break;
		case sf::Event::TextEntered:
			realize_yellow(window, shape, x_yellow, y_yellow);
			move_keyboard(window, shape, event.text.unicode , x_yellow, y_yellow, num,count1,sound);
			break;
		default:
			break;
		}
	}
}

void false_cover(std::vector<std::vector<bool>>& boolean)
{
	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			boolean[i][j] = false;
		}
	}
}

void cover(sf::RenderWindow& window, std::vector<std::vector<sf::CircleShape>>& shape, int& x_mouse, int& y_mouse, std::vector<std::vector<bool>>& boolean)
{
	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			if (pow(x_mouse - shape[i][j].getPosition().x - shape[i][j].getRadius(), 2) + pow(y_mouse - shape[i][j].getPosition().y - shape[i][j].getRadius(), 2) <= pow(shape[i][j].getRadius(), 2))
			{
				boolean[i][j] = true;
				if (shape[i][j].getFillColor() == sf::Color::Yellow)
					boolean[i][j] = false;
			}
		}
	}
}

void moving(sf::RenderWindow& window, int& i_boolean, int& j_boolean, std::vector<std::vector<sf::CircleShape>>& shape, int& x_yellow, int& y_yellow, std::vector<std::vector<bool>>& boolean, std::vector<std::vector<int>>& num, int& count,sf::Sound& sound)
{
	if (j_boolean != 3)
	{
		if (shape[i_boolean][j_boolean + 1].getFillColor() == sf::Color::Yellow)
		{
			sound.play();
			moving_help(window, i_boolean, j_boolean, shape, x_yellow, y_yellow, boolean, num);
			count++;
		}
	}
	if (j_boolean != 0)
	{
		if (shape[i_boolean][j_boolean - 1].getFillColor() == sf::Color::Yellow)
		{
			sound.play();
			moving_help(window, i_boolean, j_boolean, shape, x_yellow, y_yellow, boolean, num);
			count++;
		}
	}
	if (i_boolean != 3)
	{
		if (shape[i_boolean + 1][j_boolean].getFillColor() == sf::Color::Yellow)
		{
			sound.play();
			moving_help(window, i_boolean, j_boolean, shape, x_yellow, y_yellow, boolean, num);
			count++;
		}
	}
	if (i_boolean != 0)
	{
		if (shape[i_boolean - 1][j_boolean].getFillColor() == sf::Color::Yellow)
		{
			sound.play();
			moving_help(window, i_boolean, j_boolean, shape, x_yellow, y_yellow, boolean, num);
			count++;
		}
	}
}

void move_keyboard(sf::RenderWindow& window, std::vector<std::vector<sf::CircleShape>>& shape, char a,int& x_yellow, int& y_yellow, std::vector<std::vector<int>>& num,int& count1,sf::Sound& sound)
{
	switch (a)
	{
	case 'w':
		if (x_yellow != 0)
		{
			sound.play();
			move_keyboard_help(window, shape);
			shape[x_yellow - 1][y_yellow].setFillColor(sf::Color::Yellow);
			int count;
			count = num[x_yellow][y_yellow];
			num[x_yellow][y_yellow] = num[x_yellow-1][y_yellow];
			num[x_yellow-1][y_yellow] = count;
			count1++;
		}
		break;
	case 's':
		if (x_yellow != 3)
		{
			sound.play();
			move_keyboard_help(window, shape);
			shape[x_yellow + 1][y_yellow].setFillColor(sf::Color::Yellow);
			int count;
			count = num[x_yellow][y_yellow];
			num[x_yellow][y_yellow] = num[x_yellow + 1][y_yellow];
			num[x_yellow + 1][y_yellow] = count;
			count1++;
		}
		break;
	case 'a':
		if (y_yellow != 0)
		{
			sound.play();
			move_keyboard_help(window, shape);
			shape[x_yellow ][y_yellow-1].setFillColor(sf::Color::Yellow);
			int count;
			count = num[x_yellow][y_yellow];
			num[x_yellow][y_yellow] = num[x_yellow][y_yellow - 1];
			num[x_yellow][y_yellow - 1] = count;
			count1++;
		}
		break;
	case 'd':
		if (y_yellow != 3)
		{
			sound.play();
			move_keyboard_help(window, shape);
			shape[x_yellow][y_yellow + 1].setFillColor(sf::Color::Yellow);
			int count;
			count = num[x_yellow][y_yellow];
			num[x_yellow][y_yellow] = num[x_yellow][y_yellow + 1];
			num[x_yellow][y_yellow + 1] = count;
			count1++;
		}
		break;
	default:
		break;
	}
}

void realize_boolean(std::vector<std::vector<bool>>& boolean, sf::RenderWindow& window, std::vector<std::vector<sf::CircleShape>>& shape, int& i_boolean, int& j_boolean)
{
	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			if (boolean[i][j] == true)
			{
				i_boolean = i;
				j_boolean = j;
				break;
			}
		}
	}
}

void realize_yellow(sf::RenderWindow& window, std::vector<std::vector<sf::CircleShape>>& shape, int& x_yellow, int& y_yellow)
{
	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			if (shape[i][j].getFillColor() == sf::Color::Yellow)
			{
				x_yellow = i;
				y_yellow = j;
				break;
			}
		}
	}
}

void move_up(std::vector<std::vector<int>>& vec, int& i, int& j)
{
	int x;
	if (i != 0)
	{
		x = vec[i][j];
		vec[i][j] = vec[i - 1][j];
		vec[i - 1][j] = x;
		i--;
	}
}

void move_down(std::vector<std::vector<int>>& vec, int& i, int& j)
{
	int x;
	if (i != 3)
	{
		x = vec[i][j];
		vec[i][j] = vec[i + 1][j];
		vec[i + 1][j] = x;
		i++;
	}
}

void move_right(std::vector<std::vector<int>>& vec, int& i, int& j)
{
	int x;
	if (j != 3)
	{
		x = vec[i][j];
		vec[i][j] = vec[i][j + 1];
		vec[i][j + 1] = x;
		j++;
	}
}

void move_left(std::vector<std::vector<int>>& vec, int& i, int& j)
{
	int x;
	if (j != 0)
	{
		x = vec[i][j];
		vec[i][j] = vec[i][j - 1];
		vec[i][j - 1] = x;
		j--;
	}
}

void moving_help(sf::RenderWindow& window, int& i_boolean, int& j_boolean, std::vector<std::vector<sf::CircleShape>>& shape, int& x_yellow, int& y_yellow, std::vector<std::vector<bool>>& boolean, std::vector<std::vector<int>>& num)
{
	shape.clear();
	std::vector<sf::CircleShape> shape2;
	sf::CircleShape circle{ 40 };
	circle.setFillColor(sf::Color(150, 150, 150));
	circle.setOutlineThickness(2);
	circle.setOutlineColor(sf::Color::Black);
	for (size_t i{}; i < 4; i++)
	{
		shape2.push_back(circle);
	}
	for (size_t i = 0; i < 4; i++)
	{
		shape.push_back(shape2);
	}
	shape[i_boolean][j_boolean].setFillColor(sf::Color::Yellow);
	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			shape[i][j].setPosition(sf::Vector2f(84 * (j)+200, 84 * (i)+150));
		}
	}
	int count;
	count = num[i_boolean][j_boolean];
	num[i_boolean][j_boolean] = num[x_yellow][y_yellow];
	num[x_yellow][y_yellow] = count;

}

void move_keyboard_help(sf::RenderWindow& window, std::vector<std::vector<sf::CircleShape>>& shape)
{
	shape.clear();
	std::vector<sf::CircleShape> shape2;
	sf::CircleShape circle{ 40 };
	circle.setFillColor(sf::Color(150, 150, 150));
	circle.setOutlineThickness(2);
	circle.setOutlineColor(sf::Color::Black);
	for (size_t i{}; i < 4; i++)
	{
		shape2.push_back(circle);
	}
	for (size_t i = 0; i < 4; i++)
	{
		shape.push_back(shape2);
	}
	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			shape[i][j].setPosition(sf::Vector2f(84 * (j)+200, 84 * (i)+150));
		}
	}
}

void cover_repeat(sf::RenderWindow& window, int& x, int& y, bool& boolean)
{
	if (x >= 50 && x <= 150 && y >= 50 && y <= 150)
	{
		boolean = true;
	}
}

void create_theme(std::vector<sf::RectangleShape>& theme)
{
	static sf::Texture texture_theme;
	if (!texture_theme.loadFromFile("winter.jpg"))
		std::cout << "winter.jpg not found" << std::endl;
	sf::RectangleShape rect{sf::Vector2f(150,90)};
	rect.setTexture(&texture_theme);
	theme.push_back(rect);
	static sf::Texture texture1;
	if (!texture1.loadFromFile("classic.jpg"))
		std::cout << "classic.jpg not found" << std::endl;
	sf::RectangleShape rect1{ sf::Vector2f(150,90) };
	rect1.setTexture(&texture1);
	theme.push_back(rect1);
	static sf::Texture texture2;
	if (!texture2.loadFromFile("cartoon.jpg"))
		std::cout << "cartoon.jpg not found" << std::endl;
	sf::RectangleShape rect2{ sf::Vector2f(150,90) };
	rect2.setTexture(&texture2);
	theme.push_back(rect2);
	static sf::Texture texture4;
	if (!texture4.loadFromFile("green.jpg"))
		std::cout << "green.jpg not found" << std::endl;
	sf::RectangleShape rect4{ sf::Vector2f(150,90) };
	rect4.setTexture(&texture4);
	theme.push_back(rect4);
}

void draw_theme(sf::RenderWindow& window, std::vector<sf::RectangleShape>& theme)
{
	for (size_t i = 0; i < 4; i++)
	{
		theme[i].setPosition(sf::Vector2f(150*(i+1)-50, 510));
		window.draw(theme[i]);
	}
}

void bool_cover(std::vector<bool>& boolean,int& x, int& y)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (x>=100&&x<=250)
		{
			if (y >= 510 && y <= 600)
			{
				false_boolean(boolean);
				boolean[0] = true;
			}
		}
		if (x >= 250 && x <= 400)
		{
			if (y >= 510 && y <= 600)
			{
				false_boolean(boolean);
				boolean[1] = true;
			}
		}
		if (x >= 400 && x <= 550)
		{
			if (y >= 510 && y <= 600)
			{
				false_boolean(boolean);
				boolean[2] = true;
			}
		}
		if (x >= 550 && x <= 700)
		{
			if (y >= 510 && y <= 600)
			{
				false_boolean(boolean);
				boolean[3] = true;
			}
		}
	}
}

void false_boolean(std::vector<bool>& boolean)
{
	for (size_t i = 0; i < 4; i++)
	{
		boolean[i] = false;
	}
}

void creating_background(std::vector<sf::RectangleShape>& rect_theme_background)
{
	static sf::Texture texture_theme;
	if (!texture_theme.loadFromFile("winter.jpg"))
		std::cout << "winter.jpg not found" << std::endl;
	sf::RectangleShape rect{ sf::Vector2f(800,600) };
	rect.setTexture(&texture_theme);
	rect_theme_background.push_back(rect);
	static sf::Texture texture1;
	if (!texture1.loadFromFile("classic.jpg"))
		std::cout << "classic.jpg not found" << std::endl;
	sf::RectangleShape rect1{ sf::Vector2f(800,600) };
	rect1.setTexture(&texture1);
	rect_theme_background.push_back(rect1);
	static sf::Texture texture2;
	if (!texture2.loadFromFile("cartoon.jpg"))
		std::cout << "cartoon.jpg not found" << std::endl;
	sf::RectangleShape rect2{ sf::Vector2f(800,600) };
	rect2.setTexture(&texture2);
	rect_theme_background.push_back(rect2);
	static sf::Texture texture4;
	if (!texture4.loadFromFile("green.jpg"))
		std::cout << "green.jpg not found" << std::endl;
	sf::RectangleShape rect4{ sf::Vector2f(800,600) };
	rect4.setTexture(&texture4);
	rect_theme_background.push_back(rect4);
}

void print_stars(sf::RenderWindow& window, std::vector<sf::RectangleShape>& stars, int& x,sf::Texture& texture)
{
	if (x < 100)
	{
		window.draw(stars[2]);
	}
	if (x < 200)
	{
		window.draw(stars[1]);
	}
	if (x < 300)
	{
		window.draw(stars[0]);
	}
}

void create_star(sf::RenderWindow& window, std::vector<sf::RectangleShape>& stars, int& x, sf::Texture& textur)
{
	sf::RectangleShape rect(sf::Vector2f(50, 50));
	rect.setTexture(&textur);
	for (size_t i = 0; i < 3; i++)
	{
		stars.push_back(rect);
	}
	for (size_t i = 0; i < 3; i++)
	{
		stars[i].setPosition(sf::Vector2f(600 + 60 * (i), 150));
	}
}

void create_text(sf::Text& text1, sf::Text& text2, sf::Text& text3, sf::Font& font)
{
	text1.setFont(font);
	text1.setCharacterSize(24);
	text1.setColor(sf::Color::Black);
	text1.setPosition(sf::Vector2f(80, 235));
	text2.setFont(font);
	text2.setCharacterSize(24);
	text2.setColor(sf::Color::Black);
	text3.setFont(font);
	text3.setCharacterSize(50);
	text3.setColor(sf::Color::Black);
	text3.setPosition(220, 50);
	text3.setString("Game of 15");
	text3.setStyle(sf::Text::Bold | sf::Text::Underlined);
}