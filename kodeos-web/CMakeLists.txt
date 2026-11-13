cmake_minimum_required(VERSION 3.18)
project(kgui_sim C)
include(${CMAKE_CURRENT_LIST_DIR}/../../../sdk/components/kui/sim/CMakeLists.txt)

# First milestone: compile the unmodified original launcher screen.
# Other original screens require firmware services (FreeRTOS/ESP-IDF).
kui_sim_add(kgui_sim
    SOURCES
        ${CMAKE_CURRENT_LIST_DIR}/../../../web-compat/launcher_sim.c
        ${CMAKE_CURRENT_LIST_DIR}/../screens/kgui_screen_launcher.c
    INCLUDES
        ${CMAKE_CURRENT_LIST_DIR}/../screens
        ${CMAKE_CURRENT_LIST_DIR}/..
        ${CMAKE_CURRENT_LIST_DIR}/../include)
if(EMSCRIPTEN)
    set_target_properties(kgui_sim PROPERTIES SUFFIX ".html")
    target_link_options(kgui_sim PRIVATE
        "-sUSE_SDL=2"
        "-sALLOW_MEMORY_GROWTH=1"
        "-sINITIAL_MEMORY=67108864"
        "-sENVIRONMENT=web"
        "-sEXIT_RUNTIME=0")
endif()
