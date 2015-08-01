#include "NewScene6.h"
#include "HelloWorldScene.h"

USING_NS_CC;
USING_NS_CC_EXT;




Scene* NewScene6::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = NewScene6::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool NewScene6::init()
{

   //////////////////////////////
    // 1. super init first
	if ( !LayerColor::initWithColor(Color4B::WHITE) )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

     

	Button *btn = Button::create("b1.png","snd.png");
	ImageView *imv = ImageView::create("HelloWorld.png");





	Layout *ly = Layout::create();
	ly->setLayoutType(Layout::Type::HORIZONTAL);
	ly->setPosition(Vec2(400, 300));
	ly->addChild(btn);
	ly->addChild(imv);

	
	this->addChild(ly);


	






 
	auto mni = MenuItemImage::create("bk.png","bk.png",CC_CALLBACK_1(NewScene6::btntouch, this));
	mni->setPosition(Point(origin.x + visibleSize.width - mni->getContentSize().width / 2, origin.y + mni->getContentSize().height/ 2));
	auto mn = Menu::create(mni,NULL);
	mn->setPosition(Point::ZERO);
	this->addChild(mn);

	

	setKeyboardEnabled(true);
    
    return true;
}




void NewScene6::onKeyReleased(EventKeyboard::KeyCode keycode, Event *event)
{

	if(keycode == EventKeyboard::KeyCode::KEY_BAR)
	{
		Director::getInstance()->replaceScene(TransitionFlipX::create(2, HelloWorld::createScene()));
	}
   
}

void NewScene6::btntouch(Ref *pSender)
{
  
	Director::getInstance()->replaceScene(TransitionFlipX::create(2, HelloWorld::createScene()));

}
