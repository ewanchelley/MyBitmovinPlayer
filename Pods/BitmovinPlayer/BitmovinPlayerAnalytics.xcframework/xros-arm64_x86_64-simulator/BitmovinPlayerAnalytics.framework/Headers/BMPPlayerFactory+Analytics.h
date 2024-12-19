//
// Bitmovin Player iOS SDK
// Copyright (C) 2023, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>
#import <BitmovinPlayerCore/BitmovinPlayerCore.h>

@class BMAAnalyticsConfig;
@class BMADefaultMetadata;
@class BMPAnalyticsPlayerConfig;

NS_ASSUME_NONNULL_BEGIN

/**
 Extends `BMPPlayerFactory` to create a `BMPPlayer` with built-in analytics data collection.
 */
NS_SWIFT_UNAVAILABLE("Use PlayerFactory instead")
NS_SWIFT_SENDABLE
@interface BMPPlayerFactory (Analytics)

/**
 Creates and configures a `BMPPlayer` instance.

 The `BMPPlayer` is configured with a default configuration.
 Analytics data collection is enabled with default configuration.

 @Note If you have manually configured Bitmovin Analytics using the `BitmovinAnalyticsCollector`, either migrate to
 the analytics namespace from the player or disable analytics by passing `[BMPAnalyticsPlayerConfig disabled]`
 to `createPlayerWithPlayerConfig:analytics:`.
 Using both, analytics on the player and a manually configured collector will result in a crash.
 */
+ (id<BMPPlayer>)createPlayer;
/**
 Creates and configures a `BMPPlayer` instance.

 @param playerConfig The `BMPPlayer` is configured via the provided `playerConfig`.

 Analytics data collection is enabled with default configuration.

 @Note If you have manually configured Bitmovin Analytics using the `BitmovinAnalyticsCollector`, either migrate to
 the bundled collector or disable bundled analytics by passing `[BMPAnalyticsPlayerConfig disabled]`
 as `analytics` to `createPlayerWithPlayerConfig:analytics:`.
 Using both, the bundled and the manually configured collector will result in a crash.
 */
+ (id<BMPPlayer>)createPlayerWithPlayerConfig:(BMPPlayerConfig *)playerConfig;
/**
 Creates and configures a `BMPPlayer` instance.

 @param playerConfig The `BMPPlayer` is configured via the provided `playerConfig`.
 @param analytics The `BMPAnalyticsPlayerConfig` can be used to customize the analytics data collection, or disable analytics support for the `BMPPlayer` instance.

 @Note If you have manually configured Bitmovin Analytics using the `BitmovinAnalyticsCollector`, either migrate to
 the bundled collector or disable bundled analytics by using `[BMPAnalyticsPlayerConfig disabled]` as `analytics`.
 Using both, the bundled and the manually configured collector will result in a crash.
 */
+ (id<BMPPlayer>)createPlayerWithPlayerConfig:(BMPPlayerConfig *)playerConfig
                                    analytics:(BMPAnalyticsPlayerConfig *)analytics;

/**
 Creates a `BMPPlayer` instance where Analytics is enabled and configured via the `BMAAnalyticsConfig`.
 */
+ (id<BMPPlayer>)createWithAnalyticsConfig:(BMAAnalyticsConfig *)analyticsConfig __deprecated_msg("Use createPlayerWithPlayerConfig:analytics: instead.");

+ (id<BMPPlayer>)createWithAnalyticsConfig:(BMAAnalyticsConfig *)analyticsConfig
                           defaultMetadata:(BMADefaultMetadata *)defaultMetadata __deprecated_msg("Use createPlayerWithPlayerConfig:analytics: instead.");
/**
 Creates a `BMPPlayer` instance where Analytics is enabled and configured via the provided `BMPPlayerConfig`
 and the `BMAAnalyticsConfig`.
 */
+ (id<BMPPlayer>)createWithPlayerConfig:(BMPPlayerConfig *)playerConfig
                        analyticsConfig:(BMAAnalyticsConfig *)analyticsConfig __deprecated_msg("Use createPlayerWithPlayerConfig:analytics: instead.");

+ (id<BMPPlayer>)createWithPlayerConfig:(BMPPlayerConfig *)playerConfig
                        analyticsConfig:(BMAAnalyticsConfig *)analyticsConfig
                        defaultMetadata:(BMADefaultMetadata *)defaultMetadata __deprecated_msg("Use createPlayerWithPlayerConfig:analytics: instead.");

@end

NS_ASSUME_NONNULL_END
