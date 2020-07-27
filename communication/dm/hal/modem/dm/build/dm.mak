#--------------------------------------------------------------------------------------------------------------------
# (C) Copyright 2006, 2007 Marvell DSPC Ltd. All Rights Reserved.
#-------------------------------------------------------------------------------------------------------------------

#=========================================================================
# File Name      : dm.mak
# Description    : Main make file for the pca_components/gpc package.
#
# Usage          : make [-s] -f gpc.mak OPT_FILE=<path>/<opt_file>
#
# Notes          : The options file defines macro values defined
#                  by the environment, target, and groups. It
#                  must be included for proper package building.
#
# INTEL CONFIDENTIAL
# Copyright 2006 Intel Corporation All Rights Reserved. 
# The source code contained or described herein and all documents related to the source code ("Material") are owned 
# by Intel Corporation or its suppliers or licensors. Title to the Material remains with Intel Corporation or 
# its suppliers and licensors. The Material contains trade secrets and proprietary and confidential information of 
# Intel or its suppliers and licensors. The Material is protected by worldwide copyright and trade secret laws and 
# treaty provisions. No part of the Material may be used, copied, reproduced, modified, published, uploaded, posted, 
# transmitted, distributed, or disclosed in any way without Intel’s prior express written permission.
# 
# No license under any patent, copyright, trade secret or other intellectual property right is granted to or 
# conferred upon you by disclosure or delivery of the Materials, either expressly, by implication, inducement, 
# estoppel or otherwise. Any license under such intellectual property rights must be express and approved by 
# Intel in writing.
# 
# Unless otherwise agreed by Intel in writing, you may not remove or alter this notice or any other notice embedded
# in Materials by Intel or Intel’s suppliers or licensors in any way.
#=========================================================================

# Package build options
include ${OPT_FILE}
 
# Pre-Pass
# PP =

# Package Makefile information
GEN_PACK_MAKEFILE = ${BUILD_ROOT}/env/${HOST}/build/package.mak

# Define Package ---------------------------------------

PACKAGE_NAME     = dm
PACKAGE_BASE     = pcac
PACKAGE_DEP_FILE = dm_dep.mak
PACKAGE_PATH     = ${BUILD_ROOT}/${PACKAGE_BASE}/${PACKAGE_NAME}

# The relative path locations of source and include file directories.
PACKAGE_SRC_PATH    = ${PACKAGE_PATH}/src
PACKAGE_INC_PATHS   = ${PACKAGE_PATH}/src \
                      $(PACKAGE_PATH)/inc \
                      $(BUILD_ROOT)/pcac/mxml/inc \
                      $(BUILD_ROOT)/pcac/lwipv4v6/src/include/arch \
                      $(BUILD_ROOT)/pcac/lwipv4v6/src/include/lwip \
                      $(BUILD_ROOT)/pcac/lwipv4v6/src/include/netif \
                      $(BUILD_ROOT)/pcac/lwipv4v6/src/include/ipv4/lwip \
                      $(BUILD_ROOT)/pcac/lwipv4v6/src/include/ipv6/lwip

# Package source files, paths not required
PACKAGE_SRC_FILES = cJSON.c            \
                    Waterworld_base64.c\
                    wtwd_telecom_dm.c

# These are the tool flags specific to the ci_stub package only.
# The environment, target, and group also set flags.
PACKAGE_CFLAGS  =
PACKAGE_DFLAGS  =
PACKAGE_ARFLAGS =

# Define Package Variants -------------------------------

# Include the Standard Package Make File ---------------
include ${GEN_PACK_MAKEFILE}

# Include the Make Dependency File ---------------------
# This must be the last line in the file
include ${PACKAGE_DEP_FILE}
