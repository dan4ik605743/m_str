cmake_minimum_required(VERSION 3.0)

project(
    m_str
    DESCRIPTION "The std::string library is written with constexpr and SSO (Small String Optimization)"
    HOMEPAGE_URL "https://github.com/dan4ik605743/m_str"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(Boost_USE_MULTITHREADED ON)

file(GLOB HEADERS ./m_str/*.hh)

add_library(
    ${PROJECT_NAME} INTERFACE
)

target_include_directories(
    ${PROJECT_NAME} INTERFACE ./
)

target_link_libraries(
    ${PROJECT_NAME} PRIVATE
)

include(GNUInstallDirs)
install(TARGETS ${PROJECT_NAME} LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
install(FILES ${HEADERS} DESTINATION include/${PROJECT_NAME})

if (ENABLE_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()
