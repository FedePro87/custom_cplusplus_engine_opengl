// Dear ImGui
#include <DearImGui/imgui.h>
#include <DearImGui/imgui_impl_glfw.h>
#include <DearImGui/imgui_impl_opengl3.h>

//GLFW
#include <GLFW/glfw3.h>

#include <CustomException.cpp>

class ImGuiHelper{

    public:

        static void init(GLFWwindow* window){
            // Setup Dear ImGui context
            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
            IMGUI_CHECKVERSION();
            ImGui::CreateContext();
            ImGuiIO &io = ImGui::GetIO();
            
            // Setup Dear ImGui style
            ImGui::StyleColorsDark();

            // Setup Platform/Renderer bindings and ensure they work
            if (!ImGui_ImplGlfw_InitForOpenGL(window, true)) {
                throw CustomException("Failed integration with ImGui and GLFW");
            }

            if (!ImGui_ImplOpenGL3_Init()) {
                throw CustomException("Failed integration with ImGui and Opengl3");
            }
        }

        static void renderMainFrame(GLFWwindow* window){
            ImGuiHelper::composeDearImGuiFrame(window);
            ImGui::Render();
            ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        }

        static void composeDearImGuiFrame(GLFWwindow* window){
            ImGui_ImplOpenGL3_NewFrame();
            ImGui_ImplGlfw_NewFrame();

            ImGui::NewFrame();

            // standard demo window
            bool show_demo_window = false;
            ImGui::ShowDemoWindow(&show_demo_window);
    }

};