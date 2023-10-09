#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "E_Pet.pb.h"
#include "E_Pet_s.h"

#define DEFINE_E_PETDISPLAY_M_MATERIAL_MAX_NUM 3
#define DEFINE_SHEET_PETDISPLAY_E_PETDISPLAY_LIST_MAX_NUM 64
#define DEFINE_E_PETATTRIBUTETPYE_M_ATTRIBUTE_MAX_NUM 6
#define DEFINE_SHEET_PETATTRIBUTETPYE_E_PETATTRIBUTETPYE_LIST_MAX_NUM 128
#define DEFINE_SHEET_PETLVEXP_E_PETLVEXP_LIST_MAX_NUM 512
#define DEFINE_E_PETADVANCELV_M_ADVANCE_MAX_NUM 2
#define DEFINE_SHEET_PETADVANCELV_E_PETADVANCELV_LIST_MAX_NUM 128
#define DEFINE_E_PETSTARUP_M_UPATTRIBUTE_MAX_NUM 6
#define DEFINE_SHEET_PETSTARUP_E_PETSTARUP_LIST_MAX_NUM 64
#define DEFINE_E_PETEGG_M_PET_MAX_NUM 13
#define DEFINE_SHEET_PETEGG_E_PETEGG_LIST_MAX_NUM 64
#define DEFINE_E_PETDECOMPOSE_M_DECOMPOSE_MAX_NUM 4
#define DEFINE_SHEET_PETDECOMPOSE_E_PETDECOMPOSE_LIST_MAX_NUM 8
#define DEFINE_E_PETFETTERS_M_PETID_MAX_NUM 3
#define DEFINE_E_PETFETTERS_M_ATTRIBUTE_MAX_NUM 7
#define DEFINE_E_PETFETTERS_M_ATCTIVE_SKILLID_MAX_NUM 4
#define DEFINE_SHEET_PETFETTERS_E_PETFETTERS_LIST_MAX_NUM 8
#define DEFINE_E_PETPETEQUIP_M_ACT_MAX_NUM 2
#define DEFINE_SHEET_PETPETEQUIP_E_PETPETEQUIP_LIST_MAX_NUM 32
#define DEFINE_E_PETEQUIPVALUE_M_ATTRIBUTE_MAX_NUM 5
#define DEFINE_E_PETEQUIPVALUE_M_EXTRA_MAX_NUM 5
#define DEFINE_SHEET_PETEQUIPVALUE_E_PETEQUIPVALUE_LIST_MAX_NUM 1024
#define DEFINE_E_PETSTARVALUE_M_ATTRIBUTE_MAX_NUM 4
#define DEFINE_E_PETSTARVALUE_M_ADVANCE_TYPE_MAX_NUM 3
#define DEFINE_E_PETSTARVALUE_M_EQUIP_MAX_NUM 2
#define DEFINE_SHEET_PETSTARVALUE_E_PETSTARVALUE_LIST_MAX_NUM 256
#define DEFINE_E_PETWRAITHS_M_MATERIAL_MAX_NUM 3
#define DEFINE_SHEET_PETWRAITHS_E_PETWRAITHS_LIST_MAX_NUM 256
#define DEFINE_E_PETWRAITHSVALUE_M_ATTRIBUTE_MAX_NUM 6
#define DEFINE_SHEET_PETWRAITHSVALUE_E_PETWRAITHSVALUE_LIST_MAX_NUM 256
#define DEFINE_SHEET_PETWRAITHSLV_E_PETWRAITHSLV_LIST_MAX_NUM 256
#define DEFINE_SHEET_PETSMELT_E_PETSMELT_LIST_MAX_NUM 64
#define DEFINE_SHEET_PETREFINECONVERSION_E_PETREFINECONVERSION_LIST_MAX_NUM 32
#define DEFINE_E_PETSTOVE_M_STOVE_MAX_NUM 4
#define DEFINE_SHEET_PETSTOVE_E_PETSTOVE_LIST_MAX_NUM 512
#define DEFINE_E_PETSUIT_M_ATTRIBUTE_MAX_NUM 5
#define DEFINE_SHEET_PETSUIT_E_PETSUIT_LIST_MAX_NUM 32


namespace proto_ff_s {

	struct E_PetDisplayMaterialDesc_s : public NFDescStoreSeqOP {
		E_PetDisplayMaterialDesc_s();
		virtual ~E_PetDisplayMaterialDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_exp;//经验值
		int64_t m_id;//ID

		virtual void write_to_pbmsg(::proto_ff::E_PetDisplayMaterialDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_PetDisplayMaterialDesc & msg);
		static ::proto_ff::E_PetDisplayMaterialDesc* new_pbmsg(){ return new ::proto_ff::E_PetDisplayMaterialDesc(); }
		static ::proto_ff::E_PetDisplayMaterialDesc make_pbmsg(){ return ::proto_ff::E_PetDisplayMaterialDesc(); }
	};
	typedef struct E_PetDisplayMaterialDesc_s E_PetDisplayMaterialDesc_t;

	struct E_PetDisplay_s : public NFDescStoreSeqOP {
		E_PetDisplay_s();
		virtual ~E_PetDisplay_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_id;//外观ID
		NFShmString<64> m_name;//名字
		int32_t m_quality;//宠物品质
		int32_t m_isstar;//是否可升星
		NFShmString<64> m_grade;//评级
		int64_t m_monsterid;//怪物表ID
		int32_t m_activeskillid;//主动技能
		NFShmString<64> m_exclusiveskillid;//专属技能
		NFShmString<64> m_passiveskillid;//被动技能
		int32_t m_activeattribute;//初始获得属性模板
		int32_t m_growatt;//升级属性模板
		float m_activeparama;//初值值系数
		float m_growattparama;//升级属性系数
		float m_growstandarda;//标准值系数A
		float m_growstandardb;//标准值系数B
		float m_growstandard;//资质标准值
		float m_growmin;//初始资质下限
		float m_growmax;//初始资质上限
		float m_growstar;//升星资质提升系数
		int32_t m_advanceattribute;//进阶值模板
		int32_t m_advancetype;//进阶类型
		NFShmString<64> m_pettagskill;//神宠技能
		int32_t m_starattribute;//升星属性模板
		int32_t m_starpercent;//升星属性加成
		int32_t m_starllimit;//升星上限
		int64_t m_staritem;//升星道具
		NFShmString<64> m_starnum;//升星道具数量
		int64_t m_starpetid;//升星宠物ID
		NFShmString<64> m_starpetnum;//升星宠物数量
		int32_t m_weapon;//专属武器
		int64_t m_upattributeid;//升星属性组ID
		int32_t m_fettersid;//羁绊ID
		NFShmString<64> m_suit;//套装
		NFShmVector<struct E_PetDisplayMaterialDesc_s, DEFINE_E_PETDISPLAY_M_MATERIAL_MAX_NUM> m_material;//升级材料

