#include <iostream>
#include <string>
#include <dlfcn.h>
#include "include/dobby.h"

bool hook(std::string token) {
    std::cout << "[hook] Token received: " << token << std::endl;
    return true;
}

__attribute__((constructor)) static void ctor() {
    printf("[info] Dobby hook initializing...\n");

    // find symbol using dlsym instead
    void *symbol_address = dlsym(RTLD_DEFAULT, "_Z6verifyNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE");
    printf("[info] Symbol Address: %p\n", symbol_address);

    if (symbol_address == NULL) {
        printf("[error] Symbol not found: %s\n", dlerror());
        return;
    }

    // do hook
    int ret = DobbyHook(symbol_address, (void *)hook, NULL);
    printf("[info] DobbyHook returned: %d\n", ret);
}
