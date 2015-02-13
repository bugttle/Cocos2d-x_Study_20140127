#ifndef __SAMPLE6_SCENE_H__
#define __SAMPLE6_SCENE_H__

#include "SampleBaseScene.h"

class Sample6Scene : public SampleBaseScene
{
public:
    CREATE_SCENE_FUNC(Sample6Scene);
    CREATE_FUNC(Sample6Scene);
    bool init() override;
    
private:
    void backCallback(cocos2d::Ref* pSender) override;
    void nextCallback(cocos2d::Ref* pSender) override;
};

#endif // __SAMPLE6_SCENE_H__
