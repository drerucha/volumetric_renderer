// C++ includes.
#include <iostream>
#include <fstream>

// My includes.
#include "SceneData.h"
#include "Utilities.h"


////////////////////////////////////////////////////
// Constructor + destructor.
////////////////////////////////////////////////////

SceneData::SceneData( std::string config_file_path )
{
	voxel_densities = NULL;
	parseConfigFile( config_file_path );

	// Initialize scene camera.
	cam = new Camera( fovy,
					  reso,
					  eyep,
					  vdir,
					  uvec );
}


SceneData::~SceneData()
{
	delete[] voxel_densities;
	delete cam;
}


////////////////////////////////////////////////////
// Read in config file and extract data.
////////////////////////////////////////////////////
void SceneData::parseConfigFile( std::string config_file_path )
{
	CONSOLE_MSG( "Parsing config file..." );

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
				xyzc.x = Utilities::stringToFloat( v[1] );
				xyzc.y = Utilities::stringToFloat( v[2] );
				xyzc.z = Utilities::stringToFloat( v[3] );

				// Allocate memory to store voxel density values.
				voxel_densities = new float[( int )( xyzc.x * xyzc.y * xyzc.z )];
			}
			else if ( v.front() == "BRGB" ) {
				brgb.x = Utilities::stringToFloat( v[1] );
				brgb.y = Utilities::stringToFloat( v[2] );
				brgb.z = Utilities::stringToFloat( v[3] );
			}
			else if ( v.front() == "MRGB" ) {
				mrgb.x = Utilities::stringToFloat( v[1] );
				mrgb.y = Utilities::stringToFloat( v[2] );
				mrgb.z = Utilities::stringToFloat( v[3] );
			}
			else if ( v.front() == "FILE" ) {
				output_file_name = v[1];
			}
			else if ( v.front() == "RESO" ) {
				reso.x = Utilities::stringToFloat( v[1] );
				reso.y = Utilities::stringToFloat( v[2] );
			}
			else if ( v.front() == "EYEP" ) {
				eyep.x = Utilities::stringToFloat( v[1] );
				eyep.y = Utilities::stringToFloat( v[2] );
				eyep.z = Utilities::stringToFloat( v[3] );
			}
			else if ( v.front() == "VDIR" ) {
				vdir.x = Utilities::stringToFloat( v[1] );
				vdir.y = Utilities::stringToFloat( v[2] );
				vdir.z = Utilities::stringToFloat( v[3] );
			}
			else if ( v.front() == "UVEC" ) {
				uvec.x = Utilities::stringToFloat( v[1] );
				uvec.y = Utilities::stringToFloat( v[2] );
				uvec.z = Utilities::stringToFloat( v[3] );
			}
			else if ( v.front() == "FOVY" ) {
				fovy = Utilities::stringToFloat( v[1] );
			}
			else if ( v.front() == "LPOS" ) {
				lpos.x = Utilities::stringToFloat( v[1] );
				lpos.y = Utilities::stringToFloat( v[2] );
				lpos.z = Utilities::stringToFloat( v[3] );
			}
			else if ( v.front() == "LCOL" ) {
				lcol.x = Utilities::stringToFloat( v[1] );
				lcol.y = Utilities::stringToFloat( v[2] );
				lcol.z = Utilities::stringToFloat( v[3] );
			}

			// Console output.
			if ( num_lines_processed_since_last_output == NUM_LINES_PROCESSED_BETWEEN_CONSOLE_OUTPUT ) {
				num_lines_processed_since_last_output = 0;
				CONSOLE_MSG( "Processed " << num_lines_processed << " lines." );
			}

			++num_lines_processed;
			++num_lines_processed_since_last_output;
		}

		file.close();
	}
	else {
		CONSOLE_MSG( "Unable to open file at " << config_file_path );
	}

	CONSOLE_MSG( "Processed " << num_lines_processed << " lines." );
	CONSOLE_MSG( "Done parsing scene config file." );
}


Camera * SceneData::getCamera()
{
	return cam;
}


std::string SceneData::getOutputFileName()
{
	return output_file_name;
}