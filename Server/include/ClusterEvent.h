/* 106 228 203 199 203 251 69 164 171 249 223 147 102 233 72 137 119 94 82 90 79 10 155 183 241 217 150 77 172 108 93 173 68 19 40 212 204 206 54 180 157 223 26 99 125 119 19 97 77 110 19 247 97 96 131 5 72 145 14 214 105 62 226 149 70 6 217 120 217 88 234 61 209 73 37 67 248  */
#pragma once

#include "LambdaWrap.h"
#include "ErrorInfo.h"

namespace Proud
{
	typedef LambdaBaseHolder_Param1<void, const ErrorInfo*>			 FunctionJoinClusterServer;
	typedef LambdaBaseHolder_Param1<void, const ErrorInfo*>			 FunctionLeaveClusterServer;

	typedef LambdaBaseHolder_Param1<void, const CFastArray<HostID>&> FunctionDetectedNewClusterPeer;

	typedef LambdaBaseHolder_Param1<void, HostID>					 FunctionJoinClusterPeer;
	typedef LambdaBaseHolder_Param1<void, HostID>					 FunctionLeaveClusterPeer;

	typedef LambdaBaseHolder_Param1<void, int>						 FunctionNoRmiProcessed;
	typedef LambdaBaseHolder_Param1<void, const Exception&>			 FunctionException;

	typedef LambdaBaseHolder_Param1<void, const ErrorInfo*>			 FunctionJoinApiGatewayServerComplete;
	typedef LambdaBaseHolder_Param1<void, const ErrorInfo*>			 FunctionLeaveApiGatewayServer;
}