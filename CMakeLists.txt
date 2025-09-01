cmake_minimum_required(VERSION 3.5.0)
project(Tetris VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 20)

if (CMAKE_SYSTEM_NAME STREQUAL "Emscripten")
    set(EMSCRIPTEN TRUE)
endif()

if (EMSCRIPTEN)
    message(STATUS "Building for Web (Emscripten)")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -s USE_GLFW=3 -s ASSERTIONS=1 -s WASM=1 -s ASYNCIFY -s GL_ENABLE_GET_PROC_ADDRESS=1")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -s USE_GLFW=3 -s ASSERTIONS=1 -s WASM=1 -s ASYNCIFY -s GL_ENABLE_GET_PROC_ADDRESS=1")
    set(CMAKE_EXECUTABLE_SUFFIX ".html")
    add_definitions(-DPLATFORM_WEB)
else()
    message(STATUS "Building for Desktop")
    set(RC_FILE "${CMAKE_CURRENT_SOURCE_DIR}/app_icon.rc")
endif()

add_subdirectory(vendor/raylib-master)

file(GLOB SOURCES "src/*.cpp" "src/blocks/*.cpp")
source_group("Source Files" FILES ${SOURCES})

if (EMSCRIPTEN)
    add_executable(${PROJECT_NAME} ${SOURCES})
else()
    add_executable(${PROJECT_NAME} WIN32 ${SOURCES} ${RC_FILE})
endif()

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 20)

target_link_libraries(${PROJECT_NAME} PRIVATE raylib)

target_include_directories(${PROJECT_NAME} PRIVATE
    src
    src/blocks
    vendor/raylib-master/src
)

if (EMSCRIPTEN)
    set_target_properties(${PROJECT_NAME} PROPERTIES
        LINK_FLAGS "-s USE_GLFW=3 -s ASSERTIONS=1 -s WASM=1 -s ASYNCIFY -s GL_ENABLE_GET_PROC_ADDRESS=1 --shell-file ${CMAKE_CURRENT_SOURCE_DIR}/vendor/raylib-master/src/minshell.html --preload-file ${CMAKE_CURRENT_SOURCE_DIR}/assets@assets/"
    )
else()
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${CMAKE_CURRENT_SOURCE_DIR}/assets
            $<TARGET_FILE_DIR:${PROJECT_NAME}>/assets
        COMMENT "Copy assets folder to executable file directory"
    )
endif()