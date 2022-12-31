# Multi-threaded Word Count

<html>

<head>
<meta http-equiv=Content-Type content="text/html; charset=utf-8">
<meta name=Generator content="Microsoft Word 15 (filtered)">

</head>

<div class=WordSection1>

<p class=MsoNormal><span lang=EN-US style='font-size:24.0pt'>&nbsp;</span></p>

<h2><a name="_Toc117878240"><b><span lang=EN-US style='font-size:14.0pt'>Thread</span></b></a></h2>

<p class=MsoNormal><span lang=EN-US style='font-size:14.0pt'>&nbsp;</span></p>

<p class=MsoNormal style='text-indent:5.0pt'><span lang=KO style='font-family:
"맑은 고딕",sans-serif'>이전 </span><span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>HW1</span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>에서 프로세스의 생성을 다루었다면</span><span
lang=EN-US style='font-family:"맑은 고딕",sans-serif'>, </span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>이번 과제에선 한 프로세스에서 여러 개의 스레드를 만들어 동작시키는 것이
주 내용이다</span><span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>. </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스가 운영체제의 관점에서 가장 작은 실행 단위라면</span><span
lang=EN-US style='font-family:"맑은 고딕",sans-serif'>, </span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>스레드는 </span><span lang=EN-US
style='font-family:"맑은 고딕",sans-serif'>CPU</span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>의 관점에서 가장 작은 실행 단위라고 할 수 있다</span><span
lang=EN-US style='font-family:"맑은 고딕",sans-serif'>. </span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>모든 프로세스는 적어도 하나의 스레드를 가지며</span><span
lang=EN-US style='font-family:"맑은 고딕",sans-serif'>, </span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>한 프로세스가 둘 이상의 스레드로 동작하는 것을 </span><span
lang=EN-US style='font-family:"맑은 고딕",sans-serif'>Multi-threading</span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>이라 한다</span><span lang=EN-US
style='font-family:"맑은 고딕",sans-serif'>. </span><span lang=KO style='font-family:
"맑은 고딕",sans-serif'>운영체제가 </span><span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>Process
Control Block</span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>으로 프로세스를
다루는 것처럼</span><span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>, </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스도 각 스레드 별로 </span><span
lang=EN-US style='font-family:"맑은 고딕",sans-serif'>Thread Control Block</span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>을 만들어 관리한다</span><span
lang=EN-US style='font-family:"맑은 고딕",sans-serif'>. </span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>스레드는 프로세스에 비해 </span><span lang=EN-US
style='font-family:"맑은 고딕",sans-serif'>Context switching</span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>에 소모되는 비용이 적지만</span><span lang=EN-US
style='font-family:"맑은 고딕",sans-serif'>, </span><span lang=KO style='font-family:
"맑은 고딕",sans-serif'>하나의 프로세스를 동작 시키기 위해 여러 개의 스레드가 실행되므로 서로 공유하는 자원이 있을 땐 스레드 간
자원 선점과 동기화를 잘 맞춰줘야 한다</span><span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>.</span></p>

<p class=MsoNormal align=center style='text-align:center;text-indent:5.0pt'><span
lang=EN-US style='font-family:"맑은 고딕",sans-serif'><img width=343 height=241
id="그림 2" src="HW2.fld/image002.png"></span></p>

<p class=MsoNormal align=center style='text-align:center'><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>↑ 한 프로세스는 적어도 하나 이상의 스레드를 가진다</span><span
lang=EN-US style='font-family:"맑은 고딕",sans-serif'>.</span></p>

<p class=MsoNormal align=center style='text-align:center;text-indent:5.0pt'><span
lang=EN-US style='font-family:"맑은 고딕",sans-serif'><img width=248 height=170
id="그림 6" src="HW2.fld/image003.png" alt="테이블이(가) 표시된 사진&#10;&#10;자동 생성된 설명"></span></p>

<p class=MsoNormal align=center style='text-align:center'><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>↑ 프로세스가 갖고 있는 스레드 개수와</span></p>

<p class=MsoNormal align=center style='text-align:center'><span lang=EN-US
style='font-family:"맑은 고딕",sans-serif'>Context switching(</span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>문맥 전환</span><span lang=EN-US
style='font-family:"맑은 고딕",sans-serif'>)</span><span lang=KO style='font-family:
"맑은 고딕",sans-serif'>한 횟수 등을 알 수 있다</span><span lang=EN-US style='font-family:
"맑은 고딕",sans-serif'>.</span></p>

