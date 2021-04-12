
add_library(ayatana-common SHARED
    utils.c
)

target_link_libraries(ayatana-common
    ${GLIB_LIBRARIES}
    ${URLDISPATCHER_LIBRARIES}
)

if(URLDISPATCHER_FOUND)
    add_definitions( -DHAS_URLDISPATCHER )
endif()

set(PUBLIC_HEADERS
    utils.h
)

set_target_properties(ayatana-common
    PROPERTIES
    VERSION ${API_VERSION}.0.0
    SOVERSION ${ABI_VERSION}
)

configure_file(libayatana-common.pc.in ${CMAKE_CURRENT_BINARY_DIR}/libayatana-common.pc @ONLY)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/libayatana-common.pc DESTINATION ${CMAKE_INSTALL_LIBDIR}/pkgconfig)
install(FILES ${PUBLIC_HEADERS} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/ayatana/common)
install(TARGETS ayatana-common DESTINATION ${CMAKE_INSTALL_LIBDIR})
