// C++ includes.
#include <sstream>

// My includes.
#include "Utilities.h"


const float PI = 3.14159265359f;


std::vector<std::string> Utilities::tokenizeString( const std::string &s,
													const char &d )
{
    std::vector<std::string> words;
    std::stringstream stream( s );
    std::string item;
    while ( getline( stream, item, d ) ) {
        words.push_back( item );
    }
    return words;
}

float Utilities::stringToFloat( std::string s )
{
	return ( float )atof( s.c_str() );
}

int Utilities::stringToInt( std::string s )
{
	return ( int )atoi( s.c_str() );
}

bool Utilities::stringIsPositiveInt( std::string s )
{
	for ( int i = 0; i < s.length(); ++i ) {
		if ( !isdigit( s[i] ) ) {
			return false;
		}
	}
	return true;
}

float Utilities::degreesToRadians( float degrees )
{
	return degrees * ( PI / 180.0f );
}