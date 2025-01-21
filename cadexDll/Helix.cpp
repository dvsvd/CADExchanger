#include "pch.h"
#include "framework.h"

#define _USE_MATH_DEFINES
#include <stdexcept>
#include <cmath>
#include "Utility.h"
#include "Helix.h"

using namespace CadexShapes;

Helix::Helix(float radius, float step, const Vector3D& center)
{
	if (step <= 0.f)
		throw std::logic_error("Invalid step value");
	m_step = step;
	m_b = step / 2.f * static_cast<float>(M_PI);
	m_r = radius;
}

Vector3D Helix::point(float t) const
{
	// Get the point's projecton to OXY plane
	Circle c(m_r);
	Vector3D pt = c.point(t);
	float z = m_center.z() + m_b * t;
	pt.setZ(z);
	return pt;
}

Vector3D Helix::derivative(float t) const
{
	if (!Utility::ValidateNum(t))
		throw std::domain_error("An invalid value was passed to parameter t");
	// r'(t) = (-rsint, rcost, b)
	float x = -m_r * std::sin(t);
	float y = m_r * std::cos(t);
	float z = m_b;
	// Return tangent vector
	return Vector3D(x, y, z);
}
