cmake_minimum_required(VERSION 3.19)
project(VisualizationModule LANGUAGES CXX)

set (CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Qt6 6.5 REQUIRED COMPONENTS Quick Gui Widgets )
find_package(OpenCV REQUIRED)

qt_standard_project_setup()

qt_add_executable(VisualizationModule
    main.cpp
    mainwindow.h mainwindow.cpp
    imageviewer.h imageviewer.cpp
    visualiser.h visualiser.cpp
    #mymodel.h mymodel.cpp
    mydelegate.h mydelegate.cpp
    #myview.h myview.cpp
    main.qml
)

qt_policy(SET QTP0001 NEW)  #   Новый путь (qrc:/qt/qml/)
qt_add_qml_module(VisualizationModule
    URI path
    QML_FILES main.qml
    SOURCES mymodel.h mymodel.cpp
)

target_link_libraries(VisualizationModule
    PRIVATE
        Qt6::Quick
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
