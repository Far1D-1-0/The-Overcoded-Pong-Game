#ifndef GRAPHICSCONFIG
#define GRAPHICSCONFIG

#include <SFML/Graphics.hpp>
#include <unordered_map>

namespace config::graphics {
	enum class VideoMode {
		HD,
		FHD
	};

	inline std::unordered_map<VideoMode, sf::Vector2u> resolutions = 
	{

		{VideoMode::HD, sf::Vector2u(1280u, 720u)},
		{VideoMode::FHD, sf::Vector2u(1920u, 1080u)}
	};

	constexpr VideoMode currentMode = config::graphics::VideoMode::FHD;

	inline sf::Vector2u currentRes = config::graphics::resolutions[currentMode];
}

#endif
