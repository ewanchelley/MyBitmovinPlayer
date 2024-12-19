//
// Bitmovin Player iOS SDK
// Copyright (C) 2022, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <BitmovinPlayerCore/BMPAdBreak.h>

/**
 * Contains mutable information about an ad break.
 */
NS_SWIFT_NAME(_MutableAdBreak)
@protocol _BMPMutableAdBreak <BMPAdBreak>
@property (nonatomic, readwrite) NSUInteger totalNumberOfAds;
@end
