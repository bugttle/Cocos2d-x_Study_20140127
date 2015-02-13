#ifndef __SAMPLE_GLSL_SAND_BOX1_SCENE_H__
#define __SAMPLE_GLSL_SAND_BOX1_SCENE_H__

#include "SampleBaseScene.h"

class SampleGLSLSandBox1Scene : public SampleBaseScene
{
public:
    CREATE_SCENE_FUNC(SampleGLSLSandBox1Scene);
    CREATE_FUNC(SampleGLSLSandBox1Scene);
    bool init() override;
    
private:
    void backCallback(cocos2d::Ref* pSender) override;
    void nextCallback(cocos2d::Ref* pSender) override;
};

#endif // __SAMPLE_GLSL_SAND_BOX1_SCENE_H__
