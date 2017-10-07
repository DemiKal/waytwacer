#pragma once
#include "Vec3.h"

class Camera
{
public:
	Camera(Vec3& pos, const float d);
	~Camera();
	void update();

	Vec3 p0;     //upper left corner of cam
	Vec3 p1;     //upper right corner of cam
	Vec3 p2;     //lower left corner of cam
	Vec3 view_direction = Vec3(0, 0, 0);
	Vec3 screenCenter = Vec3(0, 0, 0);
	Vec3 position = Vec3(0, 0, 0);
	Vec3 left = Vec3(-1, 0, 0);
	Vec3 right = Vec3(1, 0, 0);
	Vec3 up = Vec3(0, 1, 0);
	Vec3 down = Vec3(0, -1, 0);
	Vec3 forward = Vec3(0, 0, 1);
	Vec3 backward = Vec3(0, 0, -1);
	float aspect_ratio = 1.0f;
	float distance = 0;

	};

