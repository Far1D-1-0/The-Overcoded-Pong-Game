#include <Utilities/Control.h>

namespace utils::control {

	config::control::InputState readInput() {

		config::control::InputState input;

		input.moveUp = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W);
		input.moveDown = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S);

		return input;
	}
}
