#ifndef RACKET
#define RACKET

#include <SFML/Graphics.hpp>
#include <Configuration.h>
#include <Utilities.h>
#include <iostream>
#include <cmath>
#include <unordered_map>

class Racket {
public:
	enum class Position {
                LEFT_CENTER,
                RIGHT_CENTER,
		LEFT_TOP,
		LEFT_BOTTOM,
		RIGHT_TOP,
		RIGHT_BOTTOM
        };

	enum class Type {
		LEFT,
		RIGHT
	};

	Racket(Type t);

	void setType(Type t);

	void handleInput(config::control::InputState input);

	void update();

	bool checkCollision(sf::FloatRect other);

	const sf::RectangleShape& getShape() const;

	~Racket() = default;

private:
	sf::Color m_fillColor { sf::Color::Cyan };
	sf::RectangleShape m_shape {
			sf::Vector2f(
				utils::calculations::getPercentagef(1.0f, config::graphics::currentRes.x),
				utils::calculations::getPercentagef(8.0f, config::graphics::currentRes.y)
				)
	};
	std::unordered_map<Position, sf::Vector2f> positions;

	float speed {3};
	float dy {0};
	Type type {Type::LEFT};

	// 0 is TOP 1 is CENTER 2 is BOTTOM
	std::vector<sf::Vector2f> positionsPresets;

	void computePositionsPresets();

protected:
};

#endif
