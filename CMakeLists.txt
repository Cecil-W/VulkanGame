cmake_minimum_required(VERSION 3.30)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_SCAN_FOR_MODULES true)


project(MiniGame LANGUAGES CXX)


# https://github.com/KhronosGroup/Vulkan-Hpp?tab=readme-ov-file#usage-with-cmake
find_package(Vulkan REQUIRED)
find_package(glfw3 REQUIRED)

add_executable(Game)

target_link_libraries(Game glfw)
target_link_libraries(Game Vulkan::Vulkan)

target_include_directories(Game PUBLIC 
    imgui
    imgui/backends)

file(GLOB ImGui_SRC
    "imgui/*.cpp"
    "imgui/*.h"
    "imgui/backends/imgui_impl_vulkan.*"
    "imgui/backends/imgui_impl_glfw.*"
)

target_sources(Game PRIVATE
    FILE_SET CXX_MODULES
    FILES 
        Renderer.ixx)

target_sources(Game
    PUBLIC
        VulkanGame.cpp
        ${ImGui_SRC}
        stb_image.h
        tiny_obj_loader.h)
