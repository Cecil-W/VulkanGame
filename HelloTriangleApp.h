#pragma once


#include <vulkan/vulkan.h>
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <cstring>
#include <cstdlib>


class HelloTriangleApplication {
public:
    void run();

private:
    GLFWwindow* m_window;
    VkInstance m_instance;
    uint32_t m_window_width, m_window_height;
    VkDebugUtilsMessengerEXT m_debugMessenger;


    void initWindow(const int width, const int height);

    void initVulkan();

    void mainLoop();

    void cleanup();

    /// <summary>
    /// creates a vulkan instance
    /// </summary>
    void createInstance();

    bool checkValidationLayerSupport();

    [[nodiscard]]
    std::vector<const char*> getRequiredExtensions();


    void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);

    void setupDebugMessenger();
};

static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(
    VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
    VkDebugUtilsMessageTypeFlagsEXT messageType,
    const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
    void* pUserData);