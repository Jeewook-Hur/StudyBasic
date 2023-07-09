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

    
    //���ڸ� �Է¹޴´�
    //cout << "Input number(1~20000) : ";
    //cin >> inputed;
    getline(cin, line);

    numberOfWords = stoi(line);

    if (numberOfWords >= 1 && numberOfWords <= 20000) { //���ڰ� �Է°��� ������ 
        //�Է¹��� ���ڷ� ���ڿ� �迭�� �Ҵ��Ѵ�.
        arrayOfString = new string * [numberOfWords];
        
        i = 0;
        while (i < numberOfWords) { //�ܾ��� ���̸�ŭ �ݺ��Ѵ�.
            //�ܾ �Է¹޴´�.
            //cout << "Input word : ";
            getline(cin, inputWord);
            //cin >> inputWord;
            //�ܾ �迭�� �����Ѵ�.
            arrayOfString[i] = new string(inputWord);
            i++;
        }
        
        //���̺� ����
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
        
        //���� ���� ������ �ʱ�ȭ�Ѵ�. 
        numberOfSameLength = 1;
        //���ڿ� �迭�� ù��° ���ڿ��� ���̸� Ȯ���Ѵ�.
        i = 0;
        //���� ������ �ܾ��� �������� �ʱ�ȭ�Ѵ�. 
        startIndex = i;
        currentLength = arrayOfString[i]->length();
        i++;
        while(i < numberOfWords + 1) { //���ڿ��� ���̺��� �ϳ� ū��ŭ �ݺ��Ѵ�. 
            
            if (i < numberOfWords) { //���ڿ��� ���̸� ���� �� ������ 
                //���ڿ��� ���̸� ���Ѵ�. 
                stringLength = arrayOfString[i]->length();
            }

            if (i < numberOfWords && stringLength == currentLength) {//���ڿ��� ���̰� ���� ���ڿ��� ���̰� ������
                //���� ������ ������ ����
                numberOfSameLength++;
            }
            else if(i < numberOfWords && stringLength > currentLength && numberOfSameLength == 1) { //���ڿ��� ���̰� ���� ���ڿ��� ���̺��� ũ��
                //���� �ܾ��� �������� �ʱ�ȭ�Ѵ�. 
                startIndex = i;
                //���ڿ��� ���̸� �����Ѵ�.
                currentLength = stringLength;
                //���� ���� ������ �ʱ�ȭ�Ѵ�. 
                numberOfSameLength = 1;
            }
            else if (i == numberOfWords || (stringLength > currentLength && numberOfSameLength >= 2)) { //���ڿ��� ���̰� ���� ���ڿ��� ���̺��� ũ�� ���� ������ ������ 2�� �̻��̸�
                //���� ������ �ܾ��� �������� �����Ѵ�. 
                if (i == numberOfWords) {
                    endIndex = numberOfWords - 1;
                }
                else {
                    endIndex = i - 1;
                }
                //���ķ� ������ �ܾ���� ���ĺ� ������ �����Ѵ�. 
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
                //���� ������ �ܾ��� �������� �ʱ�ȭ�Ѵ�. 
                startIndex = i;
                //���ڿ��� ���̸� �����Ѵ�.
                currentLength = stringLength;
                //���� ���� ������ �ʱ�ȭ�Ѵ�. 
                numberOfSameLength = 1;
            }

            i++;
        }

        //�ߺ��� �ܾ �����Ѵ�. 
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


        //���ڿ��� �ܾ ����Ѵ�. 
        i = 0;
        while (i < numberOfWords) {
            cout << *arrayOfString[i] << endl;
            i++;
        }
        
        //���ڿ� �迭�� ���̸�ŭ �ݺ��Ѵ�.
        i = 0;
        while (i < numberOfWords) {
            //�迭���� �Ҵ��� ���ڿ��� �Ҵ������Ѵ�.
            delete arrayOfString[i];
            i++;
        }
        //���ڿ� �迭�� �Ҵ������Ѵ�.
        delete[] arrayOfString;
    }
    else {
        cout << "Wrong number!" << endl << "Input number between 1~20000";
    }
	return 0;
}