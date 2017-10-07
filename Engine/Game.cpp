#include "MainWindow.h"
#include "Game.h"
#include "CubeSkinScene.h"
#include "CubeVertexColorScene.h"
#include "CubeSolidScene.h"
#include <sstream>
#include "Camera.h"
#include "Ray.h"
#include "Sphere.h"
#include <iostream>

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd)
{
	/*scenes.push_back( std::make_unique<CubeSkinScene>( gfx,L"images\\office_skin.jpg" ) );
	scenes.push_back( std::make_unique<CubeVertexColorScene>( gfx ) );
	scenes.push_back( std::make_unique<CubeSolidScene>( gfx ) );
	curScene = scenes.begin();
	OutputSceneName();*/
}

void Game::Go()
{
	gfx.BeginFrame();
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

//Vec3 operator*(const float& lhs, const Vec3& rhs)
//{
//	return{ lhs* rhs.x, lhs* rhs.y, lhs*rhs.y };
//}

Vec3 operator*(const float& lhs, const _Vec3<float>& rhs);
Vec3 operator*(const float & lhs, const _Vec3<float>& rhs)
{
	return{ lhs * rhs.x, lhs * rhs.y, lhs * rhs.z };
}
//Vec3 operator*(const _Vec3<float>& lhs, const float& rhs);
//Vec3 operator*(const _Vec3<float>& lhs, const float & rhs)
//{
//	return{ lhs.x  * rhs, lhs.y * rhs, lhs.z * rhs };
//}

void Game::UpdateModel()
{
	auto a = Vec3(0, 1, 0);
	auto b = Vec3(1, 0, 0);
	auto c = a + b;
	auto d = a * b;
	auto e = a % b;

	const auto screen_width = 512;
	const auto screen_height = 512;
	const auto	part_width = 1.0f / screen_width;
	const auto	part_height = 1.f / screen_height;
	auto camera_pos = Vec3(0, 2, -2);
	const auto cam = Camera(camera_pos, 1);

	const auto AspectRatio = 1.0f;
	const auto xPlane = (cam.p1 - cam.p0) * AspectRatio * part_width;   //width is 2 units wide
	const auto yPlane = (cam.p2 - cam.p0) * part_height;                //height is 2 units high

	auto col = Color(255, 128, 21);
	auto spherepos = Vec3(0.0f, 1.0f, 1.5f);
	auto sphere = Sphere(col, spherepos, 1.0f);

	for (float x = 0; x < screen_width; x++)
	{
		for (float y = 0; y < screen_height; y++)
		{
			if (y == 511)
			{
				auto d23 = 23;
			}
			auto x2 = x * xPlane;
			auto y2 = y * yPlane;
			auto pos = cam.p0 + x2 + y2;
			const auto point_on_screen = cam.p0 + x * xPlane + y * yPlane;
			auto dir = point_on_screen - camera_pos;

			//			std::cout << "x: " << dir.x << ", y: " << dir.y << ", z: " << dir.z << std::endl;
			auto ray = Ray(camera_pos, dir);
			const auto raycolor = sphere.intersection(ray);
			gfx.PutPixel(int(x), int(y), raycolor);
		}
	}
}

void Game::ComposeFrame()
{
	//gfx.PutPixel(50, 50, Color{ 0, 250, 0, 0 });
}
void Game::CycleScenes()
{
	if (++curScene == scenes.end())
	{
		curScene = scenes.begin();
	}
	OutputSceneName();
}

void Game::ReverseCycleScenes()
{
	if (curScene == scenes.begin())
	{
		curScene = scenes.end() - 1;
	}
	else
	{
		--curScene;
	}
	OutputSceneName();
}

void Game::OutputSceneName() const
{
	std::stringstream ss;
	const std::string stars((*curScene)->GetName().size() + 4, '*');

	ss << stars << std::endl
		<< "* " << (*curScene)->GetName() << " *" << std::endl
		<< stars << std::endl;
	OutputDebugStringA(ss.str().c_str());
}


