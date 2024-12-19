#if !TARGET_OS_TV
//
// Bitmovin Player iOS SDK
// Copyright (C) 2017, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <BitmovinPlayerCore/_BMPDownloadTask.h>
#import <AVFoundation/AVFoundation.h>

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(_AssetDownloadTask)
@protocol _BMPAssetDownloadTask <_BMPDownloadTask>
@property (nonatomic, nonnull, strong, readonly) AVURLAsset *URLAsset;
@end

NS_ASSUME_NONNULL_END
#endif
