#include "code_template_user.h"
#include "public.h"
#include "task.h"

/**
 * @brief 实例配置
 *
 */
static const ModuleTemplate_InsCfgType ModuleTemplate_InsCfg[] = {
	{0},
};
/**
 * @brief 实例状态
 *
 */
static ModuleTemplate_InsInfType ModuleTemplate_InsInf[ARRAY_SIZE(ModuleTemplate_InsCfg)];

/**
 * @brief
 *
 */
void ModuleTemplate_UserInit(void)
{
	ModuleTemplate_CfgType ModuleTemplate_Config = {0};//可选 放到flash中
	ModuleTemplate_Config.InsCfgPtr = ModuleTemplate_InsCfg;
	ModuleTemplate_Config.InsInfPtr = ModuleTemplate_InsInf;
	ModuleTemplate_Config.InsNum = ARRAY_SIZE(ModuleTemplate_InsCfg);
	ModuleTemplate_Config.GetSysTickFuncPtr = Tim_GetTick;
	ModuleTemplate_Config.StartNoticationFuncPtr = NULL;
	ModuleTemplate_Config.MaxOverTimeMs = 100;
	ModuleTemplate_Init(&ModuleTemplate_Config);
	Task_Creat(TASK_NOR, ModuleTemplate_Main, 5);//可选 
}
