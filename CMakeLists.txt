project (libayatana-common C CXX)
cmake_minimum_required(VERSION 3.16)

set(PROJECT_VERSION "0.9.1")
set(PACKAGE ${CMAKE_PROJECT_NAME})

set(API_VERSION 0)
set(ABI_VERSION 0)

# Options
option (ENABLE_TESTS "Build the package's automatic tests." OFF)
option (ENABLE_COVERAGE "Generate lcov code coverage reports." OFF)

if(ENABLE_COVERAGE)
    set(ENABLE_TESTS ON)
    set(CMAKE_BUILD_TYPE "Coverage")
else()
    set(CMAKE_BUILD_TYPE "Release")
endif()


# GNU standard installation directories
include (GNUInstallDirs)
set (CMAKE_INSTALL_PKGLIBEXECDIR "${CMAKE_INSTALL_LIBEXECDIR}/${CMAKE_PROJECT_NAME}")
set (CMAKE_INSTALL_FULL_PKGLIBEXECDIR "${CMAKE_INSTALL_FULL_LIBEXECDIR}/${CMAKE_PROJECT_NAME}")

# Check for prerequisites
find_package (PkgConfig REQUIRED)
include (FindPkgConfig)

pkg_check_modules(GLIB REQUIRED
    glib-2.0>=2.36
)
include_directories (${GLIB_INCLUDE_DIRS})

pkg_check_modules(
  URLDISPATCHER
  lomiri-url-dispatcher>=0
)
include_directories(${URLDISPATCHER_INCLUDE_DIRS})

set(CC_WARNING_ARGS " -Wall -pedantic -Wextra -Wno-missing-field-initializers")

add_subdirectory(src)

if (ENABLE_TESTS)
    include(CTest)
    enable_testing()
    add_subdirectory(tests)
else()
    message(STATUS "Tests disabled")
endif()
