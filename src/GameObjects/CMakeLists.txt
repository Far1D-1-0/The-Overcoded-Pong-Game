add_library(GameObjects)

target_sources(GameObjects
	PRIVATE
		Racket.cpp
	
	PUBLIC
		FILE_SET objects
		TYPE HEADERS
		BASE_DIRS 
			${PONG_LIBS_HEADER_BASE_DIRS}
		FILES
			${PONG_LIBS_HEADER_BASE_DIRS}/GameObjects.h
			${PONG_LIBS_HEADER_BASE_DIRS}/GameObjects/Racket.h	
)

target_link_libraries(GameObjects
	PUBLIC
		SFML::Graphics
		Configuration
		Utilities
)
