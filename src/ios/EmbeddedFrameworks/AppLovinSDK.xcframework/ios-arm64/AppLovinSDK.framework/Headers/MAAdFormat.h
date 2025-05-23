//
//  MAAdFormat.h
//  AppLovinSDK
//
//  Created by Thomas So on 8/10/18.
//  Copyright © 2020 AppLovin Corporation. All rights reserved.
//

NS_ASSUME_NONNULL_BEGIN

/**
 * This class defines a format of an ad.
 */
@interface MAAdFormat : NSObject <NSCopying>

/**
 * Represents a 320×50 banner advertisement.
 */
@property (class, nonatomic, strong, readonly) MAAdFormat *banner;

/**
 * Represents a 300×250 rectangular advertisement.
 */
@property (class, nonatomic, strong, readonly) MAAdFormat *mrec;

/**
 * Represents a 728×90 leaderboard advertisement (for tablets).
 */
@property (class, nonatomic, strong, readonly) MAAdFormat *leader;

/**
 * Represents a full-screen advertisement.
 */
@property (class, nonatomic, strong, readonly) MAAdFormat *interstitial;

/**
 * Similar to @code +[MaxAdFormat interstitial] @endcode, except that it is shown upon opening the app.
 */
@property (class, nonatomic, strong, readonly) MAAdFormat *appOpen;

/**
 * Similar to @code +[MAAdFormat interstitial] @endcode except that users are given a reward at the end of the advertisement.
 */
@property (class, nonatomic, strong, readonly) MAAdFormat *rewarded;

/**
 * Represents a native advertisement.
 */
@property (class, nonatomic, strong, readonly) MAAdFormat *native;

/**
 * @deprecated Rewarded interstitial ads have been removed and this property will be removed in a future SDK version.
 */
@property (class, nonatomic, strong, readonly) MAAdFormat *rewardedInterstitial __deprecated_msg("Rewarded interstitial ads have been removed and this property will be removed in a future SDK version.");

/**
 * String representing the name of this ad format. Sample values include "BANNER", "MREC", "INTER", "REWARDED", etc.
 */
@property (nonatomic, copy, readonly) NSString *label;

/**
 * The size of the AdView format ad, or @c CGSizeZero otherwise.
 */
@property (nonatomic, assign, readonly) CGSize size;

/**
 * Get the adaptive banner size for the screen width (with safe areas insetted) at the current orientation.
 *
 * <b>Note:</b> The height is the only adaptive dimension; the width spans the screen.
 *
 * <b>Note:</b> Only AdMob / Google Ad Manager currently has support for adaptive banners and the maximum height is 15% the height of the screen.
 *
 * @see <a href="https://developers.applovin.com/en/ios/ad-formats/banner-and-mrec-ads#adaptive-banners">MAX Integration Guide ⇒ iOS ⇒ Banner & MREC Ads ⇒ Adaptive Banners</a>
 */
@property (nonatomic, assign, readonly) CGSize adaptiveSize;

/**
 * Get the adaptive banner size for the provided width at the current orientation.
 *
 * <b>Note:</b> The height is the only adaptive dimension; the width that you provide will be passed back to you in the returned size.
 *
 * <b>Note:</b> Only AdMob / Google Ad Manager currently has support for adaptive banners and the maximum height is 15% the height of the screen.
 *
 * @param width  The width to retrieve the adaptive banner size for, in points.
 *
 * @return The adaptive banner size for the current orientation and width.
 *
 * @see <a href="https://developers.applovin.com/en/ios/ad-formats/banner-and-mrec-ads#adaptive-banners">MAX Integration Guide ⇒ iOS ⇒ Banner & MREC Ads ⇒ Adaptive Banners</a>
 */
- (CGSize)adaptiveSizeForWidth:(CGFloat)width;

/**
 * Whether or not the ad format is fullscreen: that is, an interstitial, or rewarded.
 */
@property (nonatomic, assign, readonly, getter=isFullscreenAd) BOOL fullscreenAd;

/**
 * Whether or not the ad format is one of the following: a banner, leader, or MREC.
 */
@property (nonatomic, assign, readonly, getter=isAdViewAd) BOOL adViewAd;

/**
 * Whether or not the ad format is a banner or leader.
 */
@property (nonatomic, assign, readonly, getter=isBannerOrLeaderAd) BOOL bannerOrLeaderAd;

/**
 * @return human-readable representation of the format.
 */
@property (nonatomic, copy, readonly) NSString *displayName;

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
