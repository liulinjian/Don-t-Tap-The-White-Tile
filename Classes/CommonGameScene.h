#ifndef __CommonGameScene_H__
#define __CommonGameScene_H__

#include "cocos2d.h"
#include "Script.h"
USING_NS_CC;

class CommonGameColorButton;
class CommonGameScene : public cocos2d::Layer
{
public:
    int currentVerticalNum = 4;
    int bottomLineVerticalNum = verticalNum_macro-1;
    bool isSettedWhiteRect = false;
    int  missedCommonGameColorButtonTag;
    bool isTouchLock = false;
    std::vector<int > blackRectTagVec;
    std::vector<int > UnderBottom_bottom_blackRectIndexVec;
    int twoLineCount = 0;
    bool isFirstIn = true;
    int commonGameTotalLine = totalLine_macro;
    LabelTTF * timeLabel;
    float timeNum = 0.000f;
    
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* scene();
    CREATE_FUNC(CommonGameScene);
    
    static int getRandomNumber(int start,int end);
    void AllCommonGameColorButtonMoveBy(const Point& MoveByD,float duration,float rate);
    void loopRoll(Ref* sender, bool cleanup);
    void stopAllCommonGameColorButtonSchedule();
    void CommonGameOver2();
    void createFillRect();
    void replaceCommonGameOverScene(Ref* sender, bool cleanup);
    void OneLinePass();
    void RecordNewUnderBottom_blackRectIndex(int whiteIdx);
    
protected:
    int totalHorizontal = horizontalNum_macro;
    int totalVhertical = verticalNum_macro;
    
    
    const cocos2d::Size screenSize_macro = VisibleRect::getVisibleRect().size;
    const float screenHeight = VisibleRect::getVisibleRect().size.height;
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    CommonGameColorButton * createRect(Color4B color4B,int horizontal,int vertical);
    void update(float delta);
};

#endif // __CommonGameScene_SCENE_H__
