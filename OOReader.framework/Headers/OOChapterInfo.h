//
//  OOChapterInfo.h
//  readerTest
//
//  Created by guochao on 2017/3/8.
//  Copyright © 2017年 GUOCHAO. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef enum {
    OOBookTypeEpub,
    OOBookTypeTXT
}OOBookType;

@interface OOChapterInfo : NSObject

@property (nonatomic, copy) NSString *chapterID;

@property (nonatomic, copy) NSString *title;
@property (nonatomic, copy) NSString *path;
@property (nonatomic, assign) NSInteger index;
@property (nonatomic, assign) OOBookType bookType;

@property (nonatomic, strong) UIImage *coverImage;
@property (nonatomic, copy) NSString *coverImagePath;
@property (nonatomic, copy) NSString *coverBgImagePath;
@property (nonatomic, copy) NSString *author;
@property (nonatomic, copy) NSString *bookName;

@property (nonatomic, copy) NSString *decryptKey;
@property (nonatomic, copy) NSString *decryptIV;

@end
