#include "code_template.h"
#include "string.h"
#include "public.h"

ModuleTemplate_InfType ModuleTemplate_Info;

#ifdef MINIMUM_RAM__
	#define GCFG(Member) (ModuleTemplate_Info.CfgPtr->Member)
#else
	#define GCFG(Member) (ModuleTemplate_Info.Config.Member)
#endif
#define INSCFG(Member) ((GCFG(InsCfgPtr) + ins)->Member)
#define INSINF(Member) ((GCFG(InsInfPtr) + ins)->Member)


/**
 * @brief 初始化
 *
 * @param cfgPtr:
 */
void ModuleTemplate_Init(const ModuleTemplate_CfgType *cfgPtr)
{
	uint8 ins;

	memset(&ModuleTemplate_Info, 0, sizeof(ModuleTemplate_InfType));
	if (NULL == cfgPtr)
		return;
#ifdef MINIMUM_RAM__
	ModuleTemplate_Info.CfgPtr = cfgPtr;
#else
	memcpy((void *)&ModuleTemplate_Info.Config, cfgPtr, sizeof(ModuleTemplate_CfgType));
#endif
	memset((void *)GCFG(InsInfPtr), 0, sizeof(ModuleTemplate_InsInfType) * GCFG(InsNum));
	for (ins = 0; ins < GCFG(InsNum); ins++) {
		GCFG(I2cStartFuncPtr)(ins);
	}
}

/**
 * @brief 返回实例的状态指针
 *
 * @param ins:
 * @return ModuleTemplate_InsInfType*:
 */
ModuleTemplate_InsInfType *ModuleTemplate_GetInsInfPtr(uint8 ins)
{
	if (NULL == GCFG(InsInfPtr) || ins > GCFG(InsNum))
		return NULL;
	return GCFG(InsInfPtr) + ins;
}

/**
 * @brief 返回模块实例配置指针
 *
 * @param ins:
 * @return const ModuleTemplate_InsCfgType*:
 */
const ModuleTemplate_InsCfgType *ModuleTemplate_GetInsCfgPtr(uint8 ins)
{
	if (NULL == GCFG(InsCfgPtr) || ins > GCFG(InsNum))
		return NULL;
	return GCFG(InsCfgPtr) + ins;
}

/**
 * @brief 周期Main函数
 *
 */
void ModuleTemplate_Main(void)
{
	uint8 ins;
	for (ins = 0; ins < GCFG(InsNum); ins++) {
		GCFG(I2cStartFuncPtr)(ins);
	}
}
