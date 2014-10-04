#pragma once

// C++ includes.
#include <iostream>
#include <string>

// 3rd party includes.
#include "../glm/glm.hpp"
#include "EasyBMP.h"

// My includes.
#include "SceneData.h"
#include "Camera.h"
#include "SceneStructs.h"
#include "Utilities.h"


////////////////////////////////////////////////////
// Define constants.
////////////////////////////////////////////////////

const std::string CONFIG_FILE_PATH = "C:\\Users\\Danny\\Documents\\_projects\\code\\volumetric_renderer_fall_2014\\scene_data\\scene_01.txt";
const std::string OUTPUT_DIR_PATH = "C:\\Users\\Danny\\Documents\\_projects\\code\\volumetric_renderer_fall_2014\\rendered_output\\";


////////////////////////////////////////////////////
// Define global variables.
////////////////////////////////////////////////////

SceneData *g_scene_data;
Camera *g_camera;
BMP g_output_image;


////////////////////////////////////////////////////
// Define method prototypes.
////////////////////////////////////////////////////

void init( void );
void cleanup( void );


////////////////////////////////////////////////////
// Program entry point.
////////////////////////////////////////////////////
int main(int argc, char** argv)
{
	// TODO: Add a simple timing mechanism to help monitor performance during development.

	init();

	// TODO: Main program loop.

	glm::vec2 reso = g_camera->getResolution();
	for ( int y = 0; y < reso.y; ++y ) {
		for ( int x = 0; x < reso.x; ++x ) {
			Ray r = g_camera->computeRayThroughPixel( x, y );
			
			// Test generated ray directions.
			glm::vec3 abs_r = Utilities::absoluteValueOfVec3( r.direction );
			g_output_image( x, y )->Red = ( ebmpBYTE )( abs_r.x * 255.0f );
			g_output_image( x, y )->Green = ( ebmpBYTE )( abs_r.y * 255.0f );
			g_output_image( x, y )->Blue = ( ebmpBYTE )( abs_r.z * 255.0f );
		}
	}

	// Write output image at path specified above with name specified in scene config file.
	g_output_image.WriteToFile( ( OUTPUT_DIR_PATH + g_scene_data->getOutputFileName() ).c_str() );

	CONSOLE_MSG( "Render has completed." );
	std::cin.ignore();

	cleanup();
	return 0;
}


void init()
{
	g_scene_data = new SceneData( CONFIG_FILE_PATH );
	g_camera = g_scene_data->getCamera();

	// Initialize output BMP image.
	glm::vec2 reso = g_camera->getResolution();
	g_output_image.SetSize( ( int )reso.x, ( int )reso.y );
	g_output_image.SetBitDepth( 24 );
}


////////////////////////////////////////////////////
// Program-level destructor.
////////////////////////////////////////////////////
void cleanup()
{
	delete g_scene_data;
}