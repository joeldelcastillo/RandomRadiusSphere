#pragma once

#include "ofMain.h"
#include <math.h>

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

		int numpoint(int x, int y, int matrix);

		ofEasyCam cam;
		ofMesh mesh;
		int width = 300;
		int height = 300;
		bool sphere = false;
		float radius = 0;
		double pi = 2 * acos(0.0);
		float rad;
		float rotate=0;
};
