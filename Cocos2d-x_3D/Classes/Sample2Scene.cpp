#include "Scenes.h"

USING_NS_CC;

bool Sample2Scene::init()
{
    if (!SampleBaseScene::init()) {
        return false;
    }
    
    initScene(true, true);
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    /* Attaching 3D models to Sprite3D objects */
    
    _sprite = Sprite3D::create("res/orc.c3b");
    _sprite->setScale(20.0f);
    _sprite->setRotation3D(Vec3(0, 180, 0));
    addChild(_sprite);
    _sprite->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2-100));
    
    auto listener = cocos2d::EventListenerTouchOneByOne::create();
    listener->onTouchBegan = [&](cocos2d::Touch* touch, cocos2d::Event* event) {
        auto p = touch->getLocation();
        auto rect = _sprite->getBoundingBox();
        
        if (rect.containsPoint(p)) {
            if (!isAttached) {
                isAttached = true;
                auto sp = Sprite3D::create("res/axe.c3b");
                _sprite->getAttachNode("Bip001 R Hand")->addChild(sp);
            } else {
                _sprite->removeAllAttachNode();
                isAttached = false;
            }
            
            return true;
        }
        
        return false;
    };
    getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
    
    return true;
}

void Sample2Scene::backCallback(Ref* pSender)
{
    Director::getInstance()->replaceScene(Sample1Scene::createScene());
}

void Sample2Scene::nextCallback(Ref* pSender)
{
    Director::getInstance()->replaceScene(Sample3Scene::createScene());
}
