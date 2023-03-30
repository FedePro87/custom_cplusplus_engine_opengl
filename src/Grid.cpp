//GLFW
#include<glad/glad.h>
#include<GLFW/glfw3.h>

#include<cmath>

#include<Shader.cpp>
#include<Vao.cpp>
#include<Vbo.cpp>
#include<Ebo.cpp>
#include<layouts/Square.cpp>

class Grid
{

	private :

		struct {
			Square* square;
		} layout_objects;

    public:

			Grid()
            {
				try
				{
					this->layout_objects.square = new Square(2.0f);
				} catch (CustomException exception)
				{
					std::cout << exception.what() << std::endl;
				}
				
            }

			void render(){
				Square square = *this->layout_objects.square;
				square.render();
			}

			void cleanup(){
				Square square = *this->layout_objects.square;
				square.cleanup();
			}
};