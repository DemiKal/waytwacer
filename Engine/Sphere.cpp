#include "Sphere.h"

Sphere::Sphere(Color& color, Vec3& center, const float radius)
{
	this->color = color;
	this->center = center;
	this->radius = radius;
	radius2 = radius*radius;
}

Sphere::~Sphere()
{
}

Color Sphere::intersection(Ray& ray) const
{
	Vec3 c = center - ray.origin;
	float t = c * ray.direction;
	Vec3 q = c - ray.direction * t;

	float p2 = q * q;
	if (p2 > radius2) return Color(0,0,0);

	t -= float( sqrt(radius2 - p2));

	if ((t < ray.t) && (t > 0))
		ray.t = t;
	return color;
}

Vec3 Sphere::get_normal(Vec3 pos)
{	
	return{ 0,0,0 };
}
