#pragma GCC system_header
#ifndef ANDROID_FREE_MODE_H
#define ANDROID_FREE_MODE_H

#include <gui/BufferQueue.h>
#include <utils/Singleton.h>

namespace android {
// -----------------------------------------------------------------------------

class FreeModeDevice : public Singleton<FreeModeDevice> {
public:
    FreeModeDevice();
    ~FreeModeDevice();

    bool switchFreeMode(const bool& enable);
    bool freeMode(int* value, BufferQueueDefs::SlotsType* slots);

private:
    bool setScenario(const unsigned int& scenario);

    int mFd;
    unsigned int mSessionId;
    bool mIsFreeMode;
    mutable Mutex mLock;
};

// -----------------------------------------------------------------------------
}; // namespace android

#endif
