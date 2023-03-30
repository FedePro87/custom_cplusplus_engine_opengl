#pragma once

#include<glad/glad.h>

class Vbo {

    public:

        GLuint id;

        // Constructor that generates a Vertex Buffer Object and links it to vertices
        Vbo(GLfloat* vertices, GLsizeiptr size)
        {
        	glGenBuffers(1, &id);
        	glBindBuffer(GL_ARRAY_BUFFER, id);
        	glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
        }

        // Binds the Vbo
        void bind()
        {
        	glBindBuffer(GL_ARRAY_BUFFER, id);
        }

        // Unbinds the Vbo
        void unbind()
        {
        	glBindBuffer(GL_ARRAY_BUFFER, 0);
        }

        // Deletes the Vbo
        void cleanup()
        {
        	glDeleteBuffers(1, &id);
        }

        GLuint get_id()
        {
            return this->id;
        }

};