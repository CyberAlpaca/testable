cmake_minimum_required(VERSION 3.16)
project(testable LANGUAGES CXX)

set(CMAKE_PREFIX_PATH "C:/Qt/6.6.2/msvc2019_64")
set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Qml Xml Quick QuickTest Test)

# Add subdirectories (process another CMakeLists.txt file located in a subdirectory)
add_subdirectory(src)

# Include directories
include_directories(include)

set_target_properties(testable PROPERTIES
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE TRUE
)

target_link_libraries(testable PUBLIC
    Qt6::Core
    Qt6::Gui
    Qt6::Qml
    Qt6::Xml
    Qt6::Quick
    Qt6::QuickTest
    Qt6::Test
)
