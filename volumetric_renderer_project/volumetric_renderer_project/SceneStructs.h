#pragma once

#ifndef _SCENE_STRUCTS
#define _SCENE_STRUCTS

// 3rd party includes.
#include "../glm/glm.hpp"

struct Ray
{
	glm::vec3 origin;
	glm::vec3 direction;
};

#endif