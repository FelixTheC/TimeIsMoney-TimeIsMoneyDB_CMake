cmake_minimum_required(VERSION 3.24)

project(TimeIsMoneyDB_CMake VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_PREFIX_PATH "/home/felix/Qt/6.5.0/gcc_64")

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Sql)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Sql)

add_library(TimeIsMoneyDB_CMake
        SHARED
        src/taskdb.cpp
        include/tasks_table.hpp
        include/invoice_table.hpp
        include/externalapi_table.hpp
        include/serial_table.hpp)

target_link_libraries(TimeIsMoneyDB_CMake
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Sql
)

include(GNUInstallDirs)
install(TARGETS TimeIsMoneyDB_CMake
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
