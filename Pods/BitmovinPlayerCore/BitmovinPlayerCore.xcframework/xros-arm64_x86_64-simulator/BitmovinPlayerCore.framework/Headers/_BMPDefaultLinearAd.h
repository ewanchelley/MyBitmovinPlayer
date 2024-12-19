//
// Bitmovin Player iOS SDK
// Copyright (C) 2019, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//


#import <BitmovinPlayerCore/BMPLinearAd.h>
#import <BitmovinPlayerCore/_BMPDefaultAd.h>

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(_DefaultLinearAd)
@interface _BMPDefaultLinearAd : _BMPDefaultAd<BMPLinearAd>
@property (nonatomic) NSTimeInterval duration;
@property (nonatomic) NSTimeInterval skippableAfter;
@property (nullable, nonatomic) BMPLinearAdUiConfig *uiConfig;
@end

NS_ASSUME_NONNULL_END
