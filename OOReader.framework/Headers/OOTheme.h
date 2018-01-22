//
//  OOTheme.h
//  readerTest
//
//  Created by guochao on 2017/3/8.
//  Copyright © 2017年 GUOCHAO. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface OOTheme : NSObject

@property (nonatomic, strong) UIColor *titleColor;
@property (nonatomic, strong) UIColor *contentColor;

@property (nonatomic, strong) UIColor *statusBarColor;

@property (nonatomic, strong) UIColor *backgroundColor;
@property (nonatomic, strong) UIImage *backgroundImage;

@property (nonatomic, assign) BOOL nightMode;


@end
