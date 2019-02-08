//
//  CashRewards
//
//  Created by Malcolm Durling on 08/02/19.
//  Copyright © 2019 Facebook. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <React/RCTConvert.h>
#import "RNLandmarks.h"

@import LandmarksIDiOS;


@implementation RNLandmarks

RCT_EXPORT_MODULE();

- (dispatch_queue_t)methodQueue
{
  return dispatch_get_main_queue();
}

RCT_EXPORT_METHOD(initialize: (NSDictionary *)config)
{
  NSString* appId = [RCTConvert NSString:config[@"appId"]];
  NSString* appSecret = [RCTConvert NSString:config[@"appSecret"]];
  NSString* apiKey = [RCTConvert NSString:config[@"apiKey"]];
  
  LandmarksIDManagerDelegate* landmarksManager = [LandmarksIDManagerDelegate initialize: appId appSecret: appSecret apiKey: apiKey];
  
  [landmarksManager setup];
  
  [LandmarksIDLocationManager getInstance].locationDelegate = landmarksManager;
  [LandmarksIDLocationManager getInstance].sessionDelegate  = landmarksManager;
}

RCT_EXPORT_METHOD(startTracking)
{
  [[LandmarksIDManagerDelegate sharedManager] startTracking];
}

RCT_EXPORT_METHOD(stopTracking)
{
  [[LandmarksIDManagerDelegate sharedManager] stopTracking];
}

RCT_EXPORT_METHOD(requestLocationPermissions)
{
  [[LandmarksIDManagerDelegate sharedManager] requestLocationPermissions];
}


@end

