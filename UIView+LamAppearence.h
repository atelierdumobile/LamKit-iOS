//
//  UIView+LamAppearence.h
//  LamKit
//
//  Created by Mathieu Godart on 30/05/11.
//  Copyright 2011 L'atelier du mobile. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIkit.h>



/// Modification of the view's appearance.
@interface UIView (LamAppearence)

/// Generate an image of the receiver appearance.
- (UIImage *)generateImage;

/// Round the corners of the view.
/// @param aRadius Roundness of the view's corner.
- (void)roundCornerWithRadius:(CGFloat)aRadius;

/// Add a border to the view.
/// @param aColor Color of the border.
/// @param aWidth Width of the border.
- (void)addBorderWithColor:(UIColor *)aColor width:(CGFloat)aWidth;

/// Apply the given font to all subviews, but keeps the subview's current font size.
/// @param aFontName The name of the font to apply to all subviews.
- (void)setFontForAllSubviewsWithName:(NSString *)aFontName;

/// Apply the given font to all subviews, but keeps the subview's current font size.
/// If the original font was bold, boldFontName is used instead.
/// @param aFontName The name of the font to apply to all subviews.
/// @param aBoldFontName The name of the font to apply to all subviews, when the original font is bold.
- (void)setFontForAllSubviewsWithName:(NSString *)aFontName
                         boldFontName:(NSString *)aBoldFontName;

@end
