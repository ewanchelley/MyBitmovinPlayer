//
// Bitmovin Player iOS SDK
// Copyright (C) 2024, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>

@protocol BMPPlayer;
@class BMPPlayerConfig;

NS_ASSUME_NONNULL_BEGIN

/**
 Factory to create a `BMPPlayer` instance.
 */
NS_SWIFT_UNAVAILABLE("Use PlayerCoreFactory instead")
NS_SWIFT_SENDABLE
@interface BMPPlayerCoreFactory : NSObject
/**
 Returns the player SDK version number.
 */
@property (class, nonatomic, readonly) NSString *sdkVersion;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

/**
 Creates a `BMPPlayer` instance configured via the provided `BMPPlayerConfig`.
 */
+ (id<BMPPlayer>)createPlayerWithPlayerConfig:(BMPPlayerConfig *)playerConfig;

/**
 Creates a `BMPPlayer` instance with the default `BMPPlayerConfig`.
 */
+ (id<BMPPlayer>)createPlayer;
@end

NS_ASSUME_NONNULL_END
