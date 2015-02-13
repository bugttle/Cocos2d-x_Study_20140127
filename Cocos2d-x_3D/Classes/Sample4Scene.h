#ifndef __SAMPLE4_SCENE_H__
#define __SAMPLE4_SCENE_H__

#include "SampleBaseScene.h"

class Sample4Scene : public SampleBaseScene
{
public:
    CREATE_SCENE_FUNC(Sample4Scene);
    CREATE_FUNC(Sample4Scene);
    bool init() override;
    
private:
    cocos2d::Sprite3D *_sprite;
    int _animationIndex;
    void backCallback(cocos2d::Ref* pSender) override;
    void nextCallback(cocos2d::Ref* pSender) override;
};

#endif // __SAMPLE4_SCENE_H__
