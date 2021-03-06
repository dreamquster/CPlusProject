#ifndef __KSCOSAPIDATATYPE_H_INCLUDED_
#define __KSCOSAPIDATATYPE_H_INCLUDED_
/**
* @file KSCosApiDataType.h
* @author kevin.shen
* system：KSTradeAPI
* company：Kingstar
* history：
* 2012/11/12	kevin.shen	 create
*/

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

namespace KingstarAPI
{

/////////////////////////////////////////////////////////////////////////
///TKSConditionalTypeType///条件类型类型
/////////////////////////////////////////////////////////////////////////
///大于等于条件价
#define KSCOS_GreaterEqualTermPrice '0'
///小于等于条件价
#define KSCOS_LesserThanTermPrice '1'

typedef char TKSConditionalTypeType;

/////////////////////////////////////////////////////////////////////////
///TKSConditionalOrderType///条件单类型类型
/////////////////////////////////////////////////////////////////////////
///行情触发
#define KSCOS_TRIGGERTYPE_QUOTATION '0'
///开盘触发
#define KSCOS_TRIGGERTYPE_OPEN '1'
///时间触发
#define KSCOS_TRIGGERTYPE_TIME '2'
///行情和时间触发
#define KSCOS_TRIGGERTYPE_QUOTAIONANDTIME '5' 

typedef char TKSConditionalOrderType;

/////////////////////////////////////////////////////////////////////////
///TKSConditionalOrderStateAlterType///暂停或激活操作标志
/////////////////////////////////////////////////////////////////////////
///暂停
#define KSCOS_State_PAUSE '0'
///激活
#define KSCOS_State_ACTIVE '1'

typedef char TKSConditionalOrderStateAlterType;

/////////////////////////////////////////////////////////////////////////
///TKSConditionalOrderSelectResultType///选择结果
/////////////////////////////////////////////////////////////////////////
// 重试
#define KSCOS_Select_AGAIN '0'
// 跳过
#define KSCOS_Select_SKIP '1'
// 终止
#define KSCOS_Select_ABORT '2'

typedef char TKSConditionalOrderSelectResultType;

/////////////////////////////////////////////////////////////////////////
///TKSOrderPriceTypeType///报单价格类型类型
/////////////////////////////////////////////////////////////////////////
// 最新价
#define KSCOS_OrderPrice_LastPrice '0'
// 买价
#define KSCOS_OrderPrice_BidPrice '1'
//卖价
#define KSCOS_OrderPrice_AskPrice '2'

typedef char TKSOrderPriceTypeType;

/////////////////////////////////////////////////////////////////////////
///TKSCloseModeType///平仓价格类型
/////////////////////////////////////////////////////////////////////////
// 市价
#define KSPL_Close_MarketPrice '0'
// 加减买卖价
#define KSPL_Close_SalePrice '1'
//加减最新价
#define KSPL_Close_LastPrice '2'

typedef char TKSCloseModeType;

/////////////////////////////////////////////////////////////////////////
///TKSOffsetType///生成止损止盈价的方式类型
/////////////////////////////////////////////////////////////////////////
// 指定值
#define KSPL_OffsetValue_TermPrice '0'
// 开仓成交价的相对偏移值
#define KSPL_OffsetValue_TradePrice '1'

typedef char TKSOffsetValueType;

/////////////////////////////////////////////////////////////////////////
///TKSSpringTypeType是一个报单价格条件类型
/////////////////////////////////////////////////////////////////////////
///最新价
#define KSPL_SPRING_LastPrice '0'
///买卖价
#define KSPL_SPRING_SalePrice '1'

typedef char TKSSpringTypeType;

/////////////////////////////////////////////////////////////////////////
///TKSConditionalOrderStatusType///条件单状态
/////////////////////////////////////////////////////////////////////////
// 暂停
#define KSCOS_OrderStatus_PAUSENOTOUCHED      '0'
// 未触发
#define KSCOS_OrderStatus_ACTIVENOTOUCHED    '1'
//删除
#define KSCOS_OrderStatus_Deleted                     '2'
//已触发未发送
#define KSCOS_OrderStatus_TOUCHEDNOSEND   '3'
// 发送超时
#define KSCOS_OrderStatus_SENDTIMEOUT   '4'
//发送成功
#define KSCOS_OrderStatus_SENDSUCCESS   '5'
// 等待选择
#define KSCOS_OrderStatus_WAITSELECT   '6'
// 选择跳过
#define KSCOS_OrderStatus_SELECTSKIP   '7'
// 选择终止
#define KSCOS_OrderStatus_SELECTABORT   '8'

typedef char TKSConditionalOrderStatusType;

/////////////////////////////////////////////////////////////////////////
///TKSConditionalOrderIDType///条件单编号类型
/////////////////////////////////////////////////////////////////////////
typedef int TKSConditionalOrderIDType;

/////////////////////////////////////////////////////////////////////////
///TKSProfitAndLossOrderIDType///止损止盈单编号类型
/////////////////////////////////////////////////////////////////////////
typedef int TKSProfitAndLossOrderIDType;

/////////////////////////////////////////////////////////////////////////
///TKSConditionalOrderSelectTypeType///条件单选择方式类型
/////////////////////////////////////////////////////////////////////////
// 确认、取消 
#define KSCOS_Select_ConfirmORCancel '1'
// 重试、跳过、终止 
#define KS_Select_AgainOrSkipOrAbort '2'

typedef char TKSConditionalOrderSelectTypeType;

}	// end of namespace KingstarAPI
#endif