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
Date                   :=09/10/2017
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
Objects0=$(IntermediateDirectory)/LifeLogic.cpp$(ObjectSuffix) $(IntermediateDirectory)/LifePresentation.cpp$(ObjectSuffix) $(IntermediateDirectory)/TESTING-LIFE-INDICATOR.cpp$(ObjectSuffix) 



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
$(IntermediateDirectory)/LifeLogic.cpp$(ObjectSuffix): LifeLogic.cpp $(IntermediateDirectory)/LifeLogic.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/William/Documents/ELEN3009/SpaceRiderProject/LifeLogic.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/LifeLogic.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/LifeLogic.cpp$(DependSuffix): LifeLogic.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/LifeLogic.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/LifeLogic.cpp$(DependSuffix) -MM LifeLogic.cpp

$(IntermediateDirectory)/LifeLogic.cpp$(PreprocessSuffix): LifeLogic.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/LifeLogic.cpp$(PreprocessSuffix) LifeLogic.cpp

$(IntermediateDirectory)/LifePresentation.cpp$(ObjectSuffix): LifePresentation.cpp $(IntermediateDirectory)/LifePresentation.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/William/Documents/ELEN3009/SpaceRiderProject/LifePresentation.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/LifePresentation.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/LifePresentation.cpp$(DependSuffix): LifePresentation.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/LifePresentation.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/LifePresentation.cpp$(DependSuffix) -MM LifePresentation.cpp

$(IntermediateDirectory)/LifePresentation.cpp$(PreprocessSuffix): LifePresentation.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/LifePresentation.cpp$(PreprocessSuffix) LifePresentation.cpp

$(IntermediateDirectory)/TESTING-LIFE-INDICATOR.cpp$(ObjectSuffix): TESTING-LIFE-INDICATOR.cpp $(IntermediateDirectory)/TESTING-LIFE-INDICATOR.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/William/Documents/ELEN3009/SpaceRiderProject/TESTING-LIFE-INDICATOR.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/TESTING-LIFE-INDICATOR.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/TESTING-LIFE-INDICATOR.cpp$(DependSuffix): TESTING-LIFE-INDICATOR.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/TESTING-LIFE-INDICATOR.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/TESTING-LIFE-INDICATOR.cpp$(DependSuffix) -MM TESTING-LIFE-INDICATOR.cpp

$(IntermediateDirectory)/TESTING-LIFE-INDICATOR.cpp$(PreprocessSuffix): TESTING-LIFE-INDICATOR.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/TESTING-LIFE-INDICATOR.cpp$(PreprocessSuffix) TESTING-LIFE-INDICATOR.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


