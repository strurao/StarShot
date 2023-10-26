## 개발 도구 🛠
- UE 5.1
- C++

## 기능 🕹
- Epic games Paragon Belica 플레이어 캐릭터에 Mixamo 애니메이션을 리타겟팅
- 플레이어 캐릭터 애니메이션 ``Montage/BlendSpace``
  - 걷기, 달리기, 웅크리기, 총격, 재장전, 피격, 죽음 

- 5 가지의 희귀도를 가진 3 가지의 총기를 2 가지 탄약으로 장전 가능. 총기에 따라서 연사가 가능하거나 불가능. 
  - 이러한 총기의 데이터를 언리얼 엔진의 ``FTableRowBase`` 클래스에 저장해서, 
  - 언리얼 엔진 에디터에서 각 총기 인스턴스의 데이터를 수정할 수 있다.

- ``Behavior Tree`` 로 구현한 몬스터는 저마다 순찰 영역 ``AgroSphere`` 를 가진다.
- ``AgroSphere`` 에 플레이어 캐릭터가 ``overlapped`` 되면, 몬스터는 플레이어를 공격한다.
- ``AgroSphere`` 에 플레이어 캐릭터가 없어도, 캐릭터가 먼저 공격하면 캐릭터를 쫓아와 공격한다.

-  지면의 ``Physics Material`` 5가지 (물, 돌, 타일, 철, 풀) 에 따라 ``Particle System`` 과  ``SoundCue`` 설정
- ``UMG (Unreal Motion Graphics)`` UI 위젯을 코드와 바인딩

## 소개 링크 🎬
- [Youtube](https://youtu.be/PPTi-WS36Zg)



![썸넬02](https://github.com/strurao/StarShot/assets/126440235/a916be0f-5e04-4324-bab5-1478fdf5363b)
