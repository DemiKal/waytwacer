#include "Camera.h"

Camera::Camera(Vec3& pos, const float d)
{
	position = pos;
	distance = d;

	screenCenter = Vec3(0, 0, 1) * aspect_ratio + position;
	p0 = screenCenter + left + up * aspect_ratio;
	p1 = screenCenter + right + up * aspect_ratio;
	p2 = screenCenter + left + down * aspect_ratio;
	
	view_direction = screenCenter - position;
}

Camera::~Camera()
{
}

void Camera::update()
{
	//handle keyboard input and move
	
}
