#include "Scenes.h"

USING_NS_CC;

bool SampleCCSpriteFragRedScene::init()
{
    if (!SampleBaseScene::init()) {
        return false;
    }
    
    /* 標準のフラグメントシェーダを修正 */
    initScene("Fragment RED", true, true);
    
    auto glProgram = GLProgram::createWithFilenames("shaders/ccShader_PositionTextureColor_noMVP_ORIGINAL.vert",
                                                    "shaders/ccShader_PositionTextureColor_noMVP_RED.frag");
    _sprite->setGLProgram(glProgram);
    
    return true;
}

void SampleCCSpriteFragRedScene::backCallback(Ref* pSender)
{
    Director::getInstance()->replaceScene(SampleCCSpriteVertRedScene::createScene());
}

void SampleCCSpriteFragRedScene::nextCallback(Ref* pSender)
{
    Director::getInstance()->replaceScene(SampleGrayScaleScene::createScene());
}
