/*
 * Copyright (C) 2014 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef INTRINSIC_BLUR_FILTER_H_
#define INTRINSIC_BLUR_FILTER_H_

#include "RenderScript.h"
#include "SimpleFilter.h"

namespace android {

struct IntrinsicBlurFilter : public SimpleFilter {
public:
    IntrinsicBlurFilter() : mBlurRadius(1.f) {};

    virtual status_t configure(const sp<AMessage> &msg);
    virtual status_t start();
    virtual void reset();
    virtual status_t setParameters(const sp<AMessage> &msg);
    virtual status_t processBuffers(
            const sp<ABuffer> &srcBuffer, const sp<ABuffer> &outBuffer);

protected:
    virtual ~IntrinsicBlurFilter() {};

private:
    AString mCacheDir;
    RSC::sp<RSC::RS> mRS;
    RSC::sp<RSC::Allocation> mAllocIn;
    RSC::sp<RSC::Allocation> mAllocOut;
    RSC::sp<RSC::ScriptIntrinsicBlur> mBlur;
    float mBlurRadius;
};

}   // namespace android

#endif  // INTRINSIC_BLUR_FILTER_H_
