cmake_minimum_required(VERSION "3.7.1")
SET(CMAKE_C_COMPILER C:/MinGW/bin/gcc.exe)

project("ObserverWithBoost")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

include_directories("D:\\ThirdParty\\boost_1_72_0\\")

add_executable(ObserverWithBoost ObserverWithBoost.cpp)
if(MSVC)
        set_target_properties(ObserverWithBoost PROPERTIES
                LIBRARY_OUTPUT_DIRECTORY            ${PROJECT_SOURCE_DIR}
                LIBRARY_OUTPUT_DIRECTORY_DEBUG      ${PROJECT_SOURCE_DIR}
                LIBRARY_OUTPUT_DIRECTORY_RELEASE    ${PROJECT_SOURCE_DIR}
                RUNTIME_OUTPUT_DIRECTORY            ${PROJECT_SOURCE_DIR}
                RUNTIME_OUTPUT_DIRECTORY_DEBUG      ${PROJECT_SOURCE_DIR}
                RUNTIME_OUTPUT_DIRECTORY_RELEASE    ${PROJECT_SOURCE_DIR}
                ARCHIVE_OUTPUT_DIRECTORY            ${PROJECT_SOURCE_DIR}
                ARCHIVE_OUTPUT_DIRECTORY_DEBUG      ${PROJECT_SOURCE_DIR}
                ARCHIVE_OUTPUT_DIRECTORY_RELEASE    ${PROJECT_SOURCE_DIR}
        )
endif()
