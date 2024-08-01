cmake_minimum_required(VERSION 3.16)
project(testable LANGUAGES CXX)

set(CMAKE_PREFIX_PATH "C:/Qt/6.6.2/msvc2019_64/bin")

set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Qml Xml Quick QuickTest Test)

add_library(testable SHARED
    testablefunctions.cpp testablefunctions.h
    testrunner.cpp testrunner.h
    priv/testableutils.cpp priv/testableutils.h
    automator.cpp automator.h
    priv/testrunnerwrapper.cpp priv/testrunnerwrapper.h
    priv/objectutils.cpp priv/objectutils.h
)

target_include_directories(testable PRIVATE
	${CMAKE_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/priv
)

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

