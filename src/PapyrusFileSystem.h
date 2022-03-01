#pragma once

#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;

namespace PapyrusFileSystem {
        
    std::vector<std::string_view> List(RE::StaticFunctionTag*, std::string_view path) {
        auto paths = std::vector<std::string_view>();
        return paths;
        // for (const auto & path : fs::directory_iterator(path)) {

        // }
        // return paths;
    };

    bool BIND(RE::BSScript::IVirtualMachine* vm) {
        static constexpr auto className = "FileSystem";
        vm->RegisterFunction("List", className, List);
        return true;
    };
}