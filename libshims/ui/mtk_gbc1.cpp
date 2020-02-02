#include <ui/GraphicBufferMapper.h>
#include <ui/PixelFormat.h>
#include <ui/Rect.h>
#include <dlfcn.h>
#include <stdint.h>
#include <hardware/gralloc.h>
#include <iostream>
#include <string>

extern "C" {

    void _ZN7android13GraphicBufferC1Ejjij(void *instance, uint32_t inWidth, uint32_t inHeight, android::PixelFormat inFormat, uint32_t inUsage) {
        static void (*func)(void *instance, uint32_t, uint32_t, android::PixelFormat, uint32_t, std::string) = NULL;
        std::string my_requestorName("<Unknown>");

        func  = (void (*)(void *instance, uint32_t, uint32_t, android::PixelFormat, uint32_t, std::string))dlsym(RTLD_NEXT, "_ZN7android13GraphicBufferC1EjjijNSt3__112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE");

        func(instance, inWidth, inHeight, inFormat, inUsage, my_requestorName);
    }

    /*void _ZN7android5Fence4waitEi(int);

    void _ZN7android5Fence4waitEj(unsigned int timeout) {
        _ZN7android5Fence4waitEi(static_cast<int>(timeout));
    }*/

}
