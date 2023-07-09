#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* arcv[]) {
    string* (*arrayOfString) = 0;
    string* temp = 0;
    string inputWord;
    string inputed;
    string line;

    int numberOfWords;
    int numberToChange;
    int numberOfSameLength;
    int currentLength;
    int stringLength;
    int startIndex;
    int endIndex;
    int i;
    int j;
    int k;

    
    //숫자를 입력받는다
    //cout << "Input number(1~20000) : ";
    //cin >> inputed;
    getline(cin, line);

    numberOfWords = stoi(line);

    if (numberOfWords >= 1 && numberOfWords <= 20000) { //숫자가 입력값에 맞으면 
        //입력받은 숫자로 문자열 배열을 할당한다.
        arrayOfString = new string * [numberOfWords];
        
        i = 0;
        while (i < numberOfWords) { //단어의 길이만큼 반복한다.
            //단어를 입력받는다.
            //cout << "Input word : ";
            getline(cin, inputWord);
            //cin >> inputWord;
            //단어를 배열에 저장한다.
            arrayOfString[i] = new string(inputWord);
            i++;
        }
        
        //길이별 정렬
        i = 1;
        while (i < numberOfWords) { 
            temp = arrayOfString[i];
            j = i - 1;
            while (j >= 0 && (arrayOfString[j])->length() > temp->length()) {
                arrayOfString[j + 1] = arrayOfString[j];
                j--;
            }
            arrayOfString[j + 1] = temp;
            i++;
        }
        
        //같은 문자 개수를 초기화한다. 
        numberOfSameLength = 1;
        //문자열 배열의 첫번째 문자열의 길이를 확인한다.
        i = 0;
        //같은 길이의 단어의 시작점을 초기화한다. 
        startIndex = i;
        currentLength = arrayOfString[i]->length();
        i++;
        while(i < numberOfWords + 1) { //문자열의 길이보다 하나 큰만큼 반복한다. 
            
            if (i < numberOfWords) { //문자열의 길이를 구할 수 있으면 
                //문자열의 길이를 구한다. 
                stringLength = arrayOfString[i]->length();
            }

            if (i < numberOfWords && stringLength == currentLength) {//문자열의 길이가 현재 문자열과 길이가 같으면
                //같은 문자의 개수를 센다
                numberOfSameLength++;
            }
            else if(i < numberOfWords && stringLength > currentLength && numberOfSameLength == 1) { //문자열의 길이가 현재 문자열의 길이보다 크면
                //같은 단어의 시작점을 초기화한다. 
                startIndex = i;
                //문자열의 길이를 갱신한다.
                currentLength = stringLength;
                //같은 문자 개수를 초기화한다. 
                numberOfSameLength = 1;
            }
            else if (i == numberOfWords || (stringLength > currentLength && numberOfSameLength >= 2)) { //문자열의 길이가 현재 문자열의 길이보다 크고 같은 문자의 개수가 2개 이상이면
                //같은 길이의 단어의 종료점을 설정한다. 
                if (i == numberOfWords) {
                    endIndex = numberOfWords - 1;
                }
                else {
                    endIndex = i - 1;
                }
                //정렬로 범위의 단어들을 알파벳 순으로 정리한다. 
                j = startIndex + 1;
                while (j < endIndex + 1) {
                    temp = arrayOfString[j];
                    k = j - 1;
                    while (k >= startIndex && arrayOfString[k]->compare(*temp) > 0) {
                        arrayOfString[k + 1] = arrayOfString[k];
                        k--;
                    }
                    arrayOfString[k + 1] = temp;
                    j++;
                }
                //같은 길이의 단어의 시작점을 초기화한다. 
                startIndex = i;
                //문자열의 길이를 갱신한다.
                currentLength = stringLength;
                //같은 문자 개수를 초기화한다. 
                numberOfSameLength = 1;
            }

            i++;
        }

        //중복된 단어를 제거한다. 
        i = 0;
        while (i < numberOfWords - 1) {
            if ((arrayOfString[i])->compare(*(arrayOfString[i + 1])) == 0) {
                j = i;
                while (j < numberOfWords - 1) {
                    arrayOfString[j] = arrayOfString[j + 1];
                    j++;
                }
                arrayOfString[j] = 0;
                numberOfWords--;
                i--;
            }
            i++;
        }


        //문자열의 단어를 출력한다. 
        i = 0;
        while (i < numberOfWords) {
            cout << *arrayOfString[i] << endl;
            i++;
        }
        
        //문자열 배열의 길이만큼 반복한다.
        i = 0;
        while (i < numberOfWords) {
            //배열에서 할당한 문자열을 할당해제한다.
            delete arrayOfString[i];
            i++;
        }
        //문자열 배열을 할당해제한다.
        delete[] arrayOfString;
    }
    else {
        cout << "Wrong number!" << endl << "Input number between 1~20000";
    }
	return 0;
}