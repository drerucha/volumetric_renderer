#pragma once

#ifndef _SCENE_DATA
#define _SCENE_DATA

#include <string>

#include "../glm/glm.hpp"

#include "Camera.h"


// Uncomment this line to print debug statements to the console about parsing scene data.
#define CONSOLE_OUTPUT

const int NUM_LINES_PROCESSED_BETWEEN_CONSOLE_OUTPUT = 10000;


class SceneData
{
public:
	////////////////////////////////////////////////////
	// Public methods.
	////////////////////////////////////////////////////

	SceneData( std::string config_file_path );
	~SceneData( void );

private:
	////////////////////////////////////////////////////
	// Private methods.
	////////////////////////////////////////////////////

	void parseConfigFile( std::string config_file_path );


	////////////////////////////////////////////////////
	// Private members.
	////////////////////////////////////////////////////

	float delt;						// Size of a voxel in. Voxels are cubes.
	float step;						// Step size to use during rendering.
	glm::vec3 xyzc;					// Number of voxels wide, tall, and deep the buffer measures (integers).
	glm::vec3 brgb;					// Background color.
	glm::vec3 mrgb;					// Voxel buffer's material RGB.
	std::string output_file_name;	// Filename to give the rendered volumetric image.
	glm::vec2 reso;					// Width and height (in pixels) of the raytrace that should be performed (integers).
	glm::vec3 eyep;					// Position of the eye/camera in world-space.
	glm::vec3 vdir;					// Viewing direction of the center of the rendering in world-space.
	glm::vec3 uvec;					// Up-vector in world-space.
	float fovy;						// Half-angle field of view in the y-direction in degrees.
	glm::vec3 lpos;					// Position of the light in world-space.
	glm::vec3 lcol;					// Color of the point light.
	float *voxel_densities;

	Camera *cam;

	// TODO: SceneData should have VoxelBuffer and Camera members.
};

#endif