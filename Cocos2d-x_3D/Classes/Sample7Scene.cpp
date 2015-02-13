#include "Scenes.h"

USING_NS_CC;

bool Sample7Scene::init()
{
    if (!SampleBaseScene::init()) {
        return false;
    }
    
    initScene(true, true);
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    /* Light */
    
    // オーク
    _sprite = Sprite3D::create("res/orc.c3b");
    _sprite->setScale(20.0f);
    _sprite->setRotation3D(Vec3(0, 180, 0));
    _sprite->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2-100));
    addChild(_sprite);
    
    _light = nullptr;
    _lightIndex = 0;
    
    auto listener = cocos2d::EventListenerTouchOneByOne::create();
    listener->onTouchBegan = [&](cocos2d::Touch* touch, cocos2d::Event* event) {
        auto p = touch->getLocation();
        auto rect = _sprite->getBoundingBox();
        
        if (rect.containsPoint(p)) {
            if (_light) {
                _light->removeFromParent();
            }
            switch (_lightIndex) {
                case 0:
                    _light = AmbientLight::create (Color3B::RED);
                    break;
                case 1:
                    // TODO: 正常に動作しない
                    _light = DirectionLight::create(Vec3(300.0f, 300.0f, 0.0f), Color3B::WHITE);
                    break;
                case 2:
                    // TODO: 正常に動作しない
                    _light = PointLight::create(_sprite->getPosition3D(), Color3B::WHITE, 10000.0f);
                    break;
                case 3:
                    _light = SpotLight::create(Vec3(-1.0f, -1.0f, 0.0f), _sprite->getPosition3D(), Color3B::WHITE, 0.0, 0.5, 10000.0f);
                    break;
            }
            addChild (_light);
            
            if (++_lightIndex == 4) {
                _lightIndex = 0;
            }
            
            return true;
        }
        
        return false;
    };
    getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
    
    return true;
}

void Sample7Scene::backCallback(Ref* pSender)
{
    Director::getInstance()->replaceScene(Sample6Scene::createScene());
}

void Sample7Scene::nextCallback(Ref* pSender)
{
    Director::getInstance()->replaceScene(Sample8Scene::createScene());
}
