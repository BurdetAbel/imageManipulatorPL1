# cmake needs this line
cmake_minimum_required(VERSION 3.29)
project(imageManipulatorPL1)

set(CMAKE_CXX_STANDARD 23)
set(ENV{OPENCV_DIR} "c:/tools/opencv/build")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR} c:/tools/opencv/sources/cmake")


find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS} "c:/tools/opencv/build/include/")

add_executable(imageManipulatorPL1 main.cpp
        menu.cpp
        menu.h
        pila.cpp
        pila.h
        filtros.cpp
        filtros.h
        colas.cpp
        colas.h
        listas.cpp
        listas.h
        nodoPilas.cpp
        nodoPilas.h
        nodoListas.cpp
        nodoListas.h
        nodoColas.cpp
        nodoColas.h
        funciones.cpp
        funciones.h
        funciones.h)

set(OpenCV_LIBS opencv_core opencv_imgproc opencv_highgui opencv_imgcodecs)

target_link_libraries(imageManipulatorPL1 ${OpenCV_LIBS})



