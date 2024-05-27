#include "dl.hpp"

#include <dlfcn.h>
#include <stdexcept>

using namespace dl;

library::library(const char * lib) : handle(dlopen(lib, RTLD_LAZY)) {
    if(handle == NULL) throw std::runtime_error(dlerror());
}

library::library(const std::filesystem::path & lib) : library(lib.c_str()) {}

library::~library() {
    dlclose(handle);
}

void * library::get_label(const char * label) {
    dlerror();
    void * sym = dlsym(handle, label);
    if(sym == NULL) {
        const char * err = dlerror();
        if(dlerror == NULL) throw std::runtime_error(dlerror());
    }
    return sym;
}
