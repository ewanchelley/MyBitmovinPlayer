//
// Bitmovin Player iOS SDK
// Copyright (C) 2024, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>

@class BMAAnalyticsConfig;
@class BMADefaultMetadata;

NS_ASSUME_NONNULL_BEGIN

/**
 Configuration for the analytics data collection feature on the `BMPPlayer`.
 */
NS_SWIFT_UNAVAILABLE("Use the AnalyticsPlayerConfig enum instead")
NS_SWIFT_SENDABLE
@interface BMPAnalyticsPlayerConfig : NSObject

@property (nonatomic, readonly) BMAAnalyticsConfig *analyticsConfig;
@property (nonatomic, readonly) BMADefaultMetadata *defaultMetadata;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

/**
 Disables the analytics data collection feature for the `BMPPlayer`.
 */
+ (instancetype)disabled;

/**
 Enables the analytics data collection feature for the `BMPPlayer`.
 Analytics data collection is enabled with a default configuration.
 In the default configuration, the analytics license key is automatically fetched
 if one is associated and enabled for the used player license.
 Default metadata values are set for all analytics tracking.
 */
+ (instancetype)enabled;
/**
 Enables the analytics data collection feature for the `BMPPlayer`.
 Analytics data collection is configured via the provided `analyticsConfig`.
 Default metadata values are set for all analytics tracking.
 */
+ (instancetype)enabledWithAnalyticsConfig:(BMAAnalyticsConfig *)analyticsConfig;
/**
 Enables the analytics data collection feature for the `BMPPlayer`.
 Analytics data collection is enabled with a default configuration.
 In the default configuration, the analytics license key is automatically fetched
 if one is associated and enabled for the used player license.
 Default metadata values for all analytics tracking can be set via the provided `defaultMetadata`.
 */
+ (instancetype)enabledWithDefaultMetadata:(BMADefaultMetadata *)defaultMetadata;
/**
 Enables the analytics data collection feature for the `BMPPlayer`.
 Analytics data collection is configured via the provided `analyticsConfig`.
 Default metadata values for all analytics tracking can be set via the provided `defaultMetadata`.
 */
+ (instancetype)enabledWithAnalyticsConfig:(BMAAnalyticsConfig *)analyticsConfig
                           defaultMetadata:(BMADefaultMetadata *)defaultMetadata;

@end

NS_ASSUME_NONNULL_END
