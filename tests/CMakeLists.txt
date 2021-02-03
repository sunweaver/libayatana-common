find_package(GMock)

include_directories(
    ${CMAKE_SOURCE_DIR}/src
)

add_executable(tst_utils tst_utils.cpp)
target_link_libraries(tst_utils
    ayatana-common

    ${GTEST_LIBRARIES}
    ${GTEST_BOTH_LIBRARIES}
    ${GMOCK_LIBRARIES}
)
add_test(TstUtils tst_utils)
