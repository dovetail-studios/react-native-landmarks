
#import "RNLandmarks.h"

@import LandmarksIDiOS;

@implementation RNLandmarks

RCT_EXPORT_MODULE();

- (dispatch_queue_t)methodQueue
{
    return dispatch_get_main_queue();
}

RCT_EXPORT_METHOD(initialize:(NSString *)appId appSecret:(NSString *)appSecret apiKey:(NSString *)apiKey)
{
  LandmarksIDManagerDelegate* landmarksManager = [LandmarksIDManagerDelegate initialize: appId appSecret: appSecret apiKey: apiKey];
  
  [landmarksManager setup];
  
  [LandmarksIDLocationManager getInstance].locationDelegate = landmarksManager;
  [LandmarksIDLocationManager getInstance].sessionDelegate  = landmarksManager;
}


@end
  