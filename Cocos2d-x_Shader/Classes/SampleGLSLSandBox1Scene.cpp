#include "Scenes.h"

USING_NS_CC;

bool SampleGLSLSandBox1Scene::init()
{
    if (!SampleBaseScene::init()) {
        return false;
    }
    
    /* GLSL Sandboxからの引用 */
    initScene("GLSL Sandbox 1", true, false);
    
    auto glProgram = GLProgram::createWithFilenames("shaders/glslsandbox1.vert", "shaders/glslsandbox1.frag");
    auto glProgramState = GLProgramState::getOrCreateWithGLProgram(glProgram);
    
    auto s = _sprite->getTexture()->getContentSizeInPixels();
    glProgramState->setUniformVec2("resolution", Vec2(s.width, s.height));
    _sprite->setGLProgramState(glProgramState);
    
    return true;
}

void SampleGLSLSandBox1Scene::backCallback(Ref* pSender)
{
    Director::getInstance()->replaceScene(SampleWaveScene::createScene());
}

void SampleGLSLSandBox1Scene::nextCallback(Ref* pSender)
{
}
