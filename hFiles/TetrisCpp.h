#pragma one

#ifndef TETRISCPP
#define TETRISCPP

#include <iostream>
#include <raylib.h>

class blockInfo {
private:
	Vector2 mainPos;
	int Size;
	Vector2 *blockPos;
	Color blockColor;
	Vector2 maxSize;

public:
	blockInfo();
	void SetStartPos( Vector2 );
	void createBlock( int, Vector2[], Color );
	void drawBlock( Vector2, int, int );
	void SetPosition( Vector2 );
	void SetColor( Color );

	void blockMove( int, int );
};

class tetriscpp {
private:
	Vector2 mainAreaPos;
	int mainAreaPixelSize;
	const int mainAreaWidth;
	const int mainAreaHeight;
	Color **mainArea;

	blockInfo Tblock;
	Color colors[2]; 

public:
	tetriscpp( int, int );
	void drawMainArea();
	void SetPixelSize( int );
	void SetPosition( Vector2 );
	void update();

	
	~tetriscpp();
};

#endif
