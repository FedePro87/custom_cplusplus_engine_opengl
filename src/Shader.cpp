#pragma once

#include<glad/glad.h>
#include<string>
#include<fstream>
#include<sstream>
#include<iostream>
#include<cerrno>

#include<CustomException.cpp>

class Shader {

    public :

        // Reference ID of the Shader Program
	    GLuint id;

        // Constructor that build the Shader Program from 2 different shaders
        Shader(const char* vertex_shader_source, const char* fragment_shader_source)
        {
        	// Create Vertex Shader Object and get its reference
        	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
        	// Attach Vertex Shader source to the Vertex Shader Object
        	glShaderSource(vertexShader, 1, &vertex_shader_source, NULL);
        	// Compile the Vertex Shader into machine code
        	glCompileShader(vertexShader);

        	// Create Fragment Shader Object and get its reference
        	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        	// Attach Fragment Shader source to the Fragment Shader Object
        	glShaderSource(fragmentShader, 1, &fragment_shader_source, NULL);
        	// Compile the Vertex Shader into machine code
        	glCompileShader(fragmentShader);

        	// Create Shader Program Object and get its reference
        	id = glCreateProgram();
        	// Attach the Vertex and Fragment Shaders to the Shader Program
        	glAttachShader(id, vertexShader);
        	glAttachShader(id, fragmentShader);
        	// Wrap-up/Link all the shaders together into the Shader Program
        	glLinkProgram(id);

        	// Delete the now useless Vertex and Fragment Shader objects
        	glDeleteShader(vertexShader);
        	glDeleteShader(fragmentShader);
        }

        // Activates the Shader Program
        void activate()
        {
        	glUseProgram(id);
        }

        // Deletes the Shader Program
        void cleanup()
        {
        	glDeleteProgram(id);
        }

		GLuint get_id()
        {
            return this->id;
        }

};