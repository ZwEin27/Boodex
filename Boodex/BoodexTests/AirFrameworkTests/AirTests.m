//
//  Air_VersionTests.m
//  ZBook
//
//  Created by zwein on 5/24/14.
//  Copyright (c) 2014 lzhteng. All rights reserved.
//

#import "Kiwi.h"
#import "Air_Version.h"

SPEC_BEGIN(AirVersionSpec)

describe(@"Version Number", ^{
    context(@"when initial mathod called", ^{
        
        AirVersion *airVersion = [[AirVersion alloc] init];
        
        it(@"should exit", ^{
            [[AIR_VERSION should] beNonNil];
            [[airVersion should] beNonNil];
        });
        
//        it(@"should equal to 0.0.0", ^{
//            [[AIR_VERSION should] equal:@"0.0.0"];
//        });
        
    });
});
SPEC_END
