/** 
* @file HW02_womackApp.cpp 
* CSE 274 - Fall 2012  
* 
* @author Shiloh Womack 
* @due date Sept 24, 2012 
* 
* @note You are free to use, share, and remix this, privately or commercially, as long as you 
* give attribution.
*  
*/


#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"
#include "cinder/gl/TextureFont.h"
#include "Resources.h"
#include "Rectangles.h"
#include "list.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class HW02_womackApp : public AppBasic {  
  public:	
	void setup();	
	void mouseDown( MouseEvent event );
	void mouseDrag(MouseEvent event);
	void HW02_womackApp::keyDown( KeyEvent event);
	void update();	
	void draw();	
	void prepareSettings(Settings* settings);
	void insertAfter(Node* position, Rectangles* rect);

  private:	
	static const int TEXTURE_SIZE=1024;
	static const int windowWidth = 800;	
	static const int windowHeight = 600;
	Node* sentry_;	
	Node* currentNode_;
	Node* selectedNode_;
	Surface* mySurface_;
	Rectangles* r;
	int keySelect, x;
	Font mFont, mFont2;
	gl::TextureFontRef	mTextureFont;	
	gl::TextureFontRef	mTextureFont2;
};