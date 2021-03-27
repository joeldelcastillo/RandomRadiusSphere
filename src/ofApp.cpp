#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0);

	cam.setDistance(height + width);

	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			mesh.addVertex(ofPoint(x - (width / 2), y - (height / 2), 0));
			mesh.addColor(ofFloatColor(255, 255, 255));
		}
	}

}

//--------------------------------------------------------------
void ofApp::update(){
	rotate++;

	if (sphere)
	{

		for (int y = 0; y < height; y++) {
			for (int x = 0; x < width; x++) {
				
				float time = ofGetElapsedTimef();
				int pos = numpoint(x, y, width);
				float ax = ( 2* float (x) * pi)/ width ;
				float ay = ( 2* float(y) * pi) / width;


				//float noiser = height * (0.5+sin(time / 5 - ax * 10))*ofNoise(( cos(time/5 - ax*10) +  cos(time/5 - ay*10) )*radius);
				float noiser = height * ofNoise((cos(time/3 + ay * 7) + cos(time/3 + ax * 7)) * radius);
				//float noiser = height * ofNoise((cos(time + ax * 7) * radius, sin(time * ay)));
				
				ofVec3f point = mesh.getVertex(pos);
				point.x = noiser * sin(ax) * sin(ay);
				point.y = noiser * cos(ax);
				point.z = noiser * sin(ax) * cos(ay);
				mesh.setVertex(pos, point);

			}
		}
	}

	
}

//--------------------------------------------------------------
void ofApp::draw(){
	
	ofPushMatrix();
	
	cam.begin();
	mesh.drawVertices();

	cam.end();
	ofRotateZDeg(rotate*4);
	
	ofPopMatrix();

	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch (key) {
	case 'f':
		sphere = !sphere;
		break;
	case 'o':
		radius -= 0.1;
		break;
	case 'p':
		radius += 0.1;
		break;
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

int ofApp::numpoint(int x, int y, int wd) {
	return (y * wd + x);
}

