/*
 *
 * Modified BSD license.
 *
 * Based on source code copyright (c) 2010-2012 Florent Pillet,
 * Copyright (c) 2012-2013 Sung-Taek, Kim <stkim1@colorfulglue.com> All Rights
 * Reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * Redistributions of  source code  must retain  the above  copyright notice,
 * this list of  conditions and the following  disclaimer. Redistributions in
 * binary  form must  reproduce  the  above copyright  notice,  this list  of
 * conditions and the following disclaimer  in the documentation and/or other
 * materials  provided with  the distribution.  Neither the  name of Sung-Tae
 * k Kim nor the names of its contributors may be used to endorse or promote
 * products  derived  from  this  software  without  specific  prior  written
 * permission.  THIS  SOFTWARE  IS  PROVIDED BY  THE  COPYRIGHT  HOLDERS  AND
 * CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT
 * NOT LIMITED TO, THE IMPLIED  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A  PARTICULAR PURPOSE  ARE DISCLAIMED.  IN  NO EVENT  SHALL THE  COPYRIGHT
 * HOLDER OR  CONTRIBUTORS BE  LIABLE FOR  ANY DIRECT,  INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY,  OR CONSEQUENTIAL DAMAGES (INCLUDING,  BUT NOT LIMITED
 * TO, PROCUREMENT  OF SUBSTITUTE GOODS  OR SERVICES;  LOSS OF USE,  DATA, OR
 * PROFITS; OR  BUSINESS INTERRUPTION)  HOWEVER CAUSED AND  ON ANY  THEORY OF
 * LIABILITY,  WHETHER  IN CONTRACT,  STRICT  LIABILITY,  OR TORT  (INCLUDING
 * NEGLIGENCE  OR OTHERWISE)  ARISING  IN ANY  WAY  OUT OF  THE  USE OF  THIS
 * SOFTWARE,   EVEN  IF   ADVISED  OF   THE  POSSIBILITY   OF  SUCH   DAMAGE.
 *
 */


#import <Foundation/Foundation.h>
#import <CFNetwork/CFNetwork.h>
#import <Security/SecureTransport.h>

#import "LoggerPreferenceManager.h"
#import "LoggerTransportManager.h"

#import "LoggerConnection.h"

@interface LoggerTransport : NSObject <LoggerConnectionDelegate>
{
	NSMutableArray				*connections;
	NSString					*failureReason;
	
	BOOL						secure;
	BOOL						active;
	BOOL						ready;
	BOOL						failed;
	
	// stkim1_jan.29,2013
	// tag of transport. This is more of an unique id for views to identify
	int32_t						tag;
}
@property (nonatomic, assign)	BOOL					secure;
@property (nonatomic, readonly) BOOL					active;
@property (nonatomic, readonly) BOOL					failed;
@property (nonatomic, readonly) BOOL					ready;
@property (nonatomic, readwrite) int32_t				tag;
@property (nonatomic, readonly) NSMutableArray			*connections;
@property (nonatomic, retain) NSString					*failureReason;

- (void)startup;
- (void)shutdown;
- (void)restart;
- (void)addConnection:(LoggerConnection *)aConnection;
- (void)removeConnection:(LoggerConnection *)aConnection;

- (NSString *)transportInfoString;
- (NSString *)transportStatusString;

- (NSDictionary *)status;
- (void)reportStatusToManager:(NSDictionary *)aStatusDict;
- (void)reportErrorToManager:(NSDictionary *)anErrorDict;
@end
