#pragma once

namespace PapyrusDateTime {
        
    bool BIND(RE::BSScript::IVirtualMachine* vm) {
        static constexpr auto className = "FileSystem";
        // vm->RegisterFunction("Exists", className, Exists);
        return true;
    };
}
