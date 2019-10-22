#pragma once
#include "Component.h"
#include <DirectXMath.h>

class MovementComponent : public Component
{
public: 

	virtual void Start() override;
	MovementComponent(Entity* entity) : Component(entity) { }

	virtual void Tick(float deltaTime) override;
	virtual void OnMouseMove(WPARAM buttonState, int x, int y) override;

	void SetSpeed(float n_speed);
	float GetSpeed();

	void SetSensitivity(float n_sense);
	float GetSensitivity();
private:
	
	float m_speed = 1.0f; //Speed of the player
	float m_sensitivity = 0.001f; //How quickly the camera rotates depending on mouse movemnt
	DirectX::XMFLOAT2 prevMousePos;

};

