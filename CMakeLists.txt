project (libayatana-common C CXX)
cmake_minimum_required(VERSION 3.16)

set(PROJECT_VERSION "0.8.1")
set(PACKAGE ${CMAKE_PROJECT_NAME})

set(API_VERSION 0)
set(ABI_VERSION 0)

# Options
option(DISABLE_TESTS "Disable tests" off)

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

if (DISABLE_TESTS)
    message(STATUS "Tests disabled")
else()
    include(CTest)
    enable_testing()
    add_subdirectory(tests)
endif()
