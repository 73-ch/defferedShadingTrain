#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetVerticalSync(false);
    ofSetFrameRate(0);
    ofEnableDepthTest();
    
    
    ofFbo::Settings fbo_settings;
    fbo_settings.width = ofNextPow2(ofGetWidth());
    fbo_settings.height = ofNextPow2(ofGetHeight());
    fbo_settings.internalformat = GL_RGB32F;
    fbo_settings.numSamples = 0;
    fbo_settings.useDepth = true;
    fbo_settings.useStencil = false;
    fbo_settings.depthStencilAsTexture = true;
    fbo_settings.textureTarget = GL_TEXTURE_2D;
    fbo_settings.depthStencilInternalFormat = GL_DEPTH_COMPONENT24;
    fbo_settings.minFilter = GL_NEAREST;
    fbo_settings.maxFilter = GL_NEAREST;
    fbo_settings.wrapModeHorizontal = GL_CLAMP_TO_BORDER;
    fbo_settings.wrapModeVertical = GL_CLAMP_TO_BORDER;
    
    g_buffer.allocate(fbo_settings);
    
    depth_tex = g_buffer.getDepthTexture();
    
    g_buffer.createAndAttachTexture(GL_RGB16F, 1); // position
    g_buffer.createAndAttachTexture(GL_RGB, 2); // normal
    g_buffer.createAndAttachTexture(GL_RGBA, 3); // albedo
    g_buffer.createAndAttachTexture(GL_RGBA, 4); // albedo
    
    g_pass.load("g_pass_vertex.glsl", "g_pass_fragment.glsl");

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    float time = ofGetElapsedTimef();
    
    // g_pass
    g_buffer.begin();
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    g_buffer.activateAllDrawBuffers();
    g_pass.begin();
    cam.begin();
    
    ofDrawBox(0, 0, 0, 200, 200, 200);
    
    
    cam.end();
    g_pass.end();
    g_buffer.end();
    
    // g_pass end
    
    
    // fboのそれぞれのテクスチャに書き込めているかのテスト
    
    const float test_width = ofGetWidth()/4.,test_height = ofGetHeight()/4.;
    ofSetColor(255);
    g_buffer.getTexture(0).draw(vec2(0,0), test_width, test_height);
    g_buffer.getTexture(1).draw(vec2(test_width,test_height), test_width, test_height);
    g_buffer.getTexture(2).draw(vec2(test_width*2,test_height*2), test_width, test_height);
    g_buffer.getTexture(3).draw(vec2(test_width*3,test_height*3), test_width, test_height);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
