//
// Bitmovin Player iOS SDK
// Copyright (C) 2020, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>
#import <BitmovinPlayerCore/BMPAdBreak.h>
#import <BitmovinPlayerCore/BMPAdQuartile.h>

@protocol _BMPAdPlayer;
@class _BMPScheduledAdItem;
@class BMPAdItem;

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(_AdPlayerDelegate)
@protocol _BMPAdPlayerDelegate <NSObject>
- (void)adPlayer:(id<_BMPAdPlayer>)adPlayer didStartAdBreak:(id<BMPAdBreak>)adBreak NS_SWIFT_NAME(adPlayer(_:didStartAdBreak:));
- (void)adPlayer:(id<_BMPAdPlayer>)adPlayer didFinishAdBreak:(id<BMPAdBreak>)adBreak NS_SWIFT_NAME(adPlayer(_:didFinishAdBreak:));
- (void)adPlayer:(id <_BMPAdPlayer>)adPlayer didReceiveError:(NSError *)error forScheduledAdItem:(_BMPScheduledAdItem *)scheduledAdItem;
- (void)adPlayer:(id<_BMPAdPlayer>)adPlayer didReachAdQuartile:(BMPAdQuartile)adQuartile;
- (void)adPlayer:(id <_BMPAdPlayer>)adPlayer didStartAd:(id<BMPAd>)ad scheduledAdItem:(_BMPScheduledAdItem *)scheduledAdItem NS_SWIFT_NAME(adPlayer(_:didStartAd:scheduledAdItem:));
- (void)adPlayer:(id<_BMPAdPlayer>)adPlayer didFinishAd:(id<BMPAd>)ad NS_SWIFT_NAME(adPlayer(_:didFinishAd:));
- (void)adPlayer:(id<_BMPAdPlayer>)adPlayer didSkipAd:(id<BMPAd>)ad NS_SWIFT_NAME(adPlayer(_:didSkipAd:));
- (void)adPlayer:(id<_BMPAdPlayer>)adPlayer adWasClicked:(id<BMPAd>)ad;
- (void)adPlayer:(id<_BMPAdPlayer>)adPlayer didRequestContentPauseForAdItem:(BMPAdItem *)adItem NS_SWIFT_NAME(adPlayer(_:didRequestContentPauseForAdItem:));
- (void)adPlayerDidRequestContentResume:(id<_BMPAdPlayer>)adPlayer;
- (void)adPlayerWillResume:(id<_BMPAdPlayer>)adPlayer;
- (void)adPlayerDidResume:(id<_BMPAdPlayer>)adPlayer;
- (void)adPlayerWillPause:(id<_BMPAdPlayer>)adPlayer;
- (void)adPlayerDidPause:(id<_BMPAdPlayer>)adPlayer;
- (void)adPlayer:(id<_BMPAdPlayer>)adPlayer didProgressToTime:(NSTimeInterval)currentTime;
@end

NS_ASSUME_NONNULL_END
