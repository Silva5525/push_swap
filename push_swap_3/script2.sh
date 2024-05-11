#!/bin/sh

# Check if DYLD_INSERT_LIBRARIES is set
if [ ! -z "$DYLD_INSERT_LIBRARIES" ]; then
    echo "Current DYLD_INSERT_LIBRARIES: $DYLD_INSERT_LIBRARIES"
    echo "Unsetting DYLD_INSERT_LIBRARIES for this session..."
    unset DYLD_INSERT_LIBRARIES
    echo "DYLD_INSERT_LIBRARIES has been unset."
else
    echo "DYLD_INSERT_LIBRARIES is not set."
fi

# Check for library in home directory
LIB_PATH=~/usr/local/lib/libLeaksAtExit.dylib
if [ -f "$LIB_PATH" ]; then
    echo "Library found at $LIB_PATH"
else
    echo "Library not found. Please place libLeaksAtExit.dylib in ~//usr/local/lib/"
fi

# Set DYLD_INSERT_LIBRARIES in user space
echo "Setting DYLD_INSERT_LIBRARIES to $LIB_PATH"
export DYLD_INSERT_LIBRARIES=$LIB_PATH
echo "DYLD_INSERT_LIBRARIES set to $LIB_PATH"
