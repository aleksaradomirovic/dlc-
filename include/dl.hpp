#pragma once

#include <filesystem>

namespace dl {


#if defined(__unix__)
using handle_t = void *;
#else
#error dynamic linking not supported for target
#endif

class library {
  private:
    handle_t handle;
    void * get_label(const char *);
  public:
    library(const char *);
    library(const std::filesystem::path &);
    ~library();

    library(const library &) = delete;
    library & operator=(const library &) = delete;

    template <class T>
    T & resolve(const char * label) {
        return *(T*)(get_label(label));
    }
};


}
