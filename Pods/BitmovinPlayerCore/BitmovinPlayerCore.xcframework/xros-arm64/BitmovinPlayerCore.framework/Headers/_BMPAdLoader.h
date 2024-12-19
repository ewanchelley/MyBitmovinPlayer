//
// Bitmovin Player iOS SDK
// Copyright (C) 2017, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class _BMPScheduledAdItem;
@protocol _BMPAdLoaderDelegate;

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(_AdLoader)
@protocol _BMPAdLoader <NSObject>
@property (nonatomic, weak) id<_BMPAdLoaderDelegate> delegate;
- (void)loadAd:(_BMPScheduledAdItem *)scheduledAdItem;
- (void)destroy;
@end

NS_ASSUME_NONNULL_END
