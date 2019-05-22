#pragma once
#include <SFML/Audio.hpp>

void base_vec(std::vector<std::vector<int>>& base_vec);

void vector(std::vector<std::vector<int>>& num, int& i, int& j, int& x_yellow, int& y_yellow);

void move_up(std::vector<std::vector<int>>& vec, int& i, int& j);

void move_down(std::vector<std::vector<int>>& vec, int& i, int& j);

void move_right(std::vector<std::vector<int>>& vec, int& i, int& j);

void move_left(std::vector<std::vector<int>>& vec, int& i, int& j);

void create_shapes(sf::RenderWindow& window, std::vector<std::vector<sf::CircleShape>>& shape,int& i, int& j,int& x_yellow,int& y_yellow);

void set_background(sf::ConvexShape& convex, sf::Texture& texture);

void set_victory_logo(sf::ConvexShape& convex, sf::Texture& texture);

void set_replay_logo(sf::ConvexShape& convex, sf::Texture& texture3);

void draw_text(sf::RenderWindow& window, std::vector<std::vector<sf::CircleShape>>& shape, std::vector<std::vector<int>>& num, sf::Text& text, std::ostringstream& out);

void drawing_shapes(sf::RenderWindow& window, std::vector<std::vector<sf::CircleShape>>& shape, std::vector<std::vector<bool>>& boolean);

void process_event(sf::RenderWindow& window, std::vector<std::vector<sf::CircleShape>>& shape, std::vector<std::vector<bool>>& boolean, int& i_boolean, int& j_boolean, int& x_yellow, int& y_yellow, std::vector<std::vector<int>>& num, bool& boolean1, int& count1, std::vector<bool>& boolean_theme,sf::Sound& sound);
void false_cover(std::vector<std::vector<bool>>& boolean);

void cover(sf::RenderWindow& window, std::vector<std::vector<sf::CircleShape>>& shape, int& x_mouse, int& y_mouse, std::vector<std::vector<bool>>& boolean);

void moving(sf::RenderWindow& window, int& i_boolean, int& j_boolean, std::vector<std::vector<sf::CircleShape>>& shape, int& x_yellow, int& y_yellow, std::vector<std::vector<bool>>& boolean, std::vector<std::vector<int>>& num, int& count,sf::Sound& sound);

void move_keyboard(sf::RenderWindow& window, std::vector<std::vector<sf::CircleShape>>& shape, char a, int& x_yellow, int& y_yellow, std::vector<std::vector<int>>& num, int& count1, sf::Sound& sound);

void realize_boolean(std::vector<std::vector<bool>>& boolean, sf::RenderWindow& window, std::vector<std::vector<sf::CircleShape>>& shape, int& i_boolean, int& j_boolean);

void realize_yellow(sf::RenderWindow& window, std::vector<std::vector<sf::CircleShape>>& shape, int& x_yellow, int& y_yellow);

void moving_help(sf::RenderWindow& window, int& i_boolean, int& j_boolean, std::vector<std::vector<sf::CircleShape>>& shape, int& x_yellow, int& y_yellow, std::vector<std::vector<bool>>& boolean, std::vector<std::vector<int>>& num);

void move_keyboard_help(sf::RenderWindow& window, std::vector<std::vector<sf::CircleShape>>& shape);

void cover_repeat(sf::RenderWindow& window, int& x, int& y, bool& boolean);

void create_theme(std::vector<sf::RectangleShape>& theme);

void draw_theme(sf::RenderWindow& window, std::vector<sf::RectangleShape>& theme);

void bool_cover(std::vector<bool>& boolean, int& x, int& y);

void false_boolean(std::vector<bool>& boolean);

void creating_background(std::vector<sf::RectangleShape>& rect_theme_background);

void create_star(sf::RenderWindow& window, std::vector<sf::RectangleShape>& stars, int& x, sf::Texture& textur);

void print_stars(sf::RenderWindow& window, std::vector<sf::RectangleShape>& stars,int& x,sf::Texture& textur);


void create_text(sf::Text& text1, sf::Text& text2, sf::Text& text3, sf::Font& font);