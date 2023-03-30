#pragma once

#include <stdio.h>
#include <GLFW/glfw3.h>
#include <utils/DesktopUtils.cpp>
#include <CustomException.cpp>

class Window {

    public:
        static GLFWwindow* init(){
            GLFWwindow* window;

            /* Initialize the library */
            if (!glfwInit())
            {
                throw CustomException("GLFW failed initialize");
            }

            /* Create a windowed mode window and its OpenGL context */
            //FIXME harcoded.
            int horizontal, vertical;
            DesktopUtils::GetDesktopResolution(horizontal, vertical);
            window = glfwCreateWindow(horizontal, vertical, "Engine Di Federico", NULL, NULL);
    
            if (!window)
            {
                throw CustomException("GLFW failed initialize window");
            }

            /* Make the window's context current */
            glfwMakeContextCurrent(window);

            return window;
        }
    
    private:
        static Window window;

};