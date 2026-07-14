#include <GameObjects/Racket.h>

Racket::Racket(Type t) : positionsPresets(3, sf::Vector2f(0, 0)) {
	m_shape.setFillColor(m_fillColor);
	m_shape.setOrigin(
			sf::Vector2f(
				utils::calculations::getPercentagef(50.0f, m_shape.getSize().x), 
				utils::calculations::getPercentagef(50.0f, m_shape.getSize().y)
				)
			);
	// positions could be computed even before the constructor TODO: Make positions a static atribute for optimization
	positions = {
                {
                        Position::LEFT_CENTER,
                        sf::Vector2f    (
                                        m_shape.getOrigin().x + utils::calculations::getPercentagef(0.5f, config::graphics::currentRes.x),
                                        utils::calculations::getPercentagef(50.0f, config::graphics::currentRes.y)
                                        )
                },
                {
                        Position::RIGHT_CENTER,
                        sf::Vector2f    (
                                        config::graphics::currentRes.x -
                                        (m_shape.getOrigin().x + utils::calculations::getPercentagef(0.5f, config::graphics::currentRes.x)),
                                        utils::calculations::getPercentagef(50.0f, config::graphics::currentRes.y)
                                        )
                },
                {
                        Position::LEFT_TOP,
                        sf::Vector2f    (
                                        m_shape.getOrigin().x + utils::calculations::getPercentagef(0.5f, config::graphics::currentRes.x),
                                        m_shape.getOrigin().y
                                        )
                },
                {
                        Position::LEFT_BOTTOM,
                        sf::Vector2f    (
                                        m_shape.getOrigin().x + utils::calculations::getPercentagef(0.5f, config::graphics::currentRes.x),
                                        config::graphics::currentRes.y - m_shape.getOrigin().y
                                        )
                },
                {
                        Position::RIGHT_TOP,
                        sf::Vector2f    (
                                        config::graphics::currentRes.x -
                                        (m_shape.getOrigin().x + utils::calculations::getPercentagef(0.5f, config::graphics::currentRes.x)),
                                        m_shape.getOrigin().y
                                        )
                },
                {
                        Position::RIGHT_BOTTOM,
                        sf::Vector2f    (
                                        config::graphics::currentRes.x -
                                        (m_shape.getOrigin().x + utils::calculations::getPercentagef(0.5f, config::graphics::currentRes.x)),
                                        config::graphics::currentRes.y - m_shape.getOrigin().y
                                        )
                }
        };

	setType(t);

	m_shape.setPosition(positionsPresets[1]);

	
}

void Racket::setType(Type t) { 
	type = t; 
	computePositionsPresets();
}

void Racket::handleInput(config::control::InputState input) {

	if (input.moveUp) dy = -speed;
	if (input.moveDown) dy = speed;

	if (!input.moveUp && !input.moveDown) dy = 0;
	
}

void Racket::update() {

	m_shape.move(sf::Vector2f(0, dy * speed));

	// Position restriction TODO: Convert it to method
	if ((m_shape.getPosition().y - m_shape.getOrigin().y) <= 0.0f) 
		m_shape.setPosition(positionsPresets[0]);
	if ((m_shape.getPosition().y + m_shape.getOrigin().y) >= static_cast<float>(config::graphics::currentRes.y)) 
		m_shape.setPosition(positionsPresets[2]);
}

bool Racket::checkCollision(sf::FloatRect other) {
	if(m_shape.getGlobalBounds().findIntersection(other)) return true;
	else return false;
}

const sf::RectangleShape& Racket::getShape() const {
	return m_shape;
}

void Racket::computePositionsPresets() {

	if (type == Type::LEFT) {
	
		positionsPresets[0] = positions[Position::LEFT_TOP];
		positionsPresets[1] = positions[Position::LEFT_CENTER];
		positionsPresets[2] = positions[Position::LEFT_BOTTOM];
		
	} else if (type == Type::RIGHT) {
		positionsPresets[0] = positions[Position::RIGHT_TOP];
		positionsPresets[1] = positions[Position::RIGHT_CENTER];
		positionsPresets[2] = positions[Position::RIGHT_BOTTOM];
	}


}