<p class=MsoNormal><span lang=EN-US style='font-size:14.0pt;font-family:"맑은 고딕",sans-serif'>&nbsp;</span></p>

<h2><a name="_Toc117878241"><b><span lang=EN-US style='font-size:14.0pt'>Multi-threading</span></b></a></h2>

<p class=MsoNormal><span lang=EN-US style='font-size:14.0pt'>&nbsp;</span></p>

<p class=MsoNormal style='text-indent:5.0pt'><span lang=KO style='font-family:
"맑은 고딕",sans-serif'>위에서</span><span lang=KO> </span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>말했듯이</span><span lang=EN-US>, </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>한</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스가</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>둘</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>이상의</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>스레드로</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>실행되는</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>것을</span><span lang=KO> </span><span
lang=EN-US>Multi-threading(</span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>멀티</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>스레딩</span><span
lang=EN-US>)</span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>이라</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>한다</span><span
lang=EN-US>. </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>한</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스의</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>작업을</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>여러</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>스레드로</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>분할하는</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>것은</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>작업의</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>효율을</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>높이는</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>결과를</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>가져온다</span><span
lang=EN-US>. </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>예를</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>들어</span><span
lang=EN-US>, </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>만약</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>웹</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>브라우저가</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>하나의</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>스레드로만</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>이루어져</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>있다면</span><span
lang=EN-US>, </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>링크</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>하나를</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>클릭할</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>때마다</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>사용자의</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>입력은</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>로딩이</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>끝날</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>때까지</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>먹통이</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>되고</span><span
lang=EN-US>, </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>로딩은</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>해당</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>페이지를</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>순차적으로</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>불러와야</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>하므로</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>시간이</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>매우</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>오래</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>걸리게</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>될</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>것이다</span><span
lang=EN-US>. </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>하지만</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>현실의</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>크롬이나</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>사파리와</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>같은</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>웹</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>브라우저들은</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>이렇게</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>느리지</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>않다</span><span
lang=EN-US>. </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>여러</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>개의</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>스레드를</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>활용하여</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>사용자의</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>입력을</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>전담하는</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>스레드</span><span
lang=EN-US>, </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>사진을</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>불러오는</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>스레드</span><span
lang=EN-US>, </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>글자를</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>불러오는</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>스레드</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>등등으로</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>역할을</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>나누고</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>동시에</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>작업을</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>수행함으로써</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>사용자에게</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>쾌적한</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>환경을</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>제공한다</span><span
lang=EN-US>. </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>게다가</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>현대에</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>사용되는</span><span
lang=KO> </span><span lang=EN-US>CPU</span><span lang=KO style='font-family:
"맑은 고딕",sans-serif'>들은</span><span lang=KO> </span><span lang=EN-US>4</span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>코어</span><span lang=KO> </span><span
lang=EN-US>8</span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>스레드</span><span
lang=EN-US>, 8</span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>코어</span><span
lang=KO> </span><span lang=EN-US>16</span><span lang=KO style='font-family:
"맑은 고딕",sans-serif'>스레드와</span><span lang=KO> </span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>같이</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>여러</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>스레드를</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>동시에</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>실행할</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>수</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>있도록</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>설계</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>되어있어</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>멀티</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>스레딩을</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>활용한</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>프로그램은</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>단일</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>코어</span><span lang=KO> </span><span
lang=EN-US>CPU</span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>를</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>사용하던</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>때보다</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>더욱</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>효율이</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>높아지게</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>되었다</span><span
lang=EN-US>.</span></p>

