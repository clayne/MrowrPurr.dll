#pragma once

#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;

namespace PapyrusFileSystem {
        
    bool Exists(RE::StaticFunctionTag*, std::string_view path) {
        return fs::exists(path);
    };

    bool IsFile(RE::StaticFunctionTag*, std::string_view path) {
        return fs::exists(path) && ! fs::is_directory(path);
    }

    bool IsDirectory(RE::StaticFunctionTag*, std::string_view path) {
        return fs::is_directory(path);
    }

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
        vm->RegisterFunction("Exists", className, Exists);
        vm->RegisterFunction("IsFile", className, IsFile);
        vm->RegisterFunction("IsDirectory", className, IsDirectory);
        vm->RegisterFunction("List", className, List);
        return true;
    };
}
