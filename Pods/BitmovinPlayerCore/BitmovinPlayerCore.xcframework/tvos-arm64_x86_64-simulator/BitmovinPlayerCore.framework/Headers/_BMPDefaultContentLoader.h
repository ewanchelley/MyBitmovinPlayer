//
// Bitmovin Player iOS SDK
// Copyright (C) 2018, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>
#import <BitmovinPlayerCore/BMPHttpRequestTypes.h>
#import <BitmovinPlayerCore/_BMPContentLoader.h>
@protocol _BMPObjCLoggerService;
@class BMPNetworkConfig;
@class _BMPSession;
@class _BMPRequestConfigFactory;
@protocol BMPThreadHelper;

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(_DefaultContentLoader)
@interface _BMPDefaultContentLoader : NSObject<_BMPContentLoader>
@property (weak, nonatomic, nullable) id<_BMPContentLoaderDelegate> delegate;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)initWithRequestType:(BMPHttpRequestType)requestType
                      networkConfig:(BMPNetworkConfig *)networkConfig
                      loggerService:(id<_BMPObjCLoggerService>)loggerService;
- (instancetype)initWithRequestType:(BMPHttpRequestType)requestType
                      networkConfig:(BMPNetworkConfig *)networkConfig
                            session:(_BMPSession *)session
               requestConfigFactory:(_BMPRequestConfigFactory *)requestConfigFactory
                       threadHelper:(id<BMPThreadHelper>)threadHelper
                      loggerService:(id<_BMPObjCLoggerService>)loggerService NS_DESIGNATED_INITIALIZER;
- (void)load:(NSURL *)url completionHandler:(void (^_Nullable)(NSError * _Nullable))completionHandler;
@end

NS_ASSUME_NONNULL_END
