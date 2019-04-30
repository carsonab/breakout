
#include "ScriptParser.h"
#include "JSONLoader.h"

using namespace Breakout;
using namespace JSONLoader;

ScriptParser::ScriptParser()
{
    const auto definition_filename = "../../data/objectDefinitions.json";

    //load object description 
    auto objDefinition = LoadJsonFromFile(definition_filename);

    if (objDefinition.size() == 0)
    {
        return;
    }

    // todo: read the read brick
    auto types = objDefinition["ObjectTypes"];
    for (auto objType : types)
    {
        std::string friendlyName = objType["FriendlyName"];
        std::string symbolName   = objType["Symbol"];
        auto components   = objType["Components"];

        for (auto component : components)
        {
            std::string componentType = component["Type"];
            if (componentType == "CollisionComponent")
            {
                int collisionWidth = component["width"];
                int collisionHeight = component["height"];

                // get our collision reactions
                std::vector<std::string> allReactions;
                auto componentReactions = component["reactions"];
                for (auto collisionReaction : componentReactions)
                {
                    allReactions.push_back(collisionReaction);
                }
                collisionWidth = collisionWidth + collisionHeight;

                // @! TODO START HERE
                // We need to create an Object owner, then create a shape. Then we can add our collisionReactions
                //CollisionComponent* collisionComponent = {};
                //collisionComponent.AddCollisionReaction(const std::string& reactionId);

                //{
                 //   collisionWidth, collisionHeight,
                //}
            }
        }

        
    }
}