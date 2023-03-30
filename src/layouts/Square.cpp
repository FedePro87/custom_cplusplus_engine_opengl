#include<glad/glad.h>

#include<string>

class Square
{
    private :

        const char* vertex_source = R"(
        #version 330 core
        layout (location = 0) in vec3 pos;
        
        // specify a color output to the fragment shader
        out vec4 vertexColor;
        
        // Controls the scale of the vertices
        uniform float scale;

        void main()
        {
            //gl_Position = vec4(pos, 1.0);
            gl_Position = vec4(pos, 1.0);
            vertexColor = vec4(0.5, 0.0, 0.0, 1.0); // set the output variable to a dark-red color
        }

        )";

        const char* fragment_source = R"(
        #version 330 core
        out vec4 FragColor;

        in vec4 vertexColor; // the input variable from the vertex shader (same name and same type)

        void main()
        {
           FragColor = vertexColor;
        }

        )";

        struct {
			GLuint vao;
			GLuint vbo;
			GLuint ebo;
			GLuint shader_program;
		} render_mapping;

        static const int vertices_number = 12;
        static const int indices_number = 4;
        float scale;

    public :

        Square(float scale)
        {
            // GLfloat vertices[] = {
            //     -0.25f, 0.4f, 1.0f, // Top-left
            //     0.25f, 0.4f, 0.0f,  // Top-right
            //     0.25f, -0.4f, 0.0f, // Bottom-right
            //     -0.25f, -0.4f, 1.0f // Bottom-left
            // };

            GLfloat vertices[] = {
                -0.25f, 0.4f, 1.0f, // Top-left
                0.25f, 0.4f, 0.0f,  // Top-right
                0.25f, -0.4f, 0.0f, // Bottom-right
                -0.25f, -0.4f, 1.0f // Bottom-left
            };

            GLuint indices[] = {
                0, 1, 2, 3
            };

            this->scale = scale;

		    // Generates Shader object using shaders defualt.vert and default.frag
            Shader shader_program(Square::vertex_source, Square::fragment_source);
            this->render_mapping.shader_program = shader_program.get_id();

			// Generates Vertex Array Object and binds it
			Vao vao;
            this->render_mapping.vao = vao.get_id();
			vao.bind();

			// Generates Vertex Buffer Object and links it to vertices
			Vbo vbo(vertices, sizeof(vertices));
            this->render_mapping.vbo = vbo.get_id();

			// Generates Element Buffer Object and links it to indices
			Ebo ebo(indices, sizeof(indices));
            this->render_mapping.ebo = ebo.get_id();

			// Links VBO to VAO
			vao.link_vbo(vbo, 0);
			// Unbind all to prevent accidentally modifying them
			vao.unbind();
			vbo.unbind();
			ebo.unbind();
        }

        void scale_object()
        {
            static float scale = 0.5f;
            static float delta = 0.001f;

            scale += delta;
            if ((scale >= 1.5f) || (scale <= 0.5)) {
                delta *= -1.0f;
            }

            GLfloat scaling[] = { scale, 0.0f,  0.0f,  0.0f,
                     0.0f,  scale, 0.0f,  0.0f,
                     0.0f,  0.0f,  scale, 0.0f,
                     0.0f,  0.0f,  0.0f,  1.0f };
    
            GLint gScalingLocation = glGetUniformLocation(this->render_mapping.shader_program, "gScaling");
            glUniformMatrix4fv(gScalingLocation, 1, GL_TRUE, scaling);
        }

        void render()
        {
            // Tell OpenGL which Shader Program we want to use
			glUseProgram(this->render_mapping.shader_program);

			// Bind the VAO so OpenGL knows to use it
			glBindVertexArray(this->render_mapping.vao);
			// Draw primitives, number of indices, datatype of indices, index of indices
			glDrawElements(GL_POLYGON, Square::indices_number, GL_UNSIGNED_INT, 0);
        }

        void cleanup()
        {
            // Delete all the objects we've created
			glDeleteVertexArrays(1, &this->render_mapping.vao);
			glDeleteBuffers(1, &this->render_mapping.vbo);
			glDeleteBuffers(1, &this->render_mapping.ebo);
			glDeleteProgram(this->render_mapping.shader_program);
        }

        const char* get_vertex_source()
        {
            return this->vertex_source;
        }

        const char* get_fragment_source()
        {
            return this->fragment_source;
        }

        int get_vertices_number()
        {
            return this->vertices_number;
        }

        int get_indices_number()
        {
            return this->indices_number;
        }

};