<p class=MsoNormal style='text-indent:5.0pt'><span lang=KO style='font-family:
"맑은 고딕",sans-serif'>그러나</span><span lang=KO> </span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>멀티</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>스레딩으로</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>프로그램을</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>구현하는</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>것은</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>쉬운</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>일이</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>아니다</span><span lang=EN-US>. </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>단일</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>스레드로</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>프로그램을</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>구현할</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>때와는</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>다르게</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>고려해야</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>할</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>요소가</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>더</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>많아</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>지기</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>때문이다</span><span lang=EN-US>. </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>컴퓨터</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>구조에서</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>싱글</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>사이클</span><span lang=KO> </span><span
lang=EN-US>CPU</span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>에서</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>파이프라인이</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>적용된</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>멀티</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>사이클</span><span
lang=KO> </span><span lang=EN-US>CPU</span><span lang=KO style='font-family:
"맑은 고딕",sans-serif'>로</span><span lang=KO> </span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>발전하는</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>것과</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>같다</span><span lang=EN-US>. </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>두</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>데이터패스를</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>비교해보면</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>후자가</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>전자에</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>비해</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>효율은</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>높아지지만</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>고려해야할</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>요소가</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>많아져</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>매우</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>복잡해지게</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>된다</span><span lang=EN-US>. </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>멀티</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>스레딩으로</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>프로그래밍</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>할</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>때</span><span lang=EN-US>, </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>스레드</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>간</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>공유</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>자원</span><span lang=EN-US>, </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>즉</span><span lang=KO> </span><span
lang=EN-US>Critical Section</span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>에</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>대해</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>여러</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>스레드가</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>동시에</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>접근하는</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>것을</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>막지</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>않는다면</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>프로그래머가</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>의도한</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>것과</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>다른</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>값이</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>나오게</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>되는</span><span
lang=KO> </span><span lang=EN-US>race condition</span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>이</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>발생할</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>수</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>있고</span><span lang=EN-US>, </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>뒤에서</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>설명할</span><span lang=KO> </span><span
lang=EN-US>mutex</span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>를</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>활용하여</span><span
lang=KO> </span><span lang=EN-US>race condition</span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>을</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>방지하더라도</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>조건을</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>잘못</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>설정한다면</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>서로가</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>서로를</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>기다리는</span><span lang=KO> </span><span
lang=EN-US>dead lock</span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>이</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>발생하는</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>등</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>다양한</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>문제들을</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>고려하면서</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>프로그램을</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>만들어야</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>한다</span><span
lang=EN-US>. </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>이번</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>과제는</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>파일을</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>읽고</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>읽은</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>파일의</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>알파벳</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>글자</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>수</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>통계를</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>내는</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>프로그램을</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>작업을</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>생산하여</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>공유</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>자원에</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>채우는</span><span
lang=EN-US> Producer, </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>공유</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>자원에서</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>작업을</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>불러와</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>처리하는</span><span
lang=KO> </span><span lang=EN-US>Consumer</span><span lang=KO style='font-family:
"맑은 고딕",sans-serif'>로</span><span lang=KO> </span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>분리한</span><span lang=KO> </span><span
lang=EN-US>Producer - Consumer </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>패턴으로</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>상기한</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>문제가</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>발생하지</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>않도록</span><span
lang=KO> </span><span lang=EN-US>mutex</span><span lang=KO style='font-family:
"맑은 고딕",sans-serif'>를</span><span lang=KO> </span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>활용해</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>멀티</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>스레딩으로</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>구현하는</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>것이다</span><span lang=EN-US>. </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>스레드와</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>관련된</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>기능들</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>중</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>과제</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>구현에</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>핵심적인</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>것들에</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>대해</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>알아보자</span><span lang=EN-US>.</span></p>

<p class=MsoNormal><span lang=EN-US style='font-size:14.0pt'>&nbsp;</span></p>

<h3 style='margin-left:50.0pt;text-indent:-20.0pt'><a name="_Toc117878242"><b><span
lang=EN-US>mutex (MUTual EXclusion)</span></b></a></h3>

<p class=MsoNormal><span lang=EN-US>&nbsp;</span></p>

<p class=MsoNormal style='text-indent:5.0pt'><span lang=EN-US>Producer –
Consumer </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>패턴에서</span><span
lang=KO> </span><span lang=EN-US>Producer</span><span lang=KO style='font-family:
"맑은 고딕",sans-serif'>가</span><span lang=KO> </span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>생산한</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>작업을</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>공유</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>공간에</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>넣는</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>도중에</span><span lang=KO> </span><span
lang=EN-US>Consumer</span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>가</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>작업을</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>불러오거나</span><span
lang=EN-US>, </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>그</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>반대의</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>상황이</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>되면</span><span
lang=KO> </span><span lang=EN-US>race condition</span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>이</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>발생하게</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>되는데</span><span lang=EN-US>, </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>이를</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>방지하는</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>기능이</span><span lang=KO> </span><span
lang=EN-US>mutex(MUTual Exclusion)</span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>이다</span><span
lang=EN-US>. mutex</span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>는</span><span
lang=KO> </span><span lang=EN-US>Critical Section</span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>에</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>진입할</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>권한을</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>얻는</span><span lang=KO> </span><span
lang=EN-US>lock, </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>권한을</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>반납하는</span><span
lang=KO> </span><span lang=EN-US>unlock</span><span lang=KO style='font-family:
"맑은 고딕",sans-serif'>의</span><span lang=KO> </span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>두가지</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>연산을</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>지원한다</span><span lang=EN-US>. </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>한</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>스레드가</span><span lang=KO> </span><span
lang=EN-US>lock</span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>으로</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>권한을</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>얻으면</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>다른</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>스레드는</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>권한이</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>반납될</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>때까지</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>대기하게</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>되고</span><span
lang=EN-US>, unlock</span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>으로</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>권한이</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>반납되면</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>그때부터</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>다른</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>스레드가</span><span
lang=KO> </span><span lang=EN-US>Critical Section</span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>에</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>진입할</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>수</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>있게</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>된다</span><span lang=EN-US>.</span></p>