		virtual void write_to_pbmsg(::proto_ff::E_PetDisplay & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_PetDisplay & msg);
		static ::proto_ff::E_PetDisplay* new_pbmsg(){ return new ::proto_ff::E_PetDisplay(); }
		static ::proto_ff::E_PetDisplay make_pbmsg(){ return ::proto_ff::E_PetDisplay(); }
	};
	typedef struct E_PetDisplay_s E_PetDisplay_t;

	struct Sheet_PetDisplay_s : public NFDescStoreSeqOP {
		Sheet_PetDisplay_s();
		virtual ~Sheet_PetDisplay_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_PetDisplay_s, DEFINE_SHEET_PETDISPLAY_E_PETDISPLAY_LIST_MAX_NUM> E_PetDisplay_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_PetDisplay & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_PetDisplay & msg);
		static ::proto_ff::Sheet_PetDisplay* new_pbmsg(){ return new ::proto_ff::Sheet_PetDisplay(); }
		static ::proto_ff::Sheet_PetDisplay make_pbmsg(){ return ::proto_ff::Sheet_PetDisplay(); }
	};
	typedef struct Sheet_PetDisplay_s Sheet_PetDisplay_t;

	struct E_PetAttributetpyeAttributeDesc_s : public NFDescStoreSeqOP {
		E_PetAttributetpyeAttributeDesc_s();
		virtual ~E_PetAttributetpyeAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_type;//ID

		virtual void write_to_pbmsg(::proto_ff::E_PetAttributetpyeAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_PetAttributetpyeAttributeDesc & msg);
		static ::proto_ff::E_PetAttributetpyeAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_PetAttributetpyeAttributeDesc(); }
		static ::proto_ff::E_PetAttributetpyeAttributeDesc make_pbmsg(){ return ::proto_ff::E_PetAttributetpyeAttributeDesc(); }
	};
	typedef struct E_PetAttributetpyeAttributeDesc_s E_PetAttributetpyeAttributeDesc_t;

	struct E_PetAttributetpye_s : public NFDescStoreSeqOP {
		E_PetAttributetpye_s();
		virtual ~E_PetAttributetpye_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_id;//id
		int32_t m_tpye;//属性类型
		NFShmVector<struct E_PetAttributetpyeAttributeDesc_s, DEFINE_E_PETATTRIBUTETPYE_M_ATTRIBUTE_MAX_NUM> m_attribute;//基础属性

		virtual void write_to_pbmsg(::proto_ff::E_PetAttributetpye & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_PetAttributetpye & msg);
		static ::proto_ff::E_PetAttributetpye* new_pbmsg(){ return new ::proto_ff::E_PetAttributetpye(); }
		static ::proto_ff::E_PetAttributetpye make_pbmsg(){ return ::proto_ff::E_PetAttributetpye(); }
	};
	typedef struct E_PetAttributetpye_s E_PetAttributetpye_t;

	struct Sheet_PetAttributetpye_s : public NFDescStoreSeqOP {
		Sheet_PetAttributetpye_s();
		virtual ~Sheet_PetAttributetpye_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_PetAttributetpye_s, DEFINE_SHEET_PETATTRIBUTETPYE_E_PETATTRIBUTETPYE_LIST_MAX_NUM> E_PetAttributetpye_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_PetAttributetpye & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_PetAttributetpye & msg);
		static ::proto_ff::Sheet_PetAttributetpye* new_pbmsg(){ return new ::proto_ff::Sheet_PetAttributetpye(); }
		static ::proto_ff::Sheet_PetAttributetpye make_pbmsg(){ return ::proto_ff::Sheet_PetAttributetpye(); }
	};
	typedef struct Sheet_PetAttributetpye_s Sheet_PetAttributetpye_t;

	struct E_PetLvexp_s : public NFDescStoreSeqOP {
		E_PetLvexp_s();
		virtual ~E_PetLvexp_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//等级
		int64_t m_exp;//升级经验

		virtual void write_to_pbmsg(::proto_ff::E_PetLvexp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_PetLvexp & msg);
		static ::proto_ff::E_PetLvexp* new_pbmsg(){ return new ::proto_ff::E_PetLvexp(); }
		static ::proto_ff::E_PetLvexp make_pbmsg(){ return ::proto_ff::E_PetLvexp(); }
	};
	typedef struct E_PetLvexp_s E_PetLvexp_t;

	struct Sheet_PetLvexp_s : public NFDescStoreSeqOP {
		Sheet_PetLvexp_s();
		virtual ~Sheet_PetLvexp_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_PetLvexp_s, DEFINE_SHEET_PETLVEXP_E_PETLVEXP_LIST_MAX_NUM> E_PetLvexp_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_PetLvexp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_PetLvexp & msg);
		static ::proto_ff::Sheet_PetLvexp* new_pbmsg(){ return new ::proto_ff::Sheet_PetLvexp(); }
		static ::proto_ff::Sheet_PetLvexp make_pbmsg(){ return ::proto_ff::Sheet_PetLvexp(); }
	};
	typedef struct Sheet_PetLvexp_s Sheet_PetLvexp_t;

	struct E_PetAdvancelvAdvanceDesc_s : public NFDescStoreSeqOP {
		E_PetAdvancelvAdvanceDesc_s();
		virtual ~E_PetAdvancelvAdvanceDesc_s(){}
		int CreateInit();
		int ResumeInit();
		float m_param;//系数
		int32_t m_type;//类型

		virtual void write_to_pbmsg(::proto_ff::E_PetAdvancelvAdvanceDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_PetAdvancelvAdvanceDesc & msg);
		static ::proto_ff::E_PetAdvancelvAdvanceDesc* new_pbmsg(){ return new ::proto_ff::E_PetAdvancelvAdvanceDesc(); }
		static ::proto_ff::E_PetAdvancelvAdvanceDesc make_pbmsg(){ return ::proto_ff::E_PetAdvancelvAdvanceDesc(); }
	};
	typedef struct E_PetAdvancelvAdvanceDesc_s E_PetAdvancelvAdvanceDesc_t;

	struct E_PetAdvancelv_s : public NFDescStoreSeqOP {
		E_PetAdvancelv_s();
		virtual ~E_PetAdvancelv_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//等级
		int32_t m_advanceitem;//进阶消耗道具
		int32_t m_advancenum;//消耗数量
		NFShmVector<struct E_PetAdvancelvAdvanceDesc_s, DEFINE_E_PETADVANCELV_M_ADVANCE_MAX_NUM> m_advance;//进阶

		virtual void write_to_pbmsg(::proto_ff::E_PetAdvancelv & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_PetAdvancelv & msg);
		static ::proto_ff::E_PetAdvancelv* new_pbmsg(){ return new ::proto_ff::E_PetAdvancelv(); }
		static ::proto_ff::E_PetAdvancelv make_pbmsg(){ return ::proto_ff::E_PetAdvancelv(); }
	};
	typedef struct E_PetAdvancelv_s E_PetAdvancelv_t;

	struct Sheet_PetAdvancelv_s : public NFDescStoreSeqOP {
		Sheet_PetAdvancelv_s();
		virtual ~Sheet_PetAdvancelv_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_PetAdvancelv_s, DEFINE_SHEET_PETADVANCELV_E_PETADVANCELV_LIST_MAX_NUM> E_PetAdvancelv_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_PetAdvancelv & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_PetAdvancelv & msg);
		static ::proto_ff::Sheet_PetAdvancelv* new_pbmsg(){ return new ::proto_ff::Sheet_PetAdvancelv(); }
		static ::proto_ff::Sheet_PetAdvancelv make_pbmsg(){ return ::proto_ff::Sheet_PetAdvancelv(); }
	};
	typedef struct Sheet_PetAdvancelv_s Sheet_PetAdvancelv_t;

	struct E_PetStarupUpattributeDesc_s : public NFDescStoreSeqOP {
		E_PetStarupUpattributeDesc_s();
		virtual ~E_PetStarupUpattributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_type;//ID

		virtual void write_to_pbmsg(::proto_ff::E_PetStarupUpattributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_PetStarupUpattributeDesc & msg);
		static ::proto_ff::E_PetStarupUpattributeDesc* new_pbmsg(){ return new ::proto_ff::E_PetStarupUpattributeDesc(); }
		static ::proto_ff::E_PetStarupUpattributeDesc make_pbmsg(){ return ::proto_ff::E_PetStarupUpattributeDesc(); }
	};
	typedef struct E_PetStarupUpattributeDesc_s E_PetStarupUpattributeDesc_t;

	struct E_PetStarup_s : public NFDescStoreSeqOP {
		E_PetStarup_s();
		virtual ~E_PetStarup_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//唯一ID
		int64_t m_upattributeid;//升星属性组ID
		int32_t m_starid;//星级
		int32_t m_skillid;//技能id
		int32_t m_activeskillidlv;//主动技能等级
		NFShmVector<struct E_PetStarupUpattributeDesc_s, DEFINE_E_PETSTARUP_M_UPATTRIBUTE_MAX_NUM> m_upattribute;//激活属性

		virtual void write_to_pbmsg(::proto_ff::E_PetStarup & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_PetStarup & msg);
		static ::proto_ff::E_PetStarup* new_pbmsg(){ return new ::proto_ff::E_PetStarup(); }
		static ::proto_ff::E_PetStarup make_pbmsg(){ return ::proto_ff::E_PetStarup(); }
	};
	typedef struct E_PetStarup_s E_PetStarup_t;

	struct Sheet_PetStarup_s : public NFDescStoreSeqOP {
		Sheet_PetStarup_s();
		virtual ~Sheet_PetStarup_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_PetStarup_s, DEFINE_SHEET_PETSTARUP_E_PETSTARUP_LIST_MAX_NUM> E_PetStarup_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_PetStarup & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_PetStarup & msg);
		static ::proto_ff::Sheet_PetStarup* new_pbmsg(){ return new ::proto_ff::Sheet_PetStarup(); }
		static ::proto_ff::Sheet_PetStarup make_pbmsg(){ return ::proto_ff::Sheet_PetStarup(); }
	};
	typedef struct Sheet_PetStarup_s Sheet_PetStarup_t;

	struct E_PetEggPetDesc_s : public NFDescStoreSeqOP {
		E_PetEggPetDesc_s();
		virtual ~E_PetEggPetDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_rand;//概率
		int32_t m_id;//ID

		virtual void write_to_pbmsg(::proto_ff::E_PetEggPetDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_PetEggPetDesc & msg);
		static ::proto_ff::E_PetEggPetDesc* new_pbmsg(){ return new ::proto_ff::E_PetEggPetDesc(); }
		static ::proto_ff::E_PetEggPetDesc make_pbmsg(){ return ::proto_ff::E_PetEggPetDesc(); }
	};
	typedef struct E_PetEggPetDesc_s E_PetEggPetDesc_t;

	struct E_PetEgg_s : public NFDescStoreSeqOP {
		E_PetEgg_s();
		virtual ~E_PetEgg_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//宠物蛋道具ID
		int32_t m_time;//孵化时间
		NFShmVector<struct E_PetEggPetDesc_s, DEFINE_E_PETEGG_M_PET_MAX_NUM> m_pet;//宠物

		virtual void write_to_pbmsg(::proto_ff::E_PetEgg & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_PetEgg & msg);
		static ::proto_ff::E_PetEgg* new_pbmsg(){ return new ::proto_ff::E_PetEgg(); }
		static ::proto_ff::E_PetEgg make_pbmsg(){ return ::proto_ff::E_PetEgg(); }
	};
	typedef struct E_PetEgg_s E_PetEgg_t;

	struct Sheet_PetEgg_s : public NFDescStoreSeqOP {
		Sheet_PetEgg_s();
		virtual ~Sheet_PetEgg_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_PetEgg_s, DEFINE_SHEET_PETEGG_E_PETEGG_LIST_MAX_NUM> E_PetEgg_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_PetEgg & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_PetEgg & msg);
		static ::proto_ff::Sheet_PetEgg* new_pbmsg(){ return new ::proto_ff::Sheet_PetEgg(); }
		static ::proto_ff::Sheet_PetEgg make_pbmsg(){ return ::proto_ff::Sheet_PetEgg(); }
	};
	typedef struct Sheet_PetEgg_s Sheet_PetEgg_t;

	struct E_PetDecomposeDecomposeDesc_s : public NFDescStoreSeqOP {
		E_PetDecomposeDecomposeDesc_s();
		virtual ~E_PetDecomposeDecomposeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_boxid;//boxID
		int32_t m_type;//type

		virtual void write_to_pbmsg(::proto_ff::E_PetDecomposeDecomposeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_PetDecomposeDecomposeDesc & msg);
		static ::proto_ff::E_PetDecomposeDecomposeDesc* new_pbmsg(){ return new ::proto_ff::E_PetDecomposeDecomposeDesc(); }
		static ::proto_ff::E_PetDecomposeDecomposeDesc make_pbmsg(){ return ::proto_ff::E_PetDecomposeDecomposeDesc(); }
	};
	typedef struct E_PetDecomposeDecomposeDesc_s E_PetDecomposeDecomposeDesc_t;

	struct E_PetDecompose_s : public NFDescStoreSeqOP {
		E_PetDecompose_s();
		virtual ~E_PetDecompose_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_quality;//宠物品质
		NFShmVector<struct E_PetDecomposeDecomposeDesc_s, DEFINE_E_PETDECOMPOSE_M_DECOMPOSE_MAX_NUM> m_decompose;//分解类型

		virtual void write_to_pbmsg(::proto_ff::E_PetDecompose & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_PetDecompose & msg);
		static ::proto_ff::E_PetDecompose* new_pbmsg(){ return new ::proto_ff::E_PetDecompose(); }
		static ::proto_ff::E_PetDecompose make_pbmsg(){ return ::proto_ff::E_PetDecompose(); }
	};
	typedef struct E_PetDecompose_s E_PetDecompose_t;

	struct Sheet_PetDecompose_s : public NFDescStoreSeqOP {
		Sheet_PetDecompose_s();
		virtual ~Sheet_PetDecompose_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_PetDecompose_s, DEFINE_SHEET_PETDECOMPOSE_E_PETDECOMPOSE_LIST_MAX_NUM> E_PetDecompose_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_PetDecompose & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_PetDecompose & msg);
		static ::proto_ff::Sheet_PetDecompose* new_pbmsg(){ return new ::proto_ff::Sheet_PetDecompose(); }
		static ::proto_ff::Sheet_PetDecompose make_pbmsg(){ return ::proto_ff::Sheet_PetDecompose(); }
	};
	typedef struct Sheet_PetDecompose_s Sheet_PetDecompose_t;

	struct E_PetFettersAttributeDesc_s : public NFDescStoreSeqOP {
		E_PetFettersAttributeDesc_s();
		virtual ~E_PetFettersAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_type;//ID

		virtual void write_to_pbmsg(::proto_ff::E_PetFettersAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_PetFettersAttributeDesc & msg);
		static ::proto_ff::E_PetFettersAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_PetFettersAttributeDesc(); }
		static ::proto_ff::E_PetFettersAttributeDesc make_pbmsg(){ return ::proto_ff::E_PetFettersAttributeDesc(); }
	};
	typedef struct E_PetFettersAttributeDesc_s E_PetFettersAttributeDesc_t;

	struct E_PetFetters_s : public NFDescStoreSeqOP {
		E_PetFetters_s();
		virtual ~E_PetFetters_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_quality;//羁绊品质
		NFShmVector<int32_t, DEFINE_E_PETFETTERS_M_PETID_MAX_NUM> m_petid;//羁绊宠物ID
		NFShmVector<struct E_PetFettersAttributeDesc_s, DEFINE_E_PETFETTERS_M_ATTRIBUTE_MAX_NUM> m_attribute;//基础属性
		NFShmVector<int32_t, DEFINE_E_PETFETTERS_M_ATCTIVE_SKILLID_MAX_NUM> m_atctive_skillid;//激活技能

		virtual void write_to_pbmsg(::proto_ff::E_PetFetters & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_PetFetters & msg);
		static ::proto_ff::E_PetFetters* new_pbmsg(){ return new ::proto_ff::E_PetFetters(); }
		static ::proto_ff::E_PetFetters make_pbmsg(){ return ::proto_ff::E_PetFetters(); }
	};
	typedef struct E_PetFetters_s E_PetFetters_t;

	struct Sheet_PetFetters_s : public NFDescStoreSeqOP {
		Sheet_PetFetters_s();
		virtual ~Sheet_PetFetters_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_PetFetters_s, DEFINE_SHEET_PETFETTERS_E_PETFETTERS_LIST_MAX_NUM> E_PetFetters_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_PetFetters & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_PetFetters & msg);
		static ::proto_ff::Sheet_PetFetters* new_pbmsg(){ return new ::proto_ff::Sheet_PetFetters(); }
		static ::proto_ff::Sheet_PetFetters make_pbmsg(){ return ::proto_ff::Sheet_PetFetters(); }
	};
	typedef struct Sheet_PetFetters_s Sheet_PetFetters_t;

	struct E_PetPetequipActDesc_s : public NFDescStoreSeqOP {
		E_PetPetequipActDesc_s();
		virtual ~E_PetPetequipActDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_mun;//数量
		int32_t m_time;//材料

		virtual void write_to_pbmsg(::proto_ff::E_PetPetequipActDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_PetPetequipActDesc & msg);
		static ::proto_ff::E_PetPetequipActDesc* new_pbmsg(){ return new ::proto_ff::E_PetPetequipActDesc(); }
		static ::proto_ff::E_PetPetequipActDesc make_pbmsg(){ return ::proto_ff::E_PetPetequipActDesc(); }
	};
	typedef struct E_PetPetequipActDesc_s E_PetPetequipActDesc_t;

	struct E_PetPetequip_s : public NFDescStoreSeqOP {
		E_PetPetequip_s();
		virtual ~E_PetPetequip_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_pet;//对应宠物
		int32_t m_orderid;//排序Id
		NFShmString<64> m_name;//备注
		int32_t m_qeuiditem;//专属物品
		int32_t m_equipqualitymin;//初始品质
		int32_t m_equipmodelid;//模型资源Id
		int32_t m_forging;//锻造类型
		int32_t m_star;//升星类型
		NFShmString<64> m_skill;//天赋技能
		NFShmVector<struct E_PetPetequipActDesc_s, DEFINE_E_PETPETEQUIP_M_ACT_MAX_NUM> m_act;//激活

		virtual void write_to_pbmsg(::proto_ff::E_PetPetequip & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_PetPetequip & msg);
		static ::proto_ff::E_PetPetequip* new_pbmsg(){ return new ::proto_ff::E_PetPetequip(); }
		static ::proto_ff::E_PetPetequip make_pbmsg(){ return ::proto_ff::E_PetPetequip(); }
	};
	typedef struct E_PetPetequip_s E_PetPetequip_t;

	struct Sheet_PetPetequip_s : public NFDescStoreSeqOP {
		Sheet_PetPetequip_s();
		virtual ~Sheet_PetPetequip_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_PetPetequip_s, DEFINE_SHEET_PETPETEQUIP_E_PETPETEQUIP_LIST_MAX_NUM> E_PetPetequip_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_PetPetequip & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_PetPetequip & msg);
		static ::proto_ff::Sheet_PetPetequip* new_pbmsg(){ return new ::proto_ff::Sheet_PetPetequip(); }
		static ::proto_ff::Sheet_PetPetequip make_pbmsg(){ return ::proto_ff::Sheet_PetPetequip(); }
	};
	typedef struct Sheet_PetPetequip_s Sheet_PetPetequip_t;

	struct E_PetEquipvalueAttributeDesc_s : public NFDescStoreSeqOP {
		E_PetEquipvalueAttributeDesc_s();
		virtual ~E_PetEquipvalueAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_type;//

		virtual void write_to_pbmsg(::proto_ff::E_PetEquipvalueAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_PetEquipvalueAttributeDesc & msg);
		static ::proto_ff::E_PetEquipvalueAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_PetEquipvalueAttributeDesc(); }
		static ::proto_ff::E_PetEquipvalueAttributeDesc make_pbmsg(){ return ::proto_ff::E_PetEquipvalueAttributeDesc(); }
	};
	typedef struct E_PetEquipvalueAttributeDesc_s E_PetEquipvalueAttributeDesc_t;

	struct E_PetEquipvalueExtraDesc_s : public NFDescStoreSeqOP {
		E_PetEquipvalueExtraDesc_s();
		virtual ~E_PetEquipvalueExtraDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_type;//

		virtual void write_to_pbmsg(::proto_ff::E_PetEquipvalueExtraDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_PetEquipvalueExtraDesc & msg);
		static ::proto_ff::E_PetEquipvalueExtraDesc* new_pbmsg(){ return new ::proto_ff::E_PetEquipvalueExtraDesc(); }
		static ::proto_ff::E_PetEquipvalueExtraDesc make_pbmsg(){ return ::proto_ff::E_PetEquipvalueExtraDesc(); }
	};
	typedef struct E_PetEquipvalueExtraDesc_s E_PetEquipvalueExtraDesc_t;

	struct E_PetEquipvalue_s : public NFDescStoreSeqOP {
		E_PetEquipvalue_s();
		virtual ~E_PetEquipvalue_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_equipvalue;//属性类型
		int32_t m_equiplv;//阶数
		int32_t m_item;//阶数物品
		int32_t m_winprob;//锻造成功概率
		int32_t m_equipitem;//道具消耗
		int32_t m_equipmun;//消耗数量
		int32_t m_failmax;//锻造保底次数
		NFShmVector<struct E_PetEquipvalueAttributeDesc_s, DEFINE_E_PETEQUIPVALUE_M_ATTRIBUTE_MAX_NUM> m_attribute;//属性
		NFShmVector<struct E_PetEquipvalueExtraDesc_s, DEFINE_E_PETEQUIPVALUE_M_EXTRA_MAX_NUM> m_extra;//额外属性

		virtual void write_to_pbmsg(::proto_ff::E_PetEquipvalue & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_PetEquipvalue & msg);
		static ::proto_ff::E_PetEquipvalue* new_pbmsg(){ return new ::proto_ff::E_PetEquipvalue(); }
		static ::proto_ff::E_PetEquipvalue make_pbmsg(){ return ::proto_ff::E_PetEquipvalue(); }
	};
	typedef struct E_PetEquipvalue_s E_PetEquipvalue_t;

	struct Sheet_PetEquipvalue_s : public NFDescStoreSeqOP {
		Sheet_PetEquipvalue_s();
		virtual ~Sheet_PetEquipvalue_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_PetEquipvalue_s, DEFINE_SHEET_PETEQUIPVALUE_E_PETEQUIPVALUE_LIST_MAX_NUM> E_PetEquipvalue_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_PetEquipvalue & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_PetEquipvalue & msg);
		static ::proto_ff::Sheet_PetEquipvalue* new_pbmsg(){ return new ::proto_ff::Sheet_PetEquipvalue(); }
		static ::proto_ff::Sheet_PetEquipvalue make_pbmsg(){ return ::proto_ff::Sheet_PetEquipvalue(); }
	};
	typedef struct Sheet_PetEquipvalue_s Sheet_PetEquipvalue_t;

	struct E_PetStarvalueAttributeDesc_s : public NFDescStoreSeqOP {
		E_PetStarvalueAttributeDesc_s();
		virtual ~E_PetStarvalueAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_type;//

		virtual void write_to_pbmsg(::proto_ff::E_PetStarvalueAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_PetStarvalueAttributeDesc & msg);
		static ::proto_ff::E_PetStarvalueAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_PetStarvalueAttributeDesc(); }
		static ::proto_ff::E_PetStarvalueAttributeDesc make_pbmsg(){ return ::proto_ff::E_PetStarvalueAttributeDesc(); }
	};
	typedef struct E_PetStarvalueAttributeDesc_s E_PetStarvalueAttributeDesc_t;

	struct E_PetStarvalueEquipDesc_s : public NFDescStoreSeqOP {
		E_PetStarvalueEquipDesc_s();
		virtual ~E_PetStarvalueEquipDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_mun;//数量
		int32_t m_item;//消耗

		virtual void write_to_pbmsg(::proto_ff::E_PetStarvalueEquipDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_PetStarvalueEquipDesc & msg);
		static ::proto_ff::E_PetStarvalueEquipDesc* new_pbmsg(){ return new ::proto_ff::E_PetStarvalueEquipDesc(); }
		static ::proto_ff::E_PetStarvalueEquipDesc make_pbmsg(){ return ::proto_ff::E_PetStarvalueEquipDesc(); }
	};
	typedef struct E_PetStarvalueEquipDesc_s E_PetStarvalueEquipDesc_t;

	struct E_PetStarvalue_s : public NFDescStoreSeqOP {
		E_PetStarvalue_s();
		virtual ~E_PetStarvalue_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_starvalue;//属性类型
		int32_t m_starlv;//星级
		NFShmVector<struct E_PetStarvalueAttributeDesc_s, DEFINE_E_PETSTARVALUE_M_ATTRIBUTE_MAX_NUM> m_attribute;//属性
		NFShmVector<NFShmString<64>, DEFINE_E_PETSTARVALUE_M_ADVANCE_TYPE_MAX_NUM> m_advance_type;//额外属性
		NFShmVector<struct E_PetStarvalueEquipDesc_s, DEFINE_E_PETSTARVALUE_M_EQUIP_MAX_NUM> m_equip;//道具

		virtual void write_to_pbmsg(::proto_ff::E_PetStarvalue & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_PetStarvalue & msg);
		static ::proto_ff::E_PetStarvalue* new_pbmsg(){ return new ::proto_ff::E_PetStarvalue(); }
		static ::proto_ff::E_PetStarvalue make_pbmsg(){ return ::proto_ff::E_PetStarvalue(); }
	};
	typedef struct E_PetStarvalue_s E_PetStarvalue_t;

	struct Sheet_PetStarvalue_s : public NFDescStoreSeqOP {
		Sheet_PetStarvalue_s();
		virtual ~Sheet_PetStarvalue_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_PetStarvalue_s, DEFINE_SHEET_PETSTARVALUE_E_PETSTARVALUE_LIST_MAX_NUM> E_PetStarvalue_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_PetStarvalue & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_PetStarvalue & msg);
		static ::proto_ff::Sheet_PetStarvalue* new_pbmsg(){ return new ::proto_ff::Sheet_PetStarvalue(); }
		static ::proto_ff::Sheet_PetStarvalue make_pbmsg(){ return ::proto_ff::Sheet_PetStarvalue(); }
	};
	typedef struct Sheet_PetStarvalue_s Sheet_PetStarvalue_t;

	struct E_PetWraithsMaterialDesc_s : public NFDescStoreSeqOP {
		E_PetWraithsMaterialDesc_s();
		virtual ~E_PetWraithsMaterialDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_exp;//经验值
		int64_t m_item;//道具

		virtual void write_to_pbmsg(::proto_ff::E_PetWraithsMaterialDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_PetWraithsMaterialDesc & msg);
		static ::proto_ff::E_PetWraithsMaterialDesc* new_pbmsg(){ return new ::proto_ff::E_PetWraithsMaterialDesc(); }
		static ::proto_ff::E_PetWraithsMaterialDesc make_pbmsg(){ return ::proto_ff::E_PetWraithsMaterialDesc(); }
	};
	typedef struct E_PetWraithsMaterialDesc_s E_PetWraithsMaterialDesc_t;

	struct E_PetWraiths_s : public NFDescStoreSeqOP {
		E_PetWraiths_s();
		virtual ~E_PetWraiths_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_wraithsname;//妖魂名称
		int32_t m_wraithspart;//妖魂部位
		int32_t m_wraithsstar;//妖魂星级
		int32_t m_wraithsquality;//妖魂品质
		int32_t m_wraithsequip;//对应装备
		int32_t m_propertylv;//升级类型
		int32_t m_propertyadvance;//进阶类型
		int32_t m_propertytop;//突破类型
		NFShmVector<struct E_PetWraithsMaterialDesc_s, DEFINE_E_PETWRAITHS_M_MATERIAL_MAX_NUM> m_material;//升级

		virtual void write_to_pbmsg(::proto_ff::E_PetWraiths & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_PetWraiths & msg);
		static ::proto_ff::E_PetWraiths* new_pbmsg(){ return new ::proto_ff::E_PetWraiths(); }
		static ::proto_ff::E_PetWraiths make_pbmsg(){ return ::proto_ff::E_PetWraiths(); }
	};
	typedef struct E_PetWraiths_s E_PetWraiths_t;

	struct Sheet_PetWraiths_s : public NFDescStoreSeqOP {
		Sheet_PetWraiths_s();
		virtual ~Sheet_PetWraiths_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_PetWraiths_s, DEFINE_SHEET_PETWRAITHS_E_PETWRAITHS_LIST_MAX_NUM> E_PetWraiths_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_PetWraiths & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_PetWraiths & msg);
		static ::proto_ff::Sheet_PetWraiths* new_pbmsg(){ return new ::proto_ff::Sheet_PetWraiths(); }
		static ::proto_ff::Sheet_PetWraiths make_pbmsg(){ return ::proto_ff::Sheet_PetWraiths(); }
	};
	typedef struct Sheet_PetWraiths_s Sheet_PetWraiths_t;

	struct E_PetWraithsvalueAttributeDesc_s : public NFDescStoreSeqOP {
		E_PetWraithsvalueAttributeDesc_s();
		virtual ~E_PetWraithsvalueAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_type;//ID

		virtual void write_to_pbmsg(::proto_ff::E_PetWraithsvalueAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_PetWraithsvalueAttributeDesc & msg);
		static ::proto_ff::E_PetWraithsvalueAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_PetWraithsvalueAttributeDesc(); }
		static ::proto_ff::E_PetWraithsvalueAttributeDesc make_pbmsg(){ return ::proto_ff::E_PetWraithsvalueAttributeDesc(); }
	};
	typedef struct E_PetWraithsvalueAttributeDesc_s E_PetWraithsvalueAttributeDesc_t;

	struct E_PetWraithsvalue_s : public NFDescStoreSeqOP {
		E_PetWraithsvalue_s();
		virtual ~E_PetWraithsvalue_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_wraithsvalue;//属性类型
		int32_t m_lv;//等级
		int32_t m_wraithsitem;//道具消耗
		int32_t m_wraithsmun;//消耗数量
		NFShmVector<struct E_PetWraithsvalueAttributeDesc_s, DEFINE_E_PETWRAITHSVALUE_M_ATTRIBUTE_MAX_NUM> m_attribute;//属性

		virtual void write_to_pbmsg(::proto_ff::E_PetWraithsvalue & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_PetWraithsvalue & msg);
		static ::proto_ff::E_PetWraithsvalue* new_pbmsg(){ return new ::proto_ff::E_PetWraithsvalue(); }
		static ::proto_ff::E_PetWraithsvalue make_pbmsg(){ return ::proto_ff::E_PetWraithsvalue(); }
	};
	typedef struct E_PetWraithsvalue_s E_PetWraithsvalue_t;

	struct Sheet_PetWraithsvalue_s : public NFDescStoreSeqOP {
		Sheet_PetWraithsvalue_s();
		virtual ~Sheet_PetWraithsvalue_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_PetWraithsvalue_s, DEFINE_SHEET_PETWRAITHSVALUE_E_PETWRAITHSVALUE_LIST_MAX_NUM> E_PetWraithsvalue_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_PetWraithsvalue & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_PetWraithsvalue & msg);
		static ::proto_ff::Sheet_PetWraithsvalue* new_pbmsg(){ return new ::proto_ff::Sheet_PetWraithsvalue(); }
		static ::proto_ff::Sheet_PetWraithsvalue make_pbmsg(){ return ::proto_ff::Sheet_PetWraithsvalue(); }
	};
	typedef struct Sheet_PetWraithsvalue_s Sheet_PetWraithsvalue_t;

	struct E_PetWraithslv_s : public NFDescStoreSeqOP {
		E_PetWraithslv_s();
		virtual ~E_PetWraithslv_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//妖魂升级id
		int32_t m_lvexp;//升级所需经验

		virtual void write_to_pbmsg(::proto_ff::E_PetWraithslv & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_PetWraithslv & msg);
		static ::proto_ff::E_PetWraithslv* new_pbmsg(){ return new ::proto_ff::E_PetWraithslv(); }
		static ::proto_ff::E_PetWraithslv make_pbmsg(){ return ::proto_ff::E_PetWraithslv(); }
	};
	typedef struct E_PetWraithslv_s E_PetWraithslv_t;

	struct Sheet_PetWraithslv_s : public NFDescStoreSeqOP {
		Sheet_PetWraithslv_s();
		virtual ~Sheet_PetWraithslv_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_PetWraithslv_s, DEFINE_SHEET_PETWRAITHSLV_E_PETWRAITHSLV_LIST_MAX_NUM> E_PetWraithslv_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_PetWraithslv & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_PetWraithslv & msg);
		static ::proto_ff::Sheet_PetWraithslv* new_pbmsg(){ return new ::proto_ff::Sheet_PetWraithslv(); }
		static ::proto_ff::Sheet_PetWraithslv make_pbmsg(){ return ::proto_ff::Sheet_PetWraithslv(); }
	};
	typedef struct Sheet_PetWraithslv_s Sheet_PetWraithslv_t;

	struct E_PetSmelt_s : public NFDescStoreSeqOP {
		E_PetSmelt_s();
		virtual ~E_PetSmelt_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_refinequality;//品质
		int32_t m_refinestar;//星级
		int32_t m_putmun;//放入妖魂数
		int32_t m_smeltexp;//获得经验
		int32_t m_smelt_box;//获得道具

		virtual void write_to_pbmsg(::proto_ff::E_PetSmelt & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_PetSmelt & msg);
		static ::proto_ff::E_PetSmelt* new_pbmsg(){ return new ::proto_ff::E_PetSmelt(); }
		static ::proto_ff::E_PetSmelt make_pbmsg(){ return ::proto_ff::E_PetSmelt(); }
	};
	typedef struct E_PetSmelt_s E_PetSmelt_t;

	struct Sheet_PetSmelt_s : public NFDescStoreSeqOP {
		Sheet_PetSmelt_s();
		virtual ~Sheet_PetSmelt_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_PetSmelt_s, DEFINE_SHEET_PETSMELT_E_PETSMELT_LIST_MAX_NUM> E_PetSmelt_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_PetSmelt & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_PetSmelt & msg);
		static ::proto_ff::Sheet_PetSmelt* new_pbmsg(){ return new ::proto_ff::Sheet_PetSmelt(); }
		static ::proto_ff::Sheet_PetSmelt make_pbmsg(){ return ::proto_ff::Sheet_PetSmelt(); }
	};
	typedef struct Sheet_PetSmelt_s Sheet_PetSmelt_t;

	struct E_PetRefineconversion_s : public NFDescStoreSeqOP {
		E_PetRefineconversion_s();
		virtual ~E_PetRefineconversion_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_itemid;//兑换道具
		int32_t m_group;//组
		int32_t m_conversionitem;//所需道具
		int32_t m_conversionmun;//兑换数量

		virtual void write_to_pbmsg(::proto_ff::E_PetRefineconversion & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_PetRefineconversion & msg);
		static ::proto_ff::E_PetRefineconversion* new_pbmsg(){ return new ::proto_ff::E_PetRefineconversion(); }
		static ::proto_ff::E_PetRefineconversion make_pbmsg(){ return ::proto_ff::E_PetRefineconversion(); }
	};
	typedef struct E_PetRefineconversion_s E_PetRefineconversion_t;

	struct Sheet_PetRefineconversion_s : public NFDescStoreSeqOP {
		Sheet_PetRefineconversion_s();
		virtual ~Sheet_PetRefineconversion_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_PetRefineconversion_s, DEFINE_SHEET_PETREFINECONVERSION_E_PETREFINECONVERSION_LIST_MAX_NUM> E_PetRefineconversion_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_PetRefineconversion & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_PetRefineconversion & msg);
		static ::proto_ff::Sheet_PetRefineconversion* new_pbmsg(){ return new ::proto_ff::Sheet_PetRefineconversion(); }
		static ::proto_ff::Sheet_PetRefineconversion make_pbmsg(){ return ::proto_ff::Sheet_PetRefineconversion(); }
	};
	typedef struct Sheet_PetRefineconversion_s Sheet_PetRefineconversion_t;

	struct E_PetStoveStoveDesc_s : public NFDescStoreSeqOP {
		E_PetStoveStoveDesc_s();
		virtual ~E_PetStoveStoveDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_mun;//值
		int32_t m_value;//属性

		virtual void write_to_pbmsg(::proto_ff::E_PetStoveStoveDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_PetStoveStoveDesc & msg);
		static ::proto_ff::E_PetStoveStoveDesc* new_pbmsg(){ return new ::proto_ff::E_PetStoveStoveDesc(); }
		static ::proto_ff::E_PetStoveStoveDesc make_pbmsg(){ return ::proto_ff::E_PetStoveStoveDesc(); }
	};
	typedef struct E_PetStoveStoveDesc_s E_PetStoveStoveDesc_t;

	struct E_PetStove_s : public NFDescStoreSeqOP {
		E_PetStove_s();
		virtual ~E_PetStove_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_stovelv;//等级
		int32_t m_stoveexp;//升级所需经验
		int32_t m_stovemax;//炼妖开放上限
		NFShmVector<struct E_PetStoveStoveDesc_s, DEFINE_E_PETSTOVE_M_STOVE_MAX_NUM> m_stove;//妖炉

		virtual void write_to_pbmsg(::proto_ff::E_PetStove & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_PetStove & msg);
		static ::proto_ff::E_PetStove* new_pbmsg(){ return new ::proto_ff::E_PetStove(); }
		static ::proto_ff::E_PetStove make_pbmsg(){ return ::proto_ff::E_PetStove(); }
	};
	typedef struct E_PetStove_s E_PetStove_t;

	struct Sheet_PetStove_s : public NFDescStoreSeqOP {
		Sheet_PetStove_s();
		virtual ~Sheet_PetStove_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_PetStove_s, DEFINE_SHEET_PETSTOVE_E_PETSTOVE_LIST_MAX_NUM> E_PetStove_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_PetStove & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_PetStove & msg);
		static ::proto_ff::Sheet_PetStove* new_pbmsg(){ return new ::proto_ff::Sheet_PetStove(); }
		static ::proto_ff::Sheet_PetStove make_pbmsg(){ return ::proto_ff::Sheet_PetStove(); }
	};
	typedef struct Sheet_PetStove_s Sheet_PetStove_t;

	struct E_PetSuitAttributeDesc_s : public NFDescStoreSeqOP {
		E_PetSuitAttributeDesc_s();
		virtual ~E_PetSuitAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_type;//

		virtual void write_to_pbmsg(::proto_ff::E_PetSuitAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_PetSuitAttributeDesc & msg);
		static ::proto_ff::E_PetSuitAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_PetSuitAttributeDesc(); }
		static ::proto_ff::E_PetSuitAttributeDesc make_pbmsg(){ return ::proto_ff::E_PetSuitAttributeDesc(); }
	};
	typedef struct E_PetSuitAttributeDesc_s E_PetSuitAttributeDesc_t;

	struct E_PetSuit_s : public NFDescStoreSeqOP {
		E_PetSuit_s();
		virtual ~E_PetSuit_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_wraithsquality;//妖魂需求
		int32_t m_piece;//套装件数
		int32_t m_resonancetype;//共鸣属性
		int32_t m_resonancevalue;//共鸣属性值
		NFShmVector<struct E_PetSuitAttributeDesc_s, DEFINE_E_PETSUIT_M_ATTRIBUTE_MAX_NUM> m_attribute;//属性

		virtual void write_to_pbmsg(::proto_ff::E_PetSuit & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_PetSuit & msg);
		static ::proto_ff::E_PetSuit* new_pbmsg(){ return new ::proto_ff::E_PetSuit(); }
		static ::proto_ff::E_PetSuit make_pbmsg(){ return ::proto_ff::E_PetSuit(); }
	};
	typedef struct E_PetSuit_s E_PetSuit_t;

	struct Sheet_PetSuit_s : public NFDescStoreSeqOP {
		Sheet_PetSuit_s();
		virtual ~Sheet_PetSuit_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_PetSuit_s, DEFINE_SHEET_PETSUIT_E_PETSUIT_LIST_MAX_NUM> E_PetSuit_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_PetSuit & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_PetSuit & msg);
		static ::proto_ff::Sheet_PetSuit* new_pbmsg(){ return new ::proto_ff::Sheet_PetSuit(); }
		static ::proto_ff::Sheet_PetSuit make_pbmsg(){ return ::proto_ff::Sheet_PetSuit(); }
	};
	typedef struct Sheet_PetSuit_s Sheet_PetSuit_t;

}
