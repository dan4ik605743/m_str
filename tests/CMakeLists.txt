find_package (Boost 1.74.0 REQUIRED COMPONENTS unit_test_framework REQUIRED)

enable_testing()

include_directories(
    ../m_str
    ${Boost_INCLUDE_DIR}
)

file(GLOB SOURCES ./*.cxx)

add_executable(
    ${PROJECT_NAME}_test
    ${SOURCES}
)

target_link_libraries(
    ${PROJECT_NAME}_test
    ${Boost_LIBRARIES} 
)

add_test(${PROJECT_NAME}_test ${PROJECT_NAME}_test)