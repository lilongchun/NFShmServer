include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/module_festival_bin

${PROTOCGEN_FILE_PATH}/module_festival_bin:${PROTOCGEN_FILE_PATH}/festival.proto.ds ${RESDB_EXCELMMO_PATH}/festival.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/module_festival_bin
	${NFEXCELPROCESS} --work="exceltobin" --src=${RESDB_EXCELMMO_PATH}/festival.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/festival.proto.ds --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy_notexist" --src="${PROTOCGEN_FILE_PATH}/FestivalDescEx.h ${PROTOCGEN_FILE_PATH}/FestivalDescEx.cpp" --dst=${DESC_STORE_EX_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_FestivalPeriodindex.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/FestivalPeriodindexDesc.h ${PROTOCGEN_FILE_PATH}/FestivalPeriodindexDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_FestivalFestival.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/FestivalFestivalDesc.h ${PROTOCGEN_FILE_PATH}/FestivalFestivalDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_FestivalTemplate.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/FestivalTemplateDesc.h ${PROTOCGEN_FILE_PATH}/FestivalTemplateDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_FestivalMuban_consumerank.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/FestivalMuban_consumerankDesc.h ${PROTOCGEN_FILE_PATH}/FestivalMuban_consumerankDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_FestivalMuban_eggsdraw.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/FestivalMuban_eggsdrawDesc.h ${PROTOCGEN_FILE_PATH}/FestivalMuban_eggsdrawDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_FestivalMuban_eggsdraw_pool.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/FestivalMuban_eggsdraw_poolDesc.h ${PROTOCGEN_FILE_PATH}/FestivalMuban_eggsdraw_poolDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_FestivalMuban_eggsdraw_task.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/FestivalMuban_eggsdraw_taskDesc.h ${PROTOCGEN_FILE_PATH}/FestivalMuban_eggsdraw_taskDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_FestivalMuban_ftreward.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/FestivalMuban_ftrewardDesc.h ${PROTOCGEN_FILE_PATH}/FestivalMuban_ftrewardDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_FestivalMuban_challenge.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/FestivalMuban_challengeDesc.h ${PROTOCGEN_FILE_PATH}/FestivalMuban_challengeDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_FestivalMuban_mystmall.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/FestivalMuban_mystmallDesc.h ${PROTOCGEN_FILE_PATH}/FestivalMuban_mystmallDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_FestivalMuban_mystmall_mall.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/FestivalMuban_mystmall_mallDesc.h ${PROTOCGEN_FILE_PATH}/FestivalMuban_mystmall_mallDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_FestivalMuban_rebatestore.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/FestivalMuban_rebatestoreDesc.h ${PROTOCGEN_FILE_PATH}/FestivalMuban_rebatestoreDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_FestivalMuban_rebatestore_mall.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/FestivalMuban_rebatestore_mallDesc.h ${PROTOCGEN_FILE_PATH}/FestivalMuban_rebatestore_mallDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_FestivalMuban_contrecharge.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/FestivalMuban_contrechargeDesc.h ${PROTOCGEN_FILE_PATH}/FestivalMuban_contrechargeDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_FestivalMuban_contrecharge_total.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/FestivalMuban_contrecharge_totalDesc.h ${PROTOCGEN_FILE_PATH}/FestivalMuban_contrecharge_totalDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_FestivalMuban_contrecharge_day.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/FestivalMuban_contrecharge_dayDesc.h ${PROTOCGEN_FILE_PATH}/FestivalMuban_contrecharge_dayDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_FestivalMuban_login.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/FestivalMuban_loginDesc.h ${PROTOCGEN_FILE_PATH}/FestivalMuban_loginDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_FestivalMuban_firstrecharge.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/FestivalMuban_firstrechargeDesc.h ${PROTOCGEN_FILE_PATH}/FestivalMuban_firstrechargeDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_FestivalMuban_love.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/FestivalMuban_loveDesc.h ${PROTOCGEN_FILE_PATH}/FestivalMuban_loveDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_FestivalMuban_love_rank.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/FestivalMuban_love_rankDesc.h ${PROTOCGEN_FILE_PATH}/FestivalMuban_love_rankDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_FestivalMuban_love_rank_data.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/FestivalMuban_love_rank_dataDesc.h ${PROTOCGEN_FILE_PATH}/FestivalMuban_love_rank_dataDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_FestivalMuban_love_task.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/FestivalMuban_love_taskDesc.h ${PROTOCGEN_FILE_PATH}/FestivalMuban_love_taskDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_FestivalMuban_love_taskreward.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/FestivalMuban_love_taskrewardDesc.h ${PROTOCGEN_FILE_PATH}/FestivalMuban_love_taskrewardDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_FestivalMuban_addbox.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/FestivalMuban_addboxDesc.h ${PROTOCGEN_FILE_PATH}/FestivalMuban_addboxDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_FestivalMuban_doublebox.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/FestivalMuban_doubleboxDesc.h ${PROTOCGEN_FILE_PATH}/FestivalMuban_doubleboxDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_FestivalMuban_bossfristkill.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/FestivalMuban_bossfristkillDesc.h ${PROTOCGEN_FILE_PATH}/FestivalMuban_bossfristkillDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_FestivalMuban_severrank.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/FestivalMuban_severrankDesc.h ${PROTOCGEN_FILE_PATH}/FestivalMuban_severrankDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_FestivalMuban_severrank_data.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/FestivalMuban_severrank_dataDesc.h ${PROTOCGEN_FILE_PATH}/FestivalMuban_severrank_dataDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_FestivalMuban_collectword.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/FestivalMuban_collectwordDesc.h ${PROTOCGEN_FILE_PATH}/FestivalMuban_collectwordDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_FestivalMuban_sign.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/FestivalMuban_signDesc.h ${PROTOCGEN_FILE_PATH}/FestivalMuban_signDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_FestivalMuban_shop.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/FestivalMuban_shopDesc.h ${PROTOCGEN_FILE_PATH}/FestivalMuban_shopDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_FestivalMuban_rechange.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/FestivalMuban_rechangeDesc.h ${PROTOCGEN_FILE_PATH}/FestivalMuban_rechangeDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_FestivalMuban_leiji.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/FestivalMuban_leijiDesc.h ${PROTOCGEN_FILE_PATH}/FestivalMuban_leijiDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_FestivalZadanconstant.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/FestivalZadanconstantDesc.h ${PROTOCGEN_FILE_PATH}/FestivalZadanconstantDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_FestivalMuban_zadan.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/FestivalMuban_zadanDesc.h ${PROTOCGEN_FILE_PATH}/FestivalMuban_zadanDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_FestivalMuban_turntable.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/FestivalMuban_turntableDesc.h ${PROTOCGEN_FILE_PATH}/FestivalMuban_turntableDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_FestivalMuban_turntable_pool.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/FestivalMuban_turntable_poolDesc.h ${PROTOCGEN_FILE_PATH}/FestivalMuban_turntable_poolDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_FestivalMuban_turntable_task.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/FestivalMuban_turntable_taskDesc.h ${PROTOCGEN_FILE_PATH}/FestivalMuban_turntable_taskDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_FestivalMuban_donate.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/FestivalMuban_donateDesc.h ${PROTOCGEN_FILE_PATH}/FestivalMuban_donateDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_FestivalMuban_donate_sever.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/FestivalMuban_donate_severDesc.h ${PROTOCGEN_FILE_PATH}/FestivalMuban_donate_severDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_FestivalMuban_donate_single.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/FestivalMuban_donate_singleDesc.h ${PROTOCGEN_FILE_PATH}/FestivalMuban_donate_singleDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_FestivalMuban_donate_task.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/FestivalMuban_donate_taskDesc.h ${PROTOCGEN_FILE_PATH}/FestivalMuban_donate_taskDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_FestivalMuban_online.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/FestivalMuban_onlineDesc.h ${PROTOCGEN_FILE_PATH}/FestivalMuban_onlineDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_FestivalMuban_rturntable.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/FestivalMuban_rturntableDesc.h ${PROTOCGEN_FILE_PATH}/FestivalMuban_rturntableDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_FestivalMuban_rturntable_recharge.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/FestivalMuban_rturntable_rechargeDesc.h ${PROTOCGEN_FILE_PATH}/FestivalMuban_rturntable_rechargeDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_FestivalMuban_rturntable_recharge_ratio.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/FestivalMuban_rturntable_recharge_ratioDesc.h ${PROTOCGEN_FILE_PATH}/FestivalMuban_rturntable_recharge_ratioDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_FestivalMuban_drawpize.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/FestivalMuban_drawpizeDesc.h ${PROTOCGEN_FILE_PATH}/FestivalMuban_drawpizeDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_FestivalMuban_drawpize_pool.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/FestivalMuban_drawpize_poolDesc.h ${PROTOCGEN_FILE_PATH}/FestivalMuban_drawpize_poolDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_FestivalMuban_drawpize_total.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/FestivalMuban_drawpize_totalDesc.h ${PROTOCGEN_FILE_PATH}/FestivalMuban_drawpize_totalDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_FestivalMuban_totalrecharge.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/FestivalMuban_totalrechargeDesc.h ${PROTOCGEN_FILE_PATH}/FestivalMuban_totalrechargeDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_FestivalMuban_dailytotalrecharge.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/FestivalMuban_dailytotalrechargeDesc.h ${PROTOCGEN_FILE_PATH}/FestivalMuban_dailytotalrechargeDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_FestivalMuban_rechargeprize.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/FestivalMuban_rechargeprizeDesc.h ${PROTOCGEN_FILE_PATH}/FestivalMuban_rechargeprizeDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_FestivalMuban_rptask.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/FestivalMuban_rptaskDesc.h ${PROTOCGEN_FILE_PATH}/FestivalMuban_rptaskDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_FestivalMuban_rppool.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/FestivalMuban_rppoolDesc.h ${PROTOCGEN_FILE_PATH}/FestivalMuban_rppoolDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_FestivalMuban_play.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/FestivalMuban_playDesc.h ${PROTOCGEN_FILE_PATH}/FestivalMuban_playDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_FestivalMuban_play_reward.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/FestivalMuban_play_rewardDesc.h ${PROTOCGEN_FILE_PATH}/FestivalMuban_play_rewardDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_FestivalMuban_play_game.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/FestivalMuban_play_gameDesc.h ${PROTOCGEN_FILE_PATH}/FestivalMuban_play_gameDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_FestivalMuban_play_score.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/FestivalMuban_play_scoreDesc.h ${PROTOCGEN_FILE_PATH}/FestivalMuban_play_scoreDesc.cpp" --dst=${DESC_STORE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/module_festival_bin
