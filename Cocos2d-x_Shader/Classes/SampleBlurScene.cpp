#include "Scenes.h"

USING_NS_CC;

bool SampleBlurScene::init()
{
    if (!SampleBaseScene::init()) {
        return false;
    }
    
    /* ブラーシェーダ */
    initScene("Blur", true, true);
    
    // Touch Event
    auto listener = cocos2d::EventListenerTouchOneByOne::create();
    listener->onTouchBegan = [&](cocos2d::Touch* touch, cocos2d::Event* event) {
        auto p = touch->getLocation();
        auto rect = _sprite->getBoundingBox();
        
        if (rect.containsPoint(p)) {
            if (!_glOriginalProgramState) {
                _glOriginalProgramState = _sprite->getGLProgramState();
                
                auto glProgram = GLProgram::createWithFilenames("shaders/gaussian_blur.vert", "shaders/gaussian_blur.frag");
                auto glProgramState = GLProgramState::getOrCreateWithGLProgram(glProgram);
                glProgramState->setUniformFloat("u_rate", 1.5f);
                _sprite->setGLProgramState(glProgramState);
            } else {
                _sprite->setGLProgramState(_glOriginalProgramState);
                _glOriginalProgramState = nullptr;
            }
            
            return true;
        }
        
        return false;
    };
    getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
    
    // Animation
    _sprite->runAction(
                       RepeatForever::create(
                                             Sequence::create(
                                                              MoveBy::create(0.25, Vec2(200, 0)),
                                                              MoveBy::create(0.5, Vec2(-400, 0)),
                                                              MoveBy::create(0.25, Vec2(200, 0)),
                                                              NULL)));
    
    return true;
}

void SampleBlurScene::backCallback(Ref* pSender)
{
    Director::getInstance()->replaceScene(SampleGrayScaleScene::createScene());
}

void SampleBlurScene::nextCallback(Ref* pSender)
{
    Director::getInstance()->replaceScene(SampleNoiseScene::createScene());
}
