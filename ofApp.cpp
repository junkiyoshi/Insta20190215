#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofSetColor(39);
	ofNoFill();
	ofSetLineWidth(1.5);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWidth() * 0.5, ofGetHeight() * 0.5);

	auto radius_base = 250;
	auto len = 125;
	auto deg_span = 5;
	for (auto deg = 0; deg < 360; deg += deg_span) {

		auto noise_point = glm::vec2(radius_base * cos(deg * DEG_TO_RAD), radius_base * sin(deg * DEG_TO_RAD));
		auto noise_value = ofNoise(noise_point.x * 0.01, noise_point.y * 0.01, ofGetFrameNum() * 0.01);
		auto radius = radius_base;
		if (noise_value > 0.7) { radius += ofMap(noise_value, 0.7, 1.0, 0, radius_base * 0.5); }
		if (noise_value < 0.3) { radius -= ofMap(noise_value, 0.0, 0.3, radius_base * 0.5, 0); }

		ofBeginShape();
		ofVertex(glm::vec2(radius * cos((deg - deg_span * 0.5)  * DEG_TO_RAD), radius * sin((deg - deg_span * 0.5) * DEG_TO_RAD)));
		ofVertex(glm::vec2(radius * cos((deg + deg_span * 0.5)  * DEG_TO_RAD), radius * sin((deg + deg_span * 0.5) * DEG_TO_RAD)));
		ofVertex(glm::vec2((radius - len) * cos((deg + deg_span * 0.5)  * DEG_TO_RAD), (radius - len) * sin((deg + deg_span * 0.5) * DEG_TO_RAD)));
		ofVertex(glm::vec2((radius - len) * cos((deg - deg_span * 0.5)  * DEG_TO_RAD), (radius - len) * sin((deg - deg_span * 0.5) * DEG_TO_RAD)));
		ofEndShape(true);
	}

}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}