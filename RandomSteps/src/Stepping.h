#pragma once

class Stepping {
protected:
	ofVec2f prevPosition;
	bool stepSide;
public:
	ofVec2f footstep;
	float stepDistance, stepWidth, stepSpeed;
	
	Stepping() {
		stepSide = false;
		stepDistance = 30;
		stepSpeed = .03;
		stepWidth = 10;
	}
	void update() {
		float t = ofGetElapsedTimef() * stepSpeed;
		ofVec2f curPosition(ofNoise(t, 0), ofNoise(0, t));
		curPosition *= ofVec2f(ofGetWidth(), ofGetHeight());
		ofVec2f perpendicular = (curPosition - prevPosition).normalize().rotate(90);		
		if(footstep.distance(curPosition) > stepDistance) {
			footstep = curPosition + perpendicular * (stepSide ? stepWidth : -stepWidth);
			stepSide = !stepSide;
		}
		prevPosition = curPosition;
	}
};