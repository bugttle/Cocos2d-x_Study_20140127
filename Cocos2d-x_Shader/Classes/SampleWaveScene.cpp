#include "Scenes.h"

USING_NS_CC;

bool SampleWaveScene::init()
{
    if (!SampleBaseScene::init()) {
        return false;
    }
    
    /* ウェーブ */
    initScene("Wave", true, true);
    
    _isWaving = false;
    
    // Touch Event
    auto listener = cocos2d::EventListenerTouchOneByOne::create();
    listener->onTouchBegan = [&](cocos2d::Touch* touch, cocos2d::Event* event) {
        auto p = touch->getLocation();
        auto rect = _sprite->getBoundingBox();
        
        if (rect.containsPoint(p)) {
            if (!_isWaving) {
                _isWaving = true;
                // Sharder
                auto glProgram = GLProgram::createWithFilenames("shaders/wave.vert", "shaders/wave.frag");
                auto glProgramState = GLProgramState::getOrCreateWithGLProgram(glProgram);
                _sprite->setGLProgramState(glProgramState);
            }
            
            auto position = _sprite->convertTouchToNodeSpace(touch);
            auto touchPosition = Vec2(position.x / rect.size.width,
                                      (rect.size.height - position.y) / rect.size.height);
            _sprite->getGLProgramState()->setUniformVec2("touchPosition", touchPosition);
            return true;
        }
        
        return false;
    };
    getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
    
    return true;
}

void SampleWaveScene::backCallback(Ref* pSender)
{
    Director::getInstance()->replaceScene(SampleFlagScene::createScene());
}

void SampleWaveScene::nextCallback(Ref* pSender)
{
    Director::getInstance()->replaceScene(SampleGLSLSandBox1Scene::createScene());
}
