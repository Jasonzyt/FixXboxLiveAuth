#include <Windows.h>

bool APIENTRY DllMain(HMODULE hModule, DWORD reasonForCall, LPVOID lpReserved) {
  switch (reasonForCall) {
  case DLL_PROCESS_ATTACH:
    break;
  case DLL_THREAD_ATTACH:
    break;
  case DLL_THREAD_DETACH:
    break;
  case DLL_PROCESS_DETACH:
    break;
  }
  return true;
}

#include <iostream>
#include <loader/Loader.h>

extern "C" __declspec(dllexport) void onPostInit() {
  std::cout << "FixXboxLiveAuth loaded! Author: Jasonzyt" << std::endl;
  std::string *authKey = (std::string *)dlsym(
      "?AuthServicePublicKey@TrustedKeys@@3V?$basic_string@DU?$char_traits@D@"
      "std@@V?$allocator@D@2@@std@@B");
  *authKey = "MHYwEAYHKoZIzj0CAQYFK4EEACIDYgAECRXueJeTDqNRRgJi/vlRufByu/"
             "2G0i2Ebt6YMar5QX/R0DIIyrJMcUpruK4QveTfJSTp3Shlq4Gk34cD/"
             "4GUWwkv0DVuzeuB+tXija7HBxii03NHDbPAD0AKnLr2wdAp";
}