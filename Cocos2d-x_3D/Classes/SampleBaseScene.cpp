#include "SampleBaseScene.h"

USING_NS_CC;

void SampleBaseScene::initScene(bool backScene, bool nextScene)
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    // Menu
    Vector<MenuItem *> items;
    if (backScene) {
        items.pushBack(createBackMenuItem(visibleSize, origin));
    }
    if (nextScene) {
        items.pushBack(createNextMenuItem(visibleSize, origin));
    }
    auto menu = Menu::createWithArray(items);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
}

MenuItemImage *SampleBaseScene::createBackMenuItem(Size visibleSize, Vec2 origin) {
    auto item = createMenuItemImage(CC_CALLBACK_1(SampleBaseScene::backCallback, this));
    item->setPosition(Vec2(origin.x + visibleSize.width - item->getContentSize().width - 60,
                           origin.y + item->getContentSize().height/2));
    item->setRotation(180);
    return item;
}

MenuItemImage *SampleBaseScene::createNextMenuItem(Size visibleSize, Vec2 origin) {
    auto item = createMenuItemImage(CC_CALLBACK_1(SampleBaseScene::nextCallback, this));
    item->setPosition(Vec2(origin.x + visibleSize.width - item->getContentSize().width/2,
                           origin.y + item->getContentSize().height/2));
    return item;
}

MenuItemImage *SampleBaseScene::createMenuItemImage(const ccMenuCallback &callback)
{
    return MenuItemImage::create("arrow.png", "arrow.png", callback);
}

void SampleBaseScene::backCallback(Ref* pSender)
{
}

void SampleBaseScene::nextCallback(Ref* pSender)
{
}
