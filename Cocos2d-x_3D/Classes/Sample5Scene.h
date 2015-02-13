#ifndef __SAMPLE5_SCENE_H__
#define __SAMPLE5_SCENE_H__

#include "SampleBaseScene.h"

class Sample5Scene : public SampleBaseScene
{
public:
    CREATE_SCENE_FUNC(Sample5Scene);
    CREATE_FUNC(Sample5Scene);
    bool init() override;
    
private:
    void backCallback(cocos2d::Ref* pSender) override;
    void nextCallback(cocos2d::Ref* pSender) override;
};

#endif // __SAMPLE5_SCENE_H__
