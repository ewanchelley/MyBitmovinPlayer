//
// Bitmovin Player iOS SDK
// Copyright (C) 2021, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <BitmovinPlayerCore/BMPRemoteControlApi.h>
@class _BMPPlaybackPosition;

NS_ASSUME_NONNULL_BEGIN

/// :nodoc:
NS_SWIFT_NAME(_RemoteControlApiInternal)
@protocol _BMPRemoteControlApiInternal <BMPRemoteControlApi>
@property (nonatomic, readonly) BOOL isRemotePlayerStateAvailable;

- (void)loadMediaInfoWithPlaybackPosition:(NSTimeInterval)playbackPosition
                          streamStartDate:(nullable NSDate *)streamStartDate
                                 autoplay:(BOOL)autoplay NS_SWIFT_NAME(loadMediaInfo(playbackPosition:streamStart:autoplay:));
- (void)showCastDialog;
@end

NS_ASSUME_NONNULL_END
