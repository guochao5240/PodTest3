//
//  OOError.h
//  OOReader
//
//  Created by guochao on 2017/4/7.
//  Copyright © 2017年 GUOCHAO. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "OOChapterInfo.h"

typedef NS_ENUM(NSInteger, OOErrorCode) {
    OOErrorFileNotExist = 101,
    OOErrorFileNotAvailable = 102,
    OOErrorDecryptFailed = 103,
    OORrrorPageIndexOutOfBounds = 104,
    OORrrorCharIndexOutOfBounds = 105,
    OORrrorContentDataNull = 106
};

@interface OOError : NSObject

@property (nonatomic, copy) NSString *errorDescription;

@property (nonatomic, strong) OOChapterInfo *errorChapterInfo;

@property (nonatomic, assign) OOErrorCode errorCode;

@end
