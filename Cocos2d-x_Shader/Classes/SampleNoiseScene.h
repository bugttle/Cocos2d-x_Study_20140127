#ifndef __SAMPLE_NOISE_SCENE_H__
#define __SAMPLE_NOISE_SCENE_H__

#include "SampleBaseScene.h"

class SampleNoiseScene : public SampleBaseScene
{
public:
    CREATE_SCENE_FUNC(SampleNoiseScene);
    CREATE_FUNC(SampleNoiseScene);
    bool init() override;
    
private:
    void backCallback(cocos2d::Ref* pSender) override;
    void nextCallback(cocos2d::Ref* pSender) override;
};

#endif // __SAMPLE_NOISE_SCENE_H__
