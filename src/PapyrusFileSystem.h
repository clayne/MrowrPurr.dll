#pragma once

#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;

// TODO make sure it doesn't explode when it's not a directory (not exist OR is file)

namespace PapyrusFileSystem {
        
    std::vector<std::string> List(RE::StaticFunctionTag*, std::string_view directory) {
        auto paths = std::vector<std::string>();
        auto directoryPath = fs::path(directory);
        if (fs::is_directory(directoryPath)) {
            for (const auto & path : fs::directory_iterator(directoryPath)) {
                paths.push_back(path.path().string());
            }
        }
        return paths;
    };

    bool BIND(RE::BSScript::IVirtualMachine* vm) {
        static constexpr auto className = "FileSystem";
        vm->RegisterFunction("List", className, List);
        return true;
    };
}
