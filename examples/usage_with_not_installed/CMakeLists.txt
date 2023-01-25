cmake_minimum_required(VERSION 3.0)

project(example_usage_witn_not_installed)
add_subdirectory(modules)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(
    ${PROJECT_NAME} 
    main.cxx
)

target_link_libraries(
    ${PROJECT_NAME} 
    PRIVATE m_str
)

include(GNUInstallDirs)
install(
    TARGETS ${PROJECT_NAME}        
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)