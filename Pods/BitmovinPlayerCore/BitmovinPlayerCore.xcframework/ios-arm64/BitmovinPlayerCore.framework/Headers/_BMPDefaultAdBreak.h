//
// Bitmovin Player iOS SDK
// Copyright (C) 2020, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>
#import <BitmovinPlayerCore/_BMPMutableAdBreak.h>

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(_DefaultAdBreak)
@interface _BMPDefaultAdBreak : NSObject <_BMPMutableAdBreak>
@property (nonatomic, readwrite) NSUInteger totalNumberOfAds;
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)initWithIdentifier:(NSString *)identifier scheduleTime:(NSTimeInterval)scheduleTime NS_DESIGNATED_INITIALIZER;
@end

NS_ASSUME_NONNULL_END
