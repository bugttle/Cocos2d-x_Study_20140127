#ifndef __SAMPLE_GRAY_SCALE_SCENE_H__
#define __SAMPLE_GRAY_SCALE_SCENE_H__

#include "SampleBaseScene.h"

class SampleGrayScaleScene : public SampleBaseScene
{
public:
    CREATE_SCENE_FUNC(SampleGrayScaleScene);
    CREATE_FUNC(SampleGrayScaleScene);
    bool init() override;
    
private:
    void backCallback(cocos2d::Ref* pSender) override;
    void nextCallback(cocos2d::Ref* pSender) override;
};

#endif // __SAMPLE_GRAY_SCALE_SCENE_H__
