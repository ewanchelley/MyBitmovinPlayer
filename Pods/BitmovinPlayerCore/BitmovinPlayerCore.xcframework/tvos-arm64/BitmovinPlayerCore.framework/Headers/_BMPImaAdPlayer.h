#if !TARGET_OS_VISION
//
// Bitmovin Player iOS SDK
// Copyright (C) 2017, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>
#import <BitmovinPlayerCore/_BMPAdPlayer.h>
#import <BitmovinPlayerCore/_BMPImaAdsManagerRegistry.h>

@protocol _BMPTimerFactory;
@protocol _BMPObjCLoggerService;
@protocol _BMPNamespacedServiceLocator;
@protocol BMPThreadHelper;

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(ImaAdPlayer)
@interface _BMPImaAdPlayer : NSObject <_BMPAdPlayer>
@property (nonatomic, weak) id<_BMPAdPlayerDelegate> delegate;
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)initWithServiceLocator:(id<_BMPNamespacedServiceLocator>)serviceLocator
                 imaAdsManagerRegistry:(_BMPImaAdsManagerRegistry *)imaAdsManagerRegistry
                         loggerService:(id<_BMPObjCLoggerService>)loggerService;
- (instancetype)initWithServiceLocator:(id<_BMPNamespacedServiceLocator>)serviceLocator
                 imaAdsManagerRegistry:(_BMPImaAdsManagerRegistry *)imaAdsManagerRegistry
                          timerFactory:(id<_BMPTimerFactory>)timerFactory
                         loggerService:(id<_BMPObjCLoggerService>)loggerService
                          threadHelper:(id<BMPThreadHelper>)threadHelper NS_DESIGNATED_INITIALIZER;
@end

NS_ASSUME_NONNULL_END
#endif
