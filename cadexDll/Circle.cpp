#include "pch.h"
#include "framework.h"

#define _USE_MATH_DEFINES
#include <stdexcept>
#include <cmath>
#include "Utility.h"

#include "Circle.h"

using namespace CadexShapes;

Circle::Circle(float radius, const Vector3D& center)
{
	m_r = radius;
}

Vector3D Circle::point(float t) const
{
	if (!Utility::ValidateNum(t))
		throw std::domain_error("An invalid value was passed to parameter t");
	float x = m_center.x() + m_r * std::cos(t);
	float y = m_center.y() + m_r * std::sin(t);
	return Vector3D(x, y);
}

Vector3D Circle::derivative(float t) const
{
	if (!Utility::ValidateNum(t))
		throw std::domain_error("An invalid value was passed to parameter t");
	// r'(t) = (-rsint, rcost)
	float x = -m_r * std::sin(t);
	float y = m_r * std::cos(t);
	// Return unit tangent vector
	return Vector2D(x, y);
}



