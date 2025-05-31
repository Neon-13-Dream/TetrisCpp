#include "hFiles/TetrisCpp.h"

int main(){
	InitWindow( 500, 840, "TetrisCpp" );
	SetTargetFPS( 60 );

	tetriscpp test( 20, 40 );
	test.SetPixelSize( 20 );
	test.SetPosition( { 20, 20 } );

	while( !WindowShouldClose() ){
		ClearBackground( { 44, 31, 41, 255 } );

		BeginDrawing();
		test.drawMainArea();
		EndDrawing();
	}

	return 0;
}
