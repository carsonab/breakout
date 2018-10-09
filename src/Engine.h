#pragma once
#include "RenderSystem.h"
#include "SFML/Graphics.hpp"

#include <memory>
#include "Object.h"

namespace Breakout
{
    class Engine
    {
      public:
        Engine(sf::RenderWindow* window);
        ~Engine() = default;

        void Update(float deltaTime, const std::vector<Object>& gameObjects);

        std::unique_ptr<RenderSystem> renderSystem;
    };
}  // namespace Breakout