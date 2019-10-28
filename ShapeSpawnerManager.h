#pragma once
#include "Component.h"
#include <stdlib.h>
#include <time.h>


class ShapeSpawnerManagerComponent : public Component
{
public:
	ShapeSpawnerManagerComponent(Entity* entity);
	void spawnShapes();
	virtual void Tick(float deltaTime) override;
	virtual void Start() override;
};