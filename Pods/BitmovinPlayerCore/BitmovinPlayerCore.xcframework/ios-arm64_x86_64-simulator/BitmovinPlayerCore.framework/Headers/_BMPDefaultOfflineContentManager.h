#if !TARGET_OS_TV
//
// Bitmovin Player iOS SDK
// Copyright (C) 2017, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#import <BitmovinPlayerCore/BMPOfflineState.h>
#import <BitmovinPlayerCore/_BMPOfflineDownloadsHandler.h>
#import <BitmovinPlayerCore/_BMPOfflineClearKeyHandler.h>
#import <BitmovinPlayerCore/_BMPInternalOfflineContentManager.h>
#import <BitmovinPlayerCore/_BMPPersistenceManager.h>

@protocol _BMPArchiveHelper;
@protocol _BMPMediaSelectionHelper;
@protocol _BMPFairplayHandlerFactory;
@protocol _BMPOfflineFairplayLicenseStorage;
@protocol _BMPOfflineFairplayPlaylistHelper;
@protocol _BMPOfflineContentManagerEventEmitterFactory;
@protocol _BMPOfflineContentUrlMigrationHandler;
@protocol _BMPObjCLoggerService;
@class BMPOfflineSourceConfig;
@class _BMPHashedIdentifier;
@class BMPSourceConfig;
@class BMPDownloadConfig;
@protocol _BMPOfflinePlaylistPostProcessor;
@protocol _BMPOfflineDownloadProgressServiceFactory;
@protocol _BMPOfflineDownloadStorageServiceFactory;
@protocol _BMPOfflineInitializationServiceFactory;
@protocol _BMPOfflineDrmServiceFactory;
@protocol _BMPDownloadService;
@protocol _BMPOfflineTrackExtractor;

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(_DefaultOfflineContentManager)
@interface _BMPDefaultOfflineContentManager : NSObject <_BMPInternalOfflineContentManager>
@property (nonatomic, strong) BMPSourceConfig *sourceConfig;
@property (nonatomic, readonly) BMPOfflineState offlineState;
@property (nonatomic, readonly) BOOL isIncomplete;
@property (nonatomic, readonly) BOOL isUserCancelled;
@property (nonatomic, strong, readonly, nullable) BMPDrmLicenseInformation *offlineDrmLicenseInformation;
@property (nonatomic) BOOL restrictMediaDownloadsToWiFi;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

- (instancetype)initWithSourceConfig:(BMPSourceConfig *)sourceConfig
                          identifier:(_BMPHashedIdentifier *)identifier
                     downloadHandler:(id<_BMPOfflineDownloadsHandler>)downloadHandler
                     clearKeyHandler:(id<_BMPOfflineClearKeyHandler>)clearKeyHandler
               playlistPostProcessor:(id<_BMPOfflinePlaylistPostProcessor>)playlistPostProcessor
                allowsCellularAccess:(BOOL)allowsCellularAccess
           sourceConfigArchiveHelper:(id<_BMPArchiveHelper>)sourceConfigArchiveHelper
                mediaSelectionHelper:(id<_BMPMediaSelectionHelper>)mediaSelectionHelper
              fairplayLicenseStorage:(id<_BMPOfflineFairplayLicenseStorage>)fairplayLicenseStorage
              fairplayHandlerFactory:(id<_BMPFairplayHandlerFactory>)fairplayHandlerFactory
              fairplayPlaylistHelper:(id<_BMPOfflineFairplayPlaylistHelper>)fairplayPlaylistHelper
                  persistenceManager:(_BMPPersistenceManager *)persistenceManager
                       loggerService:(id<_BMPObjCLoggerService>)loggerService
                 eventEmitterFactory:(id<_BMPOfflineContentManagerEventEmitterFactory>)eventEmitterFactory
          contentUrlMigrationHandler:(id<_BMPOfflineContentUrlMigrationHandler>)contentUrlMigrationHandler
              progressServiceFactory:(id<_BMPOfflineDownloadProgressServiceFactory>)progressServiceFactory
               storageServiceFactory:(id<_BMPOfflineDownloadStorageServiceFactory>)storageService
        initializationServiceFactory:(id<_BMPOfflineInitializationServiceFactory>)initializationServiceFactory
                   drmServiceFactory:(id<_BMPOfflineDrmServiceFactory>)drmServiceFactory
                     downloadService:(id<_BMPDownloadService>)downloadService
               offlineTrackExtractor:(id<_BMPOfflineTrackExtractor>)offlineTrackExtractor NS_DESIGNATED_INITIALIZER;

- (instancetype)initWithSourceConfig:(BMPSourceConfig *)sourceConfig
                          identifier:(_BMPHashedIdentifier *)identifier
                     downloadHandler:(id<_BMPOfflineDownloadsHandler>)downloadHandler
                     clearKeyHandler:(id<_BMPOfflineClearKeyHandler>)clearKeyHandler
               playlistPostProcessor:(id<_BMPOfflinePlaylistPostProcessor>)playlistPostProcessor
                allowsCellularAccess:(BOOL)allowsCellularAccess
                  persistenceManager:(_BMPPersistenceManager *)persistenceManager
                       loggerService:(id<_BMPObjCLoggerService>)loggerService;
@end

NS_ASSUME_NONNULL_END
#endif
