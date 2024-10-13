cmake_minimum_required(VERSION 3.10)
set(PROJECT_NAME connie)
project(${PROJECT_NAME} VERSION 1.0)

# C++ Standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(OpenGL REQUIRED)
add_subdirectory(deps/glfw)
add_subdirectory(deps/json)

# external stuff
set(IMGUI_SOURCE_DIR ${CMAKE_SOURCE_DIR}/deps/imgui)
set(IMGUI_BACKENDS_DIR ${IMGUI_SOURCE_DIR}/backends)
set(IMPLOT_SOURCE_DIR ${CMAKE_SOURCE_DIR}/deps/implot)
set(JSON_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/deps/json/include)

# project stuff
file(GLOB_RECURSE HEADER include/*.h)
file(GLOB_RECURSE SOURCE src/*.cpp)

set(SOURCE_FILES
	${SOURCE}
	${IMGUI_SOURCE_DIR}/imgui_demo.cpp
	${IMGUI_SOURCE_DIR}/imgui_draw.cpp
	${IMGUI_SOURCE_DIR}/imgui_tables.cpp
	${IMGUI_SOURCE_DIR}/imgui_widgets.cpp
	${IMGUI_SOURCE_DIR}/imgui.cpp
	${IMGUI_BACKENDS_DIR}/imgui_impl_glfw.cpp
	${IMGUI_BACKENDS_DIR}/imgui_impl_opengl3.cpp
	${IMPLOT_SOURCE_DIR}/implot_demo.cpp
	${IMPLOT_SOURCE_DIR}/implot_items.cpp
	${IMPLOT_SOURCE_DIR}/implot.cpp
)

# Add executable
add_executable(${PROJECT_NAME} ${HEADAER} ${SOURCE_FILES})

target_include_directories(${PROJECT_NAME} PRIVATE
	${IMGUI_SOURCE_DIR}
	${IMGUI_BACKENDS_DIR}
	${IMPLOT_SOURCE_DIR}
	${JSON_INCLUDE_DIR}
)

# Link libraries
target_link_libraries(${PROJECT_NAME} PRIVATE
	OpenGL::GL
	glfw
	nlohmann_json::nlohmann_json
)