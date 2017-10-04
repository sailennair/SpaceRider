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
Date                   :=04/10/2017
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
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/IMovingGameObject.cpp$(ObjectSuffix) $(IntermediateDirectory)/IGameCharacter.cpp$(ObjectSuffix) $(IntermediateDirectory)/PlayerLogic.cpp$(ObjectSuffix) $(IntermediateDirectory)/PlayerPresentation.cpp$(ObjectSuffix) $(IntermediateDirectory)/GameLogic.cpp$(ObjectSuffix) $(IntermediateDirectory)/GameWindow.cpp$(ObjectSuffix) $(IntermediateDirectory)/CreateWindow.cpp$(ObjectSuffix) 



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

$(IntermediateDirectory)/IGameCharacter.cpp$(ObjectSuffix): IGameCharacter.cpp $(IntermediateDirectory)/IGameCharacter.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/User/Documents/SoftwareDev2Project/SpaceRiderProject/IGameCharacter.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/IGameCharacter.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/IGameCharacter.cpp$(DependSuffix): IGameCharacter.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/IGameCharacter.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/IGameCharacter.cpp$(DependSuffix) -MM IGameCharacter.cpp

$(IntermediateDirectory)/IGameCharacter.cpp$(PreprocessSuffix): IGameCharacter.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/IGameCharacter.cpp$(PreprocessSuffix) IGameCharacter.cpp

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

$(IntermediateDirectory)/CreateWindow.cpp$(ObjectSuffix): CreateWindow.cpp $(IntermediateDirectory)/CreateWindow.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/User/Documents/SoftwareDev2Project/SpaceRiderProject/CreateWindow.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/CreateWindow.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CreateWindow.cpp$(DependSuffix): CreateWindow.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/CreateWindow.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/CreateWindow.cpp$(DependSuffix) -MM CreateWindow.cpp

$(IntermediateDirectory)/CreateWindow.cpp$(PreprocessSuffix): CreateWindow.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/CreateWindow.cpp$(PreprocessSuffix) CreateWindow.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


