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

		float increase = 0.1f;
		bool going_right = true;

    public:

			Grid()
            {
				try
				{
					this->layout_objects.square = new Square(0.5f);
				} catch (CustomException exception)
				{
					std::cout << exception.what() << std::endl;
				}
				
            }

			void render(){
				Square square = *this->layout_objects.square;
				square.render(this->increase);
				
				if(this->going_right)
				{
					this->increase += 0.01f;
				} else
				{
					this->increase -= 0.01f;
				}

				if(this->increase >= 2.0f)
				{
					this->going_right = false;
				}

				if(this->increase <= -5.0f)
				{
					this->going_right = true;
				}
			}

			void cleanup(){
				Square square = *this->layout_objects.square;
				square.cleanup();
			}
};