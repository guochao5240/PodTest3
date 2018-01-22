//
//  OOSetting.h
//  readerTest
//
//  Created by guochao on 2017/3/8.
//  Copyright © 2017年 GUOCHAO. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "OOTheme.h"

typedef enum {
    ScrollTypeCurl = 100,  //拟真
    ScrollTypeScroll,   //上下滑动
    ScrollTypeMovePageHorizontal,  //左右整页移动
    ScrollTypeMovePageVertical  //上下整页移动
}ScrollType;


@interface OOSetting : NSObject

@property (nonatomic, assign) ScrollType scrollType;  //翻页方式
@property (nonatomic, strong) UIFont *font;  //字体
@property (nonatomic, assign) NSInteger lineSpace;  //行间距
@property (nonatomic, strong) OOTheme *theme;   //主题
@property (nonatomic, assign) CGRect contentFrame;  //每一页正文内容frame（可控制四个边距）
@property (nonatomic, assign) CGRect settingFrame;  //打开设置页 需要点击的区域
@property (nonatomic, strong) NSArray *prePageFrameArr;  //跳转到上一页 需要点击的区域  元素类型： NSValue: CGRect
@property (nonatomic, strong) NSArray *nextPageFrameArr; //跳转到下一页 需要点击到区域  元素类型： NSValue: CGRect

@property (nonatomic, assign)CGFloat fontScale;
@property (nonatomic, assign)CGFloat lineHeightMultiplier;


@end
