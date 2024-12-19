//
// Bitmovin Player iOS SDK
// Copyright (C) 2017, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>
#import <BitmovinPlayerCore/_BMPServiceType.h>
#import <BitmovinPlayerCore/_BMPService.h>
#import <BitmovinPlayerCore/_BMPPlaybackService.h>
#import <BitmovinPlayerCore/_BMPCaptionService.h>
#import <BitmovinPlayerCore/_BMPServiceNamespace.h>
#import <BitmovinPlayerCore/_BMPNamespacedServiceLocator.h>

NS_ASSUME_NONNULL_BEGIN

/// :nodoc:
NS_SWIFT_NAME(_ServiceLocator)
@interface _BMPServiceLocator : NSObject
- (void)addService:(id<_BMPService>)service forNamespace:(_BMPServiceNamespace)serviceNamespace;
- (void)removeService:(_BMPServiceType)serviceType forNamespace:(_BMPServiceNamespace)serviceNamespace;
- (nullable id<_BMPService>)getService:(_BMPServiceType)serviceType forNamespace:(_BMPServiceNamespace)serviceNamespace;
- (id<_BMPNamespacedServiceLocator>)getViewForNamespace:(_BMPServiceNamespace)serviceNamespace;
@end

NS_ASSUME_NONNULL_END
