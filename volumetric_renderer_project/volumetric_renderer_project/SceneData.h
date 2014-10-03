#pragma once

#ifndef _SCENE_DATA
#define _SCENE_DATA

#include <string>

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

	// Getters for private members.

	// TODO.

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
	int xyzc[3];					// Number of voxels wide, tall, and deep the buffer measures.
	float brgb[3];					// Background color.
	float mrgb[3];					// Voxel buffer's material RGB.
	std::string output_file_name;	// Filename to give the rendered volumetric image.
	int reso[2];					// Two integers specifying the width and height (in pixels) of the raytrace that should be performed.
	float eyep[3];					// Position of the eye/camera in world-space.
	float vdir[3];					// Viewing direction of the center of the rendering in world-space.
	float uvec[3];					// Up-vector in world-space.
	float fovy;						// Half-angle field of view in the y-direction in degrees.
	float lpos[3];					// Position of the light in world-space.
	float lcol[3];					// Color of the point light.
	float *voxel_densities;

	// TODO: SceneData should have VoxelBuffer and Camera members.
};

#endif