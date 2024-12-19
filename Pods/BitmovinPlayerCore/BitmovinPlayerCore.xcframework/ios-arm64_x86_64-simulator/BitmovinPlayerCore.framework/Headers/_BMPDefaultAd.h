//
// Bitmovin Player iOS SDK
// Copyright (C) 2020, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <BitmovinPlayerCore/BMPAd.h>

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(_DefaultAd)
@interface _BMPDefaultAd : NSObject<BMPAd>

@property (nonatomic) NSInteger width;
@property (nonatomic) NSInteger height;
@property (nonatomic, nullable) NSString *identifier;
@property (nonatomic, nullable) NSURL *mediaFileUrl;
@property (nonatomic, nullable) NSURL *clickThroughUrl;
@property (nonatomic, nullable) id<BMPAdData> data;
@property (nonatomic, readwrite, nullable) void (^clickThroughUrlOpened)(void);

@end

NS_ASSUME_NONNULL_END
