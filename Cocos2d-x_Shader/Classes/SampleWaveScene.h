#ifndef __SAMPLE_WAVE_SCENE_H__
#define __SAMPLE_WAVE_SCENE_H__

#include "SampleBaseScene.h"

class SampleWaveScene : public SampleBaseScene
{
public:
    CREATE_SCENE_FUNC(SampleWaveScene);
    CREATE_FUNC(SampleWaveScene);
    bool init() override;
    
private:
    bool _isWaving;
    void backCallback(cocos2d::Ref* pSender) override;
    void nextCallback(cocos2d::Ref* pSender) override;
};

#endif // __SAMPLE_WAVE_SCENE_H__
