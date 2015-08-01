#include "NewScene3.h"
#include "HelloWorldScene.h"

USING_NS_CC;
USING_NS_CC_EXT;


Scene* NewScene3::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = NewScene3::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool NewScene3::init()
{

	
   //////////////////////////////
    // 1. super init first
	if ( !LayerColor::initWithColor(Color4B::GRAY) )
    {
        return false;
    }
    

     
   //------------------ LABEL------------------------

	auto label = Label::createWithTTF("Nueva Escena 3", "fonts/airstrike3d.ttf", 24);
    
	label->setColor(Color3B::BLACK);
    
    label->setPosition(Vec2(getOrigi().x + getVisibleSiz().width/2,
                            getOrigi().y + getVisibleSiz().height - label->getContentSize().height));

   
    this->addChild(label, 1);


	//-------------------btn------------------------


	b1 = Button::create("b1.png","b2.png");
	b1->setPosition(Point(getVisibleSiz().width/2 + getOrigi().x, getVisibleSiz().height / 2 + getOrigi().y));
	b1->addTouchEventListener(CC_CALLBACK_2(NewScene3::TouchBevent, this));
	this->addChild(b1,1);



	//------------checkbox-------------------

	auto cbx = CheckBox::create("ui/3.png","ui/3.png","ui/1.png","ui/3.png","ui/3.png");
	cbx->setPosition(Point(getOrigi().x + getVisibleSiz().width - cbx->getContentSize().height / 2, getOrigi().y + getVisibleSiz().height / 2));
	cbx->addEventListener(CC_CALLBACK_2(NewScene3::TouchCBXevent, this));
	this->addChild(cbx,1);



	//-----------Editbox

	auto ebx = EditBox::create(Size(500,60), Scale9Sprite::create("ebx1.png"));
	ebx->setPosition(Point(getOrigi().x + getVisibleSiz().width / 2, getOrigi().y + b1->getPositionY() - ebx->getContentSize().height));
	
	ebx->setFontSize(25);
	ebx->setFontColor(Color3B::RED);
	ebx->setFontName("Verdana");
	ebx->setPlaceHolder("ingrese nombre :");
	ebx->setPlaceholderFontColor(Color3B::GRAY);
	ebx->setMaxLength(8);
	ebx->setInputMode(EditBox::InputMode::ANY);

	ebx->setReturnType(EditBox::KeyboardReturnType::DEFAULT);
	this->addChild(ebx,1);


	//-----------VOLVER------------------

	auto menuItem = MenuItemLabel::create(Label::createWithTTF("Volver", "fonts/airstrike3d.ttf", 34), CC_CALLBACK_1(NewScene3::volver, this));

	menuItem->setPosition(Point(getOrigi().x + getVisibleSiz().width / 2, getOrigi().y + menuItem->getContentSize().height / 2));
	menuItem->setColor(Color3B::BLACK);

	auto menuGral = Menu::create(menuItem, NULL);
	menuGral->setPosition(Point::ZERO);
	
	this->addChild(menuGral,2);


	this->setKeyboardEnabled(true);
    
    return true;
}






void NewScene3::TouchBevent(Ref* pSender, Widget::TouchEventType type)
{
	switch (type)
	{
	case cocos2d::ui::Widget::TouchEventType::BEGAN:
		Director::getInstance()->replaceScene(TransitionFade::create(2, HelloWorld::createScene()));
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


void NewScene3::TouchCBXevent(Ref* pSender, CheckBox::EventType type)
{
	auto l1 = LabelTTF::create("hOLA","Arial",40);
	l1->setPosition(Point(getOrigi().x + getVisibleSiz().width / 2, getOrigi().y + getVisibleSiz().height / 2));
	l1->setColor(Color3B::WHITE);
	l1->setName("l1");
	switch (type)
	{
	case cocos2d::ui::CheckBox::EventType::SELECTED:
		
		this->addChild(l1,2);

		break;
	case cocos2d::ui::CheckBox::EventType::UNSELECTED:
		this->removeChildByName("l1");
		break;
	default:
		break;
	}

}



void NewScene3::volver(Ref* pSender)
{

	Director::getInstance()->replaceScene(TransitionFlipY::create(2,HelloWorld::createScene()));

}



void NewScene3::onKeyReleased(EventKeyboard::KeyCode keycode, Event *event)
{
	Director::getInstance()->replaceScene(TransitionFlipY::create(2,HelloWorld::createScene()));

}



/*
bool NewScene3::onTouchBegan(Touch *touches, Event *event){return true;}
void NewScene3::onTouchEnded(Touch *touches, Event *event){Director::getInstance()->replaceScene(TransitionFlipY::create(2,HelloWorld::createScene()));}
void NewScene3::onTouchMoved(Touch *touches, Event *event){}
*/


 /**
     * This method is called when an edit box gains focus after keyboard is shown.
     * @param editBox The edit box object that generated the event.
     * @js NA
     * @lua NA
     */
        void NewScene3::editBoxEditingDidBegin(EditBox* editBox){
		
			

		
		}
    
    
    /**
     * This method is called when an edit box loses focus after keyboard is hidden.
     * @param editBox The edit box object that generated the event.
     * @js NA
     * @lua NA
     */
		void NewScene3::editBoxEditingDidEnd(EditBox* editBox){}
    
    /**
     * This method is called when the edit box text was changed.
     * @param editBox The edit box object that generated the event.
     * @param text The new text.
     * @js NA
     * @lua NA
     */
	    void NewScene3::editBoxTextChanged(EditBox* editBox, const std::string& text){}
    
    /**
     * This method is called when the return button was pressed or the outside area of keyboard was touched.
     * @param editBox The edit box object that generated the event.
     * @js NA
     * @lua NA
     */
		void NewScene3::editBoxReturn(EditBox* editBox){}
	