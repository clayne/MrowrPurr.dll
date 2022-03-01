#define _INC_WINDOWS
#include <SKSE/Impl/PCH.h>
#include <RE/Skyrim.h>
#include <SKSE/SKSE.h>
#include <REL/Relocation.h>
#undef _INC_WINDOWS

#include <ShlObj_core.h>
#include <Windows.h>
#include <Psapi.h>
#include <stdio.h>
#include <stdexcept>

#include <format>
#include <gtest/gtest.h>
#include "PapyrusFileSystem.h"

class PapyrusFileSystemTest : public ::testing::Test {
 protected:

   std::vector<std::string_view> tempDirectories;

   void SetUp() override {
      tempDirectories = std::vector<std::string_view> {};
   }

   void TearDown() override {
      for (auto directory : tempDirectories) {
         if (fs::exists(directory)) {
            if (! fs::remove(directory)) {
               std::cout << std::format("Failed to remove {}", directory);
            }
         }
      }
   }

   std::string_view CreateTempFolder() {
      auto path = std::tmpnam(nullptr);
      if (fs::create_directory(path)) {
         tempDirectories.push_back(path);
         return path;
      } else {
         std::cout << std::format("Failed to create temp directory {}", path);
         return "";
      }
   }
};