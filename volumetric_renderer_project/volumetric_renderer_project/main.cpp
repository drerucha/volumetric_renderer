#pragma once

#include <iostream>
#include "../glm/glm.hpp"
//#include "../glm/gtc/matrix_transform.hpp"

int main(int argc, char** argv)
{
	glm::vec3 light_pos( 0.0f, 2.0f, 10.0f );

	std::cout << "Hello world." << std::endl;
	printf( "( %.2f, %.2f, %.2f )", light_pos.x, light_pos.y, light_pos.z );
	std::cin.ignore();

	return 0;
}