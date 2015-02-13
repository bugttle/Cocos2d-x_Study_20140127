#ifndef __SAMPLE8_SCENE_H__
#define __SAMPLE8_SCENE_H__

#include "SampleBaseScene.h"

class Sample8Scene : public SampleBaseScene
{
public:
    CREATE_SCENE_FUNC(Sample8Scene);
    CREATE_FUNC(Sample8Scene);
    bool init() override;
    
private:
    void backCallback(cocos2d::Ref* pSender) override;
    void nextCallback(cocos2d::Ref* pSender) override;
};

#endif // __SAMPLE8_SCENE_H__
