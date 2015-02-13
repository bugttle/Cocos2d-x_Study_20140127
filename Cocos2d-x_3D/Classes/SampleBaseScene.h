#ifndef __SAMPLE_BASE_SCENE_H__
#define __SAMPLE_BASE_SCENE_H__

#include "cocos2d.h"

#define CREATE_SCENE_FUNC(__TYPE__) \
static cocos2d::Scene* createScene() \
{ \
    auto scene = cocos2d::Scene::create(); \
    auto layer = __TYPE__::create(); \
    scene->addChild(layer); \
    return scene; \
}

class SampleBaseScene : public cocos2d::Layer
{
protected:
    void initScene(bool backScene, bool nextScene);
    virtual void backCallback(cocos2d::Ref* pSender);
    virtual void nextCallback(cocos2d::Ref* pSender);
    
private:
    cocos2d::MenuItemImage *createBackMenuItem(cocos2d::Size visibleSize, cocos2d::Vec2 origin);
    cocos2d::MenuItemImage *createNextMenuItem(cocos2d::Size visibleSize, cocos2d::Vec2 origin);
    cocos2d::MenuItemImage *createMenuItemImage(const cocos2d::ccMenuCallback &callback);
};

#endif // __SAMPLE_BASE_SCENE_H__
