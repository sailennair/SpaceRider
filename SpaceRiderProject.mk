##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=SpaceRiderProject
ConfigurationName      :=Debug
WorkspacePath          :=C:/Users/William/Documents/ELEN3009
ProjectPath            :=C:/Users/William/Documents/ELEN3009/SpaceRiderProject
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=William
Date                   :=05/10/2017
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
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch)C:\Users\William\Documents\ELEN3009\SpaceRiderProject\include 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)sfml-audio $(LibrarySwitch)sfml-graphics $(LibrarySwitch)sfml-window $(LibrarySwitch)sfml-system 
ArLibs                 :=  "sfml-audio" "sfml-graphics" "sfml-window" "sfml-system" 
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)C:\Users\William\Documents\ELEN3009\SpaceRiderProject\lib 

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
Objects0=$(IntermediateDirectory)/EnemyLogic.cpp$(ObjectSuffix) $(IntermediateDirectory)/EnemyPresentation.cpp$(ObjectSuffix) $(IntermediateDirectory)/TestingEnemyLayers.cpp$(ObjectSuffix) 



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
$(IntermediateDirectory)/EnemyLogic.cpp$(ObjectSuffix): EnemyLogic.cpp $(IntermediateDirectory)/EnemyLogic.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/William/Documents/ELEN3009/SpaceRiderProject/EnemyLogic.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/EnemyLogic.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/EnemyLogic.cpp$(DependSuffix): EnemyLogic.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/EnemyLogic.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/EnemyLogic.cpp$(DependSuffix) -MM EnemyLogic.cpp

$(IntermediateDirectory)/EnemyLogic.cpp$(PreprocessSuffix): EnemyLogic.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/EnemyLogic.cpp$(PreprocessSuffix) EnemyLogic.cpp

$(IntermediateDirectory)/EnemyPresentation.cpp$(ObjectSuffix): EnemyPresentation.cpp $(IntermediateDirectory)/EnemyPresentation.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/William/Documents/ELEN3009/SpaceRiderProject/EnemyPresentation.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/EnemyPresentation.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/EnemyPresentation.cpp$(DependSuffix): EnemyPresentation.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/EnemyPresentation.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/EnemyPresentation.cpp$(DependSuffix) -MM EnemyPresentation.cpp

$(IntermediateDirectory)/EnemyPresentation.cpp$(PreprocessSuffix): EnemyPresentation.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/EnemyPresentation.cpp$(PreprocessSuffix) EnemyPresentation.cpp

$(IntermediateDirectory)/TestingEnemyLayers.cpp$(ObjectSuffix): TestingEnemyLayers.cpp $(IntermediateDirectory)/TestingEnemyLayers.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/William/Documents/ELEN3009/SpaceRiderProject/TestingEnemyLayers.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/TestingEnemyLayers.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/TestingEnemyLayers.cpp$(DependSuffix): TestingEnemyLayers.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/TestingEnemyLayers.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/TestingEnemyLayers.cpp$(DependSuffix) -MM TestingEnemyLayers.cpp

$(IntermediateDirectory)/TestingEnemyLayers.cpp$(PreprocessSuffix): TestingEnemyLayers.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/TestingEnemyLayers.cpp$(PreprocessSuffix) TestingEnemyLayers.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


