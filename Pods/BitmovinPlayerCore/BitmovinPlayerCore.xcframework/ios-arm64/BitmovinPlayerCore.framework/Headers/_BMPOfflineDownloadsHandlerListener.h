#if !TARGET_OS_TV
//
// Bitmovin Player iOS SDK
// Copyright (C) 2017, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>

@protocol _BMPDownloadTask;
@protocol _BMPAssetDownloadTask;
@protocol _BMPOfflineDownloadsHandler;
@class _BMPLegacyAssetDownloadTask;

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(_OfflineDownloadsHandlerListener)
@protocol _BMPOfflineDownloadsHandlerListener <NSObject>
@optional
- (void)offlineDownloadsHandler:(id<_BMPOfflineDownloadsHandler>)handler
         didRestoreDownloadTask:(id<_BMPDownloadTask>)downloadTask;
- (void)offlineDownloadsHandler:(id<_BMPOfflineDownloadsHandler>)handler
                   downloadTask:(id<_BMPDownloadTask>)downloadTask
              willDownloadToURL:(NSString *)relativePath;
- (void)offlineDownloadsHandler:(id<_BMPOfflineDownloadsHandler>)handler
                   downloadTask:(id<_BMPDownloadTask>)downloadTask
                  didProgressTo:(double)percent
              forMediaSelection:(AVMediaSelection *)mediaSelection;
- (void)offlineDownloadsHandler:(id<_BMPOfflineDownloadsHandler>)handler
                   downloadTask:(id<_BMPDownloadTask>)downloadTask
   didCompleteForMediaSelection:(AVMediaSelection *)mediaSelection;
- (void)offlineDownloadsHandler:(id<_BMPOfflineDownloadsHandler>)handler
                   downloadTask:(id<_BMPDownloadTask>)downloadTask
           didCompleteWithError:(nullable NSError *)error;
- (void)offlineDownloadsHandler:(id<_BMPOfflineDownloadsHandler>)handler
 downloadTaskNeedsToBeRecreated:(id<_BMPDownloadTask>)downloadTask;
- (void)offlineDownloadsHandler:(id<_BMPOfflineDownloadsHandler>)handler
  downloadTaskNeedsToBeMigrated:(id<_BMPDownloadTask>)downloadTask;
- (void)offlineDownloadsHandler:(id<_BMPOfflineDownloadsHandler>)handler
didRestoreLegacyAssetDownloadTask:(_BMPLegacyAssetDownloadTask *)legacyAssetDownloadTask;
@end

NS_ASSUME_NONNULL_END
#endif
