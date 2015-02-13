#ifndef __SAMPLE3_SCENE_H__
#define __SAMPLE3_SCENE_H__

#include "SampleBaseScene.h"

class Sample3Scene : public SampleBaseScene
{
public:
    CREATE_SCENE_FUNC(Sample3Scene);
    CREATE_FUNC(Sample3Scene);
    bool init() override;
    
private:
    cocos2d::Sprite3D *_sprite;
    void backCallback(cocos2d::Ref* pSender) override;
    void nextCallback(cocos2d::Ref* pSender) override;
};

#endif // __SAMPLE3_SCENE_H__
