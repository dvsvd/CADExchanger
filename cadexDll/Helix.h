#pragma once
#include "pch.h"
#include "framework.h"
#include "cadexDll.h"
#include "Circle.h"

namespace CadexShapes {

class CADEXDLL_API Helix : public ICurve
{
protected:
	float m_step;
	float m_b;
	float m_r;
	Vector3D m_center;
public:
	Helix(float radius, float step, const Vector3D& center = Vector3D());
	~Helix() = default;
	/*
	* point - calculates a point of the helix
	* PARAMETERS:
	*	- t - parameter of parametric helix equation
	* RETURN:
	*	Vector3D representing the calculated point
	*/
	Vector3D point(float t) const override;
	/*
	* derivative - calculates the first derivative of the helix
	* PARAMETERS:
	*	- t - parameter of parametric helix equation
		representing the point of the helix
	* RETURN:
	* Unit tangent vector at the point of parameter t
	*/
	Vector3D derivative(float t) const override;
	const float& step() const { return m_step; };
	const float& b() const { return m_b; };
	const float& r() const { return m_r; };
};
}
