
#include "HW02_womackApp.h"

	
	void HW02_womackApp::prepareSettings(Settings* settings){	
		settings->setWindowSize(windowWidth, windowHeight);	
		settings->setResizable(false);
	}
	
	void HW02_womackApp::setup(){	
		mySurface_ = new Surface(TEXTURE_SIZE, TEXTURE_SIZE, true);	
		sentry_ = new Node;
		sentry_->next_ = sentry_;
		currentNode_ = sentry_;
		keySelect = 1;
		x = 0;

	}
	
	void HW02_womackApp::mouseDown( MouseEvent event ){
		uint8_t* dataArray = (*mySurface_).getData();
		//inserts a new shape and saves it in selected node
		if(event.isRightDown()){
			Color8u c =  Color8u(rand()%255,rand()%255,rand()%255);
			r = new Rectangles(dataArray,100+x, 100+x, 200, 200, c);
			insertAfter(currentNode_, r);
			selectedNode_ = currentNode_;
			currentNode_ = currentNode_->next_;
			x= x + 10;
		}
	}

	void HW02_womackApp::mouseDrag(MouseEvent event){
		uint8_t* dataArray = (*mySurface_).getData();
		int eventX = event.getX();
		int eventY = event.getY();

		while(event.isLeftDown() && currentNode_ != sentry_){
				if(selectedNode_->data_->isTouching(eventX,eventY)){
					int whereX = eventX - selectedNode_->data_->x_;			
					int whereY = eventY - selectedNode_->data_->y_;
					selectedNode_->data_->moveMe(eventX+whereX,eventY+whereY);
			}

		}
	}
	void HW02_womackApp::keyDown( KeyEvent event){
		if(event.getChar()=='?')		
			keySelect++;	
	}

	void HW02_womackApp::insertAfter(Node* position, Rectangles* rect){	
		Node* temp = new Node;	
		temp -> data_ = rect;	
		temp -> next_ = position -> next_;	
		position -> next_ = temp;
	}
	
	void HW02_womackApp::update(){
		uint8_t* pixels = (*mySurface_).getData();

		if(currentNode_ != sentry_){
			currentNode_->data_->draw();
			
		}
	}
	
	void HW02_womackApp::draw(){
		gl::draw(*mySurface_);
		

		if(keySelect%2==1){
			mFont = Font( "Times New Roman", 24 );		
			mTextureFont = gl::TextureFont::create( mFont );		
			std::string str("Right click on mouse to create squares, Left click to move squares, Press '?' to end this text");		
			gl::color( Color8u( 0,0,0 ) );		
			gl::enableAlphaBlending();		
			Rectf boundsRect(40, mTextureFont->getAscent() + 40, getWindowWidth() - 300, getWindowHeight() - 300 );		
			mTextureFont->drawStringWrapped( str, boundsRect );		
			gl::color(Color8u(255,255,255));
		}
	}
	
	CINDER_APP_BASIC( HW02_womackApp, RendererGl )