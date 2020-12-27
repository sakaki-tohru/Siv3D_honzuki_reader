#pragma once
#include <Siv3D.hpp>

class Speed {
	double readspeed;
public:
	Speed();
	Speed(const double& speed);

	void reset();
	double get()const;
	void adjust();
};