#include "Scenes.h"

USING_NS_CC;

bool SampleCCSpriteOriginalScene::init()
{
    if (!SampleBaseScene::init()) {
        return false;
    }
    
    /* 何もしていない普通のスクリーン */
    initScene("Hello World", false, true);
    
    return true;
}

void SampleCCSpriteOriginalScene::backCallback(Ref* pSender)
{
}

void SampleCCSpriteOriginalScene::nextCallback(Ref* pSender)
{
    Director::getInstance()->replaceScene(SampleCCSpriteVertRedScene::createScene());
}
