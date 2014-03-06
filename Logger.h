//
//  Logger.h
//  LamKit
//
//  Created by Mathieu Godart.
//  Copyright 2010 L'atelier du mobile. All rights reserved.
//

#import "LoggerClient.h"
#import "LamFunkyHelpers.h"



// Log level usages:
// Level 0: errors only!
// Level 1: important informations, app states…
// Level 2: less important logs, network requests…
// Level 3: network responses, datas and images…
// Level 4: really not important stuff



#ifdef DEBUG
    #define L(x)                            LOG_EXPR(x)
	#define NSLog(...)						LamLogMessageF(__FILE__, __LINE__, __FUNCTION__, @"Other", 0, __VA_ARGS__)
    #define LoggerModel(level, ...)         LamLogMessageF(__FILE__, __LINE__, __FUNCTION__, @"Model", level, __VA_ARGS__)
    #define LoggerAd(level, ...)            LamLogMessageF(__FILE__, __LINE__, __FUNCTION__, @"Ad and Stat", level, __VA_ARGS__)
	#define LoggerNetwork(level, ...)       LamLogMessageF(__FILE__, __LINE__, __FUNCTION__, @"Network", level, __VA_ARGS__)
	#define LoggerView(level, ...)          LamLogMessageF(__FILE__, __LINE__, __FUNCTION__, @"View", level, __VA_ARGS__)
	#define LoggerError(level, ...)         LamLogMessageF(__FILE__, __LINE__, __FUNCTION__, @"Error", level, __VA_ARGS__)
	#define LoggerService(level, ...)       LamLogMessageF(__FILE__, __LINE__, __FUNCTION__, @"Service", level, __VA_ARGS__)
	#define LoggerFlux(level, ...)      	LamLogMessageF(__FILE__, __LINE__, __FUNCTION__, @"Flux", level, __VA_ARGS__)
	#define LoggerLocation(level, ...)      LamLogMessageF(__FILE__, __LINE__, __FUNCTION__, @"Location", level, __VA_ARGS__)
	#define LoggerMemory(level, ...)     	LamLogMessageF(__FILE__, __LINE__, __FUNCTION__, @"Memory", level, __VA_ARGS__)
	#define LoggerServer(level, ...)       	LamLogMessageF(__FILE__, __LINE__, __FUNCTION__, @"Server", level, __VA_ARGS__)
	#define LoggerPush(level, ...)       	LamLogMessageF(__FILE__, __LINE__, __FUNCTION__, @"Push", level, __VA_ARGS__)
	#define LoggerApp(level, ...)       	LamLogMessageF(__FILE__, __LINE__, __FUNCTION__, @"App", level, __VA_ARGS__)
	#define LoggerFile(level, ...)          LamLogMessageF(__FILE__, __LINE__, __FUNCTION__, @"File", level, __VA_ARGS__)
    #define LoggerLam(level, ...)           LamLogMessageF(__FILE__, __LINE__, __FUNCTION__, @"Lam", level, __VA_ARGS__)
	#define LoggerSharing(level, ...)       LamLogMessageF(__FILE__, __LINE__, __FUNCTION__, @"Sharing", level, __VA_ARGS__)
	#define LoggerData(level, ...)          LamLogMessageF(__FILE__, __LINE__, __FUNCTION__, @"Data", level, __VA_ARGS__)

#else
    #define L(x)                              while(0){}
	#define NSLog(...)					  	  LogMessageCompat(__VA_ARGS__)
	#define LoggerModel(...)      			  while(0){}
	#define LoggerAd(...)        			  while(0){}
	#define LoggerNetwork(...)   			  while(0){}
	#define LoggerView(...)      			  while(0){}
	#define LoggerError(...)     			  while(0){}
	#define LoggerService(level, ...)      	  while(0){}
	#define LoggerFlux(level, ...)      	  while(0){}
	#define LoggerLocation(level, ...)        while(0){}
	#define LoggerMemory(level, ...)       	  while(0){}
	#define LoggerServer(level, ...)       	  while(0){}
	#define LoggerPush(level, ...)       	  while(0){}
	#define LoggerApp(level, ...)       	  while(0){}
	#define LoggerKiwi(level, ...)       	  while(0){}
    #define LoggerLam(level, ...)       	  while(0){}
	#define LoggerFile(level, ...)       	  while(0){}
	#define LoggerSharing(level, ...)		  while(0){}
	#define LoggerVideoDL(level, ...)		  while(0){}
	#define LoggerGraph(level, ...)		  	  while(0){}
	#define LoggerGraphRange(level, ...)	  while(0){}
	#define LoggerData(...)                   while(0){}

#endif


//#define DEBUG_DATA
//#ifdef DEBUG_DATA
//	#define LoggerData(level, ...)            LamLogMessageF(__FILE__, __LINE__, __FUNCTION__, @"Data", level, __VA_ARGS__)
//#else
//	#define LoggerData(...)                   while(0){}
//#endif


/// Starts the NSLogger with the proper user name.
/// Automatically configured by Lam podspec (it uses the setting LAM_BUILD_USERNAME="${USER}").
/// To use it, just add this macro call to your main() function.
#define LamLoggerStart() LoggerSetupBonjour(LoggerGetDefaultLogger(), NULL, \
                             CFSTR(xstr(LAM_BUILD_USERNAME)))



/// Override the tag string by @"Error" when the log level is 0.
static inline void LamLogMessageF(const char *filename, int lineNumber, const char *functionName,
                                  NSString *domain, int level, NSString *format, ...)
{
    if (level == 0) domain = @"Error";
    
    va_list args;
    va_start(args, format);
    LogMessageF_va(filename, lineNumber, functionName, domain, level, format, args);
    va_end(args);
}



// Adds LOG_EXPR.
//#import "VTPG_LogExpr.h"

