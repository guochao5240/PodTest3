//
//  ReaderVC.h
//  readerTest
//
//  Created by guochao on 2017/3/8.
//  Copyright © 2017年 GUOCHAO. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "OOSetting.h"
#import "OOChapterInfo.h"
#import "OOError.h"

//! Project version number for OOReader.
FOUNDATION_EXPORT double OOReaderVersionNumber;

//! Project version string for OOReader.
FOUNDATION_EXPORT const unsigned char OOReaderVersionString[];

@class OOReaderVC;

@protocol OOReaderDelegate <NSObject>

@required
/**
  *  当阅读到某一章的最后一页再继续往下翻页 或 第一页往前翻页 时调用。
  *  需创建与chapteIndex对应的章节并调用readWithChapter 进入对应章节。
  *  @param chapteIndex :所需章节对应的章节index
  */
- (void)reader:(OOReaderVC *)reader needChapterWithIndex:(NSInteger)chapteIndex;

@optional
/**
  *  每次翻页会调用，回调信息为当前阅读进度
  *  @param pageCount 当前章节页数量
  *  @param pageIndex 当前页码
  */
- (void)reader:(OOReaderVC *)reader progressWithPpageCount:(NSInteger)pageCount pageIndex:(NSInteger)pageIndex;

/**
  * 当点击到超链接时调用
  *  @param link 点击到的超链接字符串
  */
- (void)reader:(OOReaderVC *)reader didClickLink:(NSString *)link;

/**
  * 当点击到settingFrame 区域 并且没有点击到图片和超链接等富文本时调用
  * 可以弹出自定义的设置页面
  */
- (void)needShowSettingViewForReader:(OOReaderVC *)reader;

/**
  * 数据处理完成，准备显示时调用
  */
- (void)readerWillDisplay:(OOReaderVC *)reader;

/**
 * 选中一段文字，点击“标注”时调用  *注：标注完成后 需要更新 markList 属性
 * @param range 选中的内容对应的 range
 * @param content 选中的内容对应的 content String
 */
- (void)reader:(OOReaderVC *)reader markWithRange:(NSRange)range content:(NSString*)content;

/**
 * 选中一段文字，点击“分享”时调用
 * @param content 选中的内容
 */
- (void)reader:(OOReaderVC *)reader shareWithContent:(NSString *)content;

/**
 * 点击被标注的文字时调用
 * @param markRange 选中的内容对应的 range
 */
- (void)reader:(OOReaderVC *)reader didClickMarkRange:(NSRange)markRange;

/**
 * 复制文本成功时调用
 * @param content 复制的文本内容
 */
- (void)reader:(OOReaderVC *)reader copySucceedWithContent:(NSString*)content;

/**
  * 发生错误时调用
  *  @param error 错误类型 参照OOError注释
  */
- (void)reader:(OOReaderVC *)reader failedWithError:(OOError*)error;

@end

@interface OOReaderVC : UIViewController

/**
  * 页面设置信息
  */
@property (nonatomic, strong) OOSetting *setting;

/**
  * 标注列表 元素类型：NSValue of NSRange
  */
@property (nonatomic, strong) NSArray *markList;

/**
  * 章节信息
  */
@property (nonatomic, strong, readonly) OOChapterInfo *chapterInfo;


@property (nonatomic, assign) id<OOReaderDelegate>delegate;

/**
  *  开始阅读  跳转到指定页码
  *  @param chapterInfo 需要阅读的章节信息
  *  @param pageIndex 需要阅读的页码
  */
- (void)readWithChapter:(OOChapterInfo*)chapterInfo pageIndex:(NSInteger)pageIndex;

/**
  *  开始阅读  跳转到某一个字所在页
  *  @param chapterInfo 需要阅读的章节信息
 *  @param charIndex 指定字符在整章中的位置
  */
- (void)readWithChapter:(OOChapterInfo*)chapterInfo charIndex:(NSInteger)charIndex;

/**
  *  获取某一页的第一个字符在整章中的位置
  *  @param pageIndex 页码
  *  @param block  charLocation: 字符位置  error: pageIndex越界等错误时返回
  */
- (void)charLocationWithPageIndex:(NSInteger)pageIndex finish:(void(^)(NSInteger charLocation, OOError *error))block;

/**
  *  通过某一个字符的位置 获取该字符所在页码
  *  @param charLocation 字符位置
  *  @param block  pageIndex: 页码  error: charLocation越界等错误时返回
  */
- (void)pageIndexWithCharLocation:(NSInteger)charLocation finish:(void(^)(NSInteger pageIndex, OOError *error))block;

/**
  *  返回当前页某一个字符的frame
  *  @param index 当前页 从0开始的字符下标
  */
- (CGRect)charFrameWithIndex:(NSInteger)index;

/**
  *  特殊情况下，可刷新阅读器，如章节请求后延时处理
  */
- (void)refresh;

/**
  *  获取本SDK版本信息
  */
- (NSDictionary*)getLocalVersionInfo;


@end
