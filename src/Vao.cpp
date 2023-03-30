#pragma once

#include<glad/glad.h>
#include<Vbo.cpp>

class Vao {

    public :

        GLuint id;
    
        // Constructor that generates a Vao ID
        Vao()
        {
        	glGenVertexArrays(1, &id);
        }
    
        // Links a VBO to the Vao using a certain layout
        void link_vbo(Vbo& vbo, GLuint layout)
        {
        	vbo.bind();
        	glVertexAttribPointer(layout, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
        	glEnableVertexAttribArray(layout);
        	vbo.unbind();
        }
    
        // Binds the Vao
        void bind()
        {
        	glBindVertexArray(id);
        }
    
        // Unbinds the Vao
        void unbind()
        {
        	glBindVertexArray(0);
        }
    
        // Deletes the Vao
        void cleanup()
        {
        	glDeleteVertexArrays(1, &id);
        }

        GLuint get_id()
        {
            return this->id;
        }
    
};