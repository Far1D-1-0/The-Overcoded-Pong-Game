# The Configuration Library Target may be used by all of the other 
# library targets, so it should be added first.
add_subdirectory(Configuration)

# The Utilities library target depends on Configuration and is used
# by other implementation libraries
add_subdirectory(Utilities)

# CameObjects depends on Configuration for global variables definitions 
# and on Utilities for auxiliary methods..
add_subdirectory(GameObjects)

add_library(gameLibs INTERFACE)

target_link_libraries(gameLibs
	INTERFACE
		Configuration
		Utilities
		GameObjects
)

add_subdirectory(Pong)
