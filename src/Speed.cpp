#include "./Speed.hpp"

Speed::Speed() :Speed(0.0) {}

Speed::Speed(const double& speed) : readspeed(speed) {}

void Speed::reset() {
	readspeed = 0.0;
}

double Speed::get() {
	return readspeed;
}

void Speed::adjust() {
	SimpleGUI::Slider(U"“Ç‚Þ‘¬“x", readspeed, -5.0, 5.0, Vec2(270, 20));
}