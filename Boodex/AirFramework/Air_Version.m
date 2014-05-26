//
//  Air_Version.m
//  ZBook
//
//  Created by zwein on 5/24/14.
//  Copyright (c) 2014 lzhteng. All rights reserved.
//

#import "Air_Version.h"


// ----------------------------------
// Source code
// ----------------------------------


#pragma mark -

@interface AirVersion()
{
	NSUInteger	_major;
	NSUInteger	_minor;
	NSUInteger	_tiny;
	NSString *	_pre;
}
@end

#pragma mark -

@implementation AirVersion

DEF_SINGLETON( AirVersion )

@synthesize major = _major;
@synthesize minor = _minor;
@synthesize tiny = _tiny;
@synthesize pre = _pre;



- (id)init
{
	self = [super init];
	if ( self )
	{
		NSArray * array = [AIR_VERSION componentsSeparatedByString:@" "];
		if ( array.count > 0 )
		{
			if ( array.count > 1 )
			{
				_pre = [array objectAtIndex:1];
			}
			else
			{
				_pre = @"";
			}
			
			NSArray * subvers = [[array objectAtIndex:0] componentsSeparatedByString:@"."];
			if ( subvers.count >= 1 )
			{
				_major = [[subvers objectAtIndex:0] intValue];
			}
			if ( subvers.count >= 2 )
			{
				_minor = [[subvers objectAtIndex:1] intValue];
			}
			if ( subvers.count >= 3 )
			{
				_tiny = [[subvers objectAtIndex:2] intValue];
			}
		}
	}
	return self;
}


@end
