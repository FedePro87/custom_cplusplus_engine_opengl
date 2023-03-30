const char* fragment_source = R"(
#version 330 core
out vec4 FragColor;

in vec4 vertexColor; // the input variable from the vertex shader (same name and same type)

uniform vec4 ourColor; // we set this variable in the OpenGL code.
        
void main()
{
   FragColor = ourColor;
}

)";
        
void update_color()
{
    // update the uniform color every fotogram
    float timeValue = glfwGetTime();
    float greenValue = std::sin(timeValue) / 2.0f + 0.5f;
    int vertexColorLocation = glGetUniformLocation(this->render_mapping.shader_program, "ourColor");
    glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);
}