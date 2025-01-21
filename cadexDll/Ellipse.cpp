#include "pch.h"
#include "framework.h"

#define _USE_MATH_DEFINES
#include <stdexcept>
#include <cmath>
#include "Utility.h"
#include "Ellipse.h"

using namespace CadexShapes;

Ellipse::Ellipse(float a, float b, const Vector3D& center)
{
	if (a <= 0.f || b <= 0.f)
		throw std::logic_error("Invalid radius value");
	m_a = a;
	m_b = b;
	m_center = center;
}

Vector3D Ellipse::point(float t) const
{
	if (!Utility::ValidateNum(t))
		throw std::domain_error("An invalid value was passed to parameter t");
	float x = m_center.x() + m_a * std::cos(t);
	float y = m_center.y() + m_b * std::sin(t);
	return Vector3D(x, y);
}

Vector3D Ellipse::derivative(float t) const
{
	if (!Utility::ValidateNum(t))
		throw std::domain_error("An invalid value was passed to parameter t");
	// r'(t) = (-asint, bcost)
	float x = -m_a * std::sin(t);
	float y = m_b * std::cos(t);
	// Return tangent vector
	return Vector2D(x, y);
}
