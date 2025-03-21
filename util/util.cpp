#include <filesystem>
#include <sstream>
#include <string>
#include <vector>
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include "util.h"

int util::detour(void* addr, void* func, size_t size)
{
    constexpr int nop = 0x90;
    constexpr int jmp = 0xE9;
    auto dest = (unsigned(func) - unsigned(addr)) - 5;

    if (size < 5)
        return 0;

    unsigned long protect;
    if (!VirtualProtect(addr, size, PAGE_EXECUTE_READWRITE, &protect))
        return 0;

    std::memset(addr, nop, size);
    std::memset(addr, jmp, 1);
    __asm { inc addr }
    std::memcpy(addr, &dest, 4);
    __asm { dec addr }

    return VirtualProtect(addr, size, protect, &protect);
}

int util::read_memory(void* addr, void* dest, size_t size)
{
    if (size < 1)
        return 0;

    unsigned long protect;
    if (!VirtualProtect(addr, size, PAGE_EXECUTE_READWRITE, &protect))
        return 0;

    if (!ReadProcessMemory(GetCurrentProcess(), addr, dest, size, nullptr))
        return 0;

    return VirtualProtect(addr, size, protect, &protect);
}

int util::write_memory(void* addr, void* src, size_t size)
{
    if (size < 1)
        return 0;

    unsigned long protect;
    if (!VirtualProtect(addr, size, PAGE_EXECUTE_READWRITE, &protect))
        return 0;

    if (!WriteProcessMemory(GetCurrentProcess(), addr, src, size, nullptr))
        return 0;

    return VirtualProtect(addr, size, protect, &protect);
}

int util::write_memory(void* addr, int value, size_t size)
{
    if (size < 1)
        return 0;

    unsigned long protect;
    if (!VirtualProtect(addr, size, PAGE_EXECUTE_READWRITE, &protect))
        return 0;

    std::memset(addr, value, size);
    return VirtualProtect(addr, size, protect, &protect);
}

std::vector<std::string> util::split(const std::string& str, char sep, size_t count)
{
    if (!count)
        return {};

    std::vector<std::string> vec;
    std::istringstream iss(str);

    for (std::string str; std::getline(iss, str, sep); )
    {
        vec.push_back(str);
        if (vec.size() == count)
            break;
    }

    return vec;
}

std::vector<std::wstring> util::split(const std::wstring& str, wchar_t sep, size_t count)
{
    if (!count)
        return {};

    std::vector<std::wstring> vec;
    std::wistringstream iss(str);

    for (std::wstring str; std::getline(iss, str, sep); )
    {
        vec.push_back(str);
        if (vec.size() == count)
            break;
    }

    return vec;
}

std::string util::wcstos(const std::wstring& str)
{
    return std::filesystem::path(str).string();
}

std::wstring util::stowcs(const std::string& str)
{
    return std::filesystem::path(str).wstring();
}
