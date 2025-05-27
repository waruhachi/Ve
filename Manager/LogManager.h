//
//  LogManager.h
//  Vē
//
//  Created by Alexandra Aurora Göttlicher
//

#import <roothide.h>
#import <Foundation/Foundation.h>

@class Log;
@class BBBulletin;

static NSString* const kLogsPath = jbroot(@"/var/mobile/Library/codes.aurora.ve/logs.json");
static NSString* const kLogsAttachmentPath = jbroot(@"/var/mobile/Library/codes.aurora.ve/attachments/");

@interface LogManager : NSObject {
    NSFileManager* _fileManager;
}
@property(nonatomic)BOOL saveLocalAttachments;
@property(nonatomic)BOOL saveRemoteAttachments;
@property(nonatomic)NSUInteger logLimit;
@property(nonatomic)BOOL automaticallyDeleteLogs;
+ (instancetype)sharedInstance;
- (void)addLogForBulletin:(BBBulletin *)bulletin;
- (void)removeLog:(Log *)log;
- (NSArray *)getAttachmentsForLog:(Log *)log;
- (NSMutableArray *)getLogsFromJson:(NSMutableDictionary *)json;
- (NSMutableDictionary *)getJson;
@end
