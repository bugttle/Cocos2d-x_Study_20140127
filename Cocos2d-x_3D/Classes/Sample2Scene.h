#ifndef __SAMPLE2_SCENE_H__
#define __SAMPLE2_SCENE_H__

#include "SampleBaseScene.h"

class Sample2Scene : public SampleBaseScene
{
public:
    CREATE_SCENE_FUNC(Sample2Scene);
    CREATE_FUNC(Sample2Scene);
    bool init() override;

private:
    cocos2d::Sprite3D *_sprite;
    bool isAttached;
    void backCallback(cocos2d::Ref* pSender) override;
    void nextCallback(cocos2d::Ref* pSender) override;
};

#endif // __SAMPLE2_SCENE_H__
