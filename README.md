## 개발 환경 🛠
- UE 5.1
- C++

## 프로젝트 설명 🗂
Shooter 폴더에 관련 스크립트를 업로드했습니다.

## 소개 링크 🎬
- [Youtube](https://youtu.be/PPTi-WS36Zg)

## 기능 🕹
- Epic Games Paragon 플레이어 캐릭터에 Mixamo 애니메이션을 리타겟팅.
- 플레이어 캐릭터 애니메이션 Montage/BlendSpace
  - 걷기, 달리기, 웅크리기, 총격, 피격, 재장전, 죽음 
- 수집한 총기를 인벤토리 배열 ``TArray<AItem*> Inventory`` 에 저장하고 F,1,2,3,4,5 키를 누를 때 각 총기를 장착한다.
- 5 가지의 희귀도를 가진 3 가지의 총기를 2 가지 탄약으로 장전 가능하고, 총기에 따라서 연사가 가능하거나 불가능하도록
  - 언리얼 엔진 에디터에서 각 총기 인스턴스를 커스텀할 수 있다.
  - 이를 위해 언리얼 엔진의 ``FTableRowBase`` 클래스를 상속받는 커스텀 구조체 ``WeaponDataTable`` 에 총기 정보를 저장.
- ``Behavior Tree`` 로 행동 패턴이 정해진 몬스터는 ``Navigation Mesh`` 가 적용된 구역에서 각각의 순찰 영역을 왕복하며 순찰.
  - 몬스터의 ``AgroSphere`` (적을 인식하는 구역) 에 플레이어 캐릭터가 overlapped 되면, 몬스터는 플레이어를 Target 으로 인식하고 공격.
  - 플레이어가 몬스터를 공격하면 ``AgroSphere`` 에 플레이어가 없어도, 플레이어를 Target 으로 인식하고 쫓아와서 공격.
- 지면의 Physics Material 5가지 (물, 돌, 타일, 철, 잔디) 에 따라 Particle System 과  SoundCue 를 다르게 설정.
- UMG (Unreal Motion Graphics) UI 위젯을 코드와 바인딩하여 인벤토리, 총기, 체력의 정보를 출력.





![썸넬02](https://github.com/strurao/StarShot/assets/126440235/a916be0f-5e04-4324-bab5-1478fdf5363b)