<p class=MsoNormal><span lang=EN-US>&nbsp;</span></p>

<h3 style='margin-left:50.0pt;text-indent:-20.0pt'><a name="_Toc117878243"><b><span
lang=EN-US>condition_variable</span></b></a></h3>

<p class=MsoNormal><span lang=EN-US>&nbsp;</span></p>

<p class=MsoNormal style='text-indent:5.0pt'><span lang=KO style='font-family:
"맑은 고딕",sans-serif'>예를</span><span lang=KO> </span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>들어</span><span lang=KO> </span><span
lang=EN-US>Producer</span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>가</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>아직</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>작업을</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>생산</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>중이고</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>공유</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>공간에</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>작업이</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>없을</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>때</span><span
lang=KO> </span><span lang=EN-US>Consumer</span><span lang=KO style='font-family:
"맑은 고딕",sans-serif'>로</span><span lang=KO> </span><span lang=EN-US>Context switching</span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>된다면</span><span lang=KO> </span><span
lang=EN-US>Consumer</span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>는</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>작업을</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>모두</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>다</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>처리한</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>것으로</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>인식하여</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>스레드가</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>종료될</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>수</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>있다</span><span
lang=EN-US>. </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>이를</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>막기</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>위해선</span><span
lang=KO> </span><span lang=EN-US>Producer</span><span lang=KO style='font-family:
"맑은 고딕",sans-serif'>가</span><span lang=KO> </span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>공유</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>공간에</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>작업을</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>채울</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>때까지</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>기다리게</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>해야</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>한다</span><span lang=EN-US>. </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>기다리게</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>하는</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>방법으로는</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>대표적으로</span><span lang=KO> </span><span
lang=EN-US>spinlock</span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>과</span><span
lang=KO> </span><span lang=EN-US>mutex</span><span lang=KO style='font-family:
"맑은 고딕",sans-serif'>에서</span><span lang=KO> </span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>지원하는</span><span lang=KO> </span><span
lang=EN-US>condition_variable</span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>이</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>있다</span><span
lang=EN-US>. spinlock</span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>의</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>경우</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>스레드가</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>작업을</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>기다리는</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>동안</span><span
lang=KO> </span><span lang=EN-US>CPU </span><span lang=KO style='font-family:
"맑은 고딕",sans-serif'>자원을</span><span lang=KO> </span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>소모하는</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>데에</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>비해</span><span lang=EN-US>,
mutex</span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>의</span><span
lang=KO> </span><span lang=EN-US>condition_variable</span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>은</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>기다려야</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>하는</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>스레드를</span><span lang=EN-US>
sleep</span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>시킴으로써</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>다른</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>스레드에</span><span
lang=KO> </span><span lang=EN-US>CPU </span><span lang=KO style='font-family:
"맑은 고딕",sans-serif'>자원을</span><span lang=KO> </span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>넘겨</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>더</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>효율적으로</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>동작할</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>수</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>있게</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>한다</span><span lang=EN-US>. </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>앞에서의</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>예를</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>계속</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>적용하면</span><span lang=EN-US>,
spinlock</span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>은</span><span
lang=KO> </span><span lang=EN-US>Consumer</span><span lang=KO style='font-family:
"맑은 고딕",sans-serif'>에</span><span lang=KO> </span><span lang=EN-US>Context switching</span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>이</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>될</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>때마다</span><span lang=KO> </span><span
lang=EN-US>Producer</span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>가</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>공유</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>공간에</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>작업을</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>채웠는지</span><span
lang=EN-US>(=unlock</span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>했는지</span><span
lang=EN-US>) </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>계속</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>확인하면서</span><span
lang=KO> </span><span lang=EN-US>CPU </span><span lang=KO style='font-family:
"맑은 고딕",sans-serif'>자원을</span><span lang=KO> </span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>소모하는</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>것이라면</span><span lang=EN-US>,
condition_variable</span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>의</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>경우</span><span
lang=EN-US> Producer</span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>가</span><span
lang=KO> </span><span lang=EN-US>signal</span><span lang=KO style='font-family:
"맑은 고딕",sans-serif'>을</span><span lang=KO> </span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>보내서</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>깨울</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>때까지</span><span lang=KO> </span><span
lang=EN-US>Consumer</span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>는</span><span
lang=KO> </span><span lang=EN-US>sleep</span><span lang=KO style='font-family:
"맑은 고딕",sans-serif'>상태에</span><span lang=KO> </span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>머물면서</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>다른</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>스레드에</span><span lang=KO> </span><span
lang=EN-US>CPU </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>자원을</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>넘기게</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>된다</span><span
lang=EN-US>. </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>본</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>과제</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>구현에는</span><span
lang=KO> </span><span lang=EN-US>condition_variable</span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>을</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>적용하였다</span><span lang=EN-US>.</span></p>

