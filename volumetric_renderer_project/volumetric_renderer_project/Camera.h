#pragma once

#ifndef _CAMERA
#define _CAMERA

// 3rd party includes.
#include "../glm/glm.hpp"

// My includes.
#include "SceneStructs.h"


class Camera
{
public:
	Camera( float fovy,
			glm::vec2 reso,
			glm::vec3 eyep,
			glm::vec3 vdir,
			glm::vec3 uvec );
	~Camera( void );

	Ray computeRayThroughPixel( const int x,
								const int y );

	glm::vec2 getResolution( void );

private:
	float fovy;
	float fovx;
	glm::vec2 reso;
	glm::vec3 eyep;
	glm::vec3 vdir;
	glm::vec3 uvec;
	glm::vec3 a;
	glm::vec3 m;
	glm::vec3 h;
	glm::vec3 v;
};

#endif