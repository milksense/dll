#include "Header.h"

BOOL WINAPI MainThread(HMODULE hmodule) {
  MessageBoxA(0, ":)", "//", MB_OK);

  return true;
}

/* Note \\ WIP */
void *APIENTRY DllMain(HMODULE module, DWORD status, LPVOID LPReserved) {
  switch (status) {
    case DLL_PROCESS_ATTACH:
      DisableThreadLibraryCalls(module);
      CreateThread(0, 0, (LPTHREAD_START_ROUTINE)MainThread, 0, 0, 0);
      break;
    case DLL_PROCESS_DETACH:
      break;
  }
}