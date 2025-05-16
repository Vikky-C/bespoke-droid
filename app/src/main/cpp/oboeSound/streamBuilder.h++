//
// Created by vikky on 5/16/25.
//

#ifndef BESPOKE_DROID_STREAMBUILDER_H
#define BESPOKE_DROID_STREAMBUILDER_H

#include <oboe/Oboe.h>
#include "streamDataCallback.h++"

class StreamBuilder {
public:
  explicit StreamBuilder(const oboe::AudioStreamBuilder& oboeStreamBuilder);

  static oboe::AudioStreamBuilder oboeStreamBuilder;
};
oboe::AudioStreamBuilder oboeStreamBuilder;
StreamBuilder::StreamBuilder(const oboe::AudioStreamBuilder& oboeStreamBuilder) {
  //oboeStreamBuilder(oboe::AudioStreamBuilder oboeStreamBuilder)
      : oboeStreamBuilder(oboeStreamBuilder) {
    oboeStreamBuilder.setPerformanceMode(oboe::PerformanceMode::LowLatency)
        ->setSharingMode(oboe::SharingMode::Exclusive)
        ->setDataCallback(StreamDataCallback::streamDataCallback);
    // oboeStreamBuilder.setDataCallback(&StreamDataCallback::streamDataCallback)
  }
}

#endif // BESPOKE_DROID_STREAMBUILDER_H