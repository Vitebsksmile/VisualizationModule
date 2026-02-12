cmake_minimum_required(VERSION 3.19)
project(VisualizationModule VERSION 0.1 LANGUAGES CXX)

set (CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Qt6 6.5 REQUIRED COMPONENTS Gui Qml QuickControls2 )
#find_package(OpenCV REQUIRED)

qt_standard_project_setup()

qt_add_executable(VisualizationModule
    main.cpp
)

qt_policy(SET QTP0001 NEW)  #   Новый путь (qrc:/qt/qml/)
qt_add_qml_module(VisualizationModule
    URI path
    VERSION 1.0
    QML_FILES
        main.qml
        ImageView.qml
        ButtonSideBar.qml
        VideoViewer.qml
    SOURCES
        filehandler.h filehandler.cpp
)

target_link_libraries(VisualizationModule
    PRIVATE
        Qt6::Gui
        Qt6::Qml
        Qt6::QuickControls2
        #${OpenCV_LIBS}
)

include(GNUInstallDirs)

install(TARGETS VisualizationModule
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
