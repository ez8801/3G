/* 106 228 203 199 203 251 69 164 171 249 223 147 102 233 72 137 119 94 82 90 79 10 155 183 241 217 150 77 172 108 93 173 68 19 40 212 204 206 54 180 157 223 26 99 125 119 19 97 77 110 19 247 97 96 131 5 72 145 14 214 105 62 226 154 70 6 217 121 223 90 234 52 213 76 97 23 184  */
/*
ProudNet 1.7.38050-master


이 프로그램의 저작권은 넷텐션에게 있습니다.
이 프로그램의 수정, 사용, 배포에 관련된 사항은 본 프로그램의 소유권자와의 계약을 따르며,
계약을 준수하지 않는 경우 원칙적으로 무단 사용을 금지합니다.
무단 사용에 의한 책임은 본 프로그램의 소유권자와의 계약서에 명시되어 있습니다.

** 주의 : 저작물에 관한 위의 명시를 제거하지 마십시오.


This program is soley copyrighted by Nettention.
Any use, correction, and distribution of this program are subject to the terms and conditions of the License Agreement.
Any violated use of this program is prohibited and will be cause of immediate termination according to the License Agreement.

** WARNING : PLEASE DO NOT REMOVE THE LEGAL NOTICE ABOVE.


此程序的版??Nettention公司所有。
?此程序的修改、使用、?布相?的事?要遵守此程序的所有?者的??。
不遵守???要原?性的禁止擅自使用。
擅自使用的?任明示在?此程序所有?者的合同?里。

** 注意：不要移除?于制作物的上述明示。


このプログラムの著作?はNettentionにあります。
このプログラムの修正、使用、配布に?する事項は本プログラムの所有?者との契約に?い、
契約を遵守しない場合、原則的に無?使用を禁じます。
無?使用による責任は本プログラムの所有?者との契約書に明示されています。

** 注意：著作物に?する上記の明示を除去しないでください。

*/

#pragma once

