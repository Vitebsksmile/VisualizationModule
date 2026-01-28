cmake_minimum_required(VERSION 3.19)
project(VisualizationModule LANGUAGES CXX)

set (CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Qt6 6.5 REQUIRED COMPONENTS Quick)

#target_sources(VisualizationModule
#  PRIVATE
#    main.qml
#)

qt_standard_project_setup()

qt_add_executable(VisualizationModule
    main.cpp
)

qt_policy(SET QTP0001 NEW)  #   Новый путь (qrc:/qt/qml/)
qt_add_qml_module(VisualizationModule
    URI path   #    ссылка, по к-рой будут загружаться файлы qml
    VERSION 2.15
    QML_FILES
        main.qml
)

target_link_libraries(VisualizationModule
    PRIVATE
        Qt::Quick
)

include(GNUInstallDirs)

install(TARGETS VisualizationModule
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
