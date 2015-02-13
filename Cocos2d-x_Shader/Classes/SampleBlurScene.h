#ifndef __SAMPLE_BLUR_SCENE_H__
#define __SAMPLE_BLUR_SCENE_H__

#include "SampleBaseScene.h"

class SampleBlurScene : public SampleBaseScene
{
public:
    CREATE_SCENE_FUNC(SampleBlurScene);
    CREATE_FUNC(SampleBlurScene);
    bool init() override;
    
private:
    cocos2d::GLProgramState *_glOriginalProgramState;
    void backCallback(cocos2d::Ref* pSender) override;
    void nextCallback(cocos2d::Ref* pSender) override;
};

#endif // __SAMPLE_BLUR_SCENE_H__
