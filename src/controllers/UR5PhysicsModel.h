//
//  UR5PhysicsModel.hpp
//  physics
//
//  Created by dantheman on 8/17/16.
//
//

#pragma once
#include "ofMain.h"
#include "ofxAssimpModelLoader.h"
//#include "ofxBullet.h"

class UR5PhysicsModel{
public:
    void setup();
    void update();
    void draw();
private:
    ofxAssimpModelLoader loader;
    vector<ofMesh> meshs;
};