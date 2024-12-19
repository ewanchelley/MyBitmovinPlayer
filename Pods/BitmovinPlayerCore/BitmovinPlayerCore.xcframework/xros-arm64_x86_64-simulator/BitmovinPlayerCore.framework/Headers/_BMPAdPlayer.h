//
// Bitmovin Player iOS SDK
// Copyright (C) 2017, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>
#import <BitmovinPlayerCore/_BMPAdPlayerDelegate.h>

@class _BMPScheduledAdItem;

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(_AdPlayer)
@protocol _BMPAdPlayer <NSObject>
@property (nonatomic, weak) id<_BMPAdPlayerDelegate> delegate;
@property (nonatomic, readonly) BOOL isAd;
@property (nonatomic, readonly) BOOL isMuted;
@property (nonatomic, readonly) BOOL isPlaying;
@property (nonatomic, readonly) BOOL isPaused;
@property (nonatomic, readonly) NSTimeInterval currentTime;
@property (nonatomic, readonly) NSTimeInterval duration;

- (void)adShouldPlay:(_BMPScheduledAdItem *)scheduledAdItem;
- (void)destroy;
- (void)play;
- (void)pause;
- (void)skipAd;
- (void)skipAdBreak;
- (void)discardAdBreaksBetweenTime:(NSTimeInterval)startTime andTime:(NSTimeInterval)endTime;
- (void)mute;
- (void)unmute;
- (void)setVolume:(NSInteger)volume;
@end

NS_ASSUME_NONNULL_END
