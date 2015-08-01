#include "NewScene.h"
#include "HelloWorldScene.h"

USING_NS_CC;
USING_NS_CC_EXT;




Scene* NewScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = NewScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool NewScene::init()
{

   //////////////////////////////
    // 1. super init first
	if ( !LayerColor::initWithColor(Color4B::GREEN) )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

     
   //------------------ LABEL------------------------

	auto label = Label::createWithTTF("Nueva Escena", "fonts/airstrike3d.ttf", 24);
    
	label->setColor(Color3B::BLACK);
    
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

   
    this->addChild(label, 1);


	
	//---------- BOTON ---------------------

	Button *b1 = Button::create("b1.png","b2.png");

	b1->setPosition(Point(origin.x + visibleSize.width - b1->getContentSize().width / 2, origin.y + visibleSize.height - b1->getContentSize().height ));

	this->addChild(b1, 1);

	b1->addTouchEventListener(CC_CALLBACK_2(NewScene::touchEvent, this));



	auto b2 = Button::create("b1.png","b2.png");

	b2->setPosition(Point(origin.x + b2->getContentSize().width / 2, origin.y + visibleSize.height / 2));

	this->addChild(b2,1);

	b2->addTouchEventListener(CC_CALLBACK_2(NewScene::touchEvent2,this));



	
	



	//-----------CHECKBOX----------------



	auto checkbox1 = CheckBox::create("ui/3.png","ui/3.png","ui/1.png","ui/3.png","ui/3.png" );
	checkbox1->setPosition(Point(origin.x + checkbox1->getContentSize().width / 2, origin.y +  visibleSize.height - checkbox1->getContentSize().height));
	this->addChild(checkbox1,1);

	checkbox1->addEventListener(CC_CALLBACK_2(NewScene::selectedEvent, this));


	auto checkbox2 = CheckBox::create("ui/3.png","ui/3.png","ui/1.png","ui/3.png","ui/3.png" );
	checkbox2->setPosition(Point(origin.y + checkbox1->getContentSize().width / 2, checkbox1->getPositionY() - checkbox1->getContentSize().height));
	this->addChild(checkbox2,1);

	
	checkbox2->addEventListener(CC_CALLBACK_2(NewScene::selectedEvent, this));


	//-----------VOLVER------------------

	auto menuItem = MenuItemLabel::create(Label::createWithTTF("Volver", "fonts/airstrike3d.ttf", 34), CC_CALLBACK_1(NewScene::volver, this));

	menuItem->setPosition(Point(origin.x + visibleSize.width / 2, origin.y + menuItem->getContentSize().height / 2));
	menuItem->setColor(Color3B::BLACK);

	auto menuGral = Menu::create(menuItem,NULL);
	menuGral->setPosition(Point::ZERO);

	this->addChild(menuGral,2);




	this->setKeyboardEnabled(true);


    
    return true;
}



//-------------------EVENTOS DE BOTON---------------

//[EVENTO-1]
void NewScene::touchEvent(Ref *sender, Widget::TouchEventType type)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();


	auto l1 = Label::createWithTTF("Boton presionado","fonts/airstrikebold.ttf",100);
	l1->setColor(Color3B::BLUE);
	l1->setPosition(Point(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2));

	auto action = Sequence::create(FadeIn::create(2), FadeOut::create(1), NULL);


	switch (type)
	{
	case cocos2d::ui::Widget::TouchEventType::BEGAN:
		
		this->addChild(l1,1);

		l1->runAction(action);

		break;

	case cocos2d::ui::Widget::TouchEventType::MOVED:
		

		break;
	case cocos2d::ui::Widget::TouchEventType::ENDED:

		break;

	case cocos2d::ui::Widget::TouchEventType::CANCELED:
		
		break;
	default:
		break;
	}


}


//[EVENTO-2]
void NewScene::touchEvent2(Ref *pSender, Widget::TouchEventType type)
{

	switch (type)
	{
	case cocos2d::ui::Widget::TouchEventType::BEGAN:

		cantidad();
		
		break;
	case cocos2d::ui::Widget::TouchEventType::MOVED:
		break;
	case cocos2d::ui::Widget::TouchEventType::ENDED:
		break;
	case cocos2d::ui::Widget::TouchEventType::CANCELED:
		break;
	default:
		break;
	}


}


//-------------------EVENTOS DE CHECKBOX--------------------------


void NewScene::selectedEvent(Ref *pSender, ui::CheckBox::EventType type)
{
	Point origin = Director::getInstance()->getVisibleOrigin();
	Size visibleSize = Director::getInstance()->getVisibleSize();

	switch (type)
	{
	case cocos2d::ui::CheckBox::EventType::SELECTED:

		setScore(getScore() + 1);
		
		break;
	case cocos2d::ui::CheckBox::EventType::UNSELECTED:
		//log("checkbox deseleccionado");
		//i -=1;
		setScore(getScore() - 1);

		break;
	default:
		break;
	}



}




void NewScene::volver(Ref* pSender)
{

	Director::getInstance()->replaceScene(TransitionMoveInL::create(2,HelloWorld::createScene()));

}



	

void NewScene::cantidad()
{

	Point origin = Director::getInstance()->getVisibleOrigin();
	Size visibleSize = Director::getInstance()->getVisibleSize();

	auto action1 = Sequence::create(FadeIn::create(1), FadeOut::create(1), NULL);


	string ctd = "La cantidad es : "+ to_string(getScore());

	CCLOG("cantidad es: %s",  ctd.c_str());


	
	Label * l1 = Label::createWithTTF(ctd.c_str(),"fonts/airstrikecond.ttf",35); 

	l1->setPosition(Point(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2));

	l1->setColor(Color3B::MAGENTA);

	l1->runAction(action1);

	this->addChild(l1,1);

}

void NewScene::onKeyReleased(EventKeyboard::KeyCode keycode, Event *event)
{

	Director::getInstance()->replaceScene(TransitionMoveInL::create(2,HelloWorld::createScene()));


}
