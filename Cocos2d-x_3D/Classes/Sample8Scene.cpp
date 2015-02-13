#include "Scenes.h"

USING_NS_CC;

bool Sample8Scene::init()
{
    if (!SampleBaseScene::init()) {
        return false;
    }
    
    initScene(true, false);
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    /* BillBoard */
    
    auto billboard = BillBoard::create("HelloWorld.png", BillBoard::Mode::VIEW_POINT_ORIENTED);
    billboard->setScale(0.5f);
    billboard->setPosition3D(Vec3(-130.0f, 90.0f, 0.0f));
    billboard->setBlendFunc(BlendFunc::ALPHA_NON_PREMULTIPLIED);
    billboard->setCameraMask((unsigned short)CameraFlag::USER1);
    addChild(billboard);
    
    auto billboard2 = BillBoard::create("HelloWorld.png", BillBoard::Mode::VIEW_POINT_ORIENTED);
    billboard2->setScale(0.5f);
    billboard2->setPosition3D(Vec3(130.0f, 90.0f, 0.0f));
    billboard2->setBlendFunc(BlendFunc::ALPHA_NON_PREMULTIPLIED);
    billboard2->setCameraMask((unsigned short)CameraFlag::USER1);
    addChild(billboard2);
    
    auto billboard3 = BillBoard::create("HelloWorld.png", BillBoard::Mode::VIEW_PLANE_ORIENTED);
    billboard3->setScale(0.5f);
    billboard3->setPosition3D(Vec3(130.0f, -90.0f, 0.0f));
    billboard3->setBlendFunc(BlendFunc::ALPHA_NON_PREMULTIPLIED);
    billboard3->setCameraMask((unsigned short)CameraFlag::USER1);
    addChild(billboard3);
    
    // カメラ
    auto camera = Camera::createPerspective(60, (GLfloat)visibleSize.width/visibleSize.height, 1, 1000);
    camera->setCameraFlag(CameraFlag::USER1);
    // カメラのポジション
    camera->setPosition3D(Vec3(10, 10, 300));
    addChild(camera);
    
    return true;
}

void Sample8Scene::backCallback(Ref* pSender)
{
    Director::getInstance()->replaceScene(Sample7Scene::createScene());
}

void Sample8Scene::nextCallback(Ref* pSender)
{
}
