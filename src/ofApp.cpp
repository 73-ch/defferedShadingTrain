#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetVerticalSync(false);
    ofSetFrameRate(0);
    ofEnableDepthTest();
    
    // g_pass setup
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
    g_buffer.createAndAttachTexture(GL_RGBA, 4); // depth
    
    g_pass_shader.load("g_pass_vertex.glsl", "g_pass_fragment.glsl");
    
    
    // l_pass setup
    l_pass_shader.load("l_pass_vertex.glsl", "l_pass_fragment.glsl");
    
    for (int i = 0; i < 50; ++i) {
        l_positions.push_back(vec3(ofRandom(-200, 200),ofRandom(-200, 200),ofRandom(-200, 200)));
        l_ambients.push_back(vec3(0.5,0.,0.));
        l_diffuses.push_back(vec3(ofRandom(0.2), ofRandom(1.0), ofRandom(1.0)));
        l_speculars.push_back(vec3(1.,1.,1.));
    }
    
    rect.setMode(OF_PRIMITIVE_TRIANGLE_FAN);
    rect.addVertex(vec3(1.0, 1.0, 0.0));
    rect.addTexCoord(vec2(1., 0.));
    rect.addVertex(vec3(1.0, -1.0, 0.0));
    rect.addTexCoord(vec2(1., 1.));
    rect.addVertex(vec3(-1.0, -1.0, 0.0));
    rect.addTexCoord(vec2(0., 1.));
    rect.addVertex(vec3(-1.0, 1.0, 0.0));
    rect.addTexCoord(vec2(0., 0.));
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    const float width = ofGetWidth();
    const float height = ofGetHeight();
    
    float time = ofGetElapsedTimef();
    
    // g_pass
    g_buffer.begin();
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    g_buffer.activateAllDrawBuffers();
    g_pass_shader.begin();
    cam.begin();
    
    ofDrawBox(0, 0, 0, 200, 200, 200);
    
    
    cam.end();
    g_pass_shader.end();
    g_buffer.end();
    
    // g_pass end
    
    
    // fboのそれぞれのテクスチャに書き込めているかのテスト
    
    const float test_width = ofGetWidth()/4.,test_height = ofGetHeight()/4.;
    ofSetColor(255);
//    g_buffer.getTexture(0).draw(vec2(0,0), test_width, test_height);
//    g_buffer.getTexture(1).draw(vec2(test_width,test_height), test_width, test_height);
//    g_buffer.getTexture(2).draw(vec2(test_width*2,test_height*2), test_width, test_height);
//    g_buffer.getTexture(3).draw(vec2(test_width*3,test_height*3), test_width, test_height);
    
    // test end
    
    // clear
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    
    // l_pass
    l_pass_shader.begin();
    l_pass_shader.setUniformTexture("g_position", g_buffer.getTexture(0), 0);
    l_pass_shader.setUniformTexture("g_normal", g_buffer.getTexture(1), 0);
    l_pass_shader.setUniformTexture("g_albedo", g_buffer.getTexture(2), 0);
    l_pass_shader.setUniformTexture("g_depth", g_buffer.getTexture(3), 0);
    
    l_pass_shader.setUniform3f("cam_pos", cam.getPosition());
    
    l_pass_shader.setUniform3fv("l_positions", &l_positions[0].x, l_positions.size());
    l_pass_shader.setUniform3fv("l_ambients", &l_ambients[0].x, l_ambients.size());
    l_pass_shader.setUniform3fv("l_diffuses", &l_diffuses[0].x, l_diffuses.size());
    l_pass_shader.setUniform3fv("l_speculars", &l_speculars[0].x, l_speculars.size());
    
    rect.draw(OF_MESH_FILL);
    
    l_pass_shader.end();
    
    // l_pass end
    
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
