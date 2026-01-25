#ifndef MODULE_TEMPLATE_H__
#define MODULE_TEMPLATE_H__
#include "type.h"

/**
 * @brief 实例配置
 *
 */
typedef struct {
	uint8 InsCfgMember1;
} ModuleTemplate_InsCfgType;

/**
 * @brief 实例状态(开辟RAM)
 *
 */
typedef struct {
	uint8 InsInfMember1;
} ModuleTemplate_InsInfType;

/**
 * @brief 公共配置
 *
 */
typedef struct {
	const ModuleTemplate_InsCfgType *InsCfgPtr;
	ModuleTemplate_InsInfType *InsInfPtr;
	uint8 InsNum;
	uint32 (*GetSysTickFuncPtr)(void);
	uint32 (*SetStartNoticationFuncPtr)(uint8 ins);
	uint8 MaxOverTimeMs;
} ModuleTemplate_CfgType;

/**
 * @brief 全局状态
 *
 */
typedef struct {
#ifdef MINIMUM_RAM__
	const ModuleTemplate_CfgType *CfgPtr;
#else
	const ModuleTemplate_CfgType Config;
#endif
} ModuleTemplate_InfType;

// 变量声明
extern ModuleTemplate_InfType ModuleTemplate_Info;

// 对外提供接口
void ModuleTemplate_Init(const ModuleTemplate_CfgType *cfgPtr);
ModuleTemplate_InsInfType *ModuleTemplate_GetInsInfPtr(uint8 ins);
const ModuleTemplate_InsCfgType *ModuleTemplate_GetInsCfgPtr(uint8 ins);
void ModuleTemplate_Main(void);

#endif    // MODULE_TEMPLATE_H__
