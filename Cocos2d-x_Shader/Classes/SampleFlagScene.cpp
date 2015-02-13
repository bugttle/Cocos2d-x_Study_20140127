#include "Scenes.h"

USING_NS_CC;

bool SampleFlagScene::init()
{
    if (!SampleBaseScene::init()) {
        return false;
    }
    
    /* はためきシェーダ */
    initScene("Flag", true, true);
    
    auto glProgram = GLProgram::createWithFilenames("shaders/wave_flag.vert", "shaders/wave_flag.frag");
    _glProgramState = GLProgramState::getOrCreateWithGLProgram(glProgram);
    _sprite->setGLProgramState(_glProgramState);
    
    return true;
}

void SampleFlagScene::backCallback(Ref* pSender)
{
    Director::getInstance()->replaceScene(SampleNoiseScene::createScene());
}

void SampleFlagScene::nextCallback(Ref* pSender)
{
    Director::getInstance()->replaceScene(SampleWaveScene::createScene());
}
