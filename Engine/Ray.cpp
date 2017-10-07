#include "Ray.h"

Ray::Ray(Vec3& orig, Vec3& dir)
{
	origin = orig;
	direction = dir;
	direction.Normalize();
}

Ray::~Ray()
{
}
