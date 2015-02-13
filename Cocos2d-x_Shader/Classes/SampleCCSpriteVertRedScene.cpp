#include "Scenes.h"

USING_NS_CC;

bool SampleCCSpriteVertRedScene::init()
{
    if (!SampleBaseScene::init()) {
        return false;
    }
    
    /* 標準の頂点シェーダを修正 */
    initScene("Vertex RED", true, true);
    
    auto glProgram = GLProgram::createWithFilenames("shaders/ccShader_PositionTextureColor_noMVP_RED.vert",
                                                    "shaders/ccShader_PositionTextureColor_noMVP_ORIGINAL.frag");
    _sprite->setGLProgram(glProgram);
    
    return true;
}

void SampleCCSpriteVertRedScene::backCallback(Ref* pSender)
{
    Director::getInstance()->replaceScene(SampleCCSpriteOriginalScene::createScene());
}

void SampleCCSpriteVertRedScene::nextCallback(Ref* pSender)
{
    Director::getInstance()->replaceScene(SampleCCSpriteFragRedScene::createScene());
}
