#ifndef RECTANGLES_H
#define RECTANGLES_H
#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"
#include "cinder/gl/TextureFont.h"
#include "Resources.h"

using namespace ci;
using namespace ci::app;
using namespace std;


class Rectangles{
public:
	static const int TEXTURE_SIZE=1024;
	int x_, y_, endX_, endY_, width_, height_;
	Color8u shapeColor_;
	uint8_t* pixels_;

	Rectangles(uint8_t* pixels,int x, int y, int width, int height, Color8u shapeColor);
	void draw();
	bool isTouching(int x, int y);
	void moveMe(int x,int y);
};
#endif