<p class=MsoNormal style='text-autospace:ideograph-numeric ideograph-other;
word-break:keep-all'><span lang=EN-US style='font-size:24.0pt'>&nbsp;</span></p>

<h2><a name="_Toc117878245"><b><span lang=KO style='font-size:14.0pt;
font-family:"맑은 고딕",sans-serif'>구현</span></b></a><b><span lang=KO
style='font-size:14.0pt'> </span></b><b><span lang=KO style='font-size:14.0pt;
font-family:"맑은 고딕",sans-serif'>환경</span></b><b><span lang=KO style='font-size:
14.0pt'> </span></b><b><span lang=KO style='font-size:14.0pt;font-family:"맑은 고딕",sans-serif'>및</span></b><b><span
lang=KO style='font-size:14.0pt'> </span></b><b><span lang=KO style='font-size:
14.0pt;font-family:"맑은 고딕",sans-serif'>실행</span></b><b><span lang=KO
style='font-size:14.0pt'> </span></b><b><span lang=KO style='font-size:14.0pt;
font-family:"맑은 고딕",sans-serif'>방법</span></b></h2>

<p class=MsoNormal><span lang=EN-US style='font-size:14.0pt'>&nbsp;</span></p>

<p class=MsoNormal><span lang=KO style='font-family:"맑은 고딕",sans-serif'>운영체제</span><span
lang=EN-US> : macOS</span></p>

<p class=MsoNormal><span lang=KO style='font-family:"맑은 고딕",sans-serif'>언어</span><span
lang=KO> </span><span lang=EN-US>: C++17</span></p>

<p class=MsoNormal><span lang=KO style='font-family:"맑은 고딕",sans-serif'>컴파일러</span><span
lang=KO> </span><span lang=EN-US>: clang 14.0.0</span></p>

<p class=MsoNormal><span lang=EN-US>Makefile </span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>사용하여</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>컴파일</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>가능</span><span lang=KO> </span><span
lang=EN-US>(macOS, Linux, Windows)</span></p>

<p class=MsoNormal><span lang=KO style='font-family:"맑은 고딕",sans-serif'>소스</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>파일</span><span
lang=KO> </span><span lang=EN-US>: Makefile, main.h, main.cpp, dirSearch.cpp,
producer.cpp, consumer.cpp</span></p>

<p class=MsoNormal><span lang=KO style='font-family:"맑은 고딕",sans-serif'>실행</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>방법</span><span
lang=KO> </span><span lang=EN-US>: ./2022_os_hw2 &lt;</span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>디렉토리</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>혹은</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>파일</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>이름</span><span lang=EN-US>&gt; &lt;producer
</span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>개수</span><span
lang=EN-US>&gt; &lt;consumer </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>개수</span><span
lang=EN-US>&gt;</span></p>

<p class=MsoNormal><span lang=KO style='font-family:"맑은 고딕",sans-serif'>개수를</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>입력하지</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>않을</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>시</span><span
lang=KO> </span><span lang=EN-US>1</span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>개로</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>동작</span></p>

<p class=MsoNormal><span lang=EN-US style='font-size:14.0pt'>&nbsp;</span></p>

</div>

</body>

</html>
