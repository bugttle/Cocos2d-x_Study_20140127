#include "Scenes.h"

USING_NS_CC;

bool Sample4Scene::init()
{
    if (!SampleBaseScene::init()) {
        return false;
    }
    
    initScene(true, true);
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    /* Multiple animations */
    
    _animationIndex = 0;
    
    _sprite = Sprite3D::create("res/orc.c3b");
    _sprite->setScale(20.0f);
    _sprite->setRotation3D(Vec3(0, 180, 0));
    addChild(_sprite);
    _sprite->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2-100));
    
    auto sp = Sprite3D::create("res/axe.c3b");
    _sprite->getAttachNode("Bip001 R Hand")->addChild(sp);
    
    auto listener = cocos2d::EventListenerTouchOneByOne::create();
    listener->onTouchBegan = [&](cocos2d::Touch* touch, cocos2d::Event* event) {
        auto p = touch->getLocation();
        auto rect = _sprite->getBoundingBox();
        
        if (rect.containsPoint(p)) {
            _sprite->stopAllActions();
            auto animation = Animation3D::create("res/orc.c3b");
            switch (_animationIndex) {
                case 0:
                {
                    auto animate = Animate3D::create(animation, 0, 2);
                    _sprite->runAction(RepeatForever::create(animate));
                }
                    break;
                case 1:
                {
                    auto animate = Animate3D::create(animation, 0, 2);
                    _sprite->runAction(RepeatForever::create(animate));
                    animate = Animate3D::create(animation, 3, 5);
                    _sprite->runAction(RepeatForever::create(animate));
                }
                    break;
                case 2:
                {
                    auto animate = Animate3D::create(animation, 0, 2);
                    auto time = animate->getTransitionTime();
                    // animate->setTransitionTime(); // 存在しない
                }
                    break;
            }
            if (++_animationIndex == 3) {
                _animationIndex = 0;
            }
            
            return true;
        }
        
        return false;
    };
    getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
    
    return true;
}

void Sample4Scene::backCallback(Ref* pSender)
{
    Director::getInstance()->replaceScene(Sample2Scene::createScene());
}

void Sample4Scene::nextCallback(Ref* pSender)
{
    Director::getInstance()->replaceScene(Sample5Scene::createScene());
}
