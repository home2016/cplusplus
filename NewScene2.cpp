#include "NewScene2.h"
#include "HelloWorldScene.h"


USING_NS_CC;
USING_NS_CC_EXT;

Scene* NewScene2::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = NewScene2::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool NewScene2::init()
{



    //////////////////////////////
    // 1. super init first
	if ( !LayerColor::initWithColor(Color4B::WHITE) )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();


/*
	auto dispatcher = Director::getInstance()->getEventDispatcher();
	auto listener1 = EventListenerTouchOneByOne::create();
	listener1->setSwallowTouches(true);
	*/
	/*
	listener1->onTouchBegan = CC_CALLBACK_2(NewScene2::onTouchBegan, this);
	listener1->onTouchMoved = CC_CALLBACK_2(NewScene2::onTouchMoved,this);
	listener1->onTouchEnded = CC_CALLBACK_2(NewScene2::onTouchEnded,this):
	dispatcher->addEventListenerWithSceneGraphPriority(listener1,this);
	*/


	

	//------------- BTN...

	auto btn1 = Button::create("b1.png","b2.png");
	btn1->setPosition(Point(origin.x + btn1->getContentSize().width / 2, origin.y + visibleSize.height / 2));
	this->addChild(btn1,1);
	btn1->addTouchEventListener(CC_CALLBACK_2(NewScene2::touchEvent, this));

	


	// -----------------btn2---


	auto btn2 = MenuItemImage::create("b1.png","b2.png", CC_CALLBACK_1(NewScene2::evento,this));
	btn2->setPosition(Point(origin.x + visibleSize.width - btn2->getContentSize().width, origin.y + visibleSize.height / 2));
	auto btnGral2 = Menu::create(btn2,NULL);
	btnGral2->setPosition(Point::ZERO);
	this->addChild(btnGral2,2);



	//-------------------EDIT BOX 1-------------------

	EditBox *ebx = EditBox::create(Size(700,60), Scale9Sprite::create("ebx.png"));
	ebx->setPosition(Point(origin.x + visibleSize.width / 2, origin.y + visibleSize.height - ebx->getContentSize().height));
	ebx->setFontSize(25);
	ebx->setFontColor(Color3B::RED);
	ebx->setFontName("American Typewriter");
	ebx->setPlaceHolder("Nombre :");
	ebx->setPlaceholderFontColor(Color3B::GRAY);
	ebx->setMaxLength(8);
	ebx->setReturnType(EditBox::KeyboardReturnType::DONE);
	ebx->setDelegate(this);
	
	this->addChild(ebx,1);


	//-------------------EDIT BOX 2-------------------

	EditBox *ebx1 = EditBox::create(Size(700,60), Scale9Sprite::create("ebx1.png"));
	ebx1->setPosition(Point(origin.x + visibleSize.width / 2, ebx->getPositionY() - ebx->getContentSize().height - 10));
	ebx1->setFontSize(25);
	ebx1->setFontColor(Color3B::RED);
	ebx1->setFontName("Verdana");
	ebx1->setPlaceHolder("Password :");
	ebx1->setPlaceholderFontColor(Color3B::GRAY);
	ebx1->setMaxLength(8);
	ebx1->setInputFlag(EditBox::InputFlag::PASSWORD);
	ebx1->setInputMode(EditBox::InputMode::SINGLE_LINE);
	ebx1->setReturnType(EditBox::KeyboardReturnType::GO);
	
	

	this->addChild(ebx1,1);

	//-------------------EDIT BOX 3-------------------

	EditBox *ebx2 = EditBox::create(Size(700,60), Scale9Sprite::create("ebx1.png"));
	ebx2->setPosition(Point(origin.x + visibleSize.width / 2, ebx1->getPositionY() - ebx1->getContentSize().height - 10));
	ebx2->setFontSize(25);
	ebx2->setFontColor(Color3B::RED);
	ebx2->setFontName("Verdana");
	ebx2->setPlaceHolder("Email :");
	ebx2->setPlaceholderFontColor(Color3B::GRAY);
	ebx2->setMaxLength(8);
	ebx2->setInputMode(EditBox::InputMode::EMAIL_ADDRESS);

	ebx2->setReturnType(EditBox::KeyboardReturnType::SEARCH);

	

	this->addChild(ebx2,1);


	//-------------------EDIT BOX 4-------------------

	EditBox *ebx3 = EditBox::create(Size(700,60), Scale9Sprite::create("ebx1.png"));
	ebx3->setPosition(Point(origin.x + visibleSize.width / 2, ebx2->getPositionY() - ebx2->getContentSize().height - 10));
	ebx3->setFontSize(25);
	ebx3->setFontColor(Color3B::RED);
	ebx3->setFontName("Verdana");
	ebx3->setPlaceHolder("Edad :");
	ebx3->setPlaceholderFontColor(Color3B::GRAY);
	ebx3->setMaxLength(8);
	ebx3->setInputMode(EditBox::InputMode::NUMERIC);

	ebx3->setReturnType(EditBox::KeyboardReturnType::SEND);

	

	this->addChild(ebx3,1);


		//-------------------EDIT BOX 5-------------------

	EditBox *ebx4 = EditBox::create(Size(700,60), Scale9Sprite::create("ebx1.png"));
	ebx4->setPosition(Point(origin.x + visibleSize.width / 2, ebx3->getPositionY() - ebx3->getContentSize().height - 10));
	ebx4->setFontSize(25);
	ebx4->setFontColor(Color3B::RED);
	ebx4->setFontName("Verdana");
	ebx4->setPlaceHolder("NUMERO DE TELEFONO :");
	ebx4->setPlaceholderFontColor(Color3B::GRAY);
	ebx4->setMaxLength(8);
	ebx4->setInputMode(EditBox::InputMode::PHONE_NUMBER);

	ebx4->setReturnType(EditBox::KeyboardReturnType::SEND);

	

	this->addChild(ebx4,1);



	//-------------------EDIT BOX 6-------------------

	EditBox *ebx5 = EditBox::create(Size(700,60), Scale9Sprite::create("ebx1.png"));
	ebx5->setPosition(Point(origin.x + visibleSize.width / 2, ebx4->getPositionY() - ebx4->getContentSize().height - 10));
	ebx5->setFontSize(25);
	ebx5->setFontColor(Color3B::RED);
	ebx5->setFontName("Verdana");
	ebx5->setPlaceHolder("URL :");
	ebx5->setPlaceholderFontColor(Color3B::GRAY);
	ebx5->setMaxLength(8);
	ebx5->setInputMode(EditBox::InputMode::URL);

	ebx5->setReturnType(EditBox::KeyboardReturnType::SEND);

	

	this->addChild(ebx5,1);


	//-------------------EDIT BOX 7-------------------

	EditBox *ebx6 = EditBox::create(Size(700,60), Scale9Sprite::create("ebx1.png"));
	ebx6->setPosition(Point(origin.x + visibleSize.width / 2, ebx5->getPositionY() - ebx5->getContentSize().height - 10));
	ebx6->setFontSize(25);
	ebx6->setFontColor(Color3B::RED);
	ebx6->setFontName("Verdana");
	ebx6->setPlaceHolder("any :");
	ebx6->setPlaceholderFontColor(Color3B::GRAY);
	ebx6->setMaxLength(8);
	ebx6->setInputMode(EditBox::InputMode::ANY);

	ebx6->setReturnType(EditBox::KeyboardReturnType::SEND);
	
	

	this->addChild(ebx6,1);

	//-------------------EDIT BOX 7-------------------

	EditBox *ebx7 = EditBox::create(Size(700,60), Scale9Sprite::create("ebx1.png"));
	ebx7->setPosition(Point(origin.x + visibleSize.width / 2, ebx6->getPositionY() - ebx6->getContentSize().height - 10));
	ebx7->setFontSize(25);
	ebx7->setFontColor(Color3B::RED);
	ebx7->setFontName("Verdana");
	ebx7->setPlaceHolder("DECIMAL :");
	ebx7->setPlaceholderFontColor(Color3B::GRAY);
	ebx7->setMaxLength(8);
	ebx7->setInputMode(EditBox::InputMode::DECIMAL);

	ebx7->setReturnType(EditBox::KeyboardReturnType::DEFAULT);
	
	

	this->addChild(ebx7,1);

		//-----------VOLVER------------------

	auto menuItem = MenuItemLabel::create(Label::createWithTTF("Volver", "fonts/airstrike3d.ttf", 34), CC_CALLBACK_1(NewScene2::volver, this));
	menuItem->setPosition(Point(origin.x + visibleSize.width / 2, origin.y + menuItem->getContentSize().height / 2));
	menuItem->setColor(Color3B::BLACK);
	auto menuGral = Menu::create(menuItem,NULL);
	menuGral->setPosition(Point::ZERO);
	this->addChild(menuGral,2);


	this->setKeyboardEnabled(true);

    return true;
}




