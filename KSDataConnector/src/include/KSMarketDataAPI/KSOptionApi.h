#ifndef __KSOPTIONAPI_H_INCLUDED__
#define __KSOPTIONAPI_H_INCLUDED__
/**
* @file KSOptionApi.h
* @author kevin.shen
* system：KSTradeAPI
* company：Kingstar
* history：
* 2013/11/18	kevin.shen	 create
*/

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "KSOptionApiStruct.h"

#if defined(ISLIB) && defined(WIN32)
#ifdef LIB_TRADER_API_EXPORT
#define TRADER_OPTIONAPI_EXPORT __declspec(dllexport)
#else
#define TRADER_OPTIONAPI_EXPORT __declspec(dllimport)
#endif
#else
#ifdef WIN32
#define TRADER_OPTIONAPI_EXPORT 
#else
#define TRADER_OPTIONAPI_EXPORT __attribute__((visibility("default")))
#endif

#endif

namespace KingstarAPI
{

class CKSOptionSpi
{
public:
	///执行宣告操作请求响应
	virtual void OnRspKSExecOrderAction(CThostFtdcInputKSExecOrderActionField *pInputExecOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///请求查询执行宣告响应
	virtual void OnRspQryKSExecOrder(CThostFtdcKSExecOrderField *pKSExecOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///宣告录入请求响应
	virtual void OnRspKSExecOrderInsert(CThostFtdcInputKSExecOrderField *pInputKSExecOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///查询宣告数量请求响应
	virtual void OnRspQryExecOrderVolume(CKSExecOrderVolumeField *pExecOrderVolume, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///查询现货期权参数请求响应
	virtual void OnRspQrySpotOptionParams(CKSSpotOptionParamsField *pExecOrderParams, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///查询期权合约相关信息请求响应
	virtual void OnRspQryOptionInsInfo(CKSOptionInsInfoField *pOptionInsInfo, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///查询个股期权手续费率请求响应
	virtual void OnRspQryStockOptionInsCommRate(CKSStockOptionInsCommRateField *pStockOptionInsCommRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///查询个股期权保证金率请求响应
	virtual void OnRspQryStockOptionInsMarginRate(CKSStockOptionInsMarginRateField *pStockOptionInsMarginRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///查询个股行权指派信息请求响应
	virtual void OnRspQryStockOptionAssignment(CKSStockOptionAssignmentField *pStockOptionAssignment, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///执行宣告通知(含执行、放弃)
	virtual void OnRtnKSExecOrder(CThostFtdcKSExecOrderRtnField *pExecOrder) {};
};

class TRADER_OPTIONAPI_EXPORT CKSOptionApi
{
public:
	///请求查询执行宣告
	virtual int ReqQryKSExecOrder(CThostFtdcQryKSExecOrderField *pQryKSExecOrder, int nRequestID) = 0;

	///宣告录入请求
	virtual int ReqKSExecOrderInsert(CThostFtdcInputKSExecOrderField *pInputKSExecOrder, int nRequestID) = 0;

	///查询宣告数量请求
	virtual int ReqQryExecOrderVolume(CKSQryExecOrderVolumeField *pQryExecOrderVolume, int nRequestID) = 0;

	///查询现货期权参数请求
	virtual int ReqQrySpotOptionParams(CKSQrySpotOptionParamsField *pQrySpotOptionParams, int nRequestID) = 0;

	///查询期权合约相关信息请求
	virtual int ReqQryOptionInsInfo(CKSQryOptionInsInfoField *pQryOptionInsInfo, int nRequestID) = 0;

	///查询个股期权手续费率请求
	virtual int ReqQryStockOptionInsCommRate(CKSQryStockOptionInsCommRateField *pQryStockOptionInsCommRate, int nRequestID) = 0;

	///查询个股期权保证金率请求
	virtual int ReqQryStockOptionInsMarginRate(CKSQryStockOptionInsMarginRateField *pQryStockOptionInsMarginRate, int nRequestID) = 0;

	///查询个股行权指派信息
	virtual int ReqQryStockOptionAssignment(CKSQryStockOptionAssignmentField *pQryStockOptionAssignment, int nRequestID) = 0;
protected:
	~CKSOptionApi(){};
};

}	// end of namespace KingstarAPI
#endif