#include "../hFiles/TetrisCpp.h"

tetriscpp::tetriscpp( int width, int height ) : mainAreaWidth( width ), mainAreaHeight( height ) {
	mainAreaPos = { 0, 0 };
	mainAreaPixelSize = 10;

	colors[0] = { 44, 31, 41, 255 };
	colors[1] = { 56, 56, 56, 255 };

}

void tetriscpp::SetPixelSize( int size ){
	mainAreaPixelSize = size;
}

void tetriscpp::SetPosition( Vector2 pos ){
	mainAreaPos = pos;
}

void tetriscpp::drawMainArea(){
	for( int rowIndex = 0; rowIndex < mainAreaHeight; rowIndex++ ){
		for( int colIndex = 0; colIndex < mainAreaWidth; colIndex++ ){
			DrawRectangle( 
				mainAreaPos.x + colIndex * mainAreaPixelSize,
				mainAreaPos.y + rowIndex * mainAreaPixelSize,
				mainAreaPixelSize, mainAreaPixelSize,
				colors[1]
			);
			
			DrawRectangleLines( 
				mainAreaPos.x + colIndex * mainAreaPixelSize,
				mainAreaPos.y + rowIndex * mainAreaPixelSize,
				mainAreaPixelSize, mainAreaPixelSize,
				colors[0]
			);
		}
	}
}
