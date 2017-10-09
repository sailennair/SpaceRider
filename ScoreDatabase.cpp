#include "ScoreDatabase.h"
ScoreDatabase::ScoreDatabase(){
    _fileName = "score.dat";
    _highestScore = 0;
    _tempScore = 0;
    _WriteFile.open(_fileName, std::ofstream::out | std::ofstream::app);
    _WriteFile.close();
    _highestScore = readScoreFromFile(); 
    _currentPlayerHighestScore = 0;
        //LPCSTR and DWARD are part of window.h
    LPCSTR fileLPCWSTR = _fileName.c_str();
    DWORD fileAttributes = GetFileAttributes(fileLPCWSTR);
    SetFileAttributes(fileLPCWSTR, fileAttributes | FILE_ATTRIBUTE_HIDDEN);
}

ScoreDatabase::ScoreDatabase(std::string fileName):
    _fileName{fileName},
    _highestScore{0},
    _tempScore{0}
    {
        _WriteFile.open(_fileName, std::ofstream::out | std::ofstream::app);
        _WriteFile.close();
        _WriteFile.clear();
        _highestScore = readScoreFromFile();
    //LPCSTR and DWARD are part of window.h
    LPCSTR fileLPCWSTR = _fileName.c_str();
    DWORD fileAttributes = GetFileAttributes(fileLPCWSTR);
    SetFileAttributes(fileLPCWSTR, fileAttributes | FILE_ATTRIBUTE_HIDDEN); 
    }

int ScoreDatabase::readScoreFromFile(){
    _ReadFile.open(_fileName);    
    std::string nameInTheList;
    if(_ReadFile.is_open()){
        std::cout << "File is Open";
        if(_ReadFile.peek() == std::ifstream::traits_type::eof()){
            _ReadFile.close();
            return _highestScore;
            
        }else{


            while(_ReadFile >> nameInTheList >> _tempScore){
                if(_tempScore > _highestScore){
                    _highestScore = _tempScore;
                        
                }
            }
        }
    }else{
        std::cout << " File is not Open";
    }
    
    //_Playername = nameInTheList;
    _ReadFile.close();
    _ReadFile.clear();
    
    return _highestScore;
}

void ScoreDatabase::writeScoreToFile(int score){
    _WriteFile.open(_fileName, std::ofstream::out | std::ofstream::app);

    if(_WriteFile.is_open()){
         _WriteFile << _PlayerName << " " <<_highestScore << "\n";
    }
    _WriteFile.close();
    _WriteFile.clear();

}

void ScoreDatabase::setScorePoints(int scoreIncrement, const std::string& name){
    _currentScore += scoreIncrement;
    _PlayerName = name;
    if (_currentScore > _currentPlayerHighestScore){
        _currentPlayerHighestScore = _currentScore;
        std::cout << " 10 Points" << std::endl;
    }
    // need to update the database
    if (_currentPlayerHighestScore > _highestScore){
        _highestScore = _currentPlayerHighestScore;
        std::cout << " Wrtiting to File From within Score" << std::endl ;
        writeScoreToFile(_highestScore);
    }      
    
}