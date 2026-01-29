cmake_minimum_required(VERSION 3.19)
project(VisualizationModule LANGUAGES CXX)

set (CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Gui Widgets )
find_package(OpenCV REQUIRED)

qt_standard_project_setup()

qt_add_executable(VisualizationModule
    main.cpp
    mainwindow.h mainwindow.cpp
    imageviewer.h imageviewer.cpp
)



target_link_libraries(VisualizationModule
    PRIVATE
        Qt6::Core
        Qt6::Gui
        Qt6::Widgets
        ${OpenCV_LIBS}
)

include(GNUInstallDirs)

install(TARGETS VisualizationModule
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
