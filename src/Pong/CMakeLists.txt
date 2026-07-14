add_executable(Pong)

target_sources(Pong
	PRIVATE
		main.cpp
)

target_link_libraries(Pong
  PRIVATE
    SFML::System
    SFML::Graphics
    SFML::Window
    SFML::Network
    SFML::Audio
    gameLibs
)

