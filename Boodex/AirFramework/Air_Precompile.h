//
//  Air_Precompile.h
//  ZBook
//
//  Created by zwein on 5/24/14.
//  Copyright (c) 2014 lzhteng. All rights reserved.
//

//#ifndef Air_Precompile_h
//#define Air_Precompile_h

#ifndef __IPHONE_4_0
#warning "AirFramework only available in iOS SDK 4.0 and later."
#endif

// ----------------------------------
// Version
// ----------------------------------

#undef	AIR_VERSION
#define AIR_VERSION		@"0.0.0"

// ----------------------------------
// Global include headers
// ----------------------------------

//#import <stdio.h>
//#import <stdlib.h>
//#import <stdint.h>
//#import <string.h>
//#import <assert.h>
//#import <errno.h>
//
//#import <sys/errno.h>
//#import <sys/sockio.h>
//#import <sys/ioctl.h>
//#import <sys/types.h>
//#import <sys/socket.h>
//
//#import <math.h>
//#import <unistd.h>
//#import <limits.h>
//#import <execinfo.h>
//
//#import <netdb.h>
//#import <net/if.h>
//#import <net/if_dl.h>
//#import <netinet/in.h>
//#import <arpa/inet.h>
//#import <ifaddrs.h>
//
//#import <mach/mach.h>
//#import <malloc/malloc.h>
//#import <libxml/tree.h>

#ifdef __OBJC__

#if (TARGET_OS_IPHONE || TARGET_IPHONE_SIMULATOR)

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <QuartzCore/QuartzCore.h>
#import <AudioToolbox/AudioToolbox.h>
#import <TargetConditionals.h>

#import <AVFoundation/AVFoundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <CoreVideo/CoreVideo.h>
#import <CoreMedia/CoreMedia.h>
#import <CoreImage/CoreImage.h>
#import <CoreLocation/CoreLocation.h>

#else	// #if (TARGET_OS_IPHONE || TARGET_IPHONE_SIMULATOR)

#import <Foundation/Foundation.h>
#import <Cocoa/Cocoa.h>
#import <AppKit/AppKit.h>
#import <WebKit/WebKit.h>

#endif	// #if (TARGET_OS_IPHONE || TARGET_IPHONE_SIMULATOR)

#import <objc/runtime.h>
#import <objc/message.h>
#import <CommonCrypto/CommonDigest.h>

#endif	// #ifdef __OBJC__

// ----------------------------------
// Option values
// ----------------------------------

#undef	__ON__
#define __ON__		(1)

#undef	__OFF__
#define __OFF__		(0)

#undef	__AUTO__

#if defined(_DEBUG) || defined(DEBUG)
#define __AUTO__	(1)
#else
#define __AUTO__	(0)
#endif

// ----------------------------------
// Global compile option
// ----------------------------------

#define __AIR_DEVELOPMENT__				(__AUTO__)
#define __AIR_LOG__						(__AUTO__)
#define __AIR_UNITTEST__				(__OFF__)

#pragma mark -

#if defined(__AIR_LOG__) && __AIR_LOG__
#undef	NSLog
#define	NSLog	AirLog
#endif	// #if (__ON__ == __AIR_LOG__)

#undef	UNUSED
#define	UNUSED( __x ) \
{ \
id __unused_var__ __attribute__((unused)) = (__x); \
}

#undef	ALIAS
#define	ALIAS( __a, __b ) \
__typeof__(__a) __b = __a;

#pragma mark -

#if !defined(__clang__) || __clang_major__ < 3

#ifndef __bridge
#define __bridge
#endif

#ifndef __bridge_retain
#define __bridge_retain
#endif

#ifndef __bridge_retained
#define __bridge_retained
#endif

#ifndef __autoreleasing
#define __autoreleasing
#endif

#ifndef __strong
#define __strong
#endif

#ifndef __unsafe_unretained
#define __unsafe_unretained
#endif

#ifndef __weak
#define __weak
#endif

#endif

#if __has_feature(objc_arc)

#define AIR_PROP_RETAIN					strong
#define AIR_PROP_ASSIGN					assign

#define AIR_RETAIN( x )					(x)
#define AIR_RELEASE( x )				(x)
#define AIR_AUTORELEASE( x )			(x)

#define AIR_BLOCK_COPY( x )				(x)
#define AIR_BLOCK_RELEASE( x )			(x)
#define AIR_SUPER_DEALLOC()

#define AIR_AUTORELEASE_POOL_START()	@autoreleasepool {
#define AIR_AUTORELEASE_POOL_END()		}

#else

#define AIR_PROP_RETAIN					retain
#define AIR_PROP_ASSIGN					assign

#define AIR_RETAIN( x )					[(x) retain]
#define AIR_RELEASE( x )				[(x) release]
#define AIR_AUTORELEASE( x )			[(x) autorelease]

#define AIR_BLOCK_COPY( x )				Block_copy( x )
#define AIR_BLOCK_RELEASE( x )			Block_release( x )
#define AIR_SUPER_DEALLOC()				[super dealloc]

#define AIR_AUTORELEASE_POOL_START()	NSAutoreleasePool * __pool = [[NSAutoreleasePool alloc] init];
#define AIR_AUTORELEASE_POOL_END()		[__pool release];

#endif

#undef	AIR_DEPRECATED
#define	AIR_DEPRECATED	__attribute__((deprecated))

#undef	AIR_EXTERN
#if defined(__cplusplus)
#define AIR_EXTERN		extern "C"
#else	// #if defined(__cplusplus)
#define AIR_EXTERN		extern
#endif	// #if defined(__cplusplus)

#pragma mark -

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= 60000

#define UILineBreakMode					NSLineBreakMode
#define UILineBreakModeWordWrap			NSLineBreakByWordWrapping
#define UILineBreakModeCharacterWrap	NSLineBreakByCharWrapping
#define UILineBreakModeClip				NSLineBreakByClipping
#define UILineBreakModeHeadTruncation	NSLineBreakByTruncatingHead
#define UILineBreakModeTailTruncation	NSLineBreakByTruncatingTail
#define UILineBreakModeMiddleTruncation	NSLineBreakByTruncatingMiddle

#define UITextAlignmentLeft				NSTextAlignmentLeft
#define UITextAlignmentCenter			NSTextAlignmentCenter
#define UITextAlignmentRight			NSTextAlignmentRight
#define	UITextAlignment					NSTextAlignment

#endif	// #if __IPHONE_OS_VERSION_MAX_ALLOWED >= 60000

#ifndef	weakify
#if __has_feature(objc_arc)
#define weakify( x )	autoreleasepool{} __weak __typeof__(x) __weak_##x##__ = x;
#else	// #if __has_feature(objc_arc)
#define weakify( x )	autoreleasepool{} __block __typeof__(x) __block_##x##__ = x;
#endif	// #if __has_feature(objc_arc)
#endif	// #ifndef	weakify

#ifndef	normalize
#if __has_feature(objc_arc)
#define normalize( x )	try{} @finally{} __typeof__(x) x = __weak_##x##__;
#else	// #if __has_feature(objc_arc)
#define normalize( x )	try{} @finally{} __typeof__(x) x = __block_##x##__;
#endif	// #if __has_feature(objc_arc)
#endif	// #ifndef	@normalize

#pragma mark -

// ----------------------------------
// Preload headers
// ----------------------------------

//#import "Air_Vendor.h"


//#endif
