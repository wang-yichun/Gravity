#include "TestScene.h"
#include <string>
#include "NDKHelper.h"

using namespace std;

TestScene::TestScene(void) {}

TestScene::~TestScene(void) {}

bool TestScene::init(void) {
	m_layer01 = CCLayer::create();
	this->addChild(m_layer01, 101, 1);
	m_colorLayer = CCLayerColor::create(ccc4(100,100,100,255));
	this->addChild(m_colorLayer, 11, 2);
	CCLayerColor * _temp_layer = CCLayerColor::create(ccc4(50,50,50,255));
	_temp_layer->setContentSize(CCSize(m_layer01->getContentSize().width-40, m_layer01->getContentSize().height-40));
	_temp_layer->setPosition(ccp(20,20));
	addChild(_temp_layer, 12, 3);
	//
	CCLabelTTF * _info_ttf = CCLabelTTF::create("Test scene - 测试","arial",22);
	_info_ttf->setHorizontalAlignment(kCCTextAlignmentLeft);
	_info_ttf->setDimensions(m_layer01->getContentSize());
	_info_ttf->setColor(ccc3(255,255,255));
	_info_ttf->setAnchorPoint(CCPointMake(0,1));
	CCSize _layer_size = m_layer01->getContentSize();
	_info_ttf->setPosition(CCPointMake(25,_layer_size.height-25));
	m_layer01->addChild(_info_ttf, 0, 1);

	stringstream ss_info;
	ss_info << "Test Scene:" << endl;
	ss_info << "Line 2." << endl;
	ss_info << "TargetPlatform=" << CCApplication::sharedApplication()->getTargetPlatform() << endl;
#ifdef JANSSON_ANDROID
	ss_info << "defined JANSSON_ANDROID" << endl;
#endif // JANSSON_ANDROID

	
	string resource_path = CCFileUtils::sharedFileUtils()->fullPathForFilename("mytest.db");
	ss_info << "ResourcePath=" << resource_path << endl;
	
	string writable_path = CCFileUtils::sharedFileUtils()->getWritablePath();
	ss_info << "WritablePath=" << writable_path << endl;

	try {
		string file_path = writable_path + "mytest.db";
		string file_path_bak = writable_path + "mytest_bak.db";

		Kompex::SQLiteDatabase *pDatabase = new Kompex::SQLiteDatabase(file_path, SQLITE_OPEN_READWRITE, NULL);
		Kompex::SQLiteStatement *pStmt = new Kompex::SQLiteStatement(pDatabase);

		pDatabase->MoveDatabaseToMemory();
		pDatabase->SaveDatabaseFromMemoryToFile(file_path_bak);

		//std::cout << "SQLite version: " << pDatabase->GetLibVersionNumber() << std::endl;
		CCLOGINFO("SQLite version: %d", pDatabase->GetLibVersionNumber());

		pStmt->Sql("select name as name, age as age from user_data");

		string _user_name;
		int _user_age;
		while (pStmt->FetchRow()) {
			_user_name = pStmt->GetColumnString("name");
			_user_age = pStmt->GetColumnInt("age");

			ss_info << " - " << _user_name << " " << _user_age << endl;
		}

		pStmt->FreeQuery();
		delete pStmt;
		delete pDatabase;

	} catch(Kompex::SQLiteException &exception) {
		//std::cerr << "\nException Occured" << std::endl;
		CCLOGERROR("\nException Occured: \n%s",exception.GetString().c_str());
		exception.Show();
	}

	
	_info_ttf->setString(ss_info.str().c_str());
	ss_info.str("");

	// button
	CCMenuItemFont::setFontName("Arial");
	CCMenuItemFont * item_1 = CCMenuItemFont::create("Call Java", this, menu_selector(TestScene::menuCallback));
	CCMenu * menu = CCMenu::create(item_1, NULL);
	menu->setColor(ccc3(255,255,255));
	menu->setPositionY(100);
	m_layer01->addChild(menu,10,2);

	// bmfont text
	CCLabelBMFont * label_1 = CCLabelBMFont::create("热爱游戏·热爱生活","hwzs_adv.fnt");
	//CCSize layer_size = m_layer01->getContentSize();
	//CCRect layer_rect = CCRectMake(0,0,layer_size.width,layer_size.height);
	//label_1->setPosition(CCPointMake(layer_rect.getMidX(),layer_rect.getMidY()));
	label_1->setPosition(ccp(m_layer01->getContentSize().width/2,m_layer01->getContentSize().height/2));
	m_layer01->addChild(label_1,20,3);

	return true;
}

void TestScene::menuCallback(CCObject* sender) {
	CCLOGINFO("TestScene::menuCallback sender:%u", sender->m_uID);

	// Register a selector in a global space
	// So that when our native environment will call the method with the string
	// It can respond to the selector
	// Note : Group name is there for ease of removing the selectors
	NDKHelper::AddSelector("HelloWorldSelectors",
		"SampleSelectorWithData",
		callfuncND_selector(TestScene::SampleSelectorWithData),
		this);

	// Making parameters for message to be passed to native language
	// For the ease of use, i am sending the method to be called name from C++
	CCDictionary* prms = CCDictionary::create();
	prms->setObject(CCString::create("SampleSelectorWithData"), "to_be_called");

	// Finally call the native method in current environment
	SendMessageWithParams(string("SampleSelectorWithData"), prms);
}

// A selector with data that will respond to us, when native language will call it
void TestScene::SampleSelectorWithData(CCNode *sender, void *data)
{
	CCLog("Called from native environment");

	if (data != NULL)
	{
		CCDictionary *convertedData = (CCDictionary *)data;

		CCDictionary *sampleDictionary = (CCDictionary *)convertedData->objectForKey("sample_dictionary");
		CCArray *sampleArray = (CCArray *)sampleDictionary->objectForKey("sample_array");

		CCLog("Printing Array in Dictionary");

		for (int i = 0; i < sampleArray->count(); i++)
		{
			CCString* str = (CCString *)sampleArray->objectAtIndex(i);
			CCLog(str->getCString());
		}

		CCString* sampleInteger = (CCString*)sampleDictionary->objectForKey("sample_integer");

		CCString* sampleFloat = (CCString*)sampleDictionary->objectForKey("sample_float");

		CCString* sampleString = (CCString*)sampleDictionary->objectForKey("sample_string");

		CCLog("Printing Integer : %d", sampleInteger->intValue());
		CCLog("Printing Float : %.3f", sampleFloat->floatValue());
		CCLog("Printing String : %s", sampleString->getCString());
	}
}