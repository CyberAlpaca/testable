
file(GLOB SOURCES "*.cpp")
file(GLOB HEADERS "../include/testable/*.h")

# Create the library
add_library(testable SHARED ${SOURCES} ${HEADERS})

target_include_directories(testable PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/../include
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
