#include "../hFiles/TetrisCpp.h"

blockInfo::blockInfo(){
	Size = 0;
	mainPos = { 0, 0 };
}

void blockInfo::createBlock( int size, Vector2 blockpos[], Color newColor ){
	Size = size;
	blockPos = new Vector2[size];
	maxSize = { 0, 0 };
	for( size_t blockIndex = 0; blockIndex < size; blockIndex++ ){
		blockPos[blockIndex] = blockpos[blockIndex];

		if( blockPos[blockIndex].x > maxSize.x ) maxSize.x = blockPos[blockIndex].x;
		if( blockPos[blockIndex].y > maxSize.y ) maxSize.y = blockPos[blockIndex].y;
	}
	blockColor = newColor;
}

void blockInfo::SetPosition( Vector2 newPos ){
	mainPos = newPos;
}

void blockInfo::blockMove( int Horizontal, int Vertical ){
	mainPos.x += Horizontal;
	mainPos.y += Vertical;
}

void blockInfo::drawBlock( Vector2 globalPos, int blockWidth, int blockHeight ){
	if( Size != 0 ){
		for( size_t blockIndex = 0; blockIndex < Size; blockIndex++ ){
			DrawRectangle(
				globalPos.x + ( mainPos.x + blockPos[blockIndex].x ) * blockWidth,
				globalPos.y + ( mainPos.y + blockPos[blockIndex].y ) * blockHeight,
				blockWidth, blockHeight, blockColor
			);
		}
	}
}
