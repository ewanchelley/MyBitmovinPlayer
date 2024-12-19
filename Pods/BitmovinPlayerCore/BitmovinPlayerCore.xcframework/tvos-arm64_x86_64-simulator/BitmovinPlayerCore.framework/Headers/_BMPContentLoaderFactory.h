//
// Bitmovin Player iOS SDK
// Copyright (C) 2020, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>
@protocol _BMPContentLoader;
@protocol _BMPObjCLoggerService;
@class BMPNetworkConfig;

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(_ContentLoaderFactory)
@protocol _BMPContentLoaderFactory <NSObject>
- (id<_BMPContentLoader>)createContentLoaderWithLoggerService:(id<_BMPObjCLoggerService>)loggerService
                                                networkConfig:(BMPNetworkConfig *)networkConfig;
@end

NS_ASSUME_NONNULL_END
