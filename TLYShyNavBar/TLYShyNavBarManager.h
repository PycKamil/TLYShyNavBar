//
//  TLYShyNavBarManager.h
//  TLYShyNavBarDemo
//
//  Created by Mazyad Alabduljaleel on 6/13/14.
//  Copyright (c) 2014 Telly, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/*  CLASS DESCRIPTION:
 *  ==================
 *      Manages the relationship between a scrollView and a view
 *  controller. Must be instantiated and assigned the scrollView
 *  that drives the contraction/expansion, then assigned to the
 *  viewController that needs the functionality. Must be assigned
 *  throught the UIViewController category:
 *      
 *  viewController.shyNavManager = ...;
 *
 */

@protocol TLYShyExtensionView;

@protocol TLYShyNavBarManagerDelegate;

@interface TLYShyNavBarManager : NSObject

@property (nonatomic, weak) id<TLYShyNavBarManagerDelegate> delegate;

/* The view controller that is part of the navigation stack
 * IMPORTANT: Must have access to navigationController
 */
@property (nonatomic, readonly, weak) UIViewController *viewController;

/* The scrollView subclass that will drive the contraction/expansion 
 * IMPORTANT: set this property AFTER assigning its delegate, if needed!
 */
@property (nonatomic, weak) UIScrollView *scrollView;

/* The extension view to be shown beneath the navbar
 */
@property (nonatomic, strong) UIView<TLYShyExtensionView> *extensionView;

/* The container contains the extension view, if any. Exposed to
 * allow the developer to adjust content offset as necessary.
 */
@property (nonatomic, readonly) CGRect extensionViewBounds;

/* Control the resistance when scrolling up/down before the navbar 
 * expands/contracts again.
 */
@property (nonatomic) CGFloat expansionResistance;      // default 200
@property (nonatomic) CGFloat contractionResistance;    // default 0

/* Turn on or off the alpha fade as the navbar contracts/expands. 
 * Defaults to YES
 */
@property (nonatomic, getter = isAlphaFadeEnabled) BOOL alphaFadeEnabled;

@property (nonatomic) BOOL disable;

@end

@protocol TLYShyNavBarManagerDelegate <NSObject>

@optional
- (void)shyNavBarManager:(TLYShyNavBarManager *)manager didChangeExtensionViewHidden:(BOOL)hidden;
- (void)shyNavBarManager:(TLYShyNavBarManager *)manager
 childIsVisibleInPercent:(CGFloat)visiblePercent
          changeAnimated:(BOOL)animated
                withTime:(NSTimeInterval)animationTime;


@end


/*  CATEGORY DESCRIPTION:
 *  =====================
 *      The category described in the TLYShyNavBarManager usage, and it
 *  simply uses associated objects to attatch a TLYShyNavBar to the 
 *  designated view controller.
 *
 *      We also perform some swizzling to pass notifications to the 
 *  TLYShyNavBar. Things like, viewDidLayoutSubviews, viewWillAppear and
 *   Disappear, ... etc.
 */

@interface UIViewController (ShyNavBar)

/* Initially, this is nil, but created for you when you access it */
@property (nonatomic, strong) TLYShyNavBarManager *shyNavBarManager;

@end
