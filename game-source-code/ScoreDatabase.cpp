#include "ScoreDatabase.h"
ScoreDatabase::ScoreDatabase(){
    // This is to make sure the file exists and when we read there are no errors related to reading from empty file
    _WriteFile.open(_fileName, std::ofstream::out | std::ofstream::app);
    _WriteFile.close();
   
    //LPCSTR and DWARD are part of window.h This makes the file attrtibutes hidden
    LPCSTR fileLPCWSTR = _fileName.c_str();
    DWORD fileAttributes = GetFileAttributes(fileLPCWSTR);
    SetFileAttributes(fileLPCWSTR, fileAttributes | FILE_ATTRIBUTE_HIDDEN);
}


std::vector<int> ScoreDatabase::readScoreFromFileInt(){
    _ReadFile.open(_fileName);    
    
    if(!_ReadFile.is_open()){// If the file could not be open for reading
        std::cerr << "DataBase Error: Could not read " << _fileName;
    }
    
    if(_ReadFile.peek() == std::ifstream::traits_type::eof()){ // File is empty
        _ReadFile.close();
        _ReadFile.clear();
        return _scores;
        
    }
    
    auto tempScore = 0;
    while(_ReadFile >> tempScore){
            _scores.push_back(tempScore);        
    }
    
    _ReadFile.close();
    _ReadFile.clear();
    
    return _scores;
}

std::vector<PlayerDetails> ScoreDatabase::readScoreFromFile(){
    _ReadFile.open(_fileName);    
    
    if(!_ReadFile.is_open()){// If the file could not be open for reading
        std::cerr << "DataBase Error: Could not read from" << _fileName;
    }
    
    if(_ReadFile.peek() == std::ifstream::traits_type::eof()){ // File is empty
        _ReadFile.close();
        _ReadFile.clear();
        return _playerDetailsVect;
        
    }
    
    PlayerDetails player;
    while(_ReadFile >> player.name >> player.score){
            _playerDetailsVect.push_back(player);        
    }
    
    _ReadFile.close();
    _ReadFile.clear();
    
    return _playerDetailsVect;
}

void ScoreDatabase::writeScoreToFile(const std::vector<int>& scoresVect){
    // TOGGLE FILE HIDDEN ATTRIBUTES OFF
//    LPCSTR fileLPCWSTR = _fileName.c_str();
//    DWORD fileAttributes = GetFileAttributes(fileLPCWSTR);
//    SetFileAttributes(fileLPCWSTR, fileAttributes ^ FILE_ATTRIBUTE_HIDDEN);
    toggleFilePermission();
    _WriteFile.open(_fileName,std::ofstream::out | std::ofstream::trunc); // This line is to append entries

    
    if(!_WriteFile.is_open()){
         std::cerr << "DataBase Error: Could not write to " << _fileName;
    }
    
    for(auto iter = begin(scoresVect); iter!=end(scoresVect); ++iter){
        _WriteFile << (*iter) << "\n";
    }
    
    _WriteFile.close();
    _WriteFile.clear();
        
  // TOGGLE FILE HIDDEN ATTRIBUTES ON
    toggleFilePermission();
//    LPCSTR fileL2PCWSTR = _fileName.c_str();
//    DWORD fileAttributes2 = GetFileAttributes(fileL2PCWSTR);
//    SetFileAttributes(fileL2PCWSTR, fileAttributes2 ^ FILE_ATTRIBUTE_HIDDEN);
    

}

//void ScoreDatabase::writeScoreToFile(const std::vector<PlayerDetails>& playerScoreVect){
//    //_WriteFile.open(_fileName, std::ofstream::out | std::ofstream::app); // This line is to append entries
//    _WriteFile.open(_fileName);
//    if(!_WriteFile.is_open()){
//         
//         std::cerr << "DataBase Error: Could not write to " << _fileName;
//    }
//    for(auto iter = begin(playerScoreVect); iter!=end(playerScoreVect); ++iter){
//        _WriteFile << iter->name << " " << iter->score << "\n"; 
//    }
//    
//    _WriteFile.close();
//    _WriteFile.clear();
//
//}


void ScoreDatabase::toggleFilePermission(){
    LPCSTR fileLPCWSTR = _fileName.c_str();
    DWORD fileAttributes = GetFileAttributes(fileLPCWSTR);
    SetFileAttributes(fileLPCWSTR, fileAttributes ^ FILE_ATTRIBUTE_HIDDEN);
}