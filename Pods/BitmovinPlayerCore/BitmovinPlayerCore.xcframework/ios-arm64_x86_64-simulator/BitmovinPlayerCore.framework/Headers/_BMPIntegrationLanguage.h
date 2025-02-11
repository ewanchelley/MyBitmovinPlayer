//
// Bitmovin Player iOS SDK
// Copyright (C) 2021, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>

/**
 Is used to detect the language from which our SDK is used from
 */
typedef NSString * _BMPIntegrationLanguage NS_TYPED_ENUM NS_SWIFT_NAME(_IntegrationLanguage);
NS_SWIFT_NAME(_IntegrationLanguage.objc) static _BMPIntegrationLanguage const _BMPIntegrationLanguageObjC = @"objc";
NS_SWIFT_NAME(_IntegrationLanguage.swift) static _BMPIntegrationLanguage const _BMPIntegrationLanguageSwift = @"swift";
NS_SWIFT_NAME(_IntegrationLanguage.reactNativeBitmovin) static _BMPIntegrationLanguage const _BMPIntegrationLanguageReactNativeBitmovin = @"react-native-bitmovin";
NS_SWIFT_NAME(_IntegrationLanguage.reactNativeOther) static _BMPIntegrationLanguage const _BMPIntegrationLanguageReactNativeOther = @"react-native-other";
NS_SWIFT_NAME(_IntegrationLanguage.flutterBitmovin) static _BMPIntegrationLanguage const _BMPIntegrationLanguageFlutterBitmovin = @"flutter-bitmovin";
NS_SWIFT_NAME(_IntegrationLanguage.flutterOther) static _BMPIntegrationLanguage const _BMPIntegrationLanguageFlutterOther = @"flutter-other";
