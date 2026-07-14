#include <SFML/Graphics.hpp>
#include <Configuration.h>
#include <Utilities.h>
#include <GameObjects/Racket.h>
#include <iostream>
#include <cmath>

using namespace sf;
using namespace config::graphics;

VertexArray generate_midline();

int main() {
	
	RenderWindow window(sf::VideoMode(currentRes), "OverCoded Pong Game", Style::Default);

	window.setFramerateLimit(60);

	auto midline = generate_midline();
	Racket racket(Racket::Type::LEFT); 
	Racket racket2(Racket::Type::RIGHT);

	while(window.isOpen()) {

		while(const std::optional event = window.pollEvent()){
			if(event->is<Event::Closed>()) window.close();
		}

		config::control::InputState input = utils::control::readInput();

		racket.handleInput(input);
		racket2.handleInput(input);
		racket.update();
		racket2.update();

		window.clear();
		window.draw(midline);
		window.draw(racket.getShape());
		window.draw(racket2.getShape());
		window.display();
	}

	return 0;
}

VertexArray generate_midline() {
	float line_intervals = 22.f;
	float mid = currentRes.x/2.f;
	float rect_w = currentRes.x/150.f;
	float rect_h = currentRes.y/line_intervals;
	int num_lines = static_cast<int>(line_intervals/2);
	RectangleShape line;
	line.setSize(Vector2f(rect_w, rect_h));
	line.setFillColor(Color::White);
	line.setOrigin(Vector2f(rect_w/2, 0));
	line.setPosition({mid, 0});

	const Color color = line.getFillColor();
	const Transform& transform = line.getTransform();
	Transform mod = transform;
	mod.translate(Vector2f(0, rect_h/2));

	VertexArray lines(PrimitiveType::Triangles, num_lines * 6);

	for(int i = 0; i < num_lines; i++) {
		int prefix = 6 * i;
		lines[prefix] = {mod.transformPoint(line.getPoint(0)), color};
		lines[prefix + 1] = {mod.transformPoint(line.getPoint(1)), color};
		lines[prefix + 2] = {mod.transformPoint(line.getPoint(2)), color};
		lines[prefix + 3] = {mod.transformPoint(line.getPoint(0)), color};
		lines[prefix + 4] = {mod.transformPoint(line.getPoint(2)), color};
		lines[prefix + 5] = {mod.transformPoint(line.getPoint(3)), color};

		mod.translate(Vector2f(0, rect_h * 2));
	}

	return lines;
}