void NewScene2::volver(Ref* pSender)
{

	Director::getInstance()->replaceScene(TransitionMoveInL::create(2,HelloWorld::createScene()));

}


void NewScene2::onTouchEnded(Touch *touches, Event *event){}

void NewScene2::onTouchMoved(Touch *touches, Event *event){}

bool NewScene2::onTouchBegan(Touch *touches, Event *event){


	Point origin = Director::getInstance()->getVisibleOrigin();
	Size visibleSize = Director::getInstance()->getVisibleSize();


	auto action1 = Sequence::create(FadeIn::create(2), FadeOut::create(1), NULL);


	LabelTTF *l2 = LabelTTF::create("toquen en la pantalla","Arial",45);

	l2->setPosition(Point(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2 ));

	l2->setColor(Color3B::BLACK);

	
	this->addChild(l2,1);
    
		
	l2->runAction(action1);



	return true;
}




void NewScene2::touchEvent(Ref *pSender, Widget::TouchEventType type)
{
		Point origin = Director::getInstance()->getVisibleOrigin();
		Size visibleSize = Director::getInstance()->getVisibleSize();

		auto action1 = Sequence::create(FadeIn::create(2), FadeOut::create(2), NULL);


		LabelTTF *l1 = LabelTTF::create("btn con lib ui!","Arial",40);
		l1->setColor(Color3B::BLACK);

		l1->setPosition(Point(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2));

		

	switch (type)
	{
	case cocos2d::ui::Widget::TouchEventType::BEGAN:


		this->addChild(l1,1);
		l1->runAction(action1);

		
		

		break;
	case cocos2d::ui::Widget::TouchEventType::MOVED:
		break;
	case cocos2d::ui::Widget::TouchEventType::ENDED:
		
		this->addChild(l1,1);


		break;
	case cocos2d::ui::Widget::TouchEventType::CANCELED:
		break;
	default:
		break;
	}

}


