// C++ includes.
#include <iostream>
#include <fstream>

// My includes.
#include "SceneData.h"
#include "Utilities.h"


////////////////////////////////////////////////////
// Simple logic to control visibility of debug print statements.
////////////////////////////////////////////////////

#ifdef CONSOLE_OUTPUT
#define DEBUG_MSG( str ) do { std::cout << str << std::endl; } while( false )
#else
#define DEBUG_MSG( str ) do { } while ( false )
#endif


////////////////////////////////////////////////////
// Constructor + destructor.
////////////////////////////////////////////////////

SceneData::SceneData( std::string config_file_path )
{
	voxel_densities = NULL;
	parseConfigFile( config_file_path );
}


SceneData::~SceneData()
{
	delete[] voxel_densities;
}


////////////////////////////////////////////////////
// Read in config file and extract data.
////////////////////////////////////////////////////
void SceneData::parseConfigFile( std::string config_file_path )
{
	DEBUG_MSG( "parsing config file..." );

	std::string line;
	std::ifstream file( config_file_path );
	int voxel_buffer_index = 0;
	int num_lines_processed = 0;
	int num_lines_processed_since_last_output = 0;

	if ( file.is_open() ) {
		while ( std::getline ( file, line ) ) {
			std::vector<std::string> v = Utilities::tokenizeString( line, ' ' );

			if ( Utilities::stringIsPositiveInt( v.front() ) ) {
				if ( voxel_densities == NULL ) {
					std::cout << "ERROR: Voxel buffer dimensions must be defined before voxel density values." << std::endl;
					exit( EXIT_FAILURE );
				}
				voxel_densities[voxel_buffer_index] = Utilities::stringToFloat( v.front() );
				++voxel_buffer_index;
			}

			else if ( v.front() == "DELT" ) {
				delt = Utilities::stringToFloat( v[1] );
			}
			else if ( v.front() == "STEP" ) {
				step = Utilities::stringToFloat( v[1] );
			}
			else if ( v.front() == "XYZC" ) {
				xyzc[0] = Utilities::stringToInt( v[1] );
				xyzc[1] = Utilities::stringToInt( v[2] );
				xyzc[2] = Utilities::stringToInt( v[3] );

				// Allocate memory to store voxel density values.
				voxel_densities = new float[ xyzc[0] * xyzc[1] * xyzc[2] ];
			}
			else if ( v.front() == "BRGB" ) {
				brgb[0] = Utilities::stringToFloat( v[1] );
				brgb[1] = Utilities::stringToFloat( v[2] );
				brgb[2] = Utilities::stringToFloat( v[3] );
			}
			else if ( v.front() == "MRGB" ) {
				mrgb[0] = Utilities::stringToFloat( v[1] );
				mrgb[1] = Utilities::stringToFloat( v[2] );
				mrgb[2] = Utilities::stringToFloat( v[3] );
			}
			else if ( v.front() == "FILE" ) {
				output_file_name = v[1];
			}
			else if ( v.front() == "RESO" ) {
				reso[0] = Utilities::stringToInt( v[1] );
				reso[1] = Utilities::stringToInt( v[2] );
			}
			else if ( v.front() == "EYEP" ) {
				eyep[0] = Utilities::stringToFloat( v[1] );
				eyep[1] = Utilities::stringToFloat( v[2] );
				eyep[2] = Utilities::stringToFloat( v[3] );
			}
			else if ( v.front() == "VDIR" ) {
				vdir[0] = Utilities::stringToFloat( v[1] );
				vdir[1] = Utilities::stringToFloat( v[2] );
				vdir[2] = Utilities::stringToFloat( v[3] );
			}
			else if ( v.front() == "UVEC" ) {
				uvec[0] = Utilities::stringToFloat( v[1] );
				uvec[1] = Utilities::stringToFloat( v[2] );
				uvec[2] = Utilities::stringToFloat( v[3] );
			}
			else if ( v.front() == "FOVY" ) {
				fovy = Utilities::stringToFloat( v[1] );
			}
			else if ( v.front() == "LPOS" ) {
				lpos[0] = Utilities::stringToFloat( v[1] );
				lpos[1] = Utilities::stringToFloat( v[2] );
				lpos[2] = Utilities::stringToFloat( v[3] );
			}
			else if ( v.front() == "LCOL" ) {
				lcol[0] = Utilities::stringToFloat( v[1] );
				lcol[1] = Utilities::stringToFloat( v[2] );
				lcol[2] = Utilities::stringToFloat( v[3] );
			}

			// Console output.
			if ( num_lines_processed_since_last_output == NUM_LINES_PROCESSED_BETWEEN_CONSOLE_OUTPUT ) {
				num_lines_processed_since_last_output = 0;
				DEBUG_MSG( "Processed " << num_lines_processed << " lines." );
			}

			++num_lines_processed;
			++num_lines_processed_since_last_output;
		}

		file.close();
	}
	else {
		DEBUG_MSG( "Unable to open file at " << config_file_path );
	}

	DEBUG_MSG( "Processed " << num_lines_processed << " lines." );
	DEBUG_MSG( "Done parsing scene config file." );
}