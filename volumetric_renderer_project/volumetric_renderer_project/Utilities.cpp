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
	for ( unsigned int i = 0; i < s.length(); ++i ) {
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

glm::vec3 Utilities::clampVec3( const glm::vec3 &v, const float min, const float max )
{
	glm::vec3 n;
	n.x = ( v.x > max ) ? max : ( ( v.x < min ) ? min : v.x );
	n.y = ( v.y > max ) ? max : ( ( v.y < min ) ? min : v.y );
	n.x = ( v.z > max ) ? max : ( ( v.z < min ) ? min : v.z );
	return n;
}

glm::vec3 Utilities::absoluteValueOfVec3( const glm::vec3 &v )
{
	glm::vec3 n;
	n.x = ( v.x < 0.0f ) ? ( v.x * -1.0f ) : v.x;
	n.y = ( v.y < 0.0f ) ? ( v.y * -1.0f ) : v.y;
	n.z = ( v.z < 0.0f ) ? ( v.z * -1.0f ) : v.z;
	return n;
}