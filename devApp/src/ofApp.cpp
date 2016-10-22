#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    gui.setupFlexBoxLayout();
    
    
    //    ofxGuiPanel* panel = gui.addPanel(model.parameters);
    //    panel3->loadTheme("theme/theme3.json");
    //    panel3->setPosition(panel2->getShape().getTopRight()+ofPoint(10, 0));
    model.setup();
    cam.lookAt(glm::vec3(0, 0, 0), glm::vec3(0, 0, 1));
    tcpNode.setPosition(model.tcpNode.getGlobalPosition());
    tcpNode.setOrientation(model.tcpNode.getOrientationQuat());
    bRun = false;
    target.setPosition(glm::vec3(0.25, 0.25, 0.25));
    center.setPosition(0, 0, 0);
    tcpNode.setParent(center);
    bLoop = true;
}

//--------------------------------------------------------------
void ofApp::update(){
    if(bRun){
        if(bLoop){
            tcpNode.setPosition(glm::lerp(model.tcpNode.getGlobalPosition(), glm::vec3(0, 0.5, 0.5), glm::vec3(abs(sin(ofGetElapsedTimef()*0.0412)))));
        }else{
           
            tcpNode.setOrientation(model.tcpNode.getOrientationQuat());
        }
        model.update(tcpNode);
        
        drawNode.setGlobalPosition(tcpNode.getPosition()*1000);
        drawNode.setGlobalOrientation(tcpNode.getOrientationQuat());
        //        cout<<"drawNode========"<<endl;
        //        cout<<tcpNode.getPosition()<<endl;
        
    }
    
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0, 0, 0);
    cam.begin();
    model.draw();
    drawNode.draw();
    //    ofPushMatrix();
    ofDrawBox(glm::vec3(0.25, 0.25, 0.25)*1000, 50);
    //    ofPopMatrix();
    cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == ' '){
        bRun = !bRun;
    }
    if(key == 'l'){
        bLoop = !bLoop;
    }
    
    
    if(key == ']'){
        tcpNode.setPosition(model.tcpNode.getGlobalPosition()+glm::vec3(0, 0, 0.01));
    }
    if(key == '['){
        tcpNode.setPosition(model.tcpNode.getGlobalPosition()+glm::vec3(0, 0, -0.2));
    }
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
