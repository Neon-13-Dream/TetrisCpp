#pragma one

#ifndef TETRISCPP
#define TETRISCPP

#include <raylib.h>

class tetriscpp {
private:
	Vector2 mainAreaPos;
	int mainAreaPixelSize;
	const int mainAreaWidth;
	const int mainAreaHeight;

	Color colors[2]; 




public:
	tetriscpp( int, int );
	void drawMainArea();
	void SetPixelSize( int );
	void SetPosition( Vector2 );


};

#endif
