#include "../hFiles/TetrisCpp.h"

tetriscpp::tetriscpp( int width, int height ) : mainAreaWidth( width ), mainAreaHeight( height ) {
	mainAreaPos = { 0, 0 };
	mainAreaPixelSize = 10;

	colors[0] = { 44, 31, 41, 255 };
	colors[1] = { 56, 56, 56, 255 };

	mainArea = new Color*[height];
	for( size_t rowIndex = 0; rowIndex < height; rowIndex++ ){
		mainArea[rowIndex] = new Color[width];

		for( size_t colIndex = 0; colIndex < width; colIndex++ ){
			mainArea[rowIndex][colIndex] = colors[1];
		}
	}

	Vector2 TblockPos[4];
	TblockPos[0] = { 1, 0 };
	TblockPos[1] = { 0, 1 };
	TblockPos[2] = { 1, 1 };
	TblockPos[3] = { 2, 1 };
	Tblock.createBlock( 4, TblockPos, RED );
}

tetriscpp::~tetriscpp(){
	for( size_t rowIndex = 0; rowIndex < mainAreaHeight; rowIndex++ ){
		delete[] mainArea[rowIndex];
	}
	delete[] mainArea;
}

void tetriscpp::update(){
	if( IsKeyPressed( KEY_LEFT ) ) Tblock.blockMove( -1, 0 );
	if( IsKeyPressed( KEY_RIGHT ) ) Tblock.blockMove( 1, 0 );
	if( IsKeyPressed( KEY_UP ) ) Tblock.blockMove( 0, -1 );
	if( IsKeyPressed( KEY_DOWN ) ) Tblock.blockMove( 0, 1 );
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
				mainArea[rowIndex][colIndex]
			);
			
			DrawRectangleLines( 
				mainAreaPos.x + colIndex * mainAreaPixelSize,
				mainAreaPos.y + rowIndex * mainAreaPixelSize,
				mainAreaPixelSize, mainAreaPixelSize,
				colors[0]
			);
		}
	}

	Tblock.drawBlock( mainAreaPos, mainAreaPixelSize, mainAreaPixelSize );
}
