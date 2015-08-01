#include "NewScene4.h"
#include "HelloWorldScene.h"
//#include "Persona.h"

USING_NS_CC;
USING_NS_CC_EXT;



Scene* NewScene4::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = NewScene4::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool NewScene4::init()
{

	
   //////////////////////////////
    // 1. super init first
	if ( !LayerColor::initWithColor(Color4B::WHITE) )
    {
        return false;
    }
    

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();



	auto menuitem = MenuItemLabel::create(Label::createWithTTF("volver","fonts/airstrike.ttf",35), CC_CALLBACK_1(NewScene4::goBack, this));
	menuitem->setColor(Color3B::BLACK);

	menuitem->setPosition(Point(origin.x + visibleSize.width / 2, origin.y + menuitem->getContentSize().height / 2));

	auto menu = Menu::create(menuitem, NULL);
	menu->setPosition(Point::ZERO);
	this->addChild(menu,1);


	
	EditBox *ebx1 = EditBox::create(Size(300,60), Scale9Sprite::create("editbox.png"));
	ebx1->setPosition(Point(origin.x + visibleSize.width / 2, origin.y + visibleSize.height - ebx1->getContentSize().height * 2));
	ebx1->setName("nombre");
	ebx1->setFont("fonts/airstrike.ttf",30);
	//ebx1->setFontSize(30);
	ebx1->setFontColor(Color3B::BLUE);
	ebx1->setFontName("Verdana");
	ebx1->setPlaceHolder("NOMBRE :");
	ebx1->setPlaceholderFontColor(Color3B::BLUE);
	ebx1->setMaxLength(10);
	ebx1->setReturnType(EditBox::KeyboardReturnType::DONE);
	ebx1->setDelegate(this);
	
	this->addChild(ebx1,1);
	

	
	EditBox *ebx2 = EditBox::create(Size(300,60), Scale9Sprite::create("ebx.png"));
	ebx2->setPosition(Point(origin.x + visibleSize.width / 2, origin.y + ebx1->getPositionY() - ebx1->getContentSize().height * 2));
	ebx2->setName("apellido");
	ebx2->setFontSize(30);
	ebx2->setFontColor(Color3B::BLUE);
	ebx2->setFontName("Verdana");
	ebx2->setPlaceHolder("APELLIDO :");
	ebx2->setPlaceholderFontColor(Color3B::BLUE);
	ebx2->setMaxLength(15);
	ebx2->setReturnType(EditBox::KeyboardReturnType::DONE);
	ebx2->setDelegate(this);
	this->addChild(ebx2,1);




    EditBox *ebx3 = EditBox::create(Size(200,60), Scale9Sprite::create("ebx.png"));
	ebx3->setPosition(Point(origin.x + visibleSize.width / 2, origin.y + ebx2->getPositionY() - ebx1->getContentSize().height * 2));
	ebx3->setName("edad");

	ebx3->setFontSize(30);
	ebx3->setFontColor(Color3B::BLUE);
	ebx3->setFontName("Verdana");
	ebx3->setPlaceHolder("EDAD :");
	ebx3->setPlaceholderFontColor(Color3B::BLUE);
	ebx3->setMaxLength(3);
	ebx3->setInputMode(EditBox::InputMode::NUMERIC);
	ebx3->setReturnType(EditBox::KeyboardReturnType::DONE);
	ebx3->setDelegate(this);
	this->addChild(ebx3,1);
	

	auto btn = Button::create("b1.png","b2.png");
	btn->setPosition(Point(origin.x + visibleSize.width / 2, origin.y +  menuitem->getPositionY() + btn->getContentSize().height));
	btn->addTouchEventListener(CC_CALLBACK_2(NewScene4::touchBTNevent, this));	
	this->addChild(btn,1);


	this->setKeyboardEnabled(true);


	return true;

}


void NewScene4::goBack(Ref *pSender)
{

	Director::getInstance()->replaceScene(TransitionFlipX::create(2, HelloWorld::createScene()));

}








void NewScene4::touchBTNevent(Ref*pSender, Widget::TouchEventType type)
{
	
	switch (type)
	{
	case cocos2d::ui::Widget::TouchEventType::BEGAN:

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



 /**
     * This method is called when an edit box gains focus after keyboard is shown.
     * @param editBox The edit box object that generated the event.
     * @js NA
     * @lua NA
     */
void NewScene4::editBoxEditingDidBegin(EditBox* editBox){}
    
    
    /**
     * This method is called when an edit box loses focus after keyboard is hidden.
     * @param editBox The edit box object that generated the event.
     * @js NA
     * @lua NA
     */
void NewScene4::editBoxEditingDidEnd(EditBox* editBox){}
    
    /**
     * This method is called when Sthe edit box text was changed.
     * @param editBox The edit box object that generated the event.
     * @param text The new text.
     * @js NA
     * @lua NA
     */
void NewScene4::editBoxTextChanged(EditBox* editBox, const std::string& text){

	 
	
	//Persona p;

	if(editBox->getName() == "nombre")
	{
		CCLOG("El texto fue ingresado en el campo nombre");
		//p.setNombre(text.c_str());

	}
	
	
	else if(editBox->getName() == "apellido")
	{
		CCLOG("El texto fue ingresado en el campo apellido");
		//p.setApellido(text.c_str());
	}

    else if(editBox->getName() == "edad")
	{
		CCLOG("El texto fue ingresado en el campo edad");
		//p.setEdad(atoi(text.c_str()));
	}


	/*
	CCLOG("texto capturado: %s", p.getNombre().c_str());
	Persona p1(p.getNombre().c_str(), p.getApellido().c_str(), p.getEdad());
	traePersona(p1);
	*/
}
    
    /**
     * This method is called when the return button was pressed or the outside area of keyboard was touched.
     * @param editBox The edit box object that generated the event.
     * @js NA
     * @lua NA
     */
void NewScene4::editBoxReturn(EditBox* editBox){}
    

//def traePersona()
/*


void NewScene4::traePersona(Persona p)
{
	
	Point origin = Director::getInstance()->getVisibleOrigin();
	Size visibleSize = Director::getInstance()->getVisibleSize();

	auto action = Sequence::create(FadeIn::create(2), FadeOut::create(2), NULL);

	Label *ln = LabelTTF::create(p.getNombre().c_str, "Arial", 40);
	ln->setPosition(Point(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2));
	ln->setColor(Color3B::BLACK);
	
	ln->runAction(action);
	this->addChild(ln);

}
*/



void NewScene4::onKeyReleased(EventKeyboard::KeyCode keycode, Event *event)
{
  
	Director::getInstance()->replaceScene(TransitionFlipX::create(2, HelloWorld::createScene()));


}