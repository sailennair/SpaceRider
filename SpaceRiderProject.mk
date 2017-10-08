##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=SpaceRiderProject
ConfigurationName      :=Debug
WorkspacePath          :=C:/Users/User/Documents/SoftwareDev2Project
ProjectPath            :=C:/Users/User/Documents/SoftwareDev2Project/SpaceRiderProject
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=User
Date                   :=08/10/2017
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :=C:/TDM-GCC-64/bin/g++.exe
SharedObjectLinkerName :=C:/TDM-GCC-64/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="SpaceRiderProject.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/TDM-GCC-64/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch)C:\Users\User\Documents\SoftwareDev2Project\SpaceRiderProject\include 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)sfml-audio $(LibrarySwitch)sfml-graphics $(LibrarySwitch)sfml-window $(LibrarySwitch)sfml-system 
ArLibs                 :=  "sfml-audio" "sfml-graphics" "sfml-window" "sfml-system" 
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)C:\Users\User\Documents\SoftwareDev2Project\SpaceRiderProject\lib 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/TDM-GCC-64/bin/ar.exe rcu
CXX      := C:/TDM-GCC-64/bin/g++.exe --std=gnu++14
CC       := C:/TDM-GCC-64/bin/gcc.exe
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/TDM-GCC-64/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/IMovingGameObject.cpp$(ObjectSuffix) $(IntermediateDirectory)/PlayerLogic.cpp$(ObjectSuffix) $(IntermediateDirectory)/PlayerPresentation.cpp$(ObjectSuffix) $(IntermediateDirectory)/GameLogic.cpp$(ObjectSuffix) $(IntermediateDirectory)/GameWindow.cpp$(ObjectSuffix) $(IntermediateDirectory)/GamePresentation.cpp$(ObjectSuffix) $(IntermediateDirectory)/IBullet.cpp$(ObjectSuffix) $(IntermediateDirectory)/PlayerBullet.cpp$(ObjectSuffix) $(IntermediateDirectory)/PlayerBulletPresentation.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/EnemyLogic.cpp$(ObjectSuffix) $(IntermediateDirectory)/EnemyPresentation.cpp$(ObjectSuffix) $(IntermediateDirectory)/EnemyBulletLogic.cpp$(ObjectSuffix) $(IntermediateDirectory)/EnemyBulletPresentation.cpp$(ObjectSuffix) $(IntermediateDirectory)/IPlayer.cpp$(ObjectSuffix) $(IntermediateDirectory)/IEnemy.cpp$(ObjectSuffix) $(IntermediateDirectory)/CollisionDetection.cpp$(ObjectSuffix) $(IntermediateDirectory)/SatelliteLogic.cpp$(ObjectSuffix) $(IntermediateDirectory)/SatellitePresentation.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/User/Documents/SoftwareDev2Project/SpaceRiderProject/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/IMovingGameObject.cpp$(ObjectSuffix): IMovingGameObject.cpp $(IntermediateDirectory)/IMovingGameObject.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/User/Documents/SoftwareDev2Project/SpaceRiderProject/IMovingGameObject.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/IMovingGameObject.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/IMovingGameObject.cpp$(DependSuffix): IMovingGameObject.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/IMovingGameObject.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/IMovingGameObject.cpp$(DependSuffix) -MM IMovingGameObject.cpp

$(IntermediateDirectory)/IMovingGameObject.cpp$(PreprocessSuffix): IMovingGameObject.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/IMovingGameObject.cpp$(PreprocessSuffix) IMovingGameObject.cpp

$(IntermediateDirectory)/PlayerLogic.cpp$(ObjectSuffix): PlayerLogic.cpp $(IntermediateDirectory)/PlayerLogic.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/User/Documents/SoftwareDev2Project/SpaceRiderProject/PlayerLogic.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/PlayerLogic.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/PlayerLogic.cpp$(DependSuffix): PlayerLogic.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/PlayerLogic.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/PlayerLogic.cpp$(DependSuffix) -MM PlayerLogic.cpp

$(IntermediateDirectory)/PlayerLogic.cpp$(PreprocessSuffix): PlayerLogic.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/PlayerLogic.cpp$(PreprocessSuffix) PlayerLogic.cpp

$(IntermediateDirectory)/PlayerPresentation.cpp$(ObjectSuffix): PlayerPresentation.cpp $(IntermediateDirectory)/PlayerPresentation.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/User/Documents/SoftwareDev2Project/SpaceRiderProject/PlayerPresentation.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/PlayerPresentation.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/PlayerPresentation.cpp$(DependSuffix): PlayerPresentation.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/PlayerPresentation.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/PlayerPresentation.cpp$(DependSuffix) -MM PlayerPresentation.cpp

$(IntermediateDirectory)/PlayerPresentation.cpp$(PreprocessSuffix): PlayerPresentation.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/PlayerPresentation.cpp$(PreprocessSuffix) PlayerPresentation.cpp

