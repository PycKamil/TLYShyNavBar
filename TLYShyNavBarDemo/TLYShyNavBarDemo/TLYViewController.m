//
//  TLYViewController.m
//  TLYShyNavBarDemo
//
//  Created by Mazyad Alabduljaleel on 6/12/14.
//  Copyright (c) 2014 Telly, Inc. All rights reserved.
//

#import "TLYViewController.h"
#import "TLYExtensionView.h"

@interface TLYViewController () <TLYShyNavBarManagerDelegate>

@property (weak, nonatomic) IBOutlet UIScrollView *scrollView;
@property (weak, nonatomic) IBOutlet UIImageView *imageView;

@end

@implementation TLYViewController

- (id)initWithCoder:(NSCoder *)aDecoder
{
    self = [super initWithCoder:aDecoder];
    if (self) {
        self.title = @"WTFox Say";
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    TLYExtensionView *view = [[TLYExtensionView alloc] initWithFrame:CGRectMake(0, 0, CGRectGetWidth(self.view.bounds), 44.f)];
    view.backgroundColor = [UIColor redColor];
    view.needsUpdate = YES;
    
    /* Library code */
    self.shyNavBarManager.scrollView = self.scrollView;
    self.shyNavBarManager.delegate = self;
    /* Can then be remove by setting the ExtensionView to nil */
    [self.shyNavBarManager setExtensionView:view];
}

- (void)viewDidLayoutSubviews
{
    [super viewDidLayoutSubviews];
    self.scrollView.contentSize = self.imageView.bounds.size;
}

- (void)shyNavBarManager:(TLYShyNavBarManager *)manager didChangeExtensionViewHidden:(BOOL)hidden {
    NSLog(@"Hidden %i", hidden);
}

- (void)shyNavBarManager:(TLYShyNavBarManager *)manager childIsVisibleInPercent:(CGFloat)visiblePercent changeAnimated:(BOOL)animated withTime:(NSTimeInterval)animationTime {
    NSLog(@"visiblePercent: %f \nchangeAnimated: %i \nanimationTime: %f", visiblePercent, animated, animationTime);
}

@end
