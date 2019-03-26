#include "Object.h"
#include "Util.h"

using Breakout::Object;

Object::Object() : destroyFlag(false)
{
}

void Breakout::Object::AddComponent(std::shared_ptr<BaseComponent> component)
{
    components.push_back(component);
}

void Breakout::Object::Update(float deltaTime)
{
    for (auto component : components)
    {
        component->Update(deltaTime);
    }
}

bool Breakout::Object::GetDestroy()
{
    return destroyFlag;
}

void Breakout::Object::SetDestroy()
{
    destroyFlag = true;
}