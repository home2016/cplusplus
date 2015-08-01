#include "NewScene5.h"
#include "HelloWorldScene.h"


USING_NS_CC;
USING_NS_CC_EXT;

Scene* NewScene5::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = NewScene5::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool NewScene5::init()
{



    //////////////////////////////
    // 1. super init first
	if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//eventos de teclado



		auto mni = MenuItemImage::create("bk.png","bk.png",CC_CALLBACK_1(NewScene5::btntouch, this));
	mni->setPosition(Point(origin.x + visibleSize.width - mni->getContentSize().width / 2, origin.y + mni->getContentSize().height / 2));
	auto mn = Menu::create(mni,NULL);
	mn->setPosition(Point::ZERO);
	this->addChild(mn);


	Menu* menu = Menu::create();
	
	const int MAX_ITEMS = 20;
	const int BASE_TAG = 100;
	const int HEIGHT = 40;

	char menuName[20];
	for (int i = 0; i < MAX_ITEMS; i++)
	{
		snprintf(menuName, sizeof(menuName), "ITEM %d", i);
		Node* menuLabel = LabelTTF::create(menuName, "Arial", 24);
		Size menuSize = menuLabel->getContentSize();
		
		MenuItem* menuItem = MenuItemLabel::create(menuLabel, CC_CALLBACK_1(NewScene5::menuItemCallback, this));
		menuItem->setTag(BASE_TAG+i);
		menuItem->setPosition(Vec2(0, (MAX_ITEMS-i)*HEIGHT - visibleSize.height/2));
		
		menu->addChild(menuItem);
	}

	

	Rect rect(0, -HEIGHT, 100, MAX_ITEMS * HEIGHT);
	

	// Setup scroll container
	Layer* scrollContainer = Layer::create();
	scrollContainer->addChild(menu);
	
	Size contentSize(rect.size.width-rect.origin.x, rect.size.height-rect.origin.y);
	scrollContainer->setContentSize(contentSize);
	
	
	// Setup scroll view
	extension::ScrollView* scrollView = extension::ScrollView::create(visibleSize, scrollContainer);
	scrollView->setBounceable(true);
	scrollView->setDirection(extension::ScrollView::Direction::VERTICAL);
	
	// Scroll to bottom
	scrollView->setContentOffset( Point::ZERO, true );
	
	this->addChild(scrollView);




	this->setKeyboardEnabled(true);




    return true;
}




	



 /**
     * @js NA
     * @lua NA
     */
    void NewScene5::scrollViewDidScroll(extension::ScrollView* view)
	{
	
	}
    /**
     * @js NA
     * @lua NA
     */
    void NewScene5::scrollViewDidZoom(extension::ScrollView* view)
	{
	
	
	}


/*

//abrir la conexion
 void NewScene5::onOpen(cocos2d::network::WebSocket* ws)
 {
	 CCLOG("on open");
 }
	//cuando se recibe la conexion o un mensaje del servidor
 void NewScene5::onMessage(cocos2d::network::WebSocket* ws, const cocos2d::network::WebSocket::Data& data)
 {
   CCLOG("on message");
 }
	// cuando se cierra la conexion
void NewScene5::onClose(cocos2d::network::WebSocket* ws)
{CCLOG("on close");}
	// cuando da error la conexion
 void NewScene5::onError(cocos2d::network::WebSocket* ws, const cocos2d::network::WebSocket::ErrorCode& error)
 {
 CCLOG("on error");
 }


 */

	void NewScene5::menuItemCallback(Ref* sender)
	{
	   MenuItem* menuItem = (MenuItem*) sender;
	   CCLOG("menu %d", menuItem->getTag());
		  
	}

 
	void NewScene5::onKeyReleased(EventKeyboard::KeyCode keycode, Event *event)
	{
	   
		if(keycode == EventKeyboard::KeyCode::KEY_BACK)
		{
				Director::getInstance()->replaceScene(TransitionFade::create(2, HelloWorld::createScene()));
		}
		  
			
		
	   
	
	}



		void NewScene5::btntouch(Ref *pSender)
		{
		  Director::getInstance()->replaceScene(TransitionFade::create(2, HelloWorld::createScene()));
		}
