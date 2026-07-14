# The Ovecroded Pong Game uses SFML library version 3.1.0. It is recomended to build SFML from source
TODO: Create a source build manual.

Download source code for SFML version 3.1.0  https://github.com/sfml/sfml

extract the contents here under SFML-3.1.0

Replace the current sources/SFML-3.1.0/CMakePresets.json file with the one provided in sources/custom/CmakePresets.json

See sources/SFML-3.1.0/cmake/SFMLConfig.cmake.in for more information on the usage of the SFML modules, Static/Dynamic Libraries etc.

Run:\
cmake --preset dev --config Release\
cmake --preset dev --config Debug\
cmake --preset dev-static --config Release\
cmake --preset dev-static --config Debug\
cmake --install build

This will build all the SFML library binaries and install them to libraries/external/SFML/

If the directories are not automatically created or you get an error regarding them, create them manually
