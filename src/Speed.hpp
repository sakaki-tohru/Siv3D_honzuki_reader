#pragma once
#include <Siv3D.hpp>

class Speed {
	double readspeed;
public:
	Speed();
	Speed(const double& speed);

	double get()const;
	void adjust();
};