#ifndef __SAMPLE7_SCENE_H__
#define __SAMPLE7_SCENE_H__

#include "SampleBaseScene.h"

class Sample7Scene : public SampleBaseScene
{
public:
    CREATE_SCENE_FUNC(Sample7Scene);
    CREATE_FUNC(Sample7Scene);
    bool init() override;
    
private:
    cocos2d::Sprite3D *_sprite;
    cocos2d::BaseLight *_light;
    int _lightIndex;
    void backCallback(cocos2d::Ref* pSender) override;
    void nextCallback(cocos2d::Ref* pSender) override;
};

#endif // __SAMPLE7_SCENE_H__
