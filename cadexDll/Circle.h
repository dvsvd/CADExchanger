#pragma once
#include "pch.h"
#include "framework.h"
#include "cadexDll.h"
#include "Vector3D.h"
#include "Ellipse.h"

namespace CadexShapes {

class CADEXDLL_API Circle : public ICurve
{
private:
	float m_r;
	Vector3D m_center;
public:
	Circle(float radius, const Vector3D& center = Vector3D());
	~Circle() = default;
	/*
	* point - calculates a point of the circle
	* PARAMETERS:
	*	- t - parameter of parametric circle equation
	* RETURN:
	*	Vector3D representing the calculated point
	*/
	Vector3D point(float t) const override;
	/*
	* derivative - calculates the first derivative of the circle
	* PARAMETERS:
	*	- t - parameter of parametric circle equation
		representing the point of the circle
	* RETURN:
	* Unit tangent vector at the point of parameter t
	*/
	Vector3D derivative(float t) const override;
	const float& r() const { return m_r; };
};
}
