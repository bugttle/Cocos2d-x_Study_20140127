#include "Scenes.h"

USING_NS_CC;

bool SampleNoiseScene::init()
{
    if (!SampleBaseScene::init()) {
        return false;
    }
    
    /* ノイズシェーダ */
    initScene("Noise", true, true);
    
    auto glProgram = GLProgram::createWithFilenames("shaders/noise.vert", "shaders/noise.frag");
    auto glProgramState = GLProgramState::getOrCreateWithGLProgram(glProgram);
    
    auto s = _sprite->getTexture()->getContentSizeInPixels();
    glProgramState->setUniformVec2("resolution", Vec2(s.width, s.height));
    _sprite->setGLProgramState(glProgramState);
    
    return true;
}

void SampleNoiseScene::backCallback(Ref* pSender)
{
    Director::getInstance()->replaceScene(SampleBlurScene::createScene());
}

void SampleNoiseScene::nextCallback(Ref* pSender)
{
    Director::getInstance()->replaceScene(SampleFlagScene::createScene());
}
