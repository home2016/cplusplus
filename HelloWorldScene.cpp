#include "HelloWorldScene.h"
#include "NewScene.h"
#include "NewScene2.h"
#include "NewScene3.h"
#include "NewScene4.h"
#include "NewScene5.h"
#include "NewScene6.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{

	i = 0;

    //////////////////////////////
    // 1. super init first
	if ( !LayerColor::initWithColor(Color4B::ORANGE) )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "b1.png",
                                           "b2.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
   
	auto label = Label::createWithTTF("Hola Mundo", "fonts/airstrike3d.ttf", 24);
    
	label->setColor(Color3B::BLACK);
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);

    
	auto menuItem = MenuItemImage::create("m1.png", "m2.png", CC_CALLBACK_1(HelloWorld::Menu, this));

	menuItem->setPosition(Point(origin.x + menuItem->getContentSize().width / 2, origin.y + visibleSize.height - menuItem->getContentSize().height));

	auto menuGral = Menu::create(menuItem,NULL);
	menuGral->setPosition(Point::ZERO);



	this->addChild(menuGral,1);
   

	this->setKeyboardEnabled(true);



    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}





void HelloWorld::Menu(Ref *pSender)
{

	addMenu();


}

void HelloWorld::addMenu()
{

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

    

	auto menuItem1 = MenuItemLabel::create(Label::createWithTTF(" Play ", "fonts/airstrikecond.ttf", 34), CC_CALLBACK_1(HelloWorld::btnNewScene, this));
	auto menuItem2 = MenuItemLabel::create(Label::createWithTTF(" Setting ", "fonts/airstrikehalf.ttf", 34), CC_CALLBACK_1(HelloWorld::btnNewScene2, this));
    auto menuItem3 = MenuItemLabel::create(Label::createWithTTF(" Records ", "fonts/airstrike3d.ttf", 34), CC_CALLBACK_1(HelloWorld::btnNewScene3, this));
	auto menuItem4 = MenuItemLabel::create(Label::createWithTTF(" Agregar Persona ", "fonts/airstrike3d.ttf", 34), CC_CALLBACK_1(HelloWorld::btnNewScene4, this));
    auto menuItem5 = MenuItemLabel::create(Label::createWithTTF(" ScrollView ", "fonts/airstrike3d.ttf", 34), CC_CALLBACK_1(HelloWorld::btnNewScene5, this));
	auto menuItem6 = MenuItemLabel::create(Label::createWithTTF(" PageView ", "fonts/airstrikecond.ttf", 34), CC_CALLBACK_1(HelloWorld::btnNewScene6, this));
 
	auto menuGral = Menu::create(menuItem1,menuItem2,menuItem3,menuItem4, menuItem5,menuItem6,NULL);
	menuGral->alignItemsVertically();


	auto sprite = Sprite::create("greenChild.jpg");

	sprite->setPosition(Point(origin.x + visibleSize.width / 2, origin.y + visibleSize.height + sprite->getContentSize().height));

	menuGral->setPosition(Point(sprite->getContentSize().width / 2, sprite->getContentSize().height / 2));

	sprite->addChild(menuGral);
    
	sprite->setName("menu");

	sprite->setOpacity(30);

	//MoveBy *accion2 ;

	
	if(i == 0)
	{


	  this->addChild(sprite,2);

	  MoveBy *accion2 = MoveBy::create(1, Point(0, - ((visibleSize.height / 2) + sprite->getContentSize().height)));
  
	  sprite->runAction(accion2);

	  i++;
	    
	}

	else if(i>0)
	{
		this->removeChildByName("menu");

		i = 0;
	}


}



void HelloWorld::btnNewScene(Ref *pSender)
{

	Director::getInstance()->replaceScene(TransitionSlideInR::create(2, NewScene::createScene()));

}



void HelloWorld::btnNewScene2(Ref *pSender)
{

	Director::getInstance()->replaceScene(TransitionFadeTR::create(2,NewScene2::createScene()));
}

void HelloWorld::btnNewScene3(Ref *pSender)
{
	Director::getInstance()->replaceScene(TransitionProgressInOut::create(2,NewScene3::createScene()));
}


void HelloWorld::btnNewScene4(Ref *pSender)
{
	Director::getInstance()->replaceScene(TransitionSplitRows::create(2,NewScene4::createScene()));
}

void HelloWorld::btnNewScene5(Ref *pSender)
{
	Director::getInstance()->replaceScene(TransitionSplitRows::create(2,NewScene5::createScene()));
}


void HelloWorld::btnNewScene6(Ref *pSender)
{
	Director::getInstance()->replaceScene(TransitionFlipAngular::create(1,NewScene6::createScene()));
}

void HelloWorld::onKeyReleased(EventKeyboard::KeyCode keycode, Event *event){


      if(keycode == EventKeyboard::KeyCode::KEY_MENU)
    {
		addMenu();
    }

	  else
		 
		  Director::getInstance()->end();

}
