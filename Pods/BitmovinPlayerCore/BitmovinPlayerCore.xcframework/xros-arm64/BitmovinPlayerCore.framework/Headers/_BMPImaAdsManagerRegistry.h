#if !TARGET_OS_VISION
//
// Bitmovin Player iOS SDK
// Copyright (C) 2020, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>
@class IMAAdsManager;
@class _BMPScheduledAdItem;
@class IMAAd;

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(_ImaAdsManagerRegistry)
@interface _BMPImaAdsManagerRegistry : NSObject
@property (nonatomic, strong, readonly) NSArray<IMAAdsManager *> *allAdsManagers;
- (nullable IMAAdsManager *)adsManagerForScheduledAdItem:(_BMPScheduledAdItem *)scheduledAdItem;
- (nullable IMAAd *)adForScheduledAdItem:(_BMPScheduledAdItem *)scheduledAdItem;
- (void)registerAdsManager:(IMAAdsManager *)adsManager forScheduledAdItem:(_BMPScheduledAdItem *)scheduledAdItem;
- (void)setDelegate:(id)delegate forScheduledAdItem:(_BMPScheduledAdItem *)scheduledAdItem;
- (void)destroyAndRemoveAdsManager:(IMAAdsManager *)adsManager;
- (void)destroyAndRemoveAdsManagerForScheduledAdItem:(_BMPScheduledAdItem *)scheduledAdItem;
- (void)removeAdsManager:(IMAAdsManager *)adsManager;
- (void)removeAllAdsManagers;
@end

NS_ASSUME_NONNULL_END
#endif