void NewScene2::evento(Ref *pSender)
{
	Point origin = Director::getInstance()->getVisibleOrigin();
	Size visibleSize = Director::getInstance()->getVisibleSize();

	auto action = Sequence::create(FadeIn::create(3), FadeOut::create(3), NULL);

	
	if(getValue() != ""){CCLOG("valor llegado al metodo evento %s", getValue().c_str());}

	else if(getValue() == "")
	{CCLOG("EL VALOR NO HA LLEGADO AL METODO...");}

	LabelTTF *l1 = LabelTTF::create(getValue().c_str(),"Arial",32);

	l1->setPosition(Point(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2));
	l1->setColor(Color3B::BLACK);
	l1->runAction(action);

	this->addChild(l1,2);

}




 /**
     * This method is called when an edit box gains focus after keyboard is shown.
     * @param editBox The edit box object that generated the event.
     * @js NA
     * @lua NA
     */
     void NewScene2::editBoxEditingDidBegin(EditBox* editBox)
	 {
		 CCLOG("Empezo");
	 }
    
    /**
     * This method is called when an edit box loses focus after keyboard is hidden.
     * @param editBox The edit box object that generated the event.
     * @js NA
     * @lua NA
     */
	 void NewScene2::editBoxEditingDidEnd(EditBox* editBox)
	 {
		 CCLOG("End");
	 }
    
    /**
     * This method is called when the edit box text was changed.
     * @param editBox The edit box object that generated the event.
     * @param text The new text.
     * @js NA
     * @lua NA
     */
	 void NewScene2::editBoxTextChanged(EditBox* editBox, const std::string& text)
	 {

		// Point origin = Director::getInstance()->getVisibleOrigin();
		// Size visibleSize = Director::getInstance()->getVisibleSize();

		// LabelTTF *l1 = LabelTTF::create(text.c_str(), "Arial", 34);
		 //l1->setPosition(Point(origin.x + visibleSize.width / 2, origin.y + visibleSize.height /2));
		 //l1->setColor(Color3B::BLACK);
		 //this->addChild(l1,3);

		 CCLOG("El texto es: %s", text.c_str());

		 CCLOG("Pasamos valor al metodo setValue ");
		 setvalue(text.c_str());

		 //save
		 

		//word = text.c_str;

	 }
    
    /**
     * This method is called when the return button was pressed or the outside area of keyboard was touched.
     * @param editBox The edit box object that generated the event.
     * @js NA
     * @lua NA
     */
	 void NewScene2::editBoxReturn(EditBox* editBox)
	 {
	   CCLOG("End");
	 }


	

	 string NewScene2::getValue()
	 {
		 return valor;
	 }


	 void NewScene2::setvalue(string a)
	 {
	    
		 CCLOG("valor ingresado al metodo setValue (valor = a.c_str())");

		 valor = a.c_str();
	 

	 }


	 void NewScene2::onKeyReleased(EventKeyboard::KeyCode keycode, Event *event)
	 {
	   
		Director::getInstance()->replaceScene(TransitionMoveInL::create(2,HelloWorld::createScene()));

	 
	 }




	 NewScene2::NewScene2()
	 {valor = "";}
	 NewScene2::~NewScene2() {}
