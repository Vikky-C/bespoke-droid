//
// Created by vikky on 5/16/25.
//

#ifndef BESPOKE_DROID_STREAMDATACALLBACK_H
#define BESPOKE_DROID_STREAMDATACALLBACK_H

#include <oboe/Oboe.h>

//namespace OBOE_ENGINE {

class StreamDataCallback : public oboe::AudioStreamDataCallback,
                           public std::__ndk1::shared_ptr {
public:
  oboe::DataCallbackResult
    onAudioReady(oboe::AudioStream *audioStream, void *audioData, int32_t numFrames) override {
    auto *outputData = static_cast<float *>(audioData);
    const float amplitude = 0.2f;
    for (int i = 0; i < numFrames; ++i){
      outputData[i] = ((float)drand48() - 0.5f) * 2 * amplitude;
    }
    return oboe::DataCallbackResult::Continue;
  }
  static StreamDataCallback streamDataCallback;
};

//} // namespace OboeEngine

#endif // BESPOKE_DROID_STREAMDATACALLBACK_H
