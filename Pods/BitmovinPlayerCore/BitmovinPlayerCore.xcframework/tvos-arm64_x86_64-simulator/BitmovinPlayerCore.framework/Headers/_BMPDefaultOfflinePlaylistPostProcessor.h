#if !TARGET_OS_TV
//
// Bitmovin Player iOS SDK
// Copyright (C) 2020, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>
#import <BitmovinPlayerCore/_BMPOfflinePlaylistPostProcessor.h>

@protocol BMPOfflinePlaylistPostProcessorStep;
@protocol _BMPObjCLoggerService;
@protocol _BMPDataReader;
@protocol _BMPDataWriter;

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(_DefaultOfflinePlaylistPostProcessor)
@interface _BMPDefaultOfflinePlaylistPostProcessor : NSObject <_BMPOfflinePlaylistPostProcessor>
@property (nonatomic, strong, readonly) NSArray<id<BMPOfflinePlaylistPostProcessorStep>> *steps;
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)initWithLoggerService:(id<_BMPObjCLoggerService>)loggerService;
- (instancetype)initWithLoggerService:(id<_BMPObjCLoggerService>)loggerService
                           dataReader:(id<_BMPDataReader>)dataReader
                           dataWriter:(id<_BMPDataWriter>)dataWriter
                          fileManager:(NSFileManager *)fileManager NS_DESIGNATED_INITIALIZER;
@end

NS_ASSUME_NONNULL_END
#endif
