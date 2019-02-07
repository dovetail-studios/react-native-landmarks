
#import "RNLandmarks.h"

@import LandmarksIDiOS;

@implementation RNLandmarks

RCT_EXPORT_MODULE();

- (dispatch_queue_t)methodQueue
{
    return dispatch_get_main_queue();
}

RCT_EXPORT_METHOD(initialize:(NSDictionary *)config)
{
  NSString* appId = config[@"appId"];
  NSString* appSecret = config[@"appSecret"];
  NSString* apiKey = config[@"apiKey"];

  LandmarksIDManagerDelegate* landmarksManager = [LandmarksIDManagerDelegate initialize: appId appSecret: appSecret apiKey: apiKey];
  
  [landmarksManager setup];
  
  [LandmarksIDLocationManager getInstance].locationDelegate = landmarksManager;
  [LandmarksIDLocationManager getInstance].sessionDelegate  = landmarksManager;
}


@end
  
