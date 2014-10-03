#pragma once

// C++ includes.
#include <iostream>
#include <string>

// 3rd party includes.
#include "../glm/glm.hpp"
//#include "../glm/gtc/matrix_transform.hpp"

// My includes.
#include "SceneData.h"


////////////////////////////////////////////////////
// Define constants.
////////////////////////////////////////////////////

const std::string CONFIG_FILE_PATH = "C:\\Users\\Danny\\Documents\\_projects\\code\\volumetric_renderer_fall_2014\\scene_data\\scene_01.txt";
const std::string OUTPUT_DIR_PATH = "C:\\Users\\Danny\\Documents\\_projects\\code\\volumetric_renderer_fall_2014\\rendered_output";


////////////////////////////////////////////////////
// Define global variables.
////////////////////////////////////////////////////

SceneData *scene_data;


////////////////////////////////////////////////////
// Define method prototypes.
////////////////////////////////////////////////////

void cleanup( void );


////////////////////////////////////////////////////
// Program entry point.
////////////////////////////////////////////////////
int main(int argc, char** argv)
{
	scene_data = new SceneData( CONFIG_FILE_PATH );

	// TODO.

	std::cin.ignore();

	cleanup();
	return 0;
}


////////////////////////////////////////////////////
// Program-level destructor.
////////////////////////////////////////////////////
void cleanup()
{
	delete scene_data;
}