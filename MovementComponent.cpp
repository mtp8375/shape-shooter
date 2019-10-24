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
	XMVECTOR translation = XMVectorSet(0, 0, 0, 0); //Stores the total amount the camera is moving this frame


	//Apply our given transformations
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

	//Multiple by deltaTime to scale it to a reasonable amount
	translation = XMVector3Normalize(translation);
	translation *= deltaTime;
	translation *= m_speed; //Multiply that by our speed (<1 for decent not terrible speedy movement)

	XMVECTOR newPos = translation + position; //Add it to the camera's position

	XMFLOAT3 newPosData;
	XMStoreFloat3(&newPosData, newPos);
	transform->SetPosition(newPosData); //Apply the change to the camera
}

void MovementComponent::OnMouseMove(WPARAM buttonState, int x, int y)
{
	int dx = x - prevMousePos.x; //Change in both x and y of mouse.
	int dy = y - prevMousePos.y;

	XMFLOAT4 rotDeltaData;
	XMVECTOR rotDelta = XMQuaternionRotationRollPitchYaw(dy * m_sensitivity, dx * m_sensitivity, 0.0f); //Multiply difference by sensitivity, store in a quaternion
	XMStoreFloat4(&rotDeltaData, rotDelta);
	GetOwner()->GetTransform()->Rotate(rotDeltaData); //Apply our new rotation to the camera

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
