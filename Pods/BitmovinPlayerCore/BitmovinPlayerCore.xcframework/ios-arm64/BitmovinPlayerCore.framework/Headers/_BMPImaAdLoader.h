#if !TARGET_OS_VISION
//
// Bitmovin Player iOS SDK
// Copyright (C) 2017, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>
#import <BitmovinPlayerCore/_BMPAdLoader.h>
#import <BitmovinPlayerCore/_BMPImaAdsManagerRegistry.h>
@protocol BMPThreadHelper;
@protocol BMPImaAdsRenderingSettingsFactory;
@protocol _BMPObjCLoggerService;
@protocol _BMPNamespacedServiceLocator;
@class BMPImaAdsRequestFactory;
@class BMPImaAdsLoaderFactory;

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(_ImaAdLoader)
@interface _BMPImaAdLoader : NSObject <_BMPAdLoader>
/**
 * weak reference to avoid an indirect retain cycle. The view is the BMPPlayerView which
 * already holds a strong reference to the BMPBitmovinPlayer
 */
@property (nonatomic, weak) UIView *adContainer;
@property (nonatomic, weak) id<_BMPAdLoaderDelegate> delegate;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)initWithServiceLocator:(id<_BMPNamespacedServiceLocator>)serviceLocator
                                player:(AVPlayer *)player
                 imaAdsManagerRegistry:(_BMPImaAdsManagerRegistry *)imaAdsManagerRegistry
                         loggerService:(id<_BMPObjCLoggerService>)loggerService;
- (instancetype)initWithServiceLocator:(id<_BMPNamespacedServiceLocator>)serviceLocator
                                player:(AVPlayer *)player
                 imaAdsManagerRegistry:(_BMPImaAdsManagerRegistry *)imaAdsManagerRegistry
                          threadHelper:(id<BMPThreadHelper>)threadHelper
           adsRenderingSettingsFactory:(id<BMPImaAdsRenderingSettingsFactory>)adsRenderingSettingsFactory
                         loggerService:(id<_BMPObjCLoggerService>)loggerService
                  imaAdsRequestFactory:(BMPImaAdsRequestFactory *)imaAdsRequestFactory
                   imaAdsLoaderFactory:(BMPImaAdsLoaderFactory *)imaAdsLoaderFactory NS_DESIGNATED_INITIALIZER;
@end

NS_ASSUME_NONNULL_END
#endif
