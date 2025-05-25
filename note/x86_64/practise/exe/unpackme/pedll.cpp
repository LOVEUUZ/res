#include <windows.h>

// 导出一个空函数，保证有导出表
extern "C" __declspec(dllexport) void DummyFunction() {}

BOOL APIENTRY DllMain(HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved) {
    switch (ul_reason_for_call) {
    case DLL_PROCESS_ATTACH:
        MessageBoxA(NULL, "DLL Loading", "hint", MB_OK | MB_ICONINFORMATION);
        break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}



//cl /LD pedll.cpp /link user32.lib 