#include "Scenes.h"

USING_NS_CC;

bool Sample3Scene::init()
{
    if (!SampleBaseScene::init()) {
        return false;
    }
    
    initScene(true, true);
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    /* Swap 3D Model */
    
    _sprite = Sprite3D::create("res/ReskinGirl.c3b");
    _sprite->setScale(10.f);
    _sprite->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2-180));
    addChild(_sprite);
    
    auto listener = cocos2d::EventListenerTouchOneByOne::create();
    listener->onTouchBegan = [&](cocos2d::Touch* touch, cocos2d::Event* event) {
        auto p = touch->getLocation();
        auto rect = _sprite->getBoundingBox();
        
        if (rect.containsPoint(p)) {
            // display the first coat
            auto girlTop0 = _sprite->getMeshByName("Girl_UpperBody01");
            girlTop0->setVisible(!girlTop0->isVisible());
            
            auto girlTop1 = _sprite->getMeshByName("Girl_UpperBody02");
            girlTop1->setVisible(girlTop1->isVisible());
            
            return true;
        }
        
        return false;
    };
    getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
    
    return true;
}

void Sample3Scene::backCallback(Ref* pSender)
{
    Director::getInstance()->replaceScene(Sample2Scene::createScene());
}

void Sample3Scene::nextCallback(Ref* pSender)
{
    Director::getInstance()->replaceScene(Sample4Scene::createScene());
}
