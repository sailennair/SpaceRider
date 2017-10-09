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
Objects0=$(IntermediateDirectory)/Score.cpp$(ObjectSuffix) $(IntermediateDirectory)/ScoreDatabase.cpp$(ObjectSuffix) $(IntermediateDirectory)/ScorePresentation.cpp$(ObjectSuffix) $(IntermediateDirectory)/Testing-Score-Presentation.cpp$(ObjectSuffix) 



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
$(IntermediateDirectory)/Score.cpp$(ObjectSuffix): Score.cpp $(IntermediateDirectory)/Score.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/William/Documents/ELEN3009/SpaceRiderProject/Score.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Score.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Score.cpp$(DependSuffix): Score.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Score.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Score.cpp$(DependSuffix) -MM Score.cpp

$(IntermediateDirectory)/Score.cpp$(PreprocessSuffix): Score.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Score.cpp$(PreprocessSuffix) Score.cpp

$(IntermediateDirectory)/ScoreDatabase.cpp$(ObjectSuffix): ScoreDatabase.cpp $(IntermediateDirectory)/ScoreDatabase.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/William/Documents/ELEN3009/SpaceRiderProject/ScoreDatabase.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ScoreDatabase.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ScoreDatabase.cpp$(DependSuffix): ScoreDatabase.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ScoreDatabase.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ScoreDatabase.cpp$(DependSuffix) -MM ScoreDatabase.cpp

$(IntermediateDirectory)/ScoreDatabase.cpp$(PreprocessSuffix): ScoreDatabase.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ScoreDatabase.cpp$(PreprocessSuffix) ScoreDatabase.cpp

$(IntermediateDirectory)/ScorePresentation.cpp$(ObjectSuffix): ScorePresentation.cpp $(IntermediateDirectory)/ScorePresentation.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/William/Documents/ELEN3009/SpaceRiderProject/ScorePresentation.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ScorePresentation.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ScorePresentation.cpp$(DependSuffix): ScorePresentation.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ScorePresentation.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ScorePresentation.cpp$(DependSuffix) -MM ScorePresentation.cpp

$(IntermediateDirectory)/ScorePresentation.cpp$(PreprocessSuffix): ScorePresentation.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ScorePresentation.cpp$(PreprocessSuffix) ScorePresentation.cpp

$(IntermediateDirectory)/Testing-Score-Presentation.cpp$(ObjectSuffix): Testing-Score-Presentation.cpp $(IntermediateDirectory)/Testing-Score-Presentation.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/William/Documents/ELEN3009/SpaceRiderProject/Testing-Score-Presentation.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Testing-Score-Presentation.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Testing-Score-Presentation.cpp$(DependSuffix): Testing-Score-Presentation.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Testing-Score-Presentation.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Testing-Score-Presentation.cpp$(DependSuffix) -MM Testing-Score-Presentation.cpp

$(IntermediateDirectory)/Testing-Score-Presentation.cpp$(PreprocessSuffix): Testing-Score-Presentation.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Testing-Score-Presentation.cpp$(PreprocessSuffix) Testing-Score-Presentation.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


