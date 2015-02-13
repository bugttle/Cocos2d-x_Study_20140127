#ifndef __SAMPLE_CC_SPRITE_VERT_RED_SCENE_H__
#define __SAMPLE_CC_SPRITE_VERT_RED_SCENE_H__

#include "SampleBaseScene.h"

class SampleCCSpriteVertRedScene : public SampleBaseScene
{
public:
    CREATE_SCENE_FUNC(SampleCCSpriteVertRedScene);
    CREATE_FUNC(SampleCCSpriteVertRedScene);
    bool init() override;
    
private:
    void backCallback(cocos2d::Ref* pSender) override;
    void nextCallback(cocos2d::Ref* pSender) override;
};

#endif // __SAMPLE_CC_SPRITE_VERT_RED_SCENE_H__
