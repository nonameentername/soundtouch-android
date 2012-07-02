#ifndef SOUNDSTRETCH_H
#define SOUNDSTRETCH_H

#include <string>

class SoundStretch {
    public:
        SoundStretch();
        ~SoundStretch();

        void process(
            std::string inFilename,
            std::string outFilename,
            float tempoDelta,
            float pitchDelta,
            float rateDelta
        );
};

#endif
