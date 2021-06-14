# org.ayatana.common.gschema.xml

find_package(GSettings)
set(ENV{LC_ALL} "C")
execute_process(COMMAND intltool-merge -quiet --xml-style --utf8 --no-translations "${CMAKE_CURRENT_SOURCE_DIR}/org.ayatana.common.gschema.xml.in" "${CMAKE_CURRENT_BINARY_DIR}/org.ayatana.common.gschema.xml")
add_schema("org.ayatana.common.gschema.xml")
