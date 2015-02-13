#include "Scenes.h"

USING_NS_CC;

bool Sample6Scene::init()
{
    if (!SampleBaseScene::init()) {
        return false;
    }
    
    initScene(true, true);
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    /* Camera */
    
    // オーク
    auto sprite = Sprite3D::create("res/orc.c3b");
    sprite->setScale(20.0f);
    sprite->setRotation3D(Vec3(0, 180, 0));
    sprite->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2-100));
    sprite->setCameraMask((unsigned short)CameraFlag::USER1);
    addChild(sprite);
    
    // カメラ
    auto camera = Camera::createPerspective(60, (GLfloat)visibleSize.width/visibleSize.height, 1, 1000);
    camera->setCameraFlag(CameraFlag::USER1);
    // カメラのポジション
    camera->setPosition3D(Vec3(0, 100, 100));
    camera->lookAt(sprite->getPosition3D(), Vec3(0, 0, 1));
    addChild(camera);
    
    return true;
}

void Sample6Scene::backCallback(Ref* pSender)
{
    Director::getInstance()->replaceScene(Sample5Scene::createScene());
}

void Sample6Scene::nextCallback(Ref* pSender)
{
    Director::getInstance()->replaceScene(Sample7Scene::createScene());
}
