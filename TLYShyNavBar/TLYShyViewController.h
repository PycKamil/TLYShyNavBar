//
//  TLYShyViewController.h
//  TLYShyNavBarDemo
//
//  Created by Mazyad Alabduljaleel on 6/14/14.
//  Copyright (c) 2014 Telly, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

extern const CGFloat contractionVelocity;

typedef CGPoint(^TLYShyViewControllerExpandedCenterBlock)(UIView *view);
typedef CGFloat(^TLYShyViewControllerContractionAmountBlock)(UIView *view);

/*  CLASS DESCRIPTION:
 *  ==================
 *      A shy view is a view that contracts when a scrolling event is
 *  triggered. We use this class to control the operations we perform on
 *  the shy view.
 *
 *      We are making some dangerous assumtions here!!! Most importantly,
 *  the TLYShyViewController can only be a maximum depth of 2. Adding a
 *  child to an already childified node is not supported.
 */
@protocol TLYShyViewControllerDelegate;

@interface TLYShyViewController : NSObject

@property (nonatomic, getter = isContracted, readonly) BOOL contracted;
@property (nonatomic, weak) id<TLYShyViewControllerDelegate> delegate;

@property (nonatomic, weak) TLYShyViewController *child;
@property (nonatomic, weak) UIView *view;

@property (nonatomic, copy) TLYShyViewControllerExpandedCenterBlock expandedCenter;
@property (nonatomic, copy) TLYShyViewControllerContractionAmountBlock contractionAmount;

@property (nonatomic) BOOL hidesSubviews;
@property (nonatomic) BOOL hidesAfterContraction;

@property (nonatomic) BOOL alphaFadeEnabled;

@property (nonatomic, readonly) CGFloat totalHeight;

- (CGFloat)updateYOffset:(CGFloat)deltaY;

- (CGFloat)snap:(BOOL)contract;

- (CGFloat)expand;
- (CGFloat)contract;

- (CGFloat)titleLabelHeight;
- (void)showAndConfigureTitleLabelWithText:(NSString *)text fontName:(NSString *)fontName tapGestureBlock:(void(^)(void))tapGestureBlock;
- (void)hideTitleLabel;

@end

@protocol TLYShyViewControllerDelegate <NSObject>

@optional
- (void)shyViewController:(TLYShyViewController *)shyViewController didChangeChildViewHidden:(BOOL)childIsHidden;
- (void)shyViewController:(TLYShyViewController *)shyViewController
  childIsVisibleInPercent:(CGFloat)visiblePercent
           changeAnimated:(BOOL)animated
                 withTime:(NSTimeInterval)animationTime;

@end

