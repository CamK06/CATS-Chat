cmake_minimum_required(VERSION 3.5)
project(CATS-Chat)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

file(GLOB SOURCES src/main.cpp
                  src/mainwindow.cpp
                  src/radiodialog.cpp
                  src/messagedialog.cpp
                  src/stationdialog.cpp)

find_package(QT NAMES Qt6 COMPONENTS Widgets REQUIRED)
find_package(Qt6 COMPONENTS Widgets REQUIRED)

if(EXISTS "${CMAKE_SOURCE_DIR}/.git")
  execute_process(
    COMMAND git log -1 --format=%h
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    OUTPUT_VARIABLE GIT_COMMIT
    OUTPUT_STRIP_TRAILING_WHITESPACE
  )
else()
  set(GIT_COMMIT "unknown")
endif()
add_definitions("-DGIT_COMMIT=\"${GIT_COMMIT}\"")

add_executable(cats-chat ${SOURCES})
target_link_libraries(cats-chat Qt6::Widgets)