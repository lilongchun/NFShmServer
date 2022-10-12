include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/noticenotice.bin ${PROTOCGEN_FILE_PATH}/NoticeNoticeDesc.h ${PROTOCGEN_FILE_PATH}/NoticeNoticeDesc.cpp 

${PROTOCGEN_FILE_PATH}/noticenotice.bin:${PROTOCGEN_FILE_PATH}/notice.proto.ds ${RESDB_EXCELMMO_PATH}/notice.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/notice.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/notice.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_noticenotice  --excel_sheetname=notice  --proto_msgname=noticenotice  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/noticenotice.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/NoticeNoticeDesc.h ${PROTOCGEN_FILE_PATH}/NoticeNoticeDesc.cpp" --dst=${DESC_STORE_PATH}/
