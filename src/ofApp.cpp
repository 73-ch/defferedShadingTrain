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
    fbo_settings.colorFormats.push_back(GL_RGB);
    
    
    g_buffer.allocate(fbo_settings);
    
    g_buffer.createAndAttachTexture(GL_RGBA32F, 1);
    g_buffer.createAndAttachTexture(GL_RGBA32F, 2);

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    g_buffer.begin();
    g_buffer.activateAllDrawBuffers();
    
    
    g_buffer.end();

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
