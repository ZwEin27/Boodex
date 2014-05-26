//
//  Air_Version.h
//  ZBook
//
//  Created by zwein on 5/24/14.
//  Copyright (c) 2014 lzhteng. All rights reserved.
//

#import "Air_Precompile.h"
#import "Air_Singleton.h"

@interface AirVersion : NSObject

AS_SINGLETON( AirVersion )

@property (nonatomic, readonly) NSUInteger	major;
@property (nonatomic, readonly) NSUInteger	minor;
@property (nonatomic, readonly) NSUInteger	tiny;
@property (nonatomic, readonly) NSString *	pre;

@end