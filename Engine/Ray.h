#pragma once
#include "Vec3.h"

class Ray
{
public:
	Ray(Vec3& o, Vec3& dir);
	~Ray();

	Vec3 origin;
	Vec3 direction;      //always normalize!
	float t = 0;		 //distance to intersection
};

