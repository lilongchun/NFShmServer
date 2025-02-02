﻿GAME_NFRAME=..
GAME_SRC_PATH=../../../

GAME_INSTALL_PATH=${GAME_SRC_PATH}/Install
GAME_BIN_PATH=${GAME_INSTALL_PATH}/Bin
GAME_DATA_PATH=${GAME_INSTALL_PATH}/Config/Data
GAME_SQL_PATH=${GAME_INSTALL_PATH}/Sql
GAME_LUA_PB_PATH=${GAME_INSTALL_PATH}/LuaScript/CommonProto
GAME_BUILD_PATH=${GAME_SRC_PATH}/Build/NFServerComm/makefile

MAKEFILE_PATH=${GAME_SRC_PATH}/src/NFServerComm/makefiles
MAKE_PROTOC_GEN=${MAKEFILE_PATH}/protoc_gen.makefile
MAKE_EXCEL_GEN=${MAKEFILE_PATH}/excel_gen.makefile

RESDB_EXCEL_PATH=${GAME_SRC_PATH}/Excel
PROTOCGEN_FILE_PATH=${GAME_BUILD_PATH}/temp

THIRD_PARTY_PATH=${GAME_SRC_PATH}/thirdparty
THIRD_PARTY_TOOLS_PATH=${THIRD_PARTY_PATH}/tools
THIRD_PARTY_INC_PATH=${THIRD_PARTY_PATH}/

TOOLS_PATH=${GAME_SRC_PATH}/tools
THIRD_PARTY_TOOLS_PATH=${TOOLS_PATH}
PROTOC=${TOOLS_PATH}/protoc
NFEXCELPROCESS=${TOOLS_PATH}/NFExcelProcess
FILE_COPY_EXE=${NFEXCELPROCESS}

MAKE_SINGLE_JOB_NUM=4

#######################
#protocol define
#######################

PROTOCOL_PATH=${GAME_SRC_PATH}/src/NFComm/Message
PROTOCOL_SVR_PATH=${GAME_SRC_PATH}/src/NFServerComm/Message
PROTOCOL_COMM_PATH=${PROTOCOL_PATH}/common
PROTOCOL_KERNEL_PATH=${PROTOCOL_PATH}/kernel
PROTOCOL_STORESVR_PATH=${PROTOCOL_PATH}/storesvr
PROTOCOL_SS_PATH=${PROTOCOL_SVR_PATH}/proto_svr
PROTOCOL_CS_PATH=${PROTOCOL_SVR_PATH}/proto_cs

PROTOCOL_COMM_XML=${PROTOCOL_COMM_PATH}/proto_common.proto
PROTOCOL_KERNEL_XML=${PROTOCOL_KERNEL_PATH}/proto_kernel.proto
PROTOCOL_FIELD_XML=${PROTOCOL_KERNEL_PATH}/yd_fieldoptions.proto
PROTOCOL_SOTRE_XML=${PROTOCOL_STORESVR_PATH}/storesvr_sqldata.proto

PROTOCOL_SS_XML=$(wildcard ${PROTOCOL_SS_PATH}/*.proto)
PROTOCOL_SS_H=$(subst $(PROTOCOL_SS_PATH),$(PROTOCGEN_FILE_PATH),$(PROTOCOL_SS_XML:.proto=.pb.h))
PROTOCOL_SS_CPP=$(PROTOCOL_SS_H:.h=.cc)
PROTOCOL_SS_DESCRIPTOR=${PROTOCGEN_FILE_PATH}/proto_server.proto.ds

PROTOCGEN_CPP= ${PROTOCOL_SS_CPP}

PROTOCGEN_H=${PROTOCOL_SS_H}

ALL_PROTOCGEN_FILE=${PROTOCGEN_CPP} ${PROTOCGEN_H}
ALL_PROTOC_DESCRIPTOR_FILE=${PROTOCOL_SS_DESCRIPTOR}
ALL_PROTOCGEN_PY=

NEW_PROTOCGEN_FILE_PATH=${GAME_SRC_PATH}/src/NFServerComm/NFServerMessage

##########################
#
##########################
MAKE_COMPILE_LOG=${GAME_BUILD_PATH}/make_compile.log
MAKE_COMPILE_WARNING_LOG=${GAME_BUILD_PATH}/make_warning.log
MAKE_COMPILE_ERROR_LOG=${GAME_BUILD_PATH}/make_error.log
MAKE_DEPENDENT_LOG=${GAME_BUILD_PATH}/make_dependent.log
MAKE_DEPENDENT_ERROR_LOG=${GAME_BUILD_PATH}/make_dependent_error.log
MAKE_LINK_ERROR_LOG=${GAME_BUILD_PATH}/make_link_error.log

NEED_CLEAN_FILES=
