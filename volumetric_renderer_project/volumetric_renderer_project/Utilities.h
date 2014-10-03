#pragma once

#ifndef _UTILITIES
#define _UTILITIES

#include <vector>
#include <string>


namespace Utilities
{
	extern std::vector<std::string> tokenizeString( const std::string &s,
													const char &d );
	
	extern float stringToFloat( std::string s );
	extern int stringToInt( std::string s );
	extern bool stringIsPositiveInt( std::string s );
}

#endif