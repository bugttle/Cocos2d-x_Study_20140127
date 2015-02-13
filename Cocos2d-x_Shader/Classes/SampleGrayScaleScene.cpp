#include "Scenes.h"

USING_NS_CC;

bool SampleGrayScaleScene::init()
{
    if (!SampleBaseScene::init()) {
        return false;
    }
    
    /* グレイスケールシェーダ */
    initScene("GrayScale", true, true);
    
    auto glProgram = GLProgram::createWithFilenames("shaders/grayscale.vert", "shaders/grayscale.frag");
    _sprite->setGLProgram(glProgram);
    
    return true;
}

void SampleGrayScaleScene::backCallback(Ref* pSender)
{
    Director::getInstance()->replaceScene(SampleCCSpriteFragRedScene::createScene());
}

void SampleGrayScaleScene::nextCallback(Ref* pSender)
{
    Director::getInstance()->replaceScene(SampleBlurScene::createScene());
}
