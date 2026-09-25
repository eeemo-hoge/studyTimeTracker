#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <fstream>
#include <cstdint>
using namespace std;

int main() {
    // intのサイズは任意のバイト数にはできないため、32ビット（通常4バイト）を指定する。
    // より小さい値だけなら std::int8_t（1バイト）または std::int16_t（2バイト）を使う。
    // date は大きいため int32_t のまま、time は 0〜2359 なので int16_t にする。
    fstream outFile("studyTimeLog.csv", ios::app);
    std::int32_t date;
    std::int16_t totalStudyTime = 0;
    std::int32_t time, studyTime = 0;
    // int8_t is treated as a character by operator>>, so "14" is read as '1'.
    std::int16_t category = 0;
    string categoryName;
    // ofstream outFile("studyTimeLog.csv", ios::app);
    cout << "Preparing todays date" << endl;
    auto now = chrono::system_clock::now();
    time_t t = chrono::system_clock::to_time_t(now);
    tm* localTime = localtime(&t);
    date = (localTime->tm_year + 1900) * 10000 + (localTime->tm_mon + 1) * 100 + localTime->tm_mday;
    time = localTime->tm_hour * 100 + localTime->tm_min;

    cout << "Current date: " << date << ", Current time: " << time << endl;
    cout << "Show csv data ? y or n || Y or N : " << flush;
    char showData[2];
    for(std::int8_t i = 0; i < 2; i++) {
        showData[i] = '\0';
    }
    cin >> showData;
    if (showData[0] == 'y' || showData[0] == 'Y') {
        ifstream inFile("studyTimeLog.csv");
        if (inFile) {
            string line;
            while (getline(inFile, line)) {
                cout << line << endl;
            }
            inFile.close();
        }
        cout << endl;
    } else if (showData[0] == 'n' || showData[0] == 'N') {
        cout << "CSV data display skipped." << endl;
    } else {
        cerr << "Invalid input. Please enter 'y' or 'n'." << endl;
    }
    outFile.close();
        cout << endl;
    //gotoのジャンプ先ラベル
    INPUT_DATA:
    outFile.open("studyTimeLog.csv", ios::app);
    if (! outFile.is_open()) {
        cerr << "Failed to open file." << endl;
        return 1;
    }else{
         for(std::int8_t i = 0; i < 64; i++){
            cout << "=" << flush;
        }
        cout << endl;
        string line;
        while (getline(cin, line)) {
            if (line.empty()) {
                break;
            }
            cout << line << endl;
        }
       
        cout << endl;
        cout << "Please enter study time tracking data." << endl;
        cout << "Here are the category names: " << endl;
        cout << "1. Reading" << endl;
        cout << "2. Working" << endl;
        cout << "3. Coding" << endl;
        cout << "4. Programming" << endl;
        cout << "5. Chore" << endl;
        cout << "6. Meditation" << endl;
        cout << "7. Exercise" << endl;
        cout << "8. Other" << endl;
        cout << "9. Reseting" << endl;
        cout << "10. Chilling lock in" << endl;
        cout << "11. Chinese" << endl;
        cout << "12. English" << endl;
        cout << "13. Reinforcing linux" << endl;
        cout << "14. LPIC" << endl;
        cout << "Number ? : ";
        cin >> category;
        switch (category) {
            case 1:
                cout << "Selected category: Reading" << endl;
                categoryName = "Reading";
                break;
            case 2:
                cout << "Selected category: Working" << endl;
                categoryName = "Working";
                break;
            case 3:
                cout << "Selected category: Coding" << endl;
                categoryName = "Coding";
                break;
            case 4:
                cout << "Selected category: Programming" << endl;
                categoryName = "Programming";
                break;
            case 5:
                cout << "Selected category: Chore" << endl;
                categoryName = "Chore";
                break;
            case 6:
                cout << "Selected category: Meditation" << endl;
                categoryName = "Meditation";
                break;
            case 7:
                cout << "Selected category: Exercise" << endl;
                categoryName = "Exercise";
                break;
            case 8:
                cout << "Selected category: Other" << endl;
                categoryName = "Other";
                break;
            case 9:
                cout << "Selected category: Reseting" << endl;
                categoryName = "Reseting";
                break;
            case 10:
                cout << "Selected category: Chilling lock in" << endl;
                categoryName = "Chilling lock in";
                break;
            case 11:
                cout << "Selected category: Chinese" << endl;
                categoryName = "Chinese";
                break;
            case 12:
                cout << "Selected category: English" << endl;
                categoryName = "English";
                break;
            case 13:
                cout << "Selected category: Reinforcing linux" << endl;
                categoryName = "Reinforcing linux";
                break;
            case 14:
                cout << "Selected category: LPIC" << endl;
                categoryName = "LPIC";      
                break;
            default:
                cerr << "Invalid category." << endl;
                return 1;
        }
        cout << "Study time (in minutes): " << flush;
        cin >> studyTime;
        //cout << "Total study time (in minutes): " << flush;
        //cin >> totalStudyTime;

        // csvファイルから今日の日付分のTotalStudyTimeMinutesを読み取って加算する
        {
            
            ifstream todayFile("studyTimeLog.csv");
            if (!todayFile.is_open()) {
                cerr << "Failed to open file." << endl;
                return 1;
            }
            string todayLine;
            bool isHeader = true;
            while (getline(todayFile, todayLine)) {
                if (isHeader) {
                    isHeader = false;
                    continue;
                }
                if (todayLine.empty()) {
                    continue;
                }
                stringstream ss(todayLine);
                string dateStr, timeStr, categoryStr, studyTimeStr;
                getline(ss, dateStr, ',');
                getline(ss, timeStr, ',');
                getline(ss, categoryStr, ',');
                getline(ss, studyTimeStr, ',');
                if (!dateStr.empty() && stoi(dateStr) == date && !studyTimeStr.empty()) {
                    totalStudyTime += static_cast<std::int16_t>(stoi(studyTimeStr));
                }
            }
            todayFile.close();
        }

        totalStudyTime = totalStudyTime + studyTime;
        ifstream inFile("studyTimeLog.csv");
        if (!getline(inFile, line)) { // 一行目がなければヘッダーを書き込む
            outFile << "Date,Time,Category,StudyTimeMinutes,TotalStudyTimeMinutes,studyTimeMinutes,totalStudyTimeHours," << endl; // Write CSV header
        }

        //studyTImeLogには、date,time,category,study time,total study timeなどの情報を記録する予定
        outFile << date                         // Date
            << "," << time                 // Time
            << "," << categoryName         // Category
            << "," << studyTime            // Study time (minutes)
            << "," << totalStudyTime       // Total study time (minutes)
            << "," << studyTime / 60.0     // Study time (hours)
            << "," << totalStudyTime / 60.0 // Total study time (hours)
            << endl;
        cout << "Data written to csv file successfully." << endl;
    }
    outFile.close();
    return 0;
}