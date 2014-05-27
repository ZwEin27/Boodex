//
//  BoodexViewController.m
//  Boodex
//
//  Created by zwein on 5/26/14.
//  Copyright (c) 2014 lzhteng. All rights reserved.
//

#import "BoodexViewController.h"

@interface BoodexViewController ()

@end

@implementation BoodexViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
    
    UILabel *label = [[UILabel alloc] init];
    label.frame = CGRectMake(40, 40, 100, 50);
    [label setTextColor:[UIColor redColor]];
    label.text = @"hahahahahahhahahahaha";
    
    [self.view addSubview:label];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
