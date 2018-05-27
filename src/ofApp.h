#pragma once

#include "ofMain.h"

using namespace glm;

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
    ofEasyCam cam;
    
    // g_pass
    ofFbo g_buffer;
    ofShader g_pass_shader;
    ofTexture depth_tex;
    
    // l_pass
    ofShader l_pass_shader;
    
    vector <vec3> l_positions;
    vector <vec3> l_ambients;
    vector <vec3> l_diffuses;
    vector <vec3> l_speculars;
    
    ofMesh rect;
};
