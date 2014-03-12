//
//  UIView+LamAppearence.m
//  Lamkit
//
//  Created by Mathieu Godart on 30/05/11.
//  Copyright 2011 L'atelier du mobile. All rights reserved.
//

#import "UIView+LamAppearence.h"
#import <QuartzCore/QuartzCore.h>



@implementation UIView (LamAppearence)



// Generate an image of the receiver appearance.
// TODO: Improve the target resolution of the generated photo. See that page, to do so:
// http://stackoverflow.com/questions/2500915/how-to-create-an-image-from-a-uiview-uiscrollview
- (UIImage *)generateImage
{
    UIGraphicsBeginImageContext(self.frame.size);
    CGContextRef generatingContext = UIGraphicsGetCurrentContext();
    
    [self.layer renderInContext:generatingContext];
    UIImage *newImage = UIGraphicsGetImageFromCurrentImageContext();
    UIGraphicsEndImageContext();
    
    return newImage;
}



// Round the corners of the view.
- (void)roundCornerWithRadius:(CGFloat)aRadius
{
    self.layer.cornerRadius = aRadius;
}



// Add a border to the view.
- (void)addBorderWithColor:(UIColor *)aColor width:(CGFloat)aWidth
{
    self.layer.borderColor = aColor.CGColor;
    self.layer.borderWidth = aWidth;
}



/// Apply the given font to all subviews, but keeps the subview's current font size.
- (void)setFontForAllSubviewsWithName:(NSString *)aFontName
{
    [self setFontForAllSubviewsWithName:aFontName boldFontName:nil];
}



/// Apply the given font to all subviews, but keeps the subview's current font size.
/// If the original font was bold, boldFontName is used instead.
- (void)setFontForAllSubviewsWithName:(NSString *)aFontName
                         boldFontName:(NSString *)aBoldFontName
{
    // Recursive call to all subviews.
    for (UIView *aView in self.subviews) {
        [aView setFontForAllSubviewsWithName:aFontName
                                boldFontName:aBoldFontName];
    }
	
    // Do it to myself.
    if ([self respondsToSelector:@selector(setFont:)] &&
        [self respondsToSelector:@selector(font)]) {
        
        UIFont *myFont = [(id)self font];
        NSString *myFontName = [myFont fontName];

        // Check if the font is bold and if a bold font has been provided.
        BOOL isBlod = NO;
        if (aBoldFontName != nil) isBlod = isABoldFontName(myFontName);
                
        UIFont *newFont;
        if (isBlod) newFont = [UIFont fontWithName:aBoldFontName size:[myFont pointSize]];
        else newFont = [UIFont fontWithName:aFontName size:[myFont pointSize]];
        
        [(id)self setFont:newFont];
    }
}



BOOL isABoldFontName(NSString *fontName)
{
    if ([fontName rangeOfString:@"bold" options:NSCaseInsensitiveSearch].location != NSNotFound &&
        fontName != nil)
    {
        return YES;
    }
    return NO;
}



@end






















