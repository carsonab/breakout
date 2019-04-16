
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
            // Do thing

        }
    }
}