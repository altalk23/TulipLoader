#import <Foundation/Foundation.h>
#include "FileTraversal.h"

#include <mach-o/loader.h>
#include <mach/machine.h>
#include <mach-o/fat.h>

void traverse_directories(char const* searchpaths[], size_t size, folder_callback cb) {
    for (size_t i = 0; i < size; i++) {
        NSString* nspath = [NSString stringWithUTF8String:searchpaths[i]];
        NSDirectoryEnumerator *enumerator = [[NSFileManager defaultManager]
            enumeratorAtURL:[NSURL URLWithString:nspath]
            includingPropertiesForKeys:nil
            options:0
            errorHandler:^BOOL(NSURL *url, NSError *error) {
                // Handle the error.
                // Return YES if the enumeration should continue after the error.
                return YES;
        }];

        for (NSURL *url in enumerator) { 
            NSError *error;
            NSNumber *isDirectory = nil;
            if (! [url getResourceValue:&isDirectory forKey:NSURLIsDirectoryKey error:&error]) {
                // handle error
            }
            else if (! [isDirectory boolValue]) {
                // No error and it’s not a directory; do something with the file
                char const* path = [[url path] UTF8String];
                if ([[url pathExtension] isEqualToString:@"dylib"]) {
                    cb(path);
                }
            }
        }
    }

}
