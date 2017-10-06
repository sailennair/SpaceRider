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
Date                   :=06/10/2017
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
Objects0=$(IntermediateDirectory)/SatelliteLogic.cpp$(ObjectSuffix) $(IntermediateDirectory)/SatellitePresentation.cpp$(ObjectSuffix) $(IntermediateDirectory)/TestingSatelliteLayers.cpp$(ObjectSuffix) 



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
$(IntermediateDirectory)/SatelliteLogic.cpp$(ObjectSuffix): SatelliteLogic.cpp $(IntermediateDirectory)/SatelliteLogic.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/William/Documents/ELEN3009/SpaceRiderProject/SatelliteLogic.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/SatelliteLogic.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/SatelliteLogic.cpp$(DependSuffix): SatelliteLogic.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/SatelliteLogic.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/SatelliteLogic.cpp$(DependSuffix) -MM SatelliteLogic.cpp

$(IntermediateDirectory)/SatelliteLogic.cpp$(PreprocessSuffix): SatelliteLogic.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/SatelliteLogic.cpp$(PreprocessSuffix) SatelliteLogic.cpp

$(IntermediateDirectory)/SatellitePresentation.cpp$(ObjectSuffix): SatellitePresentation.cpp $(IntermediateDirectory)/SatellitePresentation.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/William/Documents/ELEN3009/SpaceRiderProject/SatellitePresentation.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/SatellitePresentation.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/SatellitePresentation.cpp$(DependSuffix): SatellitePresentation.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/SatellitePresentation.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/SatellitePresentation.cpp$(DependSuffix) -MM SatellitePresentation.cpp

$(IntermediateDirectory)/SatellitePresentation.cpp$(PreprocessSuffix): SatellitePresentation.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/SatellitePresentation.cpp$(PreprocessSuffix) SatellitePresentation.cpp

$(IntermediateDirectory)/TestingSatelliteLayers.cpp$(ObjectSuffix): TestingSatelliteLayers.cpp $(IntermediateDirectory)/TestingSatelliteLayers.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/William/Documents/ELEN3009/SpaceRiderProject/TestingSatelliteLayers.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/TestingSatelliteLayers.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/TestingSatelliteLayers.cpp$(DependSuffix): TestingSatelliteLayers.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/TestingSatelliteLayers.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/TestingSatelliteLayers.cpp$(DependSuffix) -MM TestingSatelliteLayers.cpp

$(IntermediateDirectory)/TestingSatelliteLayers.cpp$(PreprocessSuffix): TestingSatelliteLayers.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/TestingSatelliteLayers.cpp$(PreprocessSuffix) TestingSatelliteLayers.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


