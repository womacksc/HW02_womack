#include "Rectangles.h"

Rectangles::Rectangles(uint8_t* pixels,int x, int y, int width, int height, Color8u shapeColor){	
	x_ = x;	
	endX_ = x + width;	
	y_ = y;	
	endY_ = y + height;
	shapeColor_ = shapeColor;
	pixels_ = pixels;	
}	

void Rectangles::draw(){	
	for(int x=0; x<=TEXTURE_SIZE; x++){		
		for(int y=0; y<=TEXTURE_SIZE; y++){			
			if(x>x_ && x<endX_ && y>y_ && y<endY_){					
				pixels_[3*(x + y * TEXTURE_SIZE)] = shapeColor_.r;					
				pixels_[3*(x + y * TEXTURE_SIZE)+1] = shapeColor_.g;					
				pixels_[3*(x + y * TEXTURE_SIZE)+2] = shapeColor_.b;		
			}		
		}	
	}
}

bool Rectangles::isTouching(int x, int y){	
	if (x>x_ && x<endX_ && y>y_ && y<endY_){
		return true;
	}
	else return false;
}

void Rectangles::moveMe(int x,int y){
	x_ = x;
	y_ = y;
}
