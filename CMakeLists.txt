cmake_minimum_required(VERSION 3.10)

# Set the project name to AUCTION-SYSTEM
project(AUCTION-SYSTEM)

# Enable C++17 (or change if using another version)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Specify the source files
file(GLOB_RECURSE SOURCES
    main.cpp
    application/*.cpp
    controllers/*.cpp
    models/*.cpp
    utils/*.cpp
    views/*.cpp
)

# Add the executable target
add_executable(AUCTION-SYSTEM ${SOURCES})

# Include directories for headers (if needed)
# include_directories(${CMAKE_SOURCE_DIR}/include)

# Optionally, if you have external libraries, you can link them here
# target_link_libraries(AUCTION-SYSTEM <library_name>)
