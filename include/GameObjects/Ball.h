#ifndef BALL
#define BALL

#include <SFML/Graphics.hpp>
#include <Configuration.h>
#include <Utilities.h>
#include <iostream>
#include <cmath>
#include <unordered_map>

class Ball {
public:
	
private:
	sf::Color m_fillColor { sf::Color::Cyan };
	sf::CircleShape m_shape { utils::calculations::getPercentagef(1.5f, config::graphics::currentRes.x) };
protected:
};

#endif
