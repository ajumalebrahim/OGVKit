//
//  OGVDecoder.h
//  OgvDemo
//
//  Created by Brion on 11/2/13.
//  Copyright (c) 2013 Brion Vibber. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef struct {
    unsigned char *YData;
    unsigned char *CbData;
    unsigned char *CrData;
    
    unsigned int YStride;
    unsigned int CbStride;
    unsigned int CrStride;
} OGVFrameBuffer;

typedef struct {
    float **pcm;
    unsigned int sampleCount;
} OGVAudioBuffer;

@interface OGVDecoder : NSObject

@property BOOL dataReady;

@property BOOL hasVideo;
@property int frameWidth;
@property int frameHeight;
@property float frameRate;
@property int pictureWidth;
@property int pictureHeight;
@property int pictureOffsetX;
@property int pictureOffsetY;
@property int hDecimation;
@property int vDecimation;

@property BOOL hasAudio;
@property int audioChannels;
@property int audioRate;

@property(strong) void (^onframe)(OGVFrameBuffer);
@property(strong) void (^onaudio)(OGVAudioBuffer);

- (id)init;
- (void)receiveInput:(NSData *)data;
- (BOOL)process;

@end