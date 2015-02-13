#ifndef __SAMPLE1_SCENE_H__
#define __SAMPLE1_SCENE_H__

#include "SampleBaseScene.h"

class Sample1Scene : public SampleBaseScene
{
public:
    CREATE_SCENE_FUNC(Sample1Scene);
    CREATE_FUNC(Sample1Scene);
    bool init() override;
    
private:
    void backCallback(cocos2d::Ref* pSender) override;
    void nextCallback(cocos2d::Ref* pSender) override;
};

#endif // __SAMPLE1_SCENE_H__
