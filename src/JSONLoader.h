
#pragma once

namespace JSONLoader
{
    nlohmann::json LoadJsonFromFile(const std::string& filename)
    {
        nlohmann::json parsed_json = {};

        FILE* file = fopen(filename.c_str(), "r");
        Assert(file != nullptr, "Failed to open {}", filename);

        if (file)
        {
            fseek(file, 0, SEEK_END);
            auto file_size = ftell(file);
            Assert(file_size > 0, "Empty file");

            fseek(file, 0, SEEK_SET);

            std::string buffer(file_size, 0);
            fread((void*)buffer.data(), file_size, 1, file);

            fclose(file);

            parsed_json = nlohmann::json::parse(buffer.c_str());
            Assert(!parsed_json.empty(), "Failed to parse JSON");
        }

        return parsed_json;
    }
}