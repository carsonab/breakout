#pragma once
#include "Math.h"
#include <map>
#include <functional>

namespace Breakout
{
    namespace Collision
    {
        enum class CollisionChannel
        {
            CC_NONE = 0
        };

        class CollisionReaction
        {
        public:
            CollisionReaction();

            typedef std::function<void(CollisionChannel, Object*, Object*, Hit&)> CollisionReactionFunc;
            bool GetCollisionReaction(const std::string& reactionName, CollisionChannel channel, CollisionReactionFunc& outFunc);

        private:
            std::map<std::string, CollisionReactionFunc> reactionMap;
        };
    }
}