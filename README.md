**연구노트 란에 계획서,최종보고서가 같이 들어가있습니다.**
# 음성인식 무드등
간단소개:불 끄러 일어나는 수고를 덜 수 있는 음성을 통해 제어할 수 있는 등+시간을 볼 수 있는 시계
# 5조 Screen 조원들
팀장:김혜진   
하드웨어(3D 프린터):노성민   
소프트웨어:이준교   
보고서,발표자료 제작:손성훈,신재웅    
# 기술 소개
저희 조가 사용한 기술은 **adafruit**과 **IFTTT** 이고 **Arduino IDE**를 이용해 sw개발을 진행했습니다.  
우선 IFTTT는 중간 다리 역할이라 볼 수 있으며 구글 어시스턴트와 adafruit을 연결해주고  

adafruit은 실행과정을 담당하며 결과를 내는 역할을 맡게 됩니다.  

이 사이트에서 아래의 과정을 거쳐 제작을 하였습니다.  
(참고 영상:<https://www.youtube.com/watch?v=WOJjtcrM94I&t=309s>)  
### adafruit 관련  
1.adafrruit(로그인 후)  
2.상단 io-dashboard-new dashboard-dashboard생성  
3.톱니바퀴 화살표-create new block-맨 위의 toggle-새 이름 생성  
4.(<https://github.com/Chando0185/Nodemcu_LED>)이 링크를 타서 코드 설치  
5.arduino mqtt library 설치  
6.ssid,passward 수정  
7.username,auth key수정
(username,auth key는 dashboard 에서 노란 키 클릭해서 확인)  
### IFTTT 관련  
1.ifttt 접속  
2.구글 계정 로그인  
3.create-if this (add)  
4.google assistant 검색  
5.connect 진행(구글 홈 이용)  
6.active scene   
7.scene name 입력 
8.그 후 then that(add) 선택  
9.adafruit 선택  
10.send data to adafruit IO 선택  
11.feed name과 data to save 선택  
12.확인 과정  
  