$(IntermediateDirectory)/GameLogic.cpp$(ObjectSuffix): GameLogic.cpp $(IntermediateDirectory)/GameLogic.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/User/Documents/SoftwareDev2Project/SpaceRiderProject/GameLogic.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/GameLogic.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/GameLogic.cpp$(DependSuffix): GameLogic.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/GameLogic.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/GameLogic.cpp$(DependSuffix) -MM GameLogic.cpp

$(IntermediateDirectory)/GameLogic.cpp$(PreprocessSuffix): GameLogic.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/GameLogic.cpp$(PreprocessSuffix) GameLogic.cpp

$(IntermediateDirectory)/GameWindow.cpp$(ObjectSuffix): GameWindow.cpp $(IntermediateDirectory)/GameWindow.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/User/Documents/SoftwareDev2Project/SpaceRiderProject/GameWindow.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/GameWindow.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/GameWindow.cpp$(DependSuffix): GameWindow.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/GameWindow.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/GameWindow.cpp$(DependSuffix) -MM GameWindow.cpp

$(IntermediateDirectory)/GameWindow.cpp$(PreprocessSuffix): GameWindow.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/GameWindow.cpp$(PreprocessSuffix) GameWindow.cpp

$(IntermediateDirectory)/GamePresentation.cpp$(ObjectSuffix): GamePresentation.cpp $(IntermediateDirectory)/GamePresentation.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/User/Documents/SoftwareDev2Project/SpaceRiderProject/GamePresentation.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/GamePresentation.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/GamePresentation.cpp$(DependSuffix): GamePresentation.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/GamePresentation.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/GamePresentation.cpp$(DependSuffix) -MM GamePresentation.cpp

$(IntermediateDirectory)/GamePresentation.cpp$(PreprocessSuffix): GamePresentation.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/GamePresentation.cpp$(PreprocessSuffix) GamePresentation.cpp

$(IntermediateDirectory)/IBullet.cpp$(ObjectSuffix): IBullet.cpp $(IntermediateDirectory)/IBullet.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/User/Documents/SoftwareDev2Project/SpaceRiderProject/IBullet.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/IBullet.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/IBullet.cpp$(DependSuffix): IBullet.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/IBullet.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/IBullet.cpp$(DependSuffix) -MM IBullet.cpp

$(IntermediateDirectory)/IBullet.cpp$(PreprocessSuffix): IBullet.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/IBullet.cpp$(PreprocessSuffix) IBullet.cpp

$(IntermediateDirectory)/PlayerBullet.cpp$(ObjectSuffix): PlayerBullet.cpp $(IntermediateDirectory)/PlayerBullet.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/User/Documents/SoftwareDev2Project/SpaceRiderProject/PlayerBullet.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/PlayerBullet.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/PlayerBullet.cpp$(DependSuffix): PlayerBullet.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/PlayerBullet.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/PlayerBullet.cpp$(DependSuffix) -MM PlayerBullet.cpp

$(IntermediateDirectory)/PlayerBullet.cpp$(PreprocessSuffix): PlayerBullet.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/PlayerBullet.cpp$(PreprocessSuffix) PlayerBullet.cpp

$(IntermediateDirectory)/PlayerBulletPresentation.cpp$(ObjectSuffix): PlayerBulletPresentation.cpp $(IntermediateDirectory)/PlayerBulletPresentation.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/User/Documents/SoftwareDev2Project/SpaceRiderProject/PlayerBulletPresentation.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/PlayerBulletPresentation.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/PlayerBulletPresentation.cpp$(DependSuffix): PlayerBulletPresentation.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/PlayerBulletPresentation.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/PlayerBulletPresentation.cpp$(DependSuffix) -MM PlayerBulletPresentation.cpp

$(IntermediateDirectory)/PlayerBulletPresentation.cpp$(PreprocessSuffix): PlayerBulletPresentation.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/PlayerBulletPresentation.cpp$(PreprocessSuffix) PlayerBulletPresentation.cpp

$(IntermediateDirectory)/EnemyLogic.cpp$(ObjectSuffix): EnemyLogic.cpp $(IntermediateDirectory)/EnemyLogic.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/User/Documents/SoftwareDev2Project/SpaceRiderProject/EnemyLogic.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/EnemyLogic.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/EnemyLogic.cpp$(DependSuffix): EnemyLogic.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/EnemyLogic.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/EnemyLogic.cpp$(DependSuffix) -MM EnemyLogic.cpp

$(IntermediateDirectory)/EnemyLogic.cpp$(PreprocessSuffix): EnemyLogic.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/EnemyLogic.cpp$(PreprocessSuffix) EnemyLogic.cpp

$(IntermediateDirectory)/EnemyPresentation.cpp$(ObjectSuffix): EnemyPresentation.cpp $(IntermediateDirectory)/EnemyPresentation.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/User/Documents/SoftwareDev2Project/SpaceRiderProject/EnemyPresentation.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/EnemyPresentation.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/EnemyPresentation.cpp$(DependSuffix): EnemyPresentation.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/EnemyPresentation.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/EnemyPresentation.cpp$(DependSuffix) -MM EnemyPresentation.cpp

