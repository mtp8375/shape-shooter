#pragma
#include "ShapeSpawnerManager.h"
#include "Rotator.h"
#include "Entity.h"
#include "World.h"
#include <DirectXMath.h>

using namespace DirectX;

ShapeSpawnerManagerComponent::ShapeSpawnerManagerComponent(Entity* entity) : Component(entity)
{
	srand(time(NULL));
}

void ShapeSpawnerManagerComponent::Tick(float deltaTime)
{
	spawnShapes();
}

void ShapeSpawnerManagerComponent::Start()
{
}

void ShapeSpawnerManagerComponent::spawnShapes()
{
	World* world = World::GetInstance();
	//cubes
	if (rand() % 100000 == 0)
	{
		Entity* cube1 = world->Instantiate("cube1");
		cube1->GetTransform()->SetPosition(XMFLOAT3(rand() % 10, rand() % 10, rand() % 10));
		cube1->AddComponent<MeshComponent>()->m_mesh = world->GetMesh("cube");
		cube1->AddComponent<MaterialComponent>()->m_material = world->GetMaterial("metal");
		Rotator* rotCube = cube1->AddComponent<Rotator>();
		rotCube->eulerDelta.x = 1.0f;
		rotCube->eulerDelta.y = 1.0f;
	}
	//cones
	if (rand() % 100000 == 0)
	{
		Entity* cone1 = world->Instantiate("cone1");
		cone1->GetTransform()->SetPosition(XMFLOAT3(rand() % 10, rand() % 10, rand() % 10));
		cone1->AddComponent<MeshComponent>()->m_mesh = world->GetMesh("cone");
		cone1->AddComponent<MaterialComponent>()->m_material = world->GetMaterial("metal");
		Rotator* rotCone = cone1->AddComponent<Rotator>();
		rotCone->eulerDelta.x = 2.0f;
		rotCone->eulerDelta.y = 1.0f;
	}
	//cylinders
	if (rand() % 100000 == 0)
	{
		Entity* cylinder1 = world->Instantiate("cylinder1");
		cylinder1->GetTransform()->SetPosition(XMFLOAT3(rand() % 10, rand() % 10, rand() % 10));
		cylinder1->AddComponent<MeshComponent>()->m_mesh = world->GetMesh("cylinder");
		cylinder1->AddComponent<MaterialComponent>()->m_material = world->GetMaterial("metal");
		Rotator* rotCyl = cylinder1->AddComponent<Rotator>();
		rotCyl->eulerDelta.x = 5.0f;
		rotCyl->eulerDelta.y = 1.0f;
	}
	//helix
	if (rand() % 100000 == 0)
	{
		Entity* helix1 = world->Instantiate("helix1");
		helix1->GetTransform()->SetPosition(XMFLOAT3(rand() % 10, rand() % 10, rand() % 10));
		helix1->AddComponent<MeshComponent>()->m_mesh = world->GetMesh("helix");
		helix1->AddComponent<MaterialComponent>()->m_material = world->GetMaterial("metal");
		Rotator* rothelix = helix1->AddComponent<Rotator>();
		rothelix->eulerDelta.x = 1.0f;
		rothelix->eulerDelta.y = 5.0f;
	}
	//sphere
	if (rand() % 100000 == 0)
	{
		Entity* sphere1 = world->Instantiate("sphere1");
		sphere1->GetTransform()->SetPosition(XMFLOAT3(rand() % 10, rand() % 10, rand() % 10));
		sphere1->AddComponent<MeshComponent>()->m_mesh = world->GetMesh("sphere");
		sphere1->AddComponent<MaterialComponent>()->m_material = world->GetMaterial("metal");
		Rotator* rotSphere = sphere1->AddComponent<Rotator>();
		rotSphere->eulerDelta.x = 1.0f;
		rotSphere->eulerDelta.y = 1.0f;
	}
	//torus
	if (rand() % 100000 == 0)
	{
		Entity* torus1 = world->Instantiate("torus1");
		torus1->GetTransform()->SetPosition(XMFLOAT3(rand() % 10, rand() % 10, rand() % 10));
		torus1->AddComponent<MeshComponent>()->m_mesh = world->GetMesh("torus");
		torus1->AddComponent<MaterialComponent>()->m_material = world->GetMaterial("metal");
		Rotator* rotTorus = torus1->AddComponent<Rotator>();
		rotTorus->eulerDelta.x = 1.0f;
		rotTorus->eulerDelta.y = 1.0f;
	}
}
