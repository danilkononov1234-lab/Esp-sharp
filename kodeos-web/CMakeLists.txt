cmake_minimum_required(VERSION 3.18)
project(kgui_sim C)
include(${CMAKE_CURRENT_LIST_DIR}/../../../sdk/components/kui/sim/CMakeLists.txt)
# The SDK's firmware components export their headers through ESP-IDF;
# desktop CMake needs explicit include paths instead.
set(KODE_SDK_ROOT ${CMAKE_CURRENT_LIST_DIR}/../../../sdk/components)
file(GLOB_RECURSE KODE_SDK_HEADERS LIST_DIRECTORIES false "${KODE_SDK_ROOT}/*.h")
set(KODE_SDK_INCLUDE_DIRS "")
foreach(_header IN LISTS KODE_SDK_HEADERS)
    get_filename_component(_dir "${_header}" DIRECTORY)
    list(APPEND KODE_SDK_INCLUDE_DIRS "${_dir}")
endforeach()
list(REMOVE_DUPLICATES KODE_SDK_INCLUDE_DIRS)
file(GLOB KGUI_SCREENS ${CMAKE_CURRENT_LIST_DIR}/../screens/*.c)
kui_sim_add(kgui_sim SOURCES ${CMAKE_CURRENT_LIST_DIR}/kgui_sim.c ${KGUI_SCREENS}
                     INCLUDES ${CMAKE_CURRENT_LIST_DIR}/../screens
                              ${CMAKE_CURRENT_LIST_DIR}/..
                              ${CMAKE_CURRENT_LIST_DIR}/../include
                              ${KODE_SDK_INCLUDE_DIRS}
                              ${CMAKE_CURRENT_LIST_DIR}/../../../web-compat)
if(EMSCRIPTEN)
    set_target_properties(kgui_sim PROPERTIES SUFFIX ".html")
    target_link_options(kgui_sim PRIVATE
        "-sUSE_SDL=2"
        "-sALLOW_MEMORY_GROWTH=1"
        "-sINITIAL_MEMORY=67108864"
        "-sENVIRONMENT=web"
        "-sEXIT_RUNTIME=0")
endif()
