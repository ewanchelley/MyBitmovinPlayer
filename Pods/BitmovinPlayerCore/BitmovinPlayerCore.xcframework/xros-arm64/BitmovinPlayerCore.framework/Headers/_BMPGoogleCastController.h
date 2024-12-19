#if !TARGET_OS_TV && !TARGET_OS_VISION
//
// Bitmovin Player iOS SDK
// Copyright (C) 2017, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>
#import <BitmovinPlayerCore/_BMPRemoteControlApiInternal.h>
#import <BitmovinPlayerCore/_BMPServiceLocator.h>
#import <BitmovinPlayerCore/_BMPPlayerAPI.h>
#import <BitmovinPlayerCore/BMPBitmovinCastManager.h>
@protocol _BMPObjCLoggerService;
@class BMPGoogleCastMediaQueueBuilder;

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(_GoogleCastController)
@interface _BMPGoogleCastController : NSObject <_BMPPlayerAPI, _BMPRemoteControlApiInternal>

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)initWithServiceLocator:(id<_BMPNamespacedServiceLocator>)serviceLocator
                         loggerService:(id<_BMPObjCLoggerService>)loggerService;
- (instancetype)initWithServiceLocator:(id<_BMPNamespacedServiceLocator>)serviceLocator
                         loggerService:(id<_BMPObjCLoggerService>)loggerService
                           castManager:(BMPBitmovinCastManager *)castManager
                     mediaQueueBuilder:(BMPGoogleCastMediaQueueBuilder *)mediaQueueBuilder NS_DESIGNATED_INITIALIZER;
@end

NS_ASSUME_NONNULL_END
#endif
