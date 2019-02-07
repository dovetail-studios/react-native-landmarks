//
//  LandmarksIDManagerDelegate.h
//  LandmarksID-ObjectiveC
//
//  Created by Nisal Periyapperuma on 28/2/18.
//  Copyright © 2018 Nisal Periyapperuma. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <CoreLocation/CoreLocation.h>
@import BDPointSDK;

@interface LandmarksIDManagerDelegate : NSObject <BDPSessionDelegate, BDPLocationDelegate, CLLocationManagerDelegate>

@property (nonatomic, strong) CLLocationManager* locationManager;

@property (nonatomic, strong) NSString *appIdentifier;
@property (nonatomic, strong) NSString *appSecret;
@property (nonatomic, strong) NSString* apiURL;
@property (nonatomic, strong) NSString* debugURL;
@property (nonatomic, strong) NSString* apiKey;
@property (nonatomic, strong) NSString* username;
@property (nonatomic, strong) NSString* packageName;

@property (nonatomic, strong) NSString* deviceId;
@property (nonatomic, strong) NSString* vendorId;
@property (nonatomic, strong) NSString* sessionId;
@property (nonatomic, strong) NSString* appBuildVersion;
@property (nonatomic, strong) NSString* osVersion;
@property (nonatomic) BOOL adTrackingEnabled;

// APP LEVEL CONFIG
@property BOOL discoveryEnabled;
@property BOOL locationOptimisedEnabled;
@property CLLocationDistance distanceFilter;
@property BOOL shouldCollectData;
@property NSString* clientId;

@property (nonatomic, strong) NSString* customerId;

@property (nonatomic, strong) NSURLSession *requestSession;
@property (nonatomic) UIBackgroundTaskIdentifier *backgroundUpdateTask;

@property NSString *lastSourceEventId;
@property NSString *lastFenceId;
@property BDLocationInfo *lastLocation;

@property NSMutableDictionary *trackLastLocation;
@property NSMutableArray *customData;

@property (nonatomic, strong) NSMutableArray *events;
@property (assign) int LOCount;
@property (assign) int LODCount;

@property (nonatomic, strong) NSString *allLogs;

@property (nonatomic) BOOL serverConfigLoaded;

@property (nonatomic) BOOL debug;
@property (nonatomic) BOOL notify;

- (id)init;

+ (LandmarksIDManagerDelegate*)initialize:(NSString *)appIdentifier
                                  appSecret:(NSString *)appSecret
                                    apiKey:(NSString *)apiKey;


+ (LandmarksIDManagerDelegate*)sharedManager;
    
- (void)setup;

- (void)startSession;
- (void)stopSession;

- (void)startTracking;
- (void)stopTracking;

- (void)setupNotifications;
- (void)testRequest;

// Handle Custom Data

- (void) setCustomInt: (NSString *)key
                value: (int) value;

- (void) setCustomFloat: (NSString *)key
                value: (float) value;

- (void) setCustomString: (NSString *)key
                  value: (NSString*) value;


- (NSString *) customerId;
- (void) setCustomerId: (NSString *)customerId;

// Handle Location Permissions

- (void)requestLocationPermissions;

// Client side kill switch

- (void)stopRecordingData;
- (void)restartRecordingData;
- (BOOL)isAllowedToRecordData;

@end


