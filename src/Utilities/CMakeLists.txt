add_library(Utilities)

target_sources(Utilities
	PRIVATE
		Calculations.cpp
		Control.cpp
	
	PUBLIC
		FILE_SET utils
		TYPE HEADERS
		BASE_DIRS
			${PONG_LIBS_HEADER_BASE_DIRS}
		FILES
			${PONG_LIBS_HEADER_BASE_DIRS}/Utilities.h
			${PONG_LIBS_HEADER_BASE_DIRS}/Utilities/Calculations.h
			${PONG_LIBS_HEADER_BASE_DIRS}/Utilities/Control.h

)

target_link_libraries(Utilities
	PUBLIC
		SFML::Graphics
		SFML::Window
		Configuration

)
