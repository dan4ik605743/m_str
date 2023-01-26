file(GLOB HEADERS *.hh)

add_library(
    ${PROJECT_NAME} INTERFACE
)

target_include_directories(
    ${PROJECT_NAME} INTERFACE ../
)

target_link_libraries(
    ${PROJECT_NAME} PRIVATE
)

include(GNUInstallDirs)
install(TARGETS ${PROJECT_NAME} LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
install(FILES ${HEADERS} DESTINATION include/${PROJECT_NAME})