#pragma once

// C++ includes.
#ifndef _UTILITIES
#define _UTILITIES

#include <vector>
#include <string>

// 3rd party includes.
#include "../glm/glm.hpp"


////////////////////////////////////////////////////
// Simple logic to control visibility of debug print statements.
////////////////////////////////////////////////////

// Uncomment this line to print debug statements to the console about parsing scene data.
#define CONSOLE_OUTPUT

#ifdef CONSOLE_OUTPUT
#define CONSOLE_MSG( str ) do { std::cout << str << std::endl; } while( false )
#else
#define CONSOLE_MSG( str ) do { } while ( false )
#endif


namespace Utilities
{
	extern std::vector<std::string> tokenizeString( const std::string &s,
													const char &d );
	
	extern float stringToFloat( std::string s );
	extern int stringToInt( std::string s );
	extern bool stringIsPositiveInt( std::string s );

	extern float degreesToRadians( float degrees );

	extern glm::vec3 clampVec3( const glm::vec3 &v, const float min, const float max );
	extern glm::vec3 absoluteValueOfVec3( const glm::vec3 &v );
}

#endif