#include "BasicTypes.h"
#include "FakeClr.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	class CThreadPool;

	/** \addtogroup net_group
	*  @{
	*/

	/**
	\~korean
	서버에 연결하기 위한 정보 구조체

	\~english
	Informtion structure of making server connection

	\~chinese
	?了?接服?器的信息?造?。

	\~japanese
	サ?バ?に接?するための情報構造?
	\~
	 */
	class CNetConnectionParam
	{
	public:
		/**
		\~korean
		연결할 서버의 주소
		- 예: 111.222.111.222(IP 주소식) 혹은 game.mydomain.net(호스트 이름식)
		- 스트레스 테스트를 하는 경우에 한꺼번에 많은 클라이언트가 서버에 접속해야 합니다. 이러한 경우
		서버 주소가 호스트 이름식인 경우 접속 속도가 매우 느릴 수 있습니다. 따라서 스트레스 테스트를 할 경우
		서버 주소로 IP 주소식을 쓰는 것을 권장합니다.

		\~english
		Address of server to coneec to
		- ex: 111.222.111.222(IP address) or game.mydomain.net(host name)
		- During a stress test, lots of clients need to be connected to the server at the same time.
		If the server address is a type of a host name, it can be seriously laggy.
		It is strongly recommended to use IP address format for server address.

		\~chinese
		要?接的服?器地址。
		- 例：111.222.111.222（IP 地址式）或 game.mydomain.net（主机名式）。
		- 做?力??的情?一次要?接多?客?端。??情?服?器地址是主机名式的?，?接速度可能??慢。因此做?力??的?候建?把IP地址式用?服?器地址。

		\~japanese
		接?するサ?バ?のアドレス
		- 例: 111.222.111.222(IPアドレス形式)または game.mydomain.net(ホスト名形式)
		- ストレステストをする場合に一度に多いクライアントがサ?バ?に接?しなければなりません。このような場合
		サ?バ?アドレスがホスト名形式である場合、接?速度が非常に?い場合があります。よって、ストレステストをする場合、サ?バ?アドレスとしてIPアドレス形式を使うことをお?めします。
		\~
		 */
		String m_serverIP;

		/**
		\~korean
		연결할 서버의 TCP 포트입니다.

		\~english
		The TCP port of the server to be connected.

		\~chinese
		要?接的服?器TCP端口。

		\~japanese
		接?するサ?バ?のTCPポ?トです。
		\~
		 */
		uint16_t m_serverPort;

		///**
		//\~korean
		//여러분이, 서버 주소로 FQDN(예: game1.mygame.com)을 사용할 수 없는 상황이지만, IPv6 클라이언트에서 IPv4 서버로 접속을 해야 하는 상황이신가요? 이 때를 위한 응급 기능입니다.
		//서버 주소로 IPv4 literal (예: 11.22.33.44)를 넣으시고, 이 두 멤버 변수에다가 IPv4 서버 주소의 FQDN을 넣으십시오. 다음은 예입니다.
		//serverIP: 11.22.33.44
		//publicDomainName1: www.naver.com
		//publicDomainName2: www.nts.go.kr
		//단, 위와 같은 상황이 아니면 본 기능을 사용하지 않는 것을 권장합니다. 대신 서버 주소로 FQDN을 사용하십시오.

		//자세한 것은 <a target="_blank" href="http://guide.nettention.com/cpp_ko#apple_ipv6_workaround" >Apple의 IPv6 정책 우회책</a> 를 참고하십시오.

		//\~english
		//It is the variable that enables connection from IPv6 network client even if connects to server by IPv4 literal string.
		//For more details, please refer to tips for resolving <a target="_blank" href="http://guide.nettention.com/cpp_en#apple_ipv6_workaround" >Apple's IPv6 enforcement.</a>

		//\~chinese
		//It is the variable that enables connection from IPv6 network client even if connects to server by IPv4 literal string.
		//For more details, please refer to tips for resolving <a target="_blank" href="http://guide.nettention.com/cpp_zh#apple_ipv6_workaround" >Apple's IPv6 enforcement.</a>

		//\~japanese
		//It is the variable that enables connection from IPv6 network client even if connects to server by IPv4 literal string.
		//For more details, please refer to tips for resolving <a target="_blank" href="http://guide.nettention.com/cpp_jp#apple_ipv6_workaround" >Apple's IPv6 enforcement.</a>
		//*/
		//String m_publicDomainName1;

		///** \copydoc m_publicDomainName1 */
		//String m_publicDomainName2;

 		/**
		\~korean
		클라이언트에서 생성하는 UDP socket이 사용할 local port 번호들입니다.

		이 모듈은 서버나 peer와의 연결 각각을 위해 1개의 UDP port를 사용합니다. 이때 m_localUdpPortPool 에서 지정한
		포트 번호들을 local port로 삼는 UDP socket들을 생성하게 됩니다. 만약 m_localUdpPortPool에서 시정한
		포트 번호가 없거나 m_localUdpPortPool에서 지정한 포트 번호들이 모두 다른데서 사용중인 경우 임의의
		포트 번호가 지정되어 UDP socket이 생성됩니다.

		일반적으로는 m_localUdpPortPool 값은 그냥 두시는 것이 좋습니다. 하지만 의도적으로 local UDP socket의
		port 번호를 강제로 지정하고자 할 때 m_localUdpPortPool 안에 원하시는 값들을 넣으십시오.

		\~english
		Numbers of UDP ports for newly created UDP sockets.

		This host module uses an UDP port for each server or peer connection. Values in m_localUdpPortPool are
		used for binding local UDP port to every UDP socket created by this module. Arbitrary UDP port number
		will be taken if m_localUdpPortPool is empty or no available UDP port corresponding to m_localUdpPortPool
		exists.

		In ordinary case, m_localUdpPortPool should be left unchanged. You should add values into m_localUdpPortPool
		if you want to bind some local UDP ports to UDP sockets created by this module.

		\~chinese
		在客?端生成的UDP socket要使用的local port??。
		此模??了?服?器或者peer的?接，各使用一?UDP port。???生成在m_localUdpPortPool指定的端口???local port的UDP socket。
		如果?有在m_localUdpPortPool指定的端口??，或者在m_localUdpPortPool指定的端口??都在?的地方使用中的?候，任意端口???被指定?生成UDP socket。
		一般的情?下，最好不要?m_localUdpPortPool?。但是想强制指定local UDP socket的port的?候，往m_localUdpPortPool里放所需的?。

		\~japanese
		クライアントで生成するUDP socketが使用するLocal port番?です。
		このモジュ?ルはサ?バ?とかpeerとの連結のためにそれぞれ1個のUDP portを使用します。この時、m_localUdpPortPoolで指定したポ?ト番?をLocal portとするUDP socketを生成するようになります。もし、m_localUdpPortPoolで是正したポ?ト番?がないとか、m_localUdpPortPoolで指定したポ?ト番?が全て違う所で使用中の場合、任意のポ?ト番?が指定されUDP socketが生成されます。
		一般的にm_localUdpPortPool値はそのまま置いた方が良いです。しかし、意?的にlocal UDP socketのport番?を?制に指定したい場合、m_localUdpPortPool?に希望する値を入れてください。
		\~
		 */
		CFastArray<int> m_localUdpPortPool;

		/**
		\~korean
		서버에 연결하기 전에, 서버와의 프로토콜 매칭을 위한 값입니다.
		- CNetServer.Start에서 입력했던 protocol version과 서버와의 연결이 성공합니다. 그렇지 않을 경우
		ErrorType_ProtocolVersionMismatch가 서버 연결 후 응답으로 옵니다.

		\~english
		This is the value to match the protocol with servers before connecting to the severs.
		- The connection to the server with the protocol version that was input at CNetServer.Start.
		If not, ErrorType_ProtocolVerionMismatch is to be returned after connected to the server.

		\~chinese
		?接服?器之前，?了?服?器protocol匹配的?。
		- 在 CNetServer.Start%?入的protocol version和服?器?接成功了。否??接服?器之后?得到ErrorType_ProtocolVersionMismatch。

		\~japanese
		サ?バ?に接?する前に、サ?バ?とのプロトコルマッチングのための値です。
		- CNetServer.Startで入力したprotocol versionとサ?バ?との接?が成功します。そうではない場合、ErrorType_ProtocolVersionMismatchがサ?バ?接?後に?答として?ます。
		\~
		 */
		Guid m_protocolVersion;
		/**
		\~korean
		서버에 보내는 추가 연결 정보입니다. INetServerEvent.OnConnectionRequest()에서 이 데이터가 받아집니다.

		\~english
		This is an additional connection info to be sent to the server.
 		This data is received at INetServerEvent.OnConnectRequest().

		\~chinese
		在服?器?送?外附加?接信息。
		在 INetServerEvent.OnConnectionRequest()接收?据。

		\~japanese
		サ?バ?に送る追加接?情報です。INetServerEvent.OnConnectionRequest()でこのデ?タが受け取られます。
		\~
		 */
		ByteArray m_userData;

		/**
		\~korean
		기본값은 false 입니다.
		true 로 설정할 경우 Reliable P2P 의 전송속도는 1MB/sec를 감당할 수 없습니다.
		그러나 처리 성능이 가벼워집니다. 더미 클라이언트 테스트를 할 때에만 true 로 설정하십시오.

		\~english
		Default is false.
		If setting it as true, Reliable P2P transmission speed cannot support 1MB/sec.
		But performance will be improved, so set it as true only for dummy client test.

		\~chinese
		基本??false。
		如果?此?置?true，Reliable P2P的?送速度?无法承?1MB/sec。
		但?提高?理性能，?只在?行????此??置?true。

		\~japanese
		デフォルト値は falseです。
		true に設定する場合Reliable P2Pの?送速度は 1MB/secを耐えることはできません。
		しかし?理性能がよくなります。ダミ?クライアントテストをする時だけ true に設定してください。

		\~
		*/
		bool m_slowReliableP2P;

		// coalesce interval. 테스트용이므로 평소에는 손대지 말 것. 0이면 기본값 인터벌 값으로 대체됨을 의미하며, 이 값 자체의 기본값은 0이다.
		int m_tunedNetworkerSendIntervalMs_TEST;

		/**
		\~korean
		\brief Simple network protocol mode.

		기본값은 false 입니다.
		패킷 캡쳐 및 복제 방식으로 더미 클라이언트 테스트를 가능하게 하기 위해서 이 값을 true로 설정하십시오.
		단, 서비스가 해커의 공격에 취약해 지며 UDP networking과 direct P2P 통신을 사용할 수 없습니다. (대신 relay 로 전송합니다.)
		라이브 서비스를 위해서는 false로 설정하십시오.

		패킷 캡쳐와 리플레이 테스트관련 내용:
		각각의 더미 클라이언트는 자신의 HostID를 확인할 수 없습니다.
		CreateP2PGroup() 과 같이 P2P 그룹 관련 함수를 호출할 경우 예상치 못한 상황이 발생할 수 있습니다.

		\~english
		\brief Simple network protocol mode.

		Default is false.
		Setting this to true allows dummy client test via packet capture and replication method.
		However, it will make service vulnerable to hackers, and does not allow UDP networking
		and direct P2P communication (will be relayed instead.)
		You should set this to false for live service.

		Notice for packet capture and replay test:
		- Each dummy client cannot identify self HostID.
		Unexpected behavior may occur if you call P2P group functions such as CreateP2PGroup().

		\~chinese
		\brief Simple network protocol mode.

		基本??false。
		是?据包截取及?制的方式，?能??行客?端????此??置?true。
		但??可能?容易受到黑客攻?且无法使用UDP networking和Direct P2P通信。（但???用relay?送）。
		?能?提供??服???此??置?false。

		?据包截取?Replay??的相??容：
		各??客?端无法??自己的HostID。
		如CreateP2PGroup()，呼叫P2P?相?函??可能??生?有??到的??。

		\~japanese
		\brief Simple network protocol mode.

		デフォルト値は false です。
		Packet capture及び複製方式でdummy client テストを可能にするためにこの値を trueに設定してください。
		ただし、サ?ビスがHackerの攻?に脆弱になり、 UDP networkingと direct P2P通信を使うことができません。 (代わりに relayで?送します。)
		Liveサ?ビスのためには falseに設定してください。

		Packet captureとリプレ?テスト?連?容
		各?の dummy client は自分の HostIDの確認ができません。
		CreateP2PGroup() のように P2Pグル?プ?連??を呼び出す場合、予想外の?況が?生する恐れがあります。

		\~
		*/
		bool m_simplePacketMode;

		/**
		\~korean
		- OnException 콜백 기능을 사용할 지 여부를 선택합니다.
		- 기본값은 true입니다.
		- 만약 false를 지정하면 유저 콜백에서 예상치 못한 Exception 발생 시 OnException이 호출되지 않고 크래시가 발생합니다.

		\~english
		- Decide whether it uses OnException callback function or not.
		- Default value is true.
		- If setting it as false, when exception occurs during  user callback, crash will occur as OnException is not called.

		\~chinese
		- ??是否使用 OnException Callback功能。
		- 基本?? true。
		- 如果指定false，用?在Callback?程中?生意想不到的 Exception ?，OnException?不被呼出，且?生Crash。

		\~japanese
		- OnException Callback機能を使用するかどうかを選?します。
		- デフォルト値はtrueです。
		- もしfalseを指定するとユ?ザ?Callbackから予想できないExceptionが?生した時、OnExceptionが呼び出されずにクラッシュが?生します。
		\~
		*/
		bool m_allowExceptionEvent;

		/**
		\~korean
		서버와 클라이언트가 NAT 라우터 뒤에 있는 상태에서 다른 클라이언트와 P2P 통신을 해야 할 경우 필요할 수 있습니다.
		가령 클라이언트가 게임 플레이를 처리하는 super peer가 되어야 하는 경우,
		그리고 super peer와 서버가 같은 host인 경우,
		super peer 안에서는 여기에 super peer의 public 주소를 넣으시기 바랍니다.

		\~english
		It is variable used when trying to set the clients' external address by force.
		It might be necesaary to make a P2P communication with other clients when a server and client is behind the NAT router.
		For example, if it should be the super peer that the client deal with game play and if it is the host that has a same server with the super peer, put the public address of the super peer here in the super peer.

		\~chinese
		是?了强制?置客?端的外部地址的?候使用的?量。
		服?器和客?端在NAT路由器后面的??下?其他客?端P2P通信的?候可能需要。
		?使客?端（client）需要?理游?的super peer, 而且super peer 和服?器一?是host的情?下，super peer要配置super peer的public地址。
		平?不要?置价格。

		\~japanese
		クライアントの外部アドレスを?制的に設定しようとする際に使用される??です。
		サ?バ?とクライアントがNATル?タ?の後ろにある?態で、他のクライアントとP2P通信をしなければならない場合、必要になるかもしれません。
		?にクライアントがゲ?ムプレイを?理するsuper peerにならなければならない場合、
		そしてsuper peerとサ?バ?が同じhostの場合、
		super peee?では、ここにsuper peerのpublicアドレスを入力してください。
		普段は値を設定しないでください。

		\~
		*/
		String m_clientAddrAtServer;

		/** <a target="_blank" href="http://guide.nettention.com/cpp_ko#acr" >연결 유지 기능 사용하기</a> 를 켜거나 끕니다. 기본적으로 꺼져 있습니다. */
		bool m_enableAutoConnectionRecovery;

		/**
		\ref
		RMI, 이벤트 를 콜백 받을 쓰레드 모델을 지정합니다.

		- SingleThreaded 지정시 사용자는 NetClient.FrameMove 함수를 호출 할 때 RMI, 이벤트가 콜백 됩니다.
		- MultiThreaded 지정시 RMI, 이벤트 콜백이 멀티 쓰레드로 콜백 됩니다.
		- UseExternalThreadPool 지정시 m_externalUserWorkerThreadPool 에 지정 된 사용자 정의 쓰레드 풀로 작동 됩니다.
		기본 옵션은 SingleThreaded 입니다.

		(주의! SingleThreaded 옵션 사용시 사용자는 NetClient.FrameMove 함수를 반드시 호출 해야 합니다.)
		*/
		ThreadModel m_userWorkerThreadModel;

		/**
		\ref
		네트워크 I/O 처리 작업에 대한 쓰레드 모델을 지정합니다.

		- SingleThreaded 지정시 사용자는 NetClient.FrameMove 함수를 호출 할 때 I/O 처리를 합니다.
		- MultiThreaded 지정시 전역 공유 쓰레드풀에서 멀티 쓰레드로 처리가 됩니다.
		- UseExternalThreadPool 지정시 m_externalNetWorkerThreadPool 에 지정 된 사용자 정의 쓰레드 풀로 작동 됩니다.
		 (전역 공유 쓰레드풀이란, NetClient 객체가 여러개가 되더라도 엔진 내부의 하나의 쓰레드풀에서 처리가 됩니다.)

		기본 옵션은 MultiThreaded 입니다.

		(주의! SingleThreaded 옵션 사용시 사용자는 NetClient.FrameMove 함수를 반드시 호출 해야 합니다.)
		*/
		ThreadModel m_netWorkerThreadModel;

		/**
		\ref
		RMI, 이벤트 콜백 등 다양한 작업을 사용자의 쓰레드 풀에서 작동 하도록 합니다.
		m_userWorkerThreadModel 에서 ThreadModel_UseExternalThreadPool 지정 시 반드시 이 값을 세팅 해야 합니다.
		*/
		CThreadPool* m_externalUserWorkerThreadPool;

		/**
		\ref
		네트워크 I/O 처리를 사용자의 쓰레드 풀에서 작동 하도록 합니다.
		m_netWorkerThreadModel 에서 ThreadModel_UseExternalThreadPool 지정 시 반드시 이 값을 세팅 해야 합니다.
		*/
		CThreadPool* m_externalNetWorkerThreadPool;

		/**
		\~korean
		Timer callback 주기 입니다. <a target="_blank" href="http://guide.nettention.com/cpp_ko#server_timer_callback" >서버에서 타이머 루프 RMI 이벤트 처리하기</a>  기능입니다.
		이것을 세팅하면 milisec단위로 한번씩 INetServerEvent.OnTick 가 호출됩니다.
		- 0이면 콜백하지 않습니다.
		- 기본값은 0입니다.

		\~english
		This sets the period of timer callback. A function described in <a target="_blank" href="http://guide.nettention.com/cpp_en#server_timer_callback" >Managing Timer loop RMI Event from server</a>.
		When this is activated, INetServerEvent.OnTimerCallback will be called at every period set by millisecond unit.
		- Ther is no callback when this is set as 0.
		- The default value is 0

		\~chinese
		Timer callback周期。<a target="_blank" href="http://guide.nettention.com/cpp_zh#server_timer_callback" >在服?器?理Timer Loop，RMI，Event</a> 功能。
		?置??的?， INetServerEvent.OnTick%?以milisec?位呼叫一次。
		- 0的的?不?回?。
		- 默??是0。

		\~japanese
		Timer callback 周期です。\ref server_timer_callback  機能です。
		これを設定すると、ミリ秒?位で一度ずつINetServerEvent.OnTickが呼び出されます。
		- 0であればコ?ルバックしません。
		- 基本値は0です。
		\~
		*/
		uint32_t m_timerCallbackIntervalMs;

		/**
		\~korean
		Timer callback이 동시 몇 개의 user worker thread에서 호출될 수 있는지를 정합니다.
		기본값은 1입니다. 모든 user worker thread를 사용하고 싶다면 INT_MAX를 입력해도 됩니다.

		\~english TODO:translate needed.

		\~chinese
		?定Timer callback同?能在??user worker thread被呼叫。
		默??是1。想使用所有user worker thread的?也可以?入INT_MAX。

		\~japanese
		Timer callbackが同時にいくつのuser worker threadで呼び出されることができるのかを決めます。
		基本値は1です。全てのuser worker threadを使用したい場合は、INT_MAXを入力しても良いです。
		\~
		*/
		int32_t m_timerCallbackParallelMaxCount;

		/**
		\~korean
		서버에서 일정주기에 한번씩 콜백을 할시에 인자로 사용되는 유저 데이터입니다.
		Proud.INetServerEvent.OnTick 가 호출될시에 인자값으로 들어갑니다. <a target="_blank" href="http://guide.nettention.com/cpp_ko#server_timer_callback" >서버에서 타이머 루프 RMI 이벤트 처리하기</a> 기능입니다.
		- 기본값은 NULL입니다.

		\~english
		This is a user data used as an index when the server calls back each time in every period.
		This value is to be input as an index when Proud.INetServerEvent.OnTimerCallback is called. A function described in <a target="_blank" href="http://guide.nettention.com/cpp_en#server_timer_callback" >Managing Timer loop RMI Event from server</a>.
		- The default value is NULL.

		\~chinese
		在服?器每一定周期回?一次的?候用于因素的用??据。
		Proud.INetServerEvent.OnTick%被呼叫的?候?入成因素?。是<a target="_blank" href="http://guide.nettention.com/cpp_zh#server_timer_callback" >在服?器?理Timer Loop，RMI，Event</a>%功能。
		- 默??是NULL。

		\~japanese
		サ?バ?で所定周期に一度ずつコ?ルバックをする時に因子として使われるユ?ザ?デ?タです。
		Proud.INetServerEvent.OnTickが呼び出される時に因子値として入ります。\ref server_timer_callback 機能です。
		- 基本値はNULLです。
		\~
		*/
		void* m_timerCallbackContext;

		PROUD_API CNetConnectionParam();
	};

	/**  @} */
}


#ifdef _MSC_VER
#pragma pack(pop)
#endif
