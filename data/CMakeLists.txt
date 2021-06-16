# org.ayatana.common.gschema.xml

find_package(GSettings)
set(ENV{LC_ALL} "C")
execute_process(COMMAND intltool-merge -quiet --xml-style --utf8 --no-translations "${CMAKE_CURRENT_SOURCE_DIR}/org.ayatana.common.gschema.xml.in" "${CMAKE_CURRENT_BINARY_DIR}/org.ayatana.common.gschema.xml")
add_schema("org.ayatana.common.gschema.xml")

# ayatana-indicators.target

pkg_check_modules(SYSTEMD systemd)

if (${SYSTEMD_FOUND})
    if (${SYSTEMD_VERSION} VERSION_LESS 247)
        set(SYSTEMD_USER_UNIT_DIR "${CMAKE_INSTALL_FULL_LIBDIR}/systemd/user")
    else()
        pkg_get_variable(SYSTEMD_USER_UNIT_DIR systemd systemd_user_unit_dir)
    endif()
    install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/ayatana-indicators.target" DESTINATION "${SYSTEMD_USER_UNIT_DIR}")
endif()
