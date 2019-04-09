
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
    auto redBrick = objDefinition["red_brick"];
}