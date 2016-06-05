#pragma once

#include <core/sdk/IDecoder.h>

#include <neaacdec.h>
#include <mp4ff.h>

class AacDecoder : public musik::core::audio::IDecoder {
    public:
        AacDecoder();
        ~AacDecoder();

        virtual void Destroy();
        virtual double SetPosition(double seconds);
        virtual bool GetBuffer(musik::core::audio::IBuffer *buffer);
        virtual bool Open(musik::core::io::IDataStream *stream);

    private:
        NeAACDecHandle decoder;
        mp4ff_t* decoderFile;
        mp4ff_callback_t decoderCallbacks;
        int audioTrackId;
        long totalSamples;
        unsigned long sampleRate;
        unsigned char channelCount;
        long decoderSampleId;
};
