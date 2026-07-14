add_library(Configuration INTERFACE)

target_sources(Configuration
	INTERFACE
		FILE_SET config
		TYPE HEADERS
		BASE_DIRS 
			${PONG_LIBS_HEADER_BASE_DIRS}
		FILES
			${PONG_LIBS_HEADER_BASE_DIRS}/Configuration.h
			${PONG_LIBS_HEADER_BASE_DIRS}/Configuration/Graphics.h
			${PONG_LIBS_HEADER_BASE_DIRS}/Configuration/Control.h
)

target_link_libraries(Configuration
	INTERFACE
		SFML::Graphics
)
