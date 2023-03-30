#include <Grid.cpp>
#include <Window.cpp>
#include <CustomException.cpp>
#include <ImGuiHelper.cpp>

// Dear ImGui
#include <DearImGui/imgui.h>
#include <DearImGui/imgui_impl_glfw.h>
#include <DearImGui/imgui_impl_opengl3.h>

//GLFW
#include<glad/glad.h>
#include <GLFW/glfw3.h>

void cleanup(GLFWwindow* window, Grid grid){
    grid.cleanup();

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();
}

int main(void)
{
    GLFWwindow* window;

    //Ensure GLFW, window, glad and ImGui init
    try
    {
        window = Window::init();
        ImGuiHelper::init(window);
        gladLoadGL();
        glViewport(0, 0, 1920, 1080);
    }
    catch (CustomException e)
    {
        std::cout << e.what() << std::endl;
        return -1;
    }

    Grid grid;

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        // Dear ImGui frame
        //ImGuiHelper::renderMainFrame(window);

        //Render Grid
        grid.render();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    cleanup(window, grid);
    
    return 0;
}