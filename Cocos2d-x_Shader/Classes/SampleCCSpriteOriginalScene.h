#ifndef __SAMPLE_CC_SPRITE_ORIGINAL_SCENE_H__
#define __SAMPLE_CC_SPRITE_ORIGINAL_SCENE_H__

#include "SampleBaseScene.h"

class SampleCCSpriteOriginalScene : public SampleBaseScene
{
public:
    CREATE_SCENE_FUNC(SampleCCSpriteOriginalScene);
    CREATE_FUNC(SampleCCSpriteOriginalScene);
    bool init() override;
    
private:
    void backCallback(cocos2d::Ref* pSender) override;
    void nextCallback(cocos2d::Ref* pSender) override;
};

#endif // __SAMPLE_CC_SPRITE_ORIGINAL_SCENE_H__
