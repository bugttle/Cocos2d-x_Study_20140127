#include "Scenes.h"

USING_NS_CC;

bool Sample1Scene::init()
{
    if (!SampleBaseScene::init()) {
        return false;
    }
    
    initScene(false, true);
    
    /* Sprite3D */
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    auto sprite = Sprite3D::create("res/boss.c3b");
    sprite->setScale(20.f);
    sprite->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2));
    addChild(sprite);
    
    return true;
}

void Sample1Scene::backCallback(Ref* pSender)
{
}

void Sample1Scene::nextCallback(Ref* pSender)
{
    Director::getInstance()->replaceScene(Sample2Scene::createScene());
}
