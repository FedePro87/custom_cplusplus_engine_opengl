#pragma once

#include<glad/glad.h>

class Ebo {

    public :

        GLuint id;

        // Constructor that generates a Elements Buffer Object and links it to indices
        Ebo(GLuint* indices, GLsizeiptr size)
        {
        	glGenBuffers(1, &id);
        	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
        	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);
        }

        // Binds the Ebo
        void bind()
        {
        	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
        }

        // Unbinds the Ebo
        void unbind()
        {
        	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
        }

        // Deletes the Ebo
        void cleanup()
        {
        	glDeleteBuffers(1, &id);
        }

        GLuint get_id()
        {
            return this->id;
        }
};