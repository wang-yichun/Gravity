#include "AppDelegate.h"
#include "AppMacros.h"
#include "HelloWorldScene.h"
#include "TestScene.h"
#include "CoreScene.h"
#include "YFile.h"
#include "CreaterConfig.h"

#if PROGRAM_MODE == PROGRAM_MODE_CREATER
#include "MapCreateScene.h"
#endif

USING_NS_CC;
using namespace ytools;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    CCDirector* pDirector = CCDirector::sharedDirector();
    CCEGLView* pEGLView = CCEGLView::sharedOpenGLView();

	pDirector->setOpenGLView(pEGLView);
	

    // turn on display FPS
    pDirector->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    pDirector->setAnimationInterval(1.0 / 60);

	// init sprite frame cache
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("art_group_01.plist");
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("CSProj/CSProj0.plist");

	// init database
	bool _has_file;
	_has_file = YFile::HasFileInWritablePath("mytest.db");
	CCLOGINFO("has_file: %s", _has_file?"Yes":"No");
	YFile::DeleteFileInWritablePath("mytest.db");
	_has_file = YFile::HasFileInWritablePath("mytest.db");
	CCLOGINFO("has_file: %s", _has_file?"Yes":"No");
	YFile::CopyFileToWritablePath("mytest.db");
	_has_file = YFile::HasFileInWritablePath("mytest.db");
	CCLOGINFO("has_file: %s", _has_file?"Yes":"No");

    // create a scene. it's an autorelease object
    // CCScene *pScene = HelloWorld::scene();
	// TestScene *pScene = TestScene::create();

#if PROGRAM_MODE == PROGRAM_MODE_GAME
	pEGLView->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, kResolutionShowAll);
	CoreScene *pScene = CoreScene::create();
#elif PROGRAM_MODE == PROGRAM_MODE_CREATER
	pEGLView -> setDesignResolutionSize(1280, 900, kResolutionShowAll); 
	CCScene *pScene = MapCreate::scene();
#else 
	CCAssert(false, "PROGRAM_MODE Unexpect.");
#endif

    // run
    pDirector->runWithScene(pScene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    CCDirector::sharedDirector()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    CCDirector::sharedDirector()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}