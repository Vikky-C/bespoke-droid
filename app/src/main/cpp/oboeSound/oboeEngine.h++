//
// Created by vikky on 5/16/25.
//

#ifndef BESPOKE_DROID_OBOEENGINE_H
#define BESPOKE_DROID_OBOEENGINE_H

#include <oboe/Oboe.h>
//#include "streamDataCallback.h++"
#include "streamBuilder.h++"
#include "streamDataCallback.h++"

namespace OboeEngine {

class oboeEngine {
public:



  bool start();
  bool stop();

private:
  std::shared_ptr<oboe::AudioStream> oboeAudioStream;
  oboe::Result result = StreamBuilder::oboeStreamBuilder.openStream(oboeAudioStream);

  if (result != oboe::Result::OK) {
    LOGE("Err: %s -- stream init failure", oboe::convertToText(result));
  }
};
} // namespace OboeEngine

#endif // BESPOKE_DROID_OBOEENGINE_H
