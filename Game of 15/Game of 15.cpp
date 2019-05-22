#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include<iostream>
#include<iomanip>er
#include<vector>
#include<ctime>
#include<cstdlib>
#include<string>
#include<sstream>
#include "Util.h"

int main()
{
	sf::Music music;
	if (!music.openFromFile("music.ogg"))
		std::cout << "Error" << std::endl;
	music.setLoop(true);
	music.play();
	sf::SoundBuffer buffer;
	if (!buffer.loadFromFile("sound.wav"))
		std::cout << "Error" << std::endl;
	sf::Sound sound;
	sound.setBuffer(buffer);

	int count_move{};
	bool boolean1{ false };
	int i{3};
	int j{3};
	int x_yellow{ };
	int y_yellow{ };
	int i_boolean{};
	int j_boolean{};

	std::vector<sf::RectangleShape> rect_theme_background;
	std::vector<bool> boolean_theme(4);
	boolean_theme[2] = true;
	std::vector<sf::RectangleShape> stars;
	std::vector<sf::RectangleShape> theme;
	std::vector<std::vector<int>> base_num(4, std::vector<int>(4));
	std::vector<std::vector<int>> num(4, std::vector<int>(4));
	std::vector<std::vector<bool>> boolean(4, std::vector<bool>(4));
	std::vector<std::vector<sf::CircleShape>> shape;

	creating_background(rect_theme_background);
	create_theme(theme);
	base_vec(base_num);
	vector(num, i , j, x_yellow, y_yellow);

	sf::ConvexShape convex1{ 4 };
	sf::ConvexShape convex2{ 4 };
	sf::ConvexShape convex3{ 4 };

	sf::CircleShape circle{ 50 };
	circle.setOutlineThickness(5);
	circle.setOutlineColor(sf::Color::Black);
	circle.setPosition(sf::Vector2f(50, 200));
	circle.setFillColor(sf::Color(154, 205, 50));

	sf::Texture texture_star;
	if (!texture_star.loadFromFile("star.png"))
		std::cout << "star.png is not found" << std::endl;
	sf::Texture texture2;
	if (!texture2.loadFromFile("victory.jpg"))
		std::cout << "victory.jpg not found" << std::endl;
	sf::Texture texture3;
	if (!texture3.loadFromFile("replay.jpg"))
		std::cout << "replay.png not found" << std::endl;

	set_victory_logo(convex2, texture2);
	set_replay_logo(convex3, texture3);

	std::ostringstream out;
	std::ostringstream out1;

	sf::Text text;
	sf::Text text2;
	sf::Text text_repeat;

	sf::Font font;
	if (!font.loadFromFile("AlGER.ttf"))
		std::cout << "not found" << std::endl;

	create_text(text_repeat, text, text2, font);

	sf::ContextSettings setting;
	setting.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(800, 600), "Game of 15", sf::Style::Default, setting);
	create_star(window, stars, count_move, texture_star);
	window.setFramerateLimit(60);

	create_shapes(window, shape, i , j,x_yellow,y_yellow);
	false_cover(boolean);
	while (window.isOpen())
	{
		process_event(window, shape, boolean, i_boolean, j_boolean, x_yellow, y_yellow, num, boolean1, count_move,boolean_theme,sound);
		window.clear();
		if (boolean1)
		{
			count_move = 0;
			i = 3;
			j = 3;
			vector(num, i, j, x_yellow, y_yellow);
			create_shapes(window, shape, i, j, x_yellow, y_yellow);
		}
		for (size_t i = 0; i < 4; i++)
		{
			if (boolean_theme[i] == true)
			{
				window.draw(rect_theme_background[i]);
			}
		}
		drawing_shapes(window, shape, boolean);
		draw_text(window, shape, num, text, out);
		window.draw(text2);
		if (num == base_num)
		{
			window.draw(convex2);
		}
		window.draw(convex3);
		window.draw(circle);
		out1.str("");
		out1.clear();
		out1 << count_move;
		text_repeat.setString(out1.str());
		draw_theme(window,theme);
		window.draw(text_repeat);
		print_stars(window, stars,count_move,texture_star);
		window.display();
	}
	return 0;
}
