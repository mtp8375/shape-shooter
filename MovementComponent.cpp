#include "MovementComponent.h"
#include "Transform.h"
#include "Entity.h"

using namespace DirectX;

void MovementComponent::Start()
{
}

void MovementComponent::Tick(float deltaTime)
{
	Transform* transform = GetOwner()->GetTransform(); //Grabs current transform of the objec this is one

	//Grab and store our values for movement including the forward vector, right vector, and position
	XMFLOAT3 posData = transform->GetPosition();
	XMFLOAT3 fwdData = transform->GetForward();
	XMFLOAT3 rightData = transform->GetRight();

	//Store these in XMVectors
	XMVECTOR position = XMLoadFloat3(&posData);
	XMVECTOR g_forward = XMLoadFloat3(&fwdData);
	XMVECTOR g_right = XMLoadFloat3(&rightData);
	XMVECTOR translation = XMVectorSet(0, 0, 0, 0); //Represents a translation

	if (GetAsyncKeyState('W') & 0x8000)
	{
		translation += g_forward;
	}
	if (GetAsyncKeyState('S') & 0x8000)
	{
		translation -= g_forward;
	}
	if (GetAsyncKeyState('D') & 0x8000)
	{
		translation += g_right;
	}
	if (GetAsyncKeyState('A') & 0x8000)
	{
		translation -= g_right;
	}

	translation = XMVector3Normalize(translation);
	translation *= deltaTime;
	translation *= m_speed;

	XMVECTOR newPos = translation + position;

	XMFLOAT3 newPosData;
	XMStoreFloat3(&newPosData, newPos);
	transform->SetPosition(newPosData);
}

void MovementComponent::OnMouseMove(WPARAM buttonState, int x, int y)
{
	int dx = x - prevMousePos.x; //Change in both x and y of mouse.
	int dy = y - prevMousePos.y;

	XMFLOAT4 rotDeltaData;
	XMVECTOR rotDelta = XMQuaternionRotationRollPitchYaw(dy * m_sensitivity, dx * m_sensitivity, 0.0f);
	XMStoreFloat4(&rotDeltaData, rotDelta);
	GetOwner()->GetTransform()->Rotate(rotDeltaData);

	prevMousePos.x = x;
	prevMousePos.y = y;
}

void MovementComponent::SetSpeed(float n_speed)
{
	m_speed = n_speed;
}

float MovementComponent::GetSpeed()
{
	return m_speed;
}

void MovementComponent::SetSensitivity(float n_sense)
{
	m_sensitivity = n_sense;
}

float MovementComponent::GetSensitivity()
{
	return m_sensitivity;
}
