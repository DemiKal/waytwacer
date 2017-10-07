#pragma once
#include "Vec3.h"
#include "Colors.h"
#include "Ray.h"
class Ray;

class Sphere
{
public:
	Sphere(Color& color,Vec3& center, const float radius);
	~Sphere();
	float radius;
	float radius2;
	Vec3 center;
	Color color;
	Color intersection(Ray& ray) const;
	Vec3 get_normal(Vec3 pos);
};

