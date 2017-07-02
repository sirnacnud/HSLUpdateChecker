//
//  HSLUpdateChecker.h
//  HSL Common Library
//
//  Created by John Arnold on 2012-08-14.
//  Copyright (c) 2012-2013 Handelabra Studio LLC. All rights reserved.
//

/** 
 Simple update checker, requires iOS 5+ and ARC.

 It uses your app's bundle identifier to ask the app store about the app,
 and if the version on the app store is different, it presents an alert with
 the "What's New" text and a button to go directly to the app store.

 The check and alert will only be performed once per new app store version
 (so that if a user declines, they do not continue to get bothered).
*/
@interface HSLUpdateChecker : NSObject <UIAlertViewDelegate>

/** Return whether new version is detected, must call check for update first
 *
 */
+ (BOOL) isNewVersionAvailable;

/** Return a string representing the new version available in the AppStore.
 *
 *  Returns nil if no new version is available.
 */
+ (NSString *) newAppStoreVersionAvailable;

/** Checks for update and presents a UIAlertView if there is an update available.
 
 */
+ (void) checkForUpdate;

/** Checks for update and calls the handler block to present your own UI or do whatever you want.
 
 @param handler Block that is only called if an update is available.
 */
+ (void) checkForUpdateWithHandler:(void (^)(NSString *appStoreVersion, NSString *localVersion, NSString *releaseNotes, NSString *updateURL))handler;

/** Check update handler can be called when debug mode is enabled.
 *  Default is NO.
 *
 *  @param enable
 */
+ (void) enableDebugMode:(BOOL)enable;

/** Enable default notification center post a @"NewVersionAvailable" notification.
 *  Userinfo dictionary:
    @{
        @"LocalVersion": localVersion,
        @"AppStoreVersion" : appStoreVersion,
        @"UpdateURL" : updateUrl
    }
 *  Default is NO.
 *
 *  @param enable
 */
+ (void) enablePostNotification:(BOOL)enable;

/** Launch AppStore page for updating to latest version
 
 */
+ (void) launchAppStore;

@end