$(IntermediateDirectory)/EnemyPresentation.cpp$(PreprocessSuffix): EnemyPresentation.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/EnemyPresentation.cpp$(PreprocessSuffix) EnemyPresentation.cpp

$(IntermediateDirectory)/EnemyBulletLogic.cpp$(ObjectSuffix): EnemyBulletLogic.cpp $(IntermediateDirectory)/EnemyBulletLogic.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/User/Documents/SoftwareDev2Project/SpaceRiderProject/EnemyBulletLogic.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/EnemyBulletLogic.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/EnemyBulletLogic.cpp$(DependSuffix): EnemyBulletLogic.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/EnemyBulletLogic.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/EnemyBulletLogic.cpp$(DependSuffix) -MM EnemyBulletLogic.cpp

$(IntermediateDirectory)/EnemyBulletLogic.cpp$(PreprocessSuffix): EnemyBulletLogic.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/EnemyBulletLogic.cpp$(PreprocessSuffix) EnemyBulletLogic.cpp

$(IntermediateDirectory)/EnemyBulletPresentation.cpp$(ObjectSuffix): EnemyBulletPresentation.cpp $(IntermediateDirectory)/EnemyBulletPresentation.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/User/Documents/SoftwareDev2Project/SpaceRiderProject/EnemyBulletPresentation.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/EnemyBulletPresentation.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/EnemyBulletPresentation.cpp$(DependSuffix): EnemyBulletPresentation.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/EnemyBulletPresentation.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/EnemyBulletPresentation.cpp$(DependSuffix) -MM EnemyBulletPresentation.cpp

$(IntermediateDirectory)/EnemyBulletPresentation.cpp$(PreprocessSuffix): EnemyBulletPresentation.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/EnemyBulletPresentation.cpp$(PreprocessSuffix) EnemyBulletPresentation.cpp

$(IntermediateDirectory)/IPlayer.cpp$(ObjectSuffix): IPlayer.cpp $(IntermediateDirectory)/IPlayer.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/User/Documents/SoftwareDev2Project/SpaceRiderProject/IPlayer.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/IPlayer.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/IPlayer.cpp$(DependSuffix): IPlayer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/IPlayer.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/IPlayer.cpp$(DependSuffix) -MM IPlayer.cpp

$(IntermediateDirectory)/IPlayer.cpp$(PreprocessSuffix): IPlayer.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/IPlayer.cpp$(PreprocessSuffix) IPlayer.cpp

$(IntermediateDirectory)/IEnemy.cpp$(ObjectSuffix): IEnemy.cpp $(IntermediateDirectory)/IEnemy.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/User/Documents/SoftwareDev2Project/SpaceRiderProject/IEnemy.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/IEnemy.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/IEnemy.cpp$(DependSuffix): IEnemy.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/IEnemy.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/IEnemy.cpp$(DependSuffix) -MM IEnemy.cpp

$(IntermediateDirectory)/IEnemy.cpp$(PreprocessSuffix): IEnemy.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/IEnemy.cpp$(PreprocessSuffix) IEnemy.cpp

$(IntermediateDirectory)/CollisionDetection.cpp$(ObjectSuffix): CollisionDetection.cpp $(IntermediateDirectory)/CollisionDetection.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/User/Documents/SoftwareDev2Project/SpaceRiderProject/CollisionDetection.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/CollisionDetection.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CollisionDetection.cpp$(DependSuffix): CollisionDetection.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/CollisionDetection.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/CollisionDetection.cpp$(DependSuffix) -MM CollisionDetection.cpp

$(IntermediateDirectory)/CollisionDetection.cpp$(PreprocessSuffix): CollisionDetection.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/CollisionDetection.cpp$(PreprocessSuffix) CollisionDetection.cpp

$(IntermediateDirectory)/SatelliteLogic.cpp$(ObjectSuffix): SatelliteLogic.cpp $(IntermediateDirectory)/SatelliteLogic.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/User/Documents/SoftwareDev2Project/SpaceRiderProject/SatelliteLogic.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/SatelliteLogic.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/SatelliteLogic.cpp$(DependSuffix): SatelliteLogic.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/SatelliteLogic.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/SatelliteLogic.cpp$(DependSuffix) -MM SatelliteLogic.cpp

$(IntermediateDirectory)/SatelliteLogic.cpp$(PreprocessSuffix): SatelliteLogic.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/SatelliteLogic.cpp$(PreprocessSuffix) SatelliteLogic.cpp

$(IntermediateDirectory)/SatellitePresentation.cpp$(ObjectSuffix): SatellitePresentation.cpp $(IntermediateDirectory)/SatellitePresentation.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/User/Documents/SoftwareDev2Project/SpaceRiderProject/SatellitePresentation.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/SatellitePresentation.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/SatellitePresentation.cpp$(DependSuffix): SatellitePresentation.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/SatellitePresentation.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/SatellitePresentation.cpp$(DependSuffix) -MM SatellitePresentation.cpp

$(IntermediateDirectory)/SatellitePresentation.cpp$(PreprocessSuffix): SatellitePresentation.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/SatellitePresentation.cpp$(PreprocessSuffix) SatellitePresentation.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


