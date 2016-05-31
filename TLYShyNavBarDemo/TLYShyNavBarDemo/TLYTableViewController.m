//
//  TLYTableViewController.m
//  TLYShyNavBarDemo
//
//  Created by Mazyad Alabduljaleel on 11/13/15.
//  Copyright © 2015 Telly, Inc. All rights reserved.
//

#import "TLYTableViewController.h"
#import "TLYExtensionView.h"

@interface TLYTableViewController () <UITableViewDataSource, UITableViewDelegate>

@property (nonatomic, assign) IBInspectable BOOL shortScrollView;

@property (nonatomic, weak) IBOutlet UITableView *tableView;

@end

@implementation TLYTableViewController

#pragma mark - View Life Cycle

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    TLYExtensionView *view = view = [[TLYExtensionView alloc] initWithFrame:CGRectMake(0, 0, CGRectGetWidth(self.view.bounds), 40.f)];
    view.backgroundColor = [UIColor redColor];
    
    /* Library code */
    self.shyNavBarManager.scrollView = self.tableView;
    /* Can then be remove by setting the ExtensionView to nil */
    [self.shyNavBarManager setExtensionView:view];
}

#pragma mark - UITableViewDataSource

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    return self.shortScrollView ? 1 : 6;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return 5;
}

- (NSString *)tableView:(UITableView *)tableView titleForHeaderInSection:(NSInteger)section
{
    return @"Section Header";
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"Cell"
                                                            forIndexPath:indexPath];
    
    cell.textLabel.text = @"Sample Data";
    
    return cell;
}

